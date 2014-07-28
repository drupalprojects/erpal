<?php

class Odf_Style_Image extends Odf_Style {

  private $width;
  private $height;
  private $offsetX;
  private $offsetY;
  private $anchorType = 'paragraph';
  public $relWidth;
  public $relHeight;

  public function __construct() {
    parent::__construct('G_');
    $this->styleType = 'graphic';
  }

  public function setWidth($width) {
    $this->width = $width;
  }

  public function getWidth() {
    return $this->width;
  }

  public function setHeight($height) {
    $this->height = $height;
  }

  public function getHeight() {
    return $this->height;
  }

  public function setArchorType($anchor_type) {
    $this->anchorType = $anchor_type;
  }

  public function getAnchorType() {
    return $this->anchorType;
  }

  public function setOffsetX($offset_x) {
    $this->offsetX = $offset_x;
  }

  public function setOffsetY($offset_y) {
    $this->offsetY = $offset_y;
  }

  public function setRelWidth($rel_width) {
    $this->relWidth = $rel_width;
  }

  public function setRelHeight($rel_height) {
    $this->relHeight = $rel_height;
  }

  public function render(Odf_File $document, DOMElement $element) {

    // Add a style to the element.
    $element->setAttribute('draw:style-name', $this->styleName);

    // Check if current style was already rendered.
    if (!empty(self::$renderedStyles[$this->styleName])) {
      return;
    }

    // Mark this style as already rendered.
    self::$renderedStyles[$this->styleName] = TRUE;

    if (!empty($this->width)) {
      $element->setAttribute('svg:width', $this->width);
    }

    if (!empty($this->height)) {
      $element->setAttribute('svg:height', $this->height);
    }

    if (!empty($this->anchorType)) {
      $element->setAttribute('text:anchor-type', $this->anchorType);
    }

    if (!empty($this->offsetX)) {
      $element->setAttribute('svg:x', $this->offsetX);
    }

    if (!empty($this->offsetY)) {
      $element->setAttribute('svg:y', $this->offsetY);
    }

    if (!empty($this->relWidth)) {
      $element->setAttribute('style:rel-width', $this->relWidth);
    }

    if (!empty($this->relHeight)) {
      $element->setAttribute('style:rel-height', $this->relHeight);
    }

    // Create new style.
    $style = $document->content->DOM->createElement('style:style');
    $style->setAttribute('style:name', $this->styleName);
    $style->setAttribute('style:family', $this->styleType);
    $style->setAttribute('style:parent-style-name', 'Graphics');

    $properties = $document->content->DOM->createElement('style:graphic-properties');

    // @todo: make this settings configurable if needed.
    $properties->setAttribute('style:vertical-pos', 'top');
    $properties->setAttribute('style:vertical-rel', 'paragraph-content');
    $properties->setAttribute('style:horizontal-pos', 'center');
    $properties->setAttribute('style:horizontal-rel', 'paragraph-content');
    $properties->setAttribute('style:mirror', 'none');
    $properties->setAttribute('style:run-through', 'foreground');
    $properties->setAttribute('style:wrap', 'none');
    $properties->setAttribute('fo:clip', 'rect(0cm, 0cm, 0cm, 0cm)');
    $properties->setAttribute('fo:border', 'none');
    $properties->setAttribute('fo:padding', '0cm');
    $properties->setAttribute('fo:margin-left', '0cm');
    $properties->setAttribute('fo:margin-right', '0cm');
    $properties->setAttribute('fo:margin-top', '0cm');
    $properties->setAttribute('fo:margin-bottom', '0cm');
    $properties->setAttribute('draw:luminance', '0%');
    $properties->setAttribute('draw:contrast', '0%');
    $properties->setAttribute('draw:red', '0%');
    $properties->setAttribute('draw:green', '0%');
    $properties->setAttribute('draw:blue', '0%');
    $properties->setAttribute('draw:gamma', '100%');
    $properties->setAttribute('draw:color-inversion', 'false');
    $properties->setAttribute('draw:image-opacity', '100%');
    $properties->setAttribute('draw:color-mode', 'standard');

    $style->appendChild($properties);
    $document->content->styles->appendChild($style);
  }

}
