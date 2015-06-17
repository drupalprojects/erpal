<div>
  
  <?php 
    if($depth > 6) $depth = 6;
    if($depth < 1) $depth = 1 
  ?>
  
  <?php echo "<h" . $depth . ">" . $title . "</h" . $depth . '>'; ?>
  
  <?php if ($add_nids):?>
    <div><span class='title_nid'>(NID: <?php echo $nid; ?>)</span></div>  
  <?php endif; ?>
  <?php echo $body; ?>

  <?php if(isset($estimation) && $estimation > 0): ?>
    <div><p><?php echo t('Estimated time: !time h', array('!time' => $estimation)); ?></p> </div>
  <?php endif ?>  

</div>

  

