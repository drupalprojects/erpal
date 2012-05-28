<?php
$title = $counter." ".$title;
$params = $pdf_object->serializeTCPDFtagParameters(array($title,1,0,'','',array(128,128,0)));  //needed later for table of contentes 

echo '<tcpdf method="Bookmark" params="'.$params.'" />';
?>

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
