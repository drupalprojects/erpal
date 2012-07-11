<?php if ($bookmark) echo $bookmark; ?>

<h1><?php echo $title; ?></h1>
<p>
<?php echo $body; ?>
<div>
<?php 
  if ($duration) echo 'Duration: '.$duration;
?></div>
<div>
<?php
  if ($nid) echo 'ID: '.$nid;
?>
</div>
</p>
