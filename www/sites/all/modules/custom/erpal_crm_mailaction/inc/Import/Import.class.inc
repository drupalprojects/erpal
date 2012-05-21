<?php
/*
 * @author 		Marc Sven Kleinboehl
 * @created 	01/14/2012
 * @copyright	2012 © Bright Solutions GmbH
 * 
 * Imports a mail as node or as a comment of a node of a specific ticket ID.
 */

namespace erpal_crm_mailaction;

class Import {
  
  private $mailParser;
  private $activityNodeModel;    
  private $contactNodeModel;
  
  /*
   * Ctor.
   */
  private function __construct () {
    
    module_load_include ('inc', 'erpal_crm_mailaction', 'inc/Import/ActivityNodeModel.class');
    module_load_include ('inc', 'erpal_crm_mailaction', 'inc/Import/ContactNodeModel.class');
    module_load_include ('inc', 'erpal_crm_mailaction', 'inc/Import/MailParser.class');
    
    $this->activityNodeModel = new ActivityNodeModel ();
    $this->contactNodeModel  = new ContactNodeModel ();
    
    return;
  }
  
  /*
   * Imports a single mail as node or comment of a node.
   * @param $to
   * @param $from
   * @param $subject
   * @param $body
   */
  public static function import ($to, $from, $subject, $body, $attachments) {

    // TODO: ATTACHMENTS TO NODE
    
    $import = new Import ();
    
    $import->mailParser  = new MailParser ($subject, $body);
    $body                = $import->mailParser->body;
    $subject             = $import->mailParser->subject;
    
    $published = (int)_erpal_crm_mailaction_get_settings (ERPAL_CRM_MAILACTION_CONFIG_GROUP_IMPORT_SETTINGS, 'publish_imports', FALSE);
 
    if (! $import->contactNodeModel->oneOftheParticipantsExists (array (
      	$to, $from
      ))) {
      $published = FALSE;
      
      $this->tryCreateUnknownContactIfRequired ($imapContactObject);
    }
    
    $import->activityNodeModel->published ($published);
 
    if ($import->activityNodeModel->isCustomerActivityAvailable ($import->mailParser->ticketID, $subject)) {

      $import->activityNodeModel->addToCustomerActivity ($import->mailParser->ticketID, $to, $from, $subject, $body, $attachments);
    }else{
      
      if (empty ($import->mailParser->ticketID)) {
        $import->activityNodeModel->insertCustomerActivity ($to, $from, $subject, $body, $attachments);
      }else{
        $import->activityNodeModel->addToCustomerActivity ($import->mailParser->ticketID, $to, $from, $subject, $body, $attachments);
      }
    }
    
    return;
  }
  
  /*
   * Tries to create a contact for unknown correspondency contact, if it was previously configured.
   * @param object	$imapContactObject	An IMAP header contact object.
   */
  private function tryCreateUnknownContactIfRequired ($imapContactObject) {
    
    if (! _erpal_crm_mailaction_get_settings (ERPAL_CRM_MAILACTION_CONFIG_GROUP_IMPORT_SETTINGS, 'create_contact_for_unknown_user', FALSE)) {
      return;
    }
    
    $import->contactNodeModel->createUnknownContact($imapContactObject);
    
    return;
  }
}
