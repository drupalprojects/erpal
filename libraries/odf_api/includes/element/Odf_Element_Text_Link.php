<?php

class Odf_Element_Text_Link extends Odf_Element {

  // XML name of an element.
  const elementName = 'text:a';

  private $text;
  private $link;

  public function __construct($text, $link) {
    $this->text = $text;
    $this->link = $link;
  }

  protected function _render(Odf_File $document) {

    // Create new link element.
    $element = $document->content->DOM->createElement($this::elementName);
    $element->setAttribute('xlink:type', 'simple');
    $element->setAttribute('xlink:href', $this->link);

    // Create new span element.
    $span = new Odf_Element_Text_Span($this->text);

    // Apply a style to a span.
    foreach ($this->styles as $style) {
      if ($style instanceof Odf_Style_Text) {
        $span->applyStyle($style);
      }
    }

    // Insert span into a link.
    $span->appendTo($document, $element);

    return $element;
  }

}
