<?php

class Odf_Style_Image_Box extends Odf_Style {

  public $imageStyle;

  public function __construct(Odf_Style_Image $image_style) {
    parent::__construct('G_');
    $this->imageStyle = $image_style;
    $this->styleType = 'graphic';
  }

  public function render(Odf_File $document, DOMElement $element) {

    // Add a style to the element.
    $element->setAttribute('draw:style-name', $this->styleName);

    // Check if current style was already rendered.
    if (!empty(self::$renderedStyles[$this->styleName])) {
      return;
    }

    // Mark this style as already rendered.
    self::$renderedStyles[$this->styleName] = TRUE;

    if ($this->imageStyle->getWidth()) {
      $element->setAttribute('svg:width', $this->imageStyle->getWidth());
    }

    if ($this->imageStyle->getAnchorType()) {
      $element->setAttribute('text:anchor-type', $this->imageStyle->getAnchorType());
    }

    if (!empty($this->imageStyle->boxrelWidth)) {
      $element->setAttribute('style:rel-width', $this->imageStyle->boxrelWidth);
    }

    if (!empty($this->imageStyle->boxrelHeight)) {
      $element->setAttribute('style:rel-height', $this->imageStyle->boxrelHeight);
    }

    // Create new style.
    $style = $document->content->DOM->createElement('style:style');
    $style->setAttribute('style:name', $this->styleName);
    $style->setAttribute('style:family', $this->styleType);
    $style->setAttribute('style:parent-style-name', 'Frame');

    $properties = $document->content->DOM->createElement('style:graphic-properties');

    // @todo: make this settings configurable if needed.
    $properties->setAttribute('fo:margin-left', '0cm');
    $properties->setAttribute('fo:margin-right', '0cm');
    $properties->setAttribute('fo:margin-top', '0cm');
    $properties->setAttribute('fo:margin-bottom', '0cm');
    $properties->setAttribute('style:wrap', 'none');
    $properties->setAttribute('style:run-through', 'foreground');
    $properties->setAttribute('style:number-wrapped-paragraphs', 'no-limit');
    $properties->setAttribute('style:vertical-pos', 'top');
    $properties->setAttribute('style:vertical-rel', 'paragraph');
    $properties->setAttribute('style:horizontal-pos', 'center');
    $properties->setAttribute('fo:padding', '0cm');
    $properties->setAttribute('fo:border', 'none');

    $style->appendChild($properties);
    $document->content->styles->appendChild($style);
  }

}
