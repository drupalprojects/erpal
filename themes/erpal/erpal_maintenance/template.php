<?php


/**
 * 
 * function theme_prepsrocess_maintenance_page
 * used to add content to the batch processes during the installation
 */
function erpal_maintenance_preprocess_maintenance_page(&$vars){
  if(isset($vars['title'])){
    // add page sponsors1.html to the module-install batch process
    if($vars['title']=='Installing ERPAL'){
      $filename = path_to_theme().'/sponsors1.html';
      $file = fopen($filename, 'r');
      $vars['sponsors'] = fread($file, filesize($filename));
      fclose($file);
    }
    // add page sponsors2.html to the preparing-site (Configure ERPAL) batch process
    if($vars['title']=='Preparing site'){
      $filename = path_to_theme().'/sponsors2.html';
      $file = fopen($filename, 'r');
      $vars['sponsors'] = fread($file, filesize($filename));
      fclose($file);
    }
  }  
}

