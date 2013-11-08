<?php

class Odf_Element_Text_Date extends Odf_Element {

  // XML name of an element.
  const elementName = 'text:date';

  private $text;
  private $timestamp;

  public function __construct($text, $date, $date_in_unix = TRUE) {
    $this->text = $text;

    if (!$date_in_unix) {
      $date = strtotime($date);
    }

    $this->timestamp = $date;
  }

  protected function _render(Odf_File $document) {

    $element = $document->content->DOM->createElement($this::elementName, $this->text);
    $element->setAttribute('text:date-value', date('c', $this->timestamp));
    $element->setAttribute('text:fixed', 'true');

    foreach ($this->styles as $style) {
      if ($style instanceof Odf_Style_Date) {
        $style->render($document, $element);
      }
    }

    return $element;
  }

}
