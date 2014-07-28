<?php

abstract class Odf_Style {

  public $styleName;
  protected $styleType;
  protected $rawStyleName;

  protected static $uniqueStyleNames = array();

  protected static $renderedStyles = array();

  abstract public function render(Odf_File $document, DOMElement $element);

  public function __construct($style_name = 'S') {
    $this->rawStyleName = $style_name;
    $this->styleName = self::generateUniqueStyleName($this->rawStyleName);
  }

  protected static function generateUniqueStyleName($style_name) {

    if (empty(self::$uniqueStyleNames[$style_name])) {
      self::$uniqueStyleNames[$style_name] = array();
    }

    $counter = count(self::$uniqueStyleNames[$style_name]) + 1;
    self::$uniqueStyleNames[$style_name][] = $counter;

    return $style_name . $counter;
  }

  public function getName() {
    return $this->styleName;
  }

  public function __clone() {
    $this->styleName = self::generateUniqueStyleName($this->rawStyleName);
  }

}
