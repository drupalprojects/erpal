<?php
/*
 * @author 		Marc Sven Kleinboehl
 * @created 	01/14/2012
 * @copyright	2012 © Bright Solutions GmbH 
 */
 
namespace erpal_crm_mailaction;

class CronProcessor {
  
  const WATCHDOG_TYPE = 'erpal_crm_mailaction - cron';
  
  private $cronModel; 
  
  /*
   * Ctor.
   */
  private function __construct () {
    
    module_load_include ('inc', 'erpal_crm_mailaction', 'inc/CronProcessor/CronModel.class');
    
    $this->cronModel = new CronModel ();
    
    return;
  }
  
  /*
   * A factory method for creating a full configured CronProcessor object.
   * @return CronProcessor	An CronProcessor object.
   */
  public static function run () {
    
    $cronProcessor = new CronProcessor ();
    
    if ($cronProcessor->areTasksAvailable ()) {
      $cronProcessor->processNextTask ();
      return $cronProcessor;
    }
    
    $cronProcessor->createNewTaks ();    
    if ($cronProcessor->areTasksAvailable ()) {
      $cronProcessor->processNextTask ();
    }
    
    return $cronProcessor;
  }
  
  /*
   * Creates new tasks from incomming mails.
   */
  private function createNewTaks () {
    
    // Include important files.
    module_load_include ('inc', 'erpal_crm_mailaction', 'inc/ImapFetcher/ImapFetcher.class');
         
    // Create a fetcher object for fetching mails.
    $imapFetcher = new ImapFetcher ();

    $connection = self::configureImapConnection ($imapFetcher);
    
    if ($connection->errorOccured ()) {
      watchdog (self::WATCHDOG_TYPE, $connection->getError (), array (), WATCHDOG_ERROR);
      return FALSE;
    }
    
    $unseen     = $imapFetcher->readUnseen();
    $messageIDs = array ();
    
    foreach ($unseen as $mail) {

      $messageIDs[] = $mail->data->msgno;
    }
    
    $messageIDPackets = array_chunk ($messageIDs, 5);
    
    foreach ($messageIDPackets as $messageIDPacket) {
      $this->cronModel->addTask ($messageIDPacket);
    }
    
    return;
  }
  
  /*
   * A Proxy method for CronModel::areTasksAvailable ().
   */
  private function areTasksAvailable () {
    
    return $this->cronModel->areTasksAvailable ();
  }
  
  /*
   * A Proxy method for CronModel::areTasksAvailable ().
   */
  private function processNextTask () {
    
    return $this->cronModel->processNextTask ();
  }
  
  /*
   * Creates an configures an ImapConnection for a specific ImapFetcher object.
   * @param ImapFetcher $imapFetcher 	An ImapFetcher object.
   * @return ImapConnection	Returns an ImapConnection object.
   */
  public static function configureImapConnection ($imapFetcher) {
    
    module_load_include ('inc', 'erpal_crm_mailaction', 'inc/config');
    
    $connection  = $imapFetcher->openConnection (
      _erpal_crm_mailaction_get_settings (ERPAL_CRM_MAILACTION_CONFIG_GROUP_MAILBOX, 'username'),
      _erpal_crm_mailaction_get_settings (ERPAL_CRM_MAILACTION_CONFIG_GROUP_MAILBOX, 'password')
    );
    
    self::imapConnectionHelper ($connection);
    
    return $connection;
  }
  
  /*
   * Configures an ImapConnection object by current settings.
   * @param ImapConnection	$imap_connection	This object 
   */
  private static function imapConnectionHelper ($imap_connection) {
    
    module_load_include ('inc', 'erpal_crm_mailaction', 'inc/config');
    
    // Realize TLS settings.
    switch (_erpal_crm_mailaction_get_settings (ERPAL_CRM_MAILACTION_CONFIG_GROUP_MAILBOX_SETTINGS, 'tls', FALSE)) {
      case '/notls':
        $imap_connection->noTls ();
        break;
        
      case '/tls':
        $imap_connection->tls ();
        break;
    }
      
    // Realize protocol settings.
    switch (_erpal_crm_mailaction_get_settings (ERPAL_CRM_MAILACTION_CONFIG_GROUP_MAILBOX_SETTINGS, 
    'protocol', FALSE)) {
      case '/imap':
        $imap_connection->imap ();
        break;
        
      case '/pop3':
        $imap_connection->pop3 ();
        break;
    }
    
    // Realize protocol settings.
    if (_erpal_crm_mailaction_get_settings (ERPAL_CRM_MAILACTION_CONFIG_GROUP_MAILBOX_SETTINGS, 
    'ssl', FALSE) == '/ssl') {
      $imap_connection->imap ();
    }
    
    // Realize certificate settings.
    switch (_erpal_crm_mailaction_get_settings (ERPAL_CRM_MAILACTION_CONFIG_GROUP_MAILBOX_SETTINGS, 
    'certificate', FALSE)) {
      case '/novalidate-cert':
        $imap_connection->doNotValidateCertificates ();
        break;
        
      case '/validate-cert':
        $imap_connection->validateCertificates ();
        break;
    }
     
    $imap_connection->port ((integer)_erpal_crm_mailaction_get_settings (ERPAL_CRM_MAILACTION_CONFIG_GROUP_MAILBOX, 
    	'port', '143'
    ));
    $imap_connection->host (_erpal_crm_mailaction_get_settings (ERPAL_CRM_MAILACTION_CONFIG_GROUP_MAILBOX, 'host', 
    	'localhost'
    ));
    $imap_connection->connect ();
    
    return;
  }
}
