<?php

/**
 * @file
 * PDF row fields plugin provides the the fields plugin for unformatted style.
 */


/**
 * This class contains all the functionality of the field PDF style.
 */ 
class erpal_vcard_style_row extends views_plugin_row {
  /**
   * Renders the views.
   */
  function render($records) {
    $options = $this->option_definition();
//    dpm($records);
    
    
  }
  
  /**
   * Option definitions
   */
  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }


}
