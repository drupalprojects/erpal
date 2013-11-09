<?php

class Odf_Style_Table_Cell extends Odf_Style {

  private $backgroundColor;
  private $padding;
  private $borderLeft;
  private $borderTop;
  private $borderRight;
  private $borderBottom;

  public function __construct() {
    parent::__construct('Table.C');
    $this->styleType = 'table-cell';
  }

  public function setBackgroundColor($bg_color) {
    $this->backgroundColor = $bg_color;
  }

  public function setPadding($padding) {
    $this->padding = $padding;
  }

  public function setBorderLeft($border_left) {
    $this->borderLeft = $border_left;
  }

  public function setBorderTop($border_top) {
    $this->borderTop = $border_top;
  }

  public function setBorderRight($border_right) {
    $this->borderRight = $border_right;
  }

  public function setBorderBottom($border_bottom) {
    $this->borderBottom = $border_bottom;
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

    $properties = $document->content->DOM->createElement('style:table-cell-properties');

    if (!empty($this->backgroundColor)) {
      $properties->setAttribute('fo:background-color', $this->backgroundColor);
    }

    if (!empty($this->padding)) {
      $properties->setAttribute('fo:padding', $this->padding);
    }

    if (!empty($this->borderLeft)) {
      $properties->setAttribute('fo:border-left', $this->borderLeft);
    }

    if (!empty($this->borderRight)) {
      $properties->setAttribute('fo:border-right', $this->borderRight);
    }

    if (!empty($this->borderTop)) {
      $properties->setAttribute('fo:border-top', $this->borderTop);
    }

    if (!empty($this->borderBottom)) {
      $properties->setAttribute('fo:border-bottom', $this->borderBottom);
    }

    $style->appendChild($properties);
    $document->content->styles->appendChild($style);
  }

}
