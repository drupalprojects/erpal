<div>
  <h1><?php echo $title; ?></h1>
  <?php if ($add_nids):?>
    <div>
      <span class='title_nid'>(NID: <?php echo $nid; ?>)</span>
    </div>  
  <?php endif; ?>
  <?php echo $body; ?>
  <div>
    <?php if(isset($estimation) && $estimation > 0): ?>
      <p><?php echo t('Estimated time: !time h', array('!time' => $estimation)); ?></p>
    <?php endif ?>  
  </div>
  
  
</div>

  

