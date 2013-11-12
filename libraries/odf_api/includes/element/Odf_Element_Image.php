<?php

class Odf_Element_Image extends Odf_Element {

  private $filepath;
  private $filename;
  private $mimetype;

  public function __construct($filepath) {
    
    if ($info = getimagesize(urldecode($filepath))) {
      $this->filepath = urldecode($filepath);
      $this->filename = basename($filepath);
      $this->mimetype = $info['mime'];
    }
    else {
      throw new Exception('Can not open image - file does not exists.');
    }
  }

  protected function _render(Odf_File $document) {

    $archive_filename = 'media/' . $this->filename;
    $document->manifest->addFileMedia($this->filepath, $archive_filename, $this->mimetype);

    $image = $document->content->DOM->createElement('draw:image');
    $image->setAttribute('xlink:href', $archive_filename);
    $image->setAttribute('xlink:show', 'embed');
    $image->setAttribute('xlink:actuate', 'onLoad');
    $image->setAttribute('xlink:type', 'simple');

    $element = $document->content->DOM->createElement('draw:frame');
    $element->appendChild($image);

    foreach ($this->styles as $style) {
      if ($style instanceof Odf_Style_Image) {
        $style->render($document, $element);
      }
    }

    return $element;
  }

}
