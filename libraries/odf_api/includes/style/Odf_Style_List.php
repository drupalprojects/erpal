<?php

class Odf_Style_List extends Odf_Style {

  private $allowedTypes = array('number', 'bullet');
  private $type;
  private $bulletChar = '•';
  private $numPrefix = '';
  private $numSuffix = '';
  private $numFormat = 1;
  private $marginLeft = 0.1;
  private $marginStep = 0.33;

  public function __construct($type = 'bullet') {

    if (!in_array($type, $this->allowedTypes)) {
      throw new Exception('Can not create list style with unknown type "' . $type . '".');
    }

    $this->type = $type;
    parent::__construct('L_');
  }

  public function setMarginLeft($margin_left) {
    $this->marginLeft = $margin_left;
  }

  public function setMarginStep($margin_step) {
    $this->marginStep = $margin_step;
  }
  
  public function setNumPrefix($numPrefix) {
    $this->numPrefix = $numPrefix;
  }

  public function setNumSuffix($numSuffix) {
    $this->numSuffix = $numSuffix;
  }

  public function render(Odf_File $document, DOMElement $element) {

    // Add a style to the element.
    $element->setAttribute('text:style-name', $this->styleName);

    // Check if current style was already rendered.
    if (!empty(self::$renderedStyles[$this->styleName])) {
      return;
    }

    // Mark this style as already rendered.
    self::$renderedStyles[$this->styleName] = TRUE;

    $style = $document->content->DOM->createElement('text:list-style');
    $style->setAttribute('style:name', $this->styleName);

    for ($level = 1; $level <= 10; $level++) {

      $list = $document->content->DOM->createElement('text:list-level-style-' . $this->type);
      $list->setAttribute('text:level', $level);

      if ($this->type == 'number') {
        $list->setAttribute('style:num-prefix', $this->numPrefix);
        $list->setAttribute('style:num-suffix', $this->numSuffix);
        $list->setAttribute('style:num-format', $this->numFormat);
        $list->setAttribute('text:display-levels', $level);
      }
      elseif ($this->type == 'bullet') {
        $list->setAttribute('text:bullet-char', $this->bulletChar);
      }

      $properties = $document->content->DOM->createElement('style:list-level-properties');
      $properties->setAttribute('text:list-level-position-and-space-mode', 'label-alignment');

      $margin_left = $this->marginLeft + $this->marginStep * $level;
      $aligment = $document->content->DOM->createElement('style:list-level-label-alignment');
      $aligment->setAttribute('text:label-followed-by', 'listtab');
      $aligment->setAttribute('fo:text-indent', -$this->marginStep . 'cm');
      $aligment->setAttribute('text:list-tab-stop-position', $margin_left . 'cm');
      $aligment->setAttribute('fo:margin-left', $margin_left . 'cm');

      $properties->appendChild($aligment);
      $list->appendChild($properties);
      $style->appendChild($list);
    }

    $document->content->styles->appendChild($style);
  }
}
