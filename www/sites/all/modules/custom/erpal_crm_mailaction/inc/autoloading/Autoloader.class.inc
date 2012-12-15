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

    $classPath = $this->resolveFilePathOfANamespace ($classPath);    
    $filePath  = $this->basePath . '/' . $classPath . '.class.inc';
    if (is_readable(realpath($filePath))) {
      require_once $filePath;
      return;
    }

    $filePath  = $this->basePath . '/' . $classPath . '.interface.inc';  
    if (is_readable($filePath)) {
      require_once $filePath;
    }

    return;
  }
   
   private function resolveFilePathOfANamespace ($namespacePath) {

     return str_replace (
       '\\', 
       '/' , 
       strtr ($namespacePath, $this->replacements)
     );
   }
   
  /**
   * Loads all classes of a specific namespace and retrieves an array of the 
   * found class pathes.
   */
  public function loadAllNamespaceClasses ($namespacePath) {
    
    $filePath = realpath ($this->basePath . '/' . $this->resolveFilePathOfANamespace ($namespacePath));
    $classes  = array ();
 
    $directoryIterator = new \DirectoryIterator($filePath);
    foreach ($directoryIterator as $fileInfo) {
        
        if ($fileInfo->isFile() && substr ($fileInfo->getFilename(), -10) == '.class.inc') {

            $classes[] = $namespacePath . '\\' . substr ($fileInfo->getFilename(), 0, -10);
        }
    }
    
    return $classes;
  }
}
    