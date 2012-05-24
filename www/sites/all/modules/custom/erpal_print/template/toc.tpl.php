<?php
  $pdf_object->addTOCPage();
  $pdf_object->setXY(10,30,'');
  $pdf_object->setTitle($title);
  $pdf_object->addTOC(1, 'courier', '.', $title, 'I', array(128,0,0));
  $pdf_object->endTOCPage();
?>