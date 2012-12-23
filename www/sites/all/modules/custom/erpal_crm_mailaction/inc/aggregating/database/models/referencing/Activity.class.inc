<?php
/**
 * @author    Marc Sven Kleinboehl
 * @created   12/07/2012
 * @copyright 2012 © Bright Solutions GmbH 
 * 
 * The model for referencing mails to activities.
 */

namespace erpal_crm_mailaction\aggregating\database\models\referencing;

use \erpal_crm_mailaction\aggregating\database\entity_wrappers\ActivityEntityWrapper as ActivityEntityWrapper;

class Activity implements ReferencingModel {

  /**
   * Implements erpal_crm_mailaction\aggregating\database\import_models\ImportModel::__construct.
   */
  public function __construct ($destinationID, $toID, $fromID, $mailID, $contactModel) {

    $activityEntity = ActivityEntityWrapper::load ($destinationID);
    if ($activityEntity == NULL) {
      return;
    }
    
    $activityEntity->createEntityReferenceFieldValue ('field_mails', $mailID, ActivityEntityWrapper::CREATE_VALUE_APPENDED);
    $activityEntity->save ();
    
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
    
    return 'erpal_activity'; // Do not use the t-function, here!!!
  }
  
  /**
   * Implements erpal_crm_mailaction\aggregating\database\import_models\ImportModel::getRelevantContentTypeHumanReadableName.
   */
  public static function getRelevantContentTypeHumanReadableName () {
    
    return t('Activity');
  }
}
