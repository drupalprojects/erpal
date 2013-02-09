<?php


/**
 * 
 * function theme_prepsrocess_maintenance_page
 * used to add content to the batch processes during the installation
 */
function erpal_maintenance_preprocess_maintenance_page(&$vars){
  $show_sponsores = FALSE;
  $show_screencasts = TRUE;  
  if($show_sponsores){  
    if(isset($vars['title'])){
      // add page sponsors1.html to the module-install batch process
      if($vars['title']=='Installing ERPAL'){
        $filename = path_to_theme().'/sponsors1.html';
        $file = fopen($filename, 'r');
        $text = fread($file, filesize($filename));
        $vars['sponsors'] = str_replace('[theme-path]', path_to_theme(), $text);
        fclose($file);
      }
      // add page sponsors2.html to the preparing-site (Configure ERPAL) batch process
      if($vars['title']=='Preparing site'){
        $filename = path_to_theme().'/sponsors2.html';
        $file = fopen($filename, 'r');
        $text = fread($file, filesize($filename));
        $vars['sponsors'] = str_replace('[theme-path]', path_to_theme(), $text);
        fclose($file);
      }
    }
  }
  
  if($show_screencasts){ 
    // add page screencasts.html to every page in the maintenance theme 
    $filename = path_to_theme().'/screencasts.html';
    $file = fopen($filename, 'r');
    $text = fread($file, filesize($filename));
    $vars['screencasts'] = str_replace('[theme-path]', path_to_theme(), $text);
    fclose($file);
  }
}


