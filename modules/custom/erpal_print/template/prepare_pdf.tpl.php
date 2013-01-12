<?php
  $pdf_object->header_html = theme('doc_header');

  $pdf_object->footer_html = token_replace(theme('doc_footer'));
  $pdf_object->SetCreator(PDF_CREATOR);  

  // set header and footer fonts
  $pdf_object->setHeaderFont(Array(PDF_FONT_NAME_MAIN, '', PDF_FONT_SIZE_MAIN));
  $pdf_object->setFooterFont(Array(PDF_FONT_NAME_DATA, '', PDF_FONT_SIZE_DATA));

  // set default monospaced font
  $pdf_object->SetDefaultMonospacedFont(PDF_FONT_MONOSPACED);

  //set margins
  $pdf_object->SetMargins(PDF_MARGIN_LEFT, PDF_MARGIN_TOP, PDF_MARGIN_RIGHT);
  //$pdf_object->SetHeaderMargin(PDF_MARGIN_HEADER);
  $pdf_object->SetFooterMargin(PDF_MARGIN_FOOTER);

  //set auto page breaks
  $pdf_object->SetAutoPageBreak(TRUE, PDF_MARGIN_BOTTOM);

  //set image scale factor
  $pdf_object->setImageScale(PDF_IMAGE_SCALE_RATIO);

  // ---------------------------------------------------------
  $pdf_object->setPrintFooter(true);
  $pdf_object->setPrintHeader(true);
?>