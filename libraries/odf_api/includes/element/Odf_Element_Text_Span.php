<?php

class Odf_Element_Text_Span extends Odf_Element {

  // XML name of an element.
  const elementName = 'text:span';

  private $text;

  public function __construct($text = '') {
    $this->text = $text;
  }

  public function setText($text) {
    $this->text = $text;
  }

  protected function _render(Odf_File $document) {
    $element = $document->content->DOM->createElement($this::elementName, $this->text);

    foreach ($this->styles as $style) {
      if ($style instanceof Odf_Style_Text) {
        $style->render($document, $element);
      }
    }

    return $element;
  }

}
