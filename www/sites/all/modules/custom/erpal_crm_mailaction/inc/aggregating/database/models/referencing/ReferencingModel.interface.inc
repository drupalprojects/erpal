<?php
/**
 * @author    Marc Sven Kleinboehl
 * @created   12/07/2012
 * @copyright 2012 © Bright Solutions GmbH 
 * 
 * The main interface for implementing referencing model classes.
 */

namespace erpal_crm_mailaction\aggregating\database\models\referencing;

interface ReferencingModel {
    
  /**
   * The standard constructor for import models.
   * One email will be imported by one object of this class.
   * 
   * @param integer           $destinationID    The ID of the destination object.
   * @param integer           $to               The database ID of a receiver contact.
   * @param integer           $from             The database ID of the sender contact.
   * @param integer           $mailID           The database ID of reference destination.
   * @param ContactNodeModel  $contactModel     A ContactNodeModel object.
   */
  public function __construct ($destinationID, $toID, $fromID, $mailID, $contactModel);
  
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
  
  /**
   * Retrieves the machine name of the relevant content type.
   * 
   * @return string   The machine name of the content type.
   */
  public static function getRelevantContentTypeMachineName ();
  
  /**
   * Retrieves the human readable name of the relevant content type.
   * 
   * @return string   The human readable name of the content type.
   */
  public static function getRelevantContentTypeHumanReadableName ();
}
