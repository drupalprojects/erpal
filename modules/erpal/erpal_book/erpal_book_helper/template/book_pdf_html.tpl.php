<?php if ($bookmark) echo $bookmark; ?>

<h1>
  <?php echo $title; ?>
  <?php if ($options['add_nids']):?>
    <span class='title_nid'>(<?php echo $nid; ?>)</span>
  <?php endif; ?>
</h1>
<p>
<?php echo $body; ?>
<div>
<?php 
  if ($duration) echo 'Duration: '.$duration;
?></div>
</p>
