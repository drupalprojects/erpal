<?php

class Odf_File_Part {

  public $filename;

  public $DOM;
  public $xpath;

  public function __construct(ZipArchive $zip) {

    if (empty($this->filename)) {
      throw new Exception('Filename for a one of ODF file part is not provided.');
    }

    $index = $zip->locateName($this->filename);
    $this->DOM = new DOMDocument();
    $this->DOM->loadXML($zip->getFromIndex($index));
    $this->DOM->formatOutput = TRUE;

    $this->xpath = new DOMXPath($this->DOM);
  }

  public function save(ZipArchive $zip) {
    $zip->addFromString($this->filename, $this->DOM->saveXML());
  }

}
