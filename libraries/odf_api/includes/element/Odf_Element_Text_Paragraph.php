<?php

class Odf_Element_Text_Paragraph extends Odf_Element {

  // XML name of an element.
  const elementName = 'text:p';

  private $data = array();

  public function __construct($data = '') {
    $this->addData($data);
  }

  public function setData($data) {
    $this->data = array();
    $this->addData($data);
  }

  public function addData($data) {
    $this->data[] = $data;
  }

  protected function _render(Odf_File $document) {

    $element = $document->content->DOM->createElement($this::elementName);

    foreach ($this->data as $data) {
      if ($data instanceof Odf_Element) {
        $data->appendTo($document, $element);
      }
      elseif ($data instanceof DOMNode) {
        $element->appendChild($data);
      }
      elseif (is_string($data)) {
        $element->nodeValue = !empty($element->nodeValue) ? $element->nodeValue . ' ' . $data : $data;
      }
    }

    foreach ($this->styles as $style) {
      if ($style instanceof Odf_Style_Text) {
        $style->render($document, $element);
      }
    }

    return $element;
  }

}
