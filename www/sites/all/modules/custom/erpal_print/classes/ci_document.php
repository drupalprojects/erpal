<?php

class CI_document extends TCPDF {
  
  public $header_html = '';
  public $footer_html = '';
  
  public function Header() {
		/*$this->setJPEGQuality(100);
    $this->SetFont('helvetica', 'R', 10);
    $this->Cell(0, 26, 'Seite '.$this->getAliasNumPage().' / '.$this->getAliasNbPages(),0, false, 'L', 0, '', 0, false, 'T', 'M');	
    $image_file = erpal_print_logo_path();
    $this->Image($image_file, 150, 8, '', 7, 'JPG', '', 'T', false, 72, '', false, false, 0, false, false, false);
    $this->Line(15,16,195,16,array());
    */
    
    $this->SetY(10);	
    $this->SetX(3);
    $this->writeHTML($this->header_html."-", true, false, true, false, ''); 
	}
  
	public function Footer() {
		$this->SetY(-26);	
    $this->SetX(15);	

    $this->writeHTML($this->footer_html, true, false, true, false, '');
	}
  
}