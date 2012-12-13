<?php
/*
 * @author    Marc Sven Kleinboehl
 * @created   10/22/2012
 * @copyright 2012 © Bright Solutions GmbH - All rights reserved.
 * 
 * This class provides the autoloader for all classes in the trainhandler module.
 */

namespace erpal_crm_mailaction\autoloading;
 
class Autoloader {
  
  private $basePath;
  private $replacements;
  private $namespaceRootRestriction;
  
  /*
   * Ctor.
   * Registers the autoload method.
   * @param string  $basePath   The base path for autoloading.
   */
   public function __construct ($basePath, 
                                array $namespaceReplacements = array (),
                                $namespaceRootRestriction = FALSE
     ) {
     
     $this->namespaceRootRestriction  = $namespaceRootRestriction;
     $this->basePath                  = $basePath;
     $this->replacements              = $namespaceReplacements;

     spl_autoload_register(array ($this, 'load'));
     
     return;
   }
   
   /*
    * Loads a class by namespace from filesystem.
    * @param string $classPath    The path of the specific class.
    */
   public function load ($classPath) {

    if ($this->namespaceRootRestriction !== FALSE) {
 
      if (substr ($classPath, 0, strlen ($this->namespaceRootRestriction)) != $this->namespaceRootRestriction) {
        return;
      }
    }

    $classPath = strtr ($classPath, $this->replacements);
    $classPath = str_replace ('\\', '/' , $classPath);
    
    $filePath  = $this->basePath . '/' . $classPath . '.class.inc';
    if (is_readable(drupal_realpath ($filePath))) {
      require_once $filePath;
      return;
    }

    $filePath  = $this->basePath . '/' . $classPath . '.interface.inc';  
    if (is_readable($filePath)) {
      require_once $filePath;
    }

    return;
  }
}
    