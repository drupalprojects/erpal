<?php
/**
 * @author    Marc Sven Kleinboehl
 * @created   12/10/2012
 * @copyright 2012 © Bright Solutions GmbH 
 */

namespace erpal_crm_mailaction\misc;

class Settings {
  
  private $settings        = array ();
  private static $instance = NULL;
  
  /**
   * CTor.
   */
  private function __construct () {
    
    $this->settings = variable_get ('erpal_crm_mailaction', array ());
    
    return;
  } 
  
  /**
   * A singleton helper method.
   * 
   * @return Settings     A singleton settings object.
   */
  private static function getInstance () {
    
    if (self::$instance == NULL) {
      self::$instance = new self ();
    }
    
    return self::$instance;
  }
  
  /**
   * Retrieves the value of a settings group or a default value if not succeed.
   * 
   * @param   string $group           The name of a settings group.
   * @param   string $key             The name of a setting.
   * @param   mixed  $defaultValue    (Optional) The default value.
   * @return  mixed                   The value on success. Otherwise the default value or FALSE.
   */
  public static function get ($group, $key, $defaultValue = FALSE) {
   
    if (! isset (self::getInstance ()->settings[$group]) || ! isset (self::getInstance ()->settings[$group][$key])) {
      return $defaultValue;
    }
    
    return self::getInstance ()->settings[$group][$key];
  }
  
  /**
   * Sets a value of a settings group or a default value if not succeed.
   * 
   * @param   string $group           The name of a settings group.
   * @param   string $key             The name of a setting.
   * @param   mixed  $value           The value.
   */
  public static function set ($group, $key, $value = FALSE) {
    
    if (! isset (self::getInstance ()->settings[$group])) {
      self::getInstance ()->settings[$group] = array ();
    }
    
    
    self::getInstance ()->settings[$group][$key] = $value;
    
    return;
  }
  
  /**
   * Saves the settings back to the database.
   * 
   * @return boolean    TRUE on success.
   */
  public static function save () {
    
    if (empty (self::getInstance ()->settings[$group])) {
      return FALSE;
    }    
    
    variable_set ('erpal_crm_mailaction', self::getInstance ()->settings);
    
    return TRUE;
  }
}
