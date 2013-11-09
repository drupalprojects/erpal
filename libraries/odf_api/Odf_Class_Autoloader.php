<?php

abstract class Odf_Class_Autoloader {

  public static function init() {
    spl_autoload_register(array('Odf_Class_Autoloader', 'autoload'));
  }

  public static function autoload($class) {

    $class_name_parts = explode('_', $class);
    if ($class_name_parts[0] == 'Odf' && count($class_name_parts) > 1) {
      $subdir = strtolower($class_name_parts[1]);
    }

    if (empty($subdir)) {
      return;
    }

    // File folder.
    $file = realpath(__DIR__) . '/includes/' . $subdir . '/' . $class . '.php';
    if (!file_exists($file)) {
      return;
    }

    // Add class to the scope.
    include_once $file;
  }

}
