<?php

class Odf_Style_Date extends Odf_Style {

  private $dayStyle;
  private $monthStyle;
  private $yearStyle;

  public function __construct() {
    parent::__construct('D_');
  }

  public function setDayStyle($day_style = 'long') {
    $this->dayStyle = $day_style;
    return $this;
  }

  public function setMonthStyle($month_style = 'long') {
    $this->monthStyle = $month_style;
  }

  public function setYearStyle($year_style = 'long') {
    $this->yearStyle = $year_style;
  }

  public function render(Odf_File $document, DOMElement $element) {

    // Add a style to the element.
    $element->setAttribute('style:data-style-name', $this->styleName);

    // Check if current style was already rendered.
    if (!empty(self::$renderedStyles[$this->styleName])) {
      return;
    }

    // Mark this style as already rendered.
    self::$renderedStyles[$this->styleName] = TRUE;

    $date_style = $document->content->DOM->createElement('number:date-style');
    $date_style->setAttribute('style:name', $this->styleName);
    $date_style->setAttribute('number:automatic-order', 'true');

    // Day format output.
    $param = $document->content->DOM->createElement('number:day');
    if (!empty($this->dayStyle)) {
      $param->setAttribute('number:style', $this->dayStyle);
    }
    $date_style->appendChild($param);

    // Month format output.
    $param = $document->content->DOM->createElement('number:month');
    if (!empty($this->monthStyle)) {
      $param->setAttribute('number:style', $this->monthStyle);
    }
    $date_style->appendChild($param);

    // Year format output.
    $param = $document->content->DOM->createElement('number:year');
    if (!empty($this->yearStyle)) {
      $param->setAttribute('number:style', $this->yearStyle);
    }
    $date_style->appendChild($param);

    $document->content->styles->appendChild($date_style);
  }
}
