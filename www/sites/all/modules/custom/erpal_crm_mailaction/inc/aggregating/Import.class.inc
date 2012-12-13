<?php
/**
 * @author 		Marc Sven Kleinboehl
 * @created 	07/12/2012
 * @copyright	2012 © Bright Solutions GmbH
 * 
 * Imports a mail as node of a various type.
 */

namespace erpal_crm_mailaction\aggregating;

use \erpal_crm_mailaction\misc\Settings as Settings;
use \erpal_crm_mailaction\aggregating\database\models\ContactNodeModel as ContactNodeModel;
use \erpal_crm_mailaction\aggregating\determining\TicketParser as TicketParser;
use \erpal_crm_mailaction\misc\Log as Log;
use \erpal_crm_mailaction\aggregating\database\entity_wrappers\MailEntityWrapper as MailEntityWrapper;
use \erpal_crm_mailaction\aggregating\database\entity_wrappers\FileEntityWrapper as FileEntityWrapper;

class Import {

  private $contactModel;
  
  /**
   * CTor.
   */
  public function __construct () {
    
    $this->contactModel = new ContactNodeModel ();
    
    return;
  }
  
  /**
   * Imports a single mail.
   * 
   * @param array   $to               The "to" address as IMAP participant object.
   * @param array   $from             The "from" address as IMAP participant object.
   * @param string  $subject          The subject/title of the mail.
   * @param string  $body             The body text of the mail.
   * @param array   $attachments      The attachments of the mail. It is 
   *                                  an array of drupal file objects. 
   */
  public function import ($to, $from, $subject, $body, $attachments) {

    $ticketParser        = new TicketParser ($subject, $body);
    $body                = $ticketParser->body;
    $subject             = $ticketParser->subject;
    $toMail              = self::imapParticipantObjectToEmailAddress ($to);
    $fromMail            = self::imapParticipantObjectToEmailAddress ($from);
 
    if (! $this->checkForErrors($ticketParser, $toMail, $fromMail, $subject)) {
      return FALSE;
    }
    
    $mailID = $this->importMail (
      $toMail,
      $fromMail,
      $subject, 
      $body, 
      $attachments
    );

    $importModel = $this->loadImportModel (
      $ticketParser->ticketClass,
      $ticketParser->ticketID,
      $this->contactModel->loadContactIDOfMailAddress ($toMail),
      $this->contactModel->loadContactIDOfMailAddress ($fromMail),
      $mailID,
      $this->contactModel
    );
    if ($importModel == NULL) {

      return FALSE;
    }
    
    // Occured errors while importing in the import model.
    if ($importModel != NULL && ! $importModel->isOk ()) {
       Log::error (
        get_class($importModel),
        $importMode->getLastError ()
      );
      
      return FALSE;
    }
    
    return TRUE;
  }

  /**
   * Loads an import model by a class path.
   * 
   * @param   string  $classPath        Describes the class path of the importer.
   * @param   array   $to               The "to" address as IMAP participant object.
   * @param   array   $from             The "from" address as IMAP participant object.
   * @param   string  $subject          The subject/title of the mail.
   * @param   string  $body             The body text of the mail.
   * @param   array   $attachments      The attachments of the mail. It is 
   *                                    an array of drupal file objects. 
   * @return  ImportModel               An implementation of the ImportModel interface on success.
   *                                    Otherwise NULL.
   */
  private function loadImportModel ($classPath, $tickedID, $toID, $fromID, $mailID) {
   
    $reflectionClass = new \ReflectionClass ($classPath);
    $importModel     = $reflectionClass->newInstanceArgs(
      array(
        $tickedID,
        $toID,
        $fromID,
        $mailID,
        $this->contactModel
      )
    );

    return $importModel;
  }
  
  /**
   * Checks for errors.
   * 
   * @param   TicketParser  $ticketParser     The ticker parser object.
   * @param   array         $to               The "to" address as IMAP participant object.
   * @param   array         $from             The "from" address as IMAP participant object.
   * @param   string        $subject          The subject/title of the mail.
   * @return  boolean                         TRUE on success.
   */
  private function checkForErrors ($ticketParser, $toMail, $fromMail, $subject) {
    
    if ($ticketParser->ticketID == TicketParser::UNKNOWN) {
      
      Log::error (
        __CLASS__,
        'Unknown ticket ID for mail "' . $subject . '".'
      );
      
      return FALSE;
    }
    
    if (! $this->contactModel->isParticipantExisting ($toMail)) {
      
      if (Settings::get ('import_settings', 'create_contact_for_unknown_user') != FALSE) {
         $this->contactModel->createUnknownContact ($toMail);
      }else{
        Log::error (
          __CLASS__,
          'Unknown conversion source partner for mail "' . $subject . '".'
        );
        
        return FALSE;
      }
      return FALSE;
    }
    
    if (! $this->contactModel->isParticipantExisting ($fromMail)) {
      
      if (Settings::get ('import_settings', 'create_contact_for_unknown_user') != FALSE) {
         $this->contactModel->createUnknownContact ($fromMail);
      }else{
        Log::error (
          __CLASS__,
          'Unknown conversion source partner for mail "' . $subject . '".'
        );
        
        return FALSE;
      }
    }
    
    return TRUE;
  }
  
  /**
   * Imports a mail.
   * 
   * @param   string  $toMail           The mail address of the receiver.
   * @param   string  $fromMail         The mail address of the sender.
   * @param   string  $subject          The subject/title of the mail.
   * @param   string  $body             The body text of the mail.
   * @param   array   $attachments      The attachments of the mail. It is 
   *                                    an array of drupal file objects. 
   */
  private function importMail ($toMail, $fromMail, $subject, $body, array $attachments) {
    
    $mailEntity = new MailEntityWrapper (
      $this->contactModel->loadContactIDOfMailAddress ($toMail),
      $this->contactModel->loadContactIDOfMailAddress ($fromMail),
      $subject,
      $body
    );
    
    if (Settings::get ('import_settings', 'publish_attachments')) {
      foreach ($attachments as $attachment) {
        
        $fileEntity = new FileEntityWrapper (
          $attachment,
          $attachment->filename
        );
        $fileEntity->save ();
        
        $mailEntity->addAttachment ($fileEntity);
      }
    }
    
    $mailEntity->status = (boolean)Settings::get ('import_settings', 'publish_imports');
    $mailEntity->save ();
    
    return $mailEntity->getID ();
  }
  
  /**
   * Creates an email address from an IMAP participant object.
   * 
   * @param   stdClass  $imapParticipantObject    The IMAP participant object.
   * @return  mixed                               The email address on succes. Otherwise FALSE.
   */
  private static function imapParticipantObjectToEmailAddress ($imapParticipantObject) {
    
    if (! is_object ($imapParticipantObject)) {
      return FALSE;
    }
    
    if (! isset ($imapParticipantObject->mailbox) || ! isset ($imapParticipantObject->host)) {
      return FALSE;
    }
    
    return $imapParticipantObject->mailbox . '@' . $imapParticipantObject->host;
  }
}
