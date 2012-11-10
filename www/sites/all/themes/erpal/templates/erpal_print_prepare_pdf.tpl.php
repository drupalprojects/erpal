<?php
  $pdf_object->header_html = theme('doc_header');
  $pdf_object->footer_html = token_replace(theme('doc_footer'));
  $pdf_object->css = "
  <style type='text/css'>
	* { color: black; font-family: Verdana, sans-serif; }
	h1, h2, h3, h4 { font-family: Verdana, sans-serif; }
	table { color: grey; font-size: 8pt;}
	th { font-weight: bold; }
  </style>
  ";
  
  $pdf_object->SetCreator(PDF_CREATOR);  

  // set header and footer fonts
  $pdf_object->setHeaderFont(Array('Helvetica', '', 20));
  $pdf_object->setFooterFont(Array('Helvetica', '', 10));

  // set default monospaced font
  // $pdf_object->SetDefaultMonospacedFont(PDF_FONT_MONOSPACED);

  //set margins
  $pdf_object->SetMargins( 25, 25, 25 );
  $pdf_object->SetHeaderMargin( 25 );
  $pdf_object->SetFooterMargin( 25 );

  //set auto page breaks
  //$pdf_object->SetAutoPageBreak(TRUE, PDF_MARGIN_BOTTOM);
  $pdf_object->SetAutoPageBreak(TRUE, 35);

  //set image scale factor
  $pdf_object->setImageScale(PDF_IMAGE_SCALE_RATIO);

  // ---------------------------------------------------------
  $pdf_object->setPrintFooter(true);
  $pdf_object->setPrintHeader(true);
  
?>