<?php
/**
 * @author    Marc Sven Kleinboehl
 * @created   12/07/2012
 * @copyright 2012 © Bright Solutions GmbH 
 * 
 * The import model for importing mails for activities.
 */

namespace erpal_crm_mailaction\aggregating\database\models\import;

class Activity implements ImportModel {
  
  private $lastError;
  
  /**
   * Implements erpal_crm_mailaction\aggregating\database\import_models\ImportModel::__construct.
   */
  public function __construct ($destinationID, $to, $from, $subject, $body, array $attachments) {
    
     
    return;
  }
  
  /**
   * Implements erpal_crm_mailaction\aggregating\database\import_models\ImportModel::getLastError.
   */
  public function getLastError () {
    
    return $this->lastError;
  }
  
  /**
   * Implements erpal_crm_mailaction\aggregating\database\import_models\ImportModel::isOk.
   */
  public function isOk () {
    
    return empty ($this->lastError);
  }
}
