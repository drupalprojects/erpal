<p>
<?php 
$params = $pdf_object->serializeTCPDFtagParameters($node->title,1,0,'','',array(128,128,0));  //needed later for table of contentes 
echo '<tcpdf method="Bookmark" params="'.$params.'" />';
echo $node->title; ?>
</p>