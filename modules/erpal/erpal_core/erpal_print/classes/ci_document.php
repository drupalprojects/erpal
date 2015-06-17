<?php

class CI_document extends TCPDF {

  public $header_html = '';
  public $footer_html = '';
  public $print_ci = true;

  function __construct($print_ci = true) {
    parent::__construct();
    $this->print_ci = $print_ci;
  }

  public function Header() {
    if ($this->print_ci) {
      $this->SetY(10);
      $this->SetX(3);
      $this->writeHTML($this->header_html, true, false, true, false, '');
    }
  }

  public function Footer() {
    if ($this->print_ci) {
      $this->SetY(-26);
      $this->SetX(15);
      $this->writeHTML($this->footer_html, true, false, true, false, '');
    }
  }

}