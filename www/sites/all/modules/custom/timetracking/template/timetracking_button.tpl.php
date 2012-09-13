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
  
  //caution!!!! A timetracking button can appear multiple times at one page if the task is shown in a view an another view or in the node view of its own. So we cannot use an id but class of html attributes.
?>
<div class='timetracking'>
  <a href="#" rel="<?php echo $state; ?>" class="timetracking_button timetracking_button_<?php echo $entity_id;?>" onclick="return timetracking_toggle('<?php echo $entity_id; ?>');">
    <img class="timetracking_button_image timetracking_button_image_<?php echo $entity_id; ?>" src="<?php echo $image; ?>" />
    <span class="timetracking_text timetracking_text_<?php echo $entity_id; ?>"><?php echo $linktext;?></span>
    <span class="timetracking_duration timetracking_duration_<?php echo $entity_id; ?>">
      <?php print $duration ?> h
    </span>
  </a>
</div>