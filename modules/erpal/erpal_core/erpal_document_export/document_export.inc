<?php
/**
 * Template class for document export plugin
 * 
 */

abstract class document_export {
  
  /**
   * hold an array of rendered html pages 
   */
  protected $pages;
  
  /**
   * contains the html for the documents header
   */
  protected $header;
  
  /**
   * contains the html for the documents footer
   */
  protected $footer;
  
  /**
   * Contains the created document later on
   */
  protected $document;
  
  /**
   * Constructor method
   * @param $options
   *   An associative array with the following keys:
   *   - pages: (optional) An array with rendered html pages or a single
   *   string with a single rendered page
   *   - header: (optional) A string with rendered html for the header
   *   - footer: (optional) A string with rendered html for the footer   
   */
  function __construct($options){
    if(isset($options['pages'])){
      $pages_array = $options['pages'];
      if(is_array($pages_array)) $this->pages = $pages_array;
      elseif (is_string($pages_array)) $this->pages = array($pages_array);
      else $this->pages = array();
    }
    if(isset($options['header']))
      $this->header = $options['header'];
    if(isset($options['footer']))
      $this->footer = $options['footer'];
  }
  
  /**
   * Abstract function to save the created document
   * @param $uri
   *  String uri to save the document
   * @param $filename
   *  String with the filename
   */
  abstract function save($uri, $filename);
  
  /**
   * Abstract function to stream the document to the browser
   * @param $filename
   *  String with a filename for the document
   */
  abstract function stream($filename);
  
  /**
   * Function streams the gived file with the filename and mimetype 
   * to the browser
   * @param $filename
   *  String with the filename to stream the file with
   * @param $file
   *  String with a file to stream
   * @param $mimetype
   *  String with a mimetype to stream the file with
   */
  protected function stream_file($filename, $file, $mimetype){
    header('Content-Description: File Transfer');
    header('Content-Type: ' . $mimetype);
    header('Content-Disposition: attachment; filename=' . $filename);
    header('Content-Transfer-Encoding: binary');
    header('Expires: 0');
    header('Cache-Control: must-revalidate, post-check=0, pre-check=0');
    header('Pragma: public');
    header('Content-Length: ' . filesize($file));
    ob_clean();
    flush();
    $status = readfile($file);
    unlink($file);
    exit;
  }
}

