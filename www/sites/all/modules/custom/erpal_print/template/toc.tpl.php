<?php
  $pdf_object->addTOCPage();
  $pdf_object->setXY(10,30,'');
  $pdf_object->addTOC(2, 'courier', '.', t('Table of contents'), 'I', array(128,0,0));
  $pdf_object->endTOCPage();
?>