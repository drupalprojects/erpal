<?php
  //prepare some path of images
  $mod_path = drupal_get_path('module', 'timetracking');
  $image_path = '/'.$mod_path.'/image';
  $path_start = $image_path.'/control_play.png';
  $path_stop = $image_path.'/control_stop.png';
  
  $start_text = t('Start');
  $stop_text = t('Stop');
  if ($state=='on') {
    $image = $path_stop;
    $linktext = $stop_text;
  }else{
    $image = $path_start;
    $linktext = $start_text;
  }
  
  //add the image paths to javascript variables to script can use them!
  $togglevalues = array(
    'on' => array(
      'imagepath' => $path_stop,
      'linktext' => $stop_text,
      'togglepath' => url('timetracking/toggle/'.$entity_type.'/', array('absolute' => true)),
    ),
    'off' => array(
      'imagepath' => $path_start,
      'linktext' => $start_text,
      'togglepath' => url('timetracking/toggle/'.$entity_type.'/', array('absolute' => true)),
    ),
  );
  drupal_add_js(array('timetracking' => $togglevalues), 'setting');
?>
<div class='timetracking'>
  <a id="timetracking_button_<?php echo $entity_id; ?>" href="#" rel="<?php echo $state; ?>" class="timetracking_button_<?php echo $state;?>" onclick="return timetracking_toggle('<?php echo $entity_id; ?>');">
    <img id="timetracking_button_image_<?php echo $entity_id; ?>" src="<?php echo $image; ?>" />
    <span id="timetracking_text_<?php echo $entity_id; ?>"><?php echo $linktext;?></span>
  </a>
</div>