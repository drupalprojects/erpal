<?php
/**
 * @author    Marc Sven Kleinboehl
 * @created   12/07/2012
 * @copyright 2012 © Bright Solutions GmbH 
 * 
 * The model for referencing mails to tickets.
 */

namespace erpal_crm_mailaction\aggregating\database\models\referencing;

class Ticket implements ReferencingModel {
  
  private $lastError;
  
  /**
   * Implements erpal_crm_mailaction\aggregating\database\import_models\ImportModel::__construct.
   */
  public function __construct ($destinationID, $toID, $fromID, $mailID, $contactModel) {
    
    // TODO: Not yet implemented.
    
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
  
  /**
   * Implements erpal_crm_mailaction\aggregating\database\import_models\ImportModel::getRelevantContentTypeMachineName.
   */
  public static function getRelevantContentTypeMachineName () {
    
    return 'erpal_task'; // Do not use the t-function, here!!!
  }
  
  /**
   * Implements erpal_crm_mailaction\aggregating\database\import_models\ImportModel::getRelevantContentTypeHumanReadableName.
   */
  public static function getRelevantContentTypeHumanReadableName () {
    
    return t('Ticket');
  }
}
