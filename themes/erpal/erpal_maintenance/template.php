<?php


/**
 * 
 * function theme_prepsrocess_maintenance_page
 * used to add content to the batch processes during the installation
 */
function erpal_maintenance_preprocess_maintenance_page(&$vars){
  $show_sponsores = FALSE;
  $show_screencasts = TRUE;  
  $number_screencasts = 3;
  if($show_sponsores){  
    if(isset($vars['title'])){
      // add page sponsors1.html to the module-install batch process
      if($vars['title']=='Installing ERPAL'){
        $diamond = theme('erpal_maintenance_sponsores_diamond');
        $vars['sponsors'] = $diamond;
      }
      // add page sponsors2.html to the preparing-site (Configure ERPAL) batch process
      if($vars['title']=='Preparing site'){
        $platin = theme('erpal_maintenance_sponsores_platin');
        $vars['sponsors'] = $platin;
      }
    }
  }
  
  if($show_screencasts){ 
    $vars['screencasts'] = _erpal_maintenance_get_screencasts($number_screencasts); 
  }
}


function _erpal_maintenance_get_screencasts($max_entrys){
  $html = '';
  $screencasts = array();
  //Get Feed from youtube channel
  $feed_url = 'http://gdata.youtube.com/feeds/base/users/ScreencastsERPAL/uploads?alt=rss&v=2&orderby=published';
  $feed_raw = @file_get_contents($feed_url);
  if(!empty($feed_raw)){
    // Parse it with SimpleXML
    $feed = simplexml_load_string($feed_raw);
    // Get items from feed
    $items = $feed->xpath('/rss/channel/item'); 
    
    // For all items  
    foreach ($items as $key => $item) {
      // IF maximum of videos is reached continue
      if($key >= $max_entrys) continue;
      // get title and description of feed
      $title = $item->title;
      $description = $item->description;
      
      // description is html so parse as DOM
      $description_dom = new DOMDocument();
      $description_dom->loadHTML($description);
      $xpath = new DOMXPath($description_dom);
      // get links src of linked image
      $pictures = $xpath->query('//a/img/@src');
      foreach ($pictures as $picture_src) {
        // get href of link
        $link = $picture_src->ownerElement->parentNode->getAttribute('href');  
        // create html 
        $html .= '<div class="video-box">' . PHP_EOL;
        $html .= '<a href="'.$link.'" target= "blank">' . PHP_EOL;
        $html .= '<img width="170" height="130" src="' . htmlspecialchars($picture_src->nodeValue) . '"></img><br/>' . PHP_EOL;   
        $html .= $title . PHP_EOL;
        $html .= '</a>' . PHP_EOL;
        $html .= '</div>'.PHP_EOL;
        $screencasts[] = array(
          'image' => htmlspecialchars($picture_src->nodeValue),
          'title' => $title,
          'link' => $link,
        );
      }    
    }
    $html = theme('erpal_maintenance_screencasts', array('screencasts' => $screencasts));
  } else {
    // If there is a problem with opening the rss feed
    // Output file /screencasts.html
    $html = theme('erpal_maintenance_screencasts');
  }
  return $html;
}


function erpal_maintenance_theme(){
  return array(
    'erpal_maintenance_sponsores_diamond' => array(
      'variables' => array(),
      'template' => 'templates/erpal_maintenance_sponsores_diamond',
    ),
    'erpal_maintenance_sponsores_platin' => array(
      'variables' => array(),
      'template' => 'templates/erpal_maintenance_sponsores_platin',
    ),
    'erpal_maintenance_screencasts' => array(
      'variables' => array(),
      'template' => 'templates/erpal_maintenance_screencasts',
    ),
  );
}


