<?php

abstract class Odf_Element {

  // List of element styles.
  protected $styles = array();

  /**
   * Allows to convert all data into an xml element.
   */
  public function render(Odf_File $document) {
    $this->appendTo($document, $document->content->body);
  }

  /**
   * Allows to append data to the selected node.
   */
  public function appendTo(Odf_File $document, DOMNode $node) {
    $element = $this->_render($document);
    $node->appendChild($element);
  }

  /**
   * Creates an xml element.
   */
  abstract protected function _render(Odf_File $document);

  /**
   * Keep the style.
   */
  public function applyStyle(Odf_Style $style) {
    $this->styles[] = $style;
  }

}
