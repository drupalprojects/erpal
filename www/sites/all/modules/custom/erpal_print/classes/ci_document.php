<?php

class CI_document extends TCPDF {
  
  public $header_html = '';
  public $footer_html = '';
  public $css 		  = '';
  
  public function Header() {
    $this->SetY(10);	
    $this->SetX(3);
    $this->writeHTML($this->css.$this->header_html, true, false, true, false, ''); 
  }
  
  public function Footer() {
	$this->SetY(-26);	
    $this->SetX(15);	

    $this->writeHTML($this->css.$this->footer_html, true, false, true, false, '');
  }
  
}