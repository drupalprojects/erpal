<?php
/**
 * @author    Marc Sven Kleinboehl
 * @created   12/07/2012
 * @copyright 2012 © Bright Solutions GmbH 
 * 
 * The main interface for implementing import model classes.
 */

namespace erpal_crm_mailaction\aggregating\database\models\import;

interface ImportModel {
    
  /**
   * The standard constructor for import models.
   * One email will be imported by one object of this class.
   * 
   * @param integer $destinationID    The ID of the destination object.
   * @param integer $to               The database ID of a receiver contact.
   * @param integer $from             The database ID of the sender contact.
   * @param string  $subject          The subject/title of the mail.
   * @param string  $body             The body text of the mail.
   * @param array   $attachments      The attachments of the mail. It is 
   *                                  an array of drupal file objects. 
   */
  public function __construct ($destinationID, $to, $from, $subject, $body, array $attachments);
  
  /**
   * Returns the message of the last occured error.
   * 
   * @return string     A message if an error occured previously. NULL if not.
   */
  public function getLastError ();
  
  /**
   * Returns FALSE if an error occured previously.
   * 
   * @return boolean    FALSE on error.
   */
  public function isOK ();
}
