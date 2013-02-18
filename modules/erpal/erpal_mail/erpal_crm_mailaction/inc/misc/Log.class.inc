<?php
/*
 * @author    Marc Sven Kleinboehl
 * @created   12/13/2012
 * @copyright 2012 © Bright Solutions GmbH
 * 
 * A simple log wrapper.
 */
 
namespace erpal_crm_mailaction\misc;
 
class Log {
  
  /**
   * Logs a message of an individual type.
   * 
   * @param string $realm   The name of the realm.
   * @param string $message The log message.
   */
  private static function log ($realm, $message, $logLevel) {
    
    if (is_object ($message) || is_array ($message)) {
      $message = var_export ($message, TRUE);
    }
    
    watchdog (
      $realm,
      $message,
      NULL,
      $logLevel,
      l($_GET['q'], array('absolute' => TRUE))
    );
    
    return;
  } 
  
  /**
   * Logs a notification message.
   * 
   * @param string $realm   The name of the realm.
   * @param string $message The log message.
   */
  public static function notification ($realm, $message) {
    
    self::log ($realm, $message, WATCHDOG_NOTICE);
    
    return;
  }
  
  /**
   * Logs an error message.
   * 
   * @param string $realm   The name of the realm.
   * @param string $message The log error message.
   */
  public static function error ($realm, $message) {
    
    self::log ($realm, $message, WATCHDOG_ERROR);
    
    return;
  }
  
  /**
   * Logs a debug message.
   * 
   * @param string $realm   The name of the realm.
   * @param string $message The log message.
   */
  public static function debug ($realm, $message) {
    
    self::log ($realm, $message, WATCHDOG_DEBUG);
    
    return;
  }
  
  /**
   * Logs a warning message.
   * 
   * @param string $realm   The name of the realm.
   * @param string $message The log message.
   */
  public static function warning ($realm, $message) {
    
    self::log ($realm, $message, WATCHDOG_WARGNING);
    
    return;
  }
  
  /**
   * Logs an alert message.
   * 
   * @param string $realm   The name of the realm.
   * @param string $message The log message.
   */
  public static function alert ($realm, $message) {
    
    self::log ($realm, $message, WATCHDOG_ALERT);
    
    return;
  }
  
  /**
   * Logs an info message.
   * 
   * @param string $realm   The name of the realm.
   * @param string $message The log message.
   */
  public static function info ($realm, $message) {
    
    self::log ($realm, $message, WATCHDOG_INFO);
    
    return;
  }
}
