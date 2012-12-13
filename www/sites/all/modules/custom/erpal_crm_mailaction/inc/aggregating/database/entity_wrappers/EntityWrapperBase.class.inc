<?php
/**
 * @author    Marc Sven Kleinboehl
 * @created   12/01/2012
 * @copyright 2012 © Bright Solutions GmbH 
 * 
 * This is the base class for implementing node entity wrappers.
 */

namespace erpal_crm_mailaction\aggregating\database\entity_wrappers;

abstract class EntityWrapperBase {
  
  /**
   * 
   */
  const CREATE_VALUE_APPENDED = TRUE;
  const CREATE_VALUE          = FALSE;
  
  const DEFAULT_BODY_FORMAT   = 'full_html';
  
  protected $entity;
  
  /**
   * Retrieves the database ID of the previously saved entity.
   * 
   * @return mixed  integer   The database ID on success. Otherwise FALSE.
   */
  public function getID () {
    
    if (! isset ($this->entity->nid)) {
      return FALSE;
    }
    
    return $this->entity->nid;
  }
  
  /**
   * To call at the end of a save-procedure.
   * Use it bypassed by your save () implementation.
   * 
   * @param   stdClass  $entity   The previously saved entity.
   */
  protected function saveEntity () {

    node_save ($this->entity);
    
    return;
  } 
  
  /**
   * Retrieves the entity object.
   * 
   * @return stdClass   The entity object on success. Otherwise NULL.
   */
  public function getEntity () {
    
    return $this->entity;
  }
  
  /**
   * Initializes the entity object.
   * 
   * @param string  $type   The type of entity.
   * @param integer $uid    The database ID of the entity author.
   */
  protected function initEntity ($type, $uid) {
    
    $this->entity = new \stdClass;
    $this->type   = $type;
    $this->uid    = $uid;
    
    node_object_prepare($this->entity);
    
    return;
  }
  
  /**
   * Creates an entity reference field value.
   * 
   * @param   string  $fieldName  The name of the field.
   * @param   integer $id         The database ID of the referenced entity.
   * @param   boolean $append     CREATE_VALUE_APPENDED if you want to append the value.
   *                              Otherwise CREATE_VALUE if you want to create only.
   */
  public function createEntityReferenceFieldValue ($fieldName, $id, $mode = self::CREATE_VALUE) {
    
    if ($mode == self::CREATE_VALUE) {
      $this->entity->{$fieldName} = array (
        LANGUAGE_NONE => array (
          array (
            'target_id' => intval($id)
          )
        )
      );
    }else{
      $this->entity->{$fieldName}[LANGUAGE_NONE][] = array ('target_id' => $id);
    }
    
    return;
  }
  
  /**
   * Creates an entity reference field value.
   * 
   * @param   string  $fieldName  The name of the field.
   * @param   integer $fileObject The database object.
   * @param   boolean $append     CREATE_VALUE_APPENDED if you want to append the value.
   *                              Otherwise CREATE_VALUE if you want to create only.
   */
  public function createEntityFileFieldValue ($fieldName, $fileObject, $description, $mode = self::CREATE_VALUE) {
    
    $valueArray = array(
      'fid'         => $fileObject->fid,
      'display'     => TRUE,
      'description' => $description
    );
    
    if ($mode == self::CREATE_VALUE) {
      $this->entity->{$fieldName} = array (
        LANGUAGE_NONE => array ($valueArray)
      );
    }else{
      $this->entity->{$fieldName}[LANGUAGE_NONE][] = $valueArray;
    }
    
    return;
  }
  
  /**
   * Creates a simple entity field  value.
   * 
   * @param   string  $fieldName  The name of the field.
   * @param   integer $value      The value.
   * @param   boolean $append     TRUE if you want to append the value.
   */
  public function createEntitySimpleValue ($fieldName, $value, $append = FALSE) {

    if ($fieldName == 'body') {
      
      $valueArray = array (
        'safe_value'  => check_markup ($value),
        'format'      => self::DEFAULT_BODY_FORMAT,
        'value'       => $value,
        'summary'     => ''
      );
    }else{
      $valueArray = array ('value' => $value);
    } 
    
    
    if (! $append) {
      $this->entity->{$fieldName} = array (
        LANGUAGE_NONE => array ($valueArray)
      );
    }else{
      $this->entity->{$fieldName}[LANGUAGE_NONE][] = $valueArray;
    }
    
    return;
  }
  
  /**
   * Creates an entity property value.
   * @param   string  $fieldName  The name of the field.
   * @param   integer $value      The value.
   */
  public function createPropertyValue ($fieldName, $value) {
 
    $this->entity->{$fieldName} = check_plain ($value);
    
    return;
  }
  
  /**
   * A getter for properties.
   * 
   * @example $wrapper->title = '123 test';
   * @param   string  $propertyName     The name of the property.
   * @return  mixed                     The value of the property on success.
   *                                    Otherwise NULL.
   */
  public function __get ($propertyName) {
    
    if (! isset ($this->entity->{$propertyName})) {
      return NULL;
    }
    
    return $this->entity->{$propertyName};
  }
  
  /**
   * A setter for properties.
   * Wrapps the createPropertyValue method.
   * 
   * @example $a = $wrapper->title;
   * @param   string $propertyName      The name of the property.
   * @param   string $propertyValue     The value of the property.
   */
  public function __set ($propertyName, $propertyValue) {
    
    $this->createPropertyValue ($propertyName, $propertyValue);
    
    return;
  }
  
  /**
   * For implementing a method for saving an entity.
   */
  public abstract function save ();
}
