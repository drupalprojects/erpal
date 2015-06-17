<div>
  <h1><?php echo $title; ?></h1>
  <?php if ($add_nids):?>
    <div>
      <span class='title_nid'>(NID: <?php echo $nid; ?>)</span>
    </div>  
  <?php endif; ?>
  <?php echo $body; ?>
    
</div>
