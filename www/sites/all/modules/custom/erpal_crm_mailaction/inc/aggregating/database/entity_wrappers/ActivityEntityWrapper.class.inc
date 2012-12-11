<?php
/**
 * @author    Marc Sven Kleinboehl
 * @created   12/01/2012
 * @copyright 2012 © Bright Solutions GmbH 
 * 
 * This is the base class for implementing node entity wrappers.
 */

namespace erpal_crm_mailaction\aggregating\database\entity_wrappers;

class ActivityEntityWrapper extends EntityWrapper {
  
  /**
   * Default values for the wrapped node entity.
   */
  const ENTITY_TYPE   = 'erpal_crm_activity';
  const ENTITY_AUTHOR = 1;
  
  /**
   * A factory for loading an activity.
   * 
   * @param   integer                 $nid;
   * @return  ActivityEntityWrapper   An ActivityEntityWrapper object on success.
   *                                  Otherwise NULL.
   */
  public static function load ($id) {
    
    $entity = node_load ($id);
    if ($entity === FALSE) {
      return NULL;
    }
    
    return new self ($entity);
  }
  
  /**
   * A factory for creating an activity.
   * 
   * @return  ActivityEntityWrapper   An ActivityEntityWrapper object on success.
   *                                  Otherwise NULL.
   */
  public static function create () {

    return new self ();
  }
  
  
  /**
   * CTor.
   * 
   * @param stdClass  $entity   A node entity object. NULL for creating a
   *                            wrapper for a new object.
   */
  private function __construct ($entity = NULL) {
    
    if ($entity == NULL) {
      $this->initEntity (self::ENTITY_TYPE, self::ENTITY_AUTHOR);
    }else{
      $this->entity = $entity;
    }
    
    return;
  }
  
  /**
   * Implements EntityWrapper::save ().
   */
  public function save () {

    return $this->saveEntity ();
  }
}
