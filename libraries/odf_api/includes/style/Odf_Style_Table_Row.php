<?php

/*
 * @todo: Didn't found any styles for a table row.
 * @todo: Just implement them here if you found it.
 */
class Odf_Style_Table_Row extends Odf_Style {

  public function __construct() {
    parent::__construct('Table.R');
    $this->styleType = 'table-row';
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

    $document->content->styles->appendChild($style);
  }

}
