<?php  
  //caution!!!! A timetracking button can appear multiple times at one page if the task is shown in a view an another view or in the node view of its own. So we cannot use an id but class of html attributes.
?>
<div class='timetracking'>
  <a href="#" rel="<?php echo $state; ?>" class="timetracking_button timetracking_button_<?php echo $entity_id;?>">
    <img class="timetracking_button_image timetracking_button_image_<?php echo $entity_id; ?>" src="<?php echo $image; ?>" />
    <span class="timetracking_text timetracking_text_<?php echo $entity_id; ?>"><?php echo $linktext;?></span>
    <span class="timetracking_duration timetracking_duration_<?php echo $entity_id; ?>">
      <?php print $duration ?> h
    </span>
  </a>
</div>