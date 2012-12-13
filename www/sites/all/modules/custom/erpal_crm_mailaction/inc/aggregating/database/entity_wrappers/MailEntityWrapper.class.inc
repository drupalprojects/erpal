<?php
/**
 * @author    Marc Sven Kleinboehl
 * @created   12/01/2012
 * @copyright 2012 © Bright Solutions GmbH 
 * 
 * This is a simple wrapper for creating mail nodes.
 */

namespace erpal_crm_mailaction\aggregating\database\entity_wrappers;

class MailEntityWrapper extends EntityWrapperBase {
  
  /**
   * Default values for the wrapped node entity.
   */
  const ENTITY_TYPE   = 'erpal_mail';
  const ENTITY_AUTHOR = 1;
  
  /**
   * CTor.
   * Creates a mail entity.
   * @param integer   $fromUID   The database ID of the sender (contact).
   * @param integer   $toID      The database ID of the receiver .
   * @param string    $subject   The mail subject.
   * @param string    $body      The mail body.
   */
  public function __construct ($fromID, $toID, $subject, $body) {
    
    $this->initEntity (self::ENTITY_TYPE, self::ENTITY_AUTHOR);
    
    $this->createEntityReferenceFieldValue (
      'field_mail_from_ref',
      $fromID
    );
    $this->createEntityReferenceFieldValue (
      'field_mail_to_ref',
      $toID
    );
    $this->createEntitySimpleValue (
      'body',
      $body
    );
    $this->createPropertyValue ('title', $subject);
    
    return;
  } 
  
  /**
   * Implements EntityWrapper::save ().
   */
  public function save () {

    return $this->saveEntity ();
  }
  
  /**
   * For adding a file attachment to the mail.
   * 
   * @param FileEntityWrapper $wrappedFileEntity    A FileEntityWrapper object.
   */
  public function addAttachment (FileEntityWrapper $file) {
    
    $this->createEntityReferenceFieldValue (
      'field_mail_attachments_ref',
      $file->getID (),
      FileEntityWrapper::CREATE_VALUE_APPENDED
    );
    
    return;
  }  
}
