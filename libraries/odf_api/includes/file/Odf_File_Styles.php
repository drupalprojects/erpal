<?php

class Odf_File_Styles extends Odf_File_Part {

  public $filename = 'styles.xml';
  public $styles_root;

  public function __construct(ZipArchive $zip) {
    parent::__construct($zip);
    $this->styles_root = $this->xpath->query('/office:document-styles/office:styles')->item(0);
  }

}
