<?php

class Odf_File_Content extends Odf_File_Part {

  /**
   * {@inheritdoc}
   */
  public $filename = 'content.xml';

  public $body;
  public $styles;
  public $fonts;

  public function __construct(ZipArchive $zip) {

    parent::__construct($zip);

    $this->body   = $this->xpath->query('/office:document-content/office:body/office:text')->item(0);
    $this->styles = $this->xpath->query('/office:document-content/office:automatic-styles')->item(0);
    $this->fonts  = $this->xpath->query('/office:document-content/office:font-face-decls')->item(0);
  }

}
