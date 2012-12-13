<?php
/**
 * @author    Marc Sven Kleinboehl
 * @created   12/01/2012
 * @copyright 2012 © Bright Solutions GmbH 
 * 
 * This is a simple wrapper for creating file nodes.
 */

namespace erpal_crm_mailaction\aggregating\database\entity_wrappers;

class FileEntityWrapper extends EntityWrapperBase {

  /**
   * Default values for the wrapped node entity.
   */
  const ENTITY_TYPE   = 'erpal_file';
  const ENTITY_AUTHOR = 1;

  /**
   * CTor.
   * 
   * @param   stdClass  $fileObject   A drupal file object.
   * @param   string    $description  The description text.
   */
  public function __construct ($fileObject, $description) {
    
    $this->initEntity (self::ENTITY_TYPE, self::ENTITY_AUTHOR);
    
    $this->createPropertyValue ('title', $fileObject->filename);
    $this->createEntitySimpleValue ('body', $description);
    $this->createEntityFileFieldValue (
      'field_docs_file',
      $fileObject, 
      $description, 
      self::CREATE_VALUE
    );
    
    return;
  }
  
  /**
   * Implements EntityWrapper::save ().
   */
  public function save () {

    return $this->saveEntity ();
  }
}
