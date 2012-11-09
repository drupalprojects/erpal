<?php
  $pdf_object->addTOCPage();
  $pdf_object->setXY(25,30,'');
  $pdf_object->setTitle($title);
  $pdf_object->addTOC($page, 'Helvetica', '.', $title, 'I', array(128,0,0));
  $pdf_object->endTOCPage();
?>