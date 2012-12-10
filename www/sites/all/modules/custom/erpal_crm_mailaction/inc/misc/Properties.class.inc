<?php
/**
 * @author 		Marc Sven Kleinboehl
 * @created 	01/14/2012
 * @copyright	2012 © Bright Solutions GmbH
 * 
 * This is an abstract class for extending other class with property functionality.
 * It is for extending other classes with properties functionality.
 */

namespace erpal_crm_mailaction\misc;

abstract class Properties {
  
  protected $__properties;
    
  /**
   * Getter.
   */
  public function __get ($key) {
    
    if (! is_array ($this->__properties)) {
      $this->__properties = array ();
    }
    
    return isset ($this->__properties[$key]) ? $this->__properties[$key] : FALSE;
  }
  
  /**
   * Setter.
   */
  public function __set ($key, $value) {
 
    if (! is_array ($this->__properties)) {
      $this->__properties = array ();
    }
    
    $this->__properties[$key] = $value;
    
    return;
  }
}