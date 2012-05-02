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
  private $authentificationModel;
  
  /*
   * Ctor.
   */
  private function __construct () {
    
    module_load_include ('inc', 'erpal_crm_mailaction', 'inc/Import/ActivityNodeModel.class');
    module_load_include ('inc', 'erpal_crm_mailaction', 'inc/Import/AuthentificationModel.class');
    
    $this->activityNodeModel     = new ActivityNodeModel ();
    $this->authentificationModel = new AuthentificationModel ();
    
    return;
  }
  
  /*
   * Imports a single mail as node or comment of a node.
   * @param $to
   * @param $from
   * @param $subject
   * @param $body
   */
  public static function import ($to, $from, $subject, $body) {

    $import = new Import ();

    module_load_include ('inc', 'erpal_crm_mailaction', 'inc/Import/MailParser.class');
    
    $import->mailParser  = new MailParser ($subject, $body);
    $body                = $import->mailParser->body;
    $subject             = $import->mailParser->subject;
 
    if (! $import->authentificationModel->oneOftheParticipantsExists (array (
      	$to, $from
      ))) {
      return;
    }
    
    if ($import->activityNodeModel->isCustomerActivityAvailable ($import->mailParser->ticketID)) {
      $import->activityNodeModel->addToCustomerActivity ($import->mailParser->ticketID, $to, $from, $subject, $body);
    }else{
      $import->activityNodeModel->insertCustomerActivity ($to, $from, $subject, $body);
    }
    
    return;
  }
}
