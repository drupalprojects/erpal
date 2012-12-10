<?php
/*
 * @author 		Marc Sven Kleinboehl
 * @created 	07/12/2012
 * @copyright	2012 © Bright Solutions GmbH
 * 
 * Imports a mail as node or as a comment of a node of a specific ticket ID.
 */

namespace erpal_crm_mailaction\aggregating;

class Import {
  
  private $lastError;
  
  /**
   * Imports a single mail.
   * 
   * @param array   $to               
   * @param array   $from             
   * @param string  $subject          The subject/title of the mail.
   * @param string  $body             The body text of the mail.
   * @param array   $attachments      The attachments of the mail. It is 
   *                                  an array of drupal file objects. 
   */
  public function import ($to, $from, $subject, $body, $attachments) {

    $import              = new Import ();
    $import->mailParser  = new \erpal_crm_mailaction\aggregating\determining\MailParser ($subject, $body);
    $body                = $import->mailParser->body;
    $subject             = $import->mailParser->subject;
    $published           = (int)\erpal_crm_mailaction\misc\Settings::get ('import_settings', 'publish_imports');
 
    if ($import->mailParser->ticketID == \erpal_crm_mailaction\aggregating\determining\MailParser::UNKNOWN) {
      
      $this->lastError = t(
        'Unknown ticket ID for mail "@mail"', 
        array (
          '@mail' => empty (trim($subject)) ? t('Unknown subject') : $subject
        )
      );
      return;
    }
 
    switch ($import->mailParser->ticketType) {
      case \erpal_crm_mailaction\aggregating\determining\MailParser::TICKET_TYPE_TICKET: // For importing to tickets.
        $importModel = new \erpal_crm_mailaction\aggregating\database\models\import\Ticket (
          $import->mailParser->ticketID,
          $to, 
          $from, 
          $subject, 
          $body, 
          $attachments
        );
        return $importModel;
      
      case \erpal_crm_mailaction\aggregating\determining\MailParser::TICKET_TYPE_ACTIVITY: // For importing to activities.
        $importModel = new \erpal_crm_mailaction\aggregating\database\models\import\Activity (
          $import->mailParser->ticketID,
          $to, 
          $from, 
          $subject, 
          $body, 
          $attachments
        );
        return $importModel;
        
      default:
        $this->lastError = t(
          'Unknown ticket type "@ticket_type" for mail "@mail"', 
          array (
            '@mail'         => empty (trim($subject)) ? t('Unknown subject') : $subject,
            '@ticket_type'  => $import->mailParser->ticketType
          )
        );
        return;
    }
    
    if (! $importMode->isOk ()) {
        $this->lastError = $importMode->getLastError ();
    }
    
    return;
  }

  /**
   * Returns the message of the last occured error.
   * 
   * @return string     A message if an error occured previously. NULL if not.
   */
  public function getLastError () {
    
    return $this->lastError ();
  }
  
  /**
   * Returns FALSE if an error occured previously.
   * 
   * @return boolean    FALSE on error.
   */
  public function isOK () {
    
    return empty ($this->lastError);
  }
}
