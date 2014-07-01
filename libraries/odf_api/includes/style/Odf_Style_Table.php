<?php

class Odf_Style_Table extends Odf_Style {

  private $width;
  private $align;
  private $marginLeft;

  public function __construct() {
    parent::__construct('Table');
    $this->styleType = 'table';
  }

  public function setWidth($width) {
    $this->width = $width;
  }

  public function setAlign($align) {
    $this->align = $align;
  }

  public function setMarginLeft($margin) {
    $this->marginLeft = $margin;
  }

  public function render(Odf_File $document, DOMElement $element) {

    // Add a style to the element.
    $element->setAttribute('table:style-name', $this->styleName);

    // Check if current style was already rendered.
    if (!empty(self::$renderedStyles[$this->styleName])) {
      return;
    }

    // Mark this style as already rendered.
    self::$renderedStyles[$this->styleName] = TRUE;

    $style = $document->content->DOM->createElement('style:style');
    $style->setAttribute('style:name', $this->styleName);
    $style->setAttribute('style:family', $this->styleType);

    $properties = $document->content->DOM->createElement('style:table-properties');

    if (!empty($this->width)) {
      $properties->setAttribute('style:width', $this->width);
    }

    if (!empty($this->align)) {
      $properties->setAttribute('table:align', $this->align);
    }

    if (!empty($this->marginLeft)) {
      $properties->setAttribute('fo:margin-left', $this->marginLeft);
    }

    $style->appendChild($properties);
    $document->content->styles->appendChild($style);
  }

}
