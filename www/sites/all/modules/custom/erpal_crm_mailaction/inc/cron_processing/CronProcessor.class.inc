<?php
/*
 * @author 		Marc Sven Kleinboehl
 * @created 	01/14/2012
 * @copyright	2012 © Bright Solutions GmbH 
 */
 
namespace erpal_crm_mailaction\cron_processing;

use \erpal_crm_mailaction\misc\Log as Log;
use \erpal_crm_mailaction\misc\Settings as Settings;
use \erpal_crm_mailaction\imap\ImapFetcher as ImapFetcher;

class CronProcessor {
  
  const WATCHDOG_TYPE = 'erpal_crm_mailaction - cron';
  
  private $cronModel; 
  
  /**
   * Ctor.
   */
  private function __construct () {
    
    $this->cronModel = new CronModel ();
    
    return;
  }
  
  /**
   * A factory method for creating a full configured CronProcessor object.
   * 
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
  
  /**
   * Creates new tasks from incomming mails.
   */
  private function createNewTaks () {

         
    // Create a fetcher object for fetching mails.
    $imapFetcher = new ImapFetcher ();

    $connection = self::configureImapConnection ($imapFetcher);
    
    if ($connection->errorOccured ()) {
      Log::error (__CLASS__, $connection->getError ());
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
  
  /**
   * A Proxy method for CronModel::areTasksAvailable ().
   * 
   * @param boolean   TRUE on success.
   */
  private function areTasksAvailable () {
    
    return $this->cronModel->areTasksAvailable ();
  }
  
  /**
   * A Proxy method for CronModel::areTasksAvailable ().
   * Just for better human reading.
   * 
   * @return boolean    TRUE on success.
   */
  private function processNextTask () {
    
    return $this->cronModel->processNextTask ();
  }
  
  /**
   * Creates an configures an ImapConnection for a specific ImapFetcher object.
   * 
   * @param ImapFetcher $imapFetcher 	An ImapFetcher object.
   * @return ImapConnection	Returns an ImapConnection object.
   */
  public static function configureImapConnection ($imapFetcher) {

    $connection  = $imapFetcher->openConnection (
      Settings::get ('mailbox_settings', 'username'),
      Settings::get ('mailbox_settings', 'password')
    );
    
    self::imapConnectionHelper ($connection);
    
    return $connection;
  }
  
  /**
   * Configures an ImapConnection object by current settings.
   * 
   * @param ImapConnection	$imapConnection	This object 
   */
  private static function imapConnectionHelper ($imapConnection) {
    
    // Realize TLS settings.
    switch (Settings::get ('mailbox_settings', 'tls')) {
      case '/notls':
        $imapConnection->noTls ();
        break;
        
      case '/tls':
        $imapConnection->tls ();
        break;
    }
      
    // Realize protocol settings.
    switch (Settings::get ('mailbox_settings', 'protocol')) {
      case '/imap':
        $imapConnection->imap ();
        break;
        
      case '/pop3':
        $imapConnection->pop3 ();
        break;
    }
    
    // Realize protocol settings.
    if (Settings::get ('mailbox_settings', 'ssl') == '/ssl') {
      $imapConnection->imap ();
    }
    
    // Realize certificate settings.
    switch (Settings::get ('mailbox_settings', 'certificate')) {
      case '/novalidate-cert':
        $imapConnection->doNotValidateCertificates ();
        break;
        
      case '/validate-cert':
        $imapConnection->validateCertificates ();
        break;
    }
    
    $imapConnection->port ((int) Settings::get ('mailbox_settings', 'port', 143)); 
    $imapConnection->host (Settings::get ('mailbox_settings', 'host', 'localhost'));
    $imapConnection->connect ();
    
    return;
  }
}
