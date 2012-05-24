<?php 
$params = $pdf_object->serializeTCPDFtagParameters(array($node->title,1,0,'','',array(128,128,0)));  //needed later for table of contentes 

echo '<tcpdf method="Bookmark" params="'.$params.'" />';
//$pdf_object->Bookmark($node->title, 0, 0, '', 'B', array(0,64,128));
echo "<h1>".$node->title."</h1>"; 
echo $node->body[LANGUAGE_NONE][0]['value'];  //this should be handeled with view modes
?>