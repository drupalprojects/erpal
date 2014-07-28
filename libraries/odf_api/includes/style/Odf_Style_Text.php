<?php

class Odf_Style_Text extends Odf_Style {

  private $fontSize;
  private $fontFamily;
  private $fontWeight;
  private $fontStyle;
  private $fontUnderline;
  private $fontStrike;
  private $backgroundColor;
  private $textColor;
  private $lineHeight;
  private $textAlign;
  private $marginLeft;
  private $marginRight;
  private $break;
  private $includeTabStops = FALSE;
  private $tabStopPosition = '17cm';
  private $tabStopType = 'right';
  private $tabStopLeaderStyle = 'dotted';
  private $tabStopLeaderText = '.';
  private $textIndent;

  public function __construct($style_name, $style_type) {
    parent::__construct($style_name);
    $this->styleType = $style_type;
  }

  public function setFontSize($font_size) {
    $this->fontSize = trim($font_size);
  }

  public function setFontFamily($font_family) {
    $this->fontFamily = trim($font_family);
  }

  public function setFontWeight($font_weight) {
    $this->fontWeight = trim($font_weight);
  }

  public function setFontStyle($font_style) {
    $this->fontStyle = trim($font_style);
  }

  public function setBgColor($bg_color) {
    $this->backgroundColor = trim($bg_color);
  }

  public function setTextColor($text_color) {
    $this->textColor = trim($text_color);
  }

  public function setMarginLeft($margin_left) {
    $this->marginLeft = $margin_left;
  }

  public function setMarginRight($margin_right) {
    $this->marginRight = $margin_right;
  }

  public function setLineHeight($line_height) {
    $this->lineHeight = $line_height;
  }

  public function setTextAlign($text_align) {
    $this->textAlign = $text_align;
  }

  public function setFontUnderline() {
    $this->fontUnderline = TRUE;
  }

  public function setFontStrike() {
    $this->fontStrike = TRUE;
  }

  public function setBreak() {
    $this->break = TRUE;
  }

  public function includeTabStops() {
    $this->includeTabStops = TRUE;
  }

  public function setTextIndent($text_indent) {
    $this->textIndent = $text_indent;
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

    // Create new style.
    $style = $document->content->DOM->createElement('style:style');
    $style->setAttribute('style:name', $this->styleName);
    $style->setAttribute('style:family', $this->styleType);

    // Paragrapth properties.
    $paragrapth_properties = $document->content->DOM->createElement('style:paragraph-properties');

    // Set a page break before paragraph.
    if (!empty($this->break)) {
      $paragrapth_properties->setAttribute('fo:break-before', 'page');
    }

    // Change line height (in %).
    if (!empty($this->lineHeight)) {
      $paragrapth_properties->setAttribute('fo:line-height', $this->lineHeight);
    }

    // Set text align (left, center, right).
    if (!empty($this->textAlign)) {
      $paragrapth_properties->setAttribute('fo:text-align', $this->textAlign);
    }

    if (!empty($this->marginLeft)) {
      $paragrapth_properties->setAttribute('fo:margin-left', $this->marginLeft);
    }

    if (!empty($this->marginRight)) {
      $paragrapth_properties->setAttribute('fo:margin-right', $this->marginRight);
    }
     // Add text indent.
    if (!empty($this->textIndent)) {
      $paragrapth_properties->setAttribute('fo:text-indent', $this->textIndent);
    }

    if (!empty($this->includeTabStops)) {
      $tab_stops = $document->content->DOM->createElement('style:tab-stops');
      $tab_stop = $document->content->DOM->createElement('style:tab-stop');
      $tab_stop->setAttribute('style:position', $this->tabStopPosition);
      $tab_stop->setAttribute('style:type', $this->tabStopType);
      $tab_stop->setAttribute('style:leader-style', $this->tabStopLeaderStyle);
      $tab_stop->setAttribute('style:leader-text', $this->tabStopLeaderText);
      $tab_stops->appendChild($tab_stop);
      $paragrapth_properties->appendChild($tab_stops);
    }

    $style->appendChild($paragrapth_properties);

    // Create text properties.
    $properties = $document->content->DOM->createElement('style:text-properties');

    // Set font family.
    if (!empty($this->fontFamily)) {
      $properties->setAttribute('style:font-name', $this->fontFamily);

      $font = $document->content->DOM->createElement('style:font-face');
      $font->setAttribute('style:name', $this->fontFamily);
      $font->setAttribute('svg:font-family', $this->fontFamily);
      $font->setAttribute('style:font-family-generic', 'swiss');
      $font->setAttribute('style:font-pitch', 'variable');
      $document->content->fonts->appendChild($font);
    }

    // Set font weight.
    if (!empty($this->fontWeight)) {
      $properties->setAttribute('fo:font-weight', $this->fontWeight);
      $properties->setAttribute('style:font-weight-asian', $this->fontWeight);
    }

    // Set font style.
    if (!empty($this->fontStyle)) {
      $properties->setAttribute('fo:font-style', $this->fontStyle);
      $properties->setAttribute('style:font-style-asian', $this->fontStyle);
    }

    // Set font size.
    if (!empty ($this->fontSize)) {
      $properties->setAttribute('fo:font-size', $this->fontSize);
      $properties->setAttribute('style:font-size-asian', $this->fontSize);
      $properties->setAttribute('style:font-size-complex', $this->fontSize);
    }

    // Set text color.
    if (!empty($this->textColor)) {
      $properties->setAttribute('fo:color', $this->textColor);
    }

    // Set background color.
    if (!empty($this->backgroundColor)) {
      $properties->setAttribute('fo:background-color', $this->backgroundColor);
    }

    // Add font strike line.
    if (!empty($this->fontStrike)) {
      $properties->setAttribute('style:text-line-through-style', 'solid');
      $properties->setAttribute('style:text-line-through-width', 'auto');
      $properties->setAttribute('style:text-line-through-color', 'font-color');
      $properties->setAttribute('style:text-line-through-mode', 'continuous');
      $properties->setAttribute('style:text-line-through-type', 'single');
    }

    // Add font underline.
    if (!empty($this->fontUnderline)) {
      $properties->setAttribute('style:text-underline-style', 'solid');
      $properties->setAttribute('style:text-underline-width', 'auto');
      $properties->setAttribute('style:text-underline-mode', 'continuous');
      $properties->setAttribute('style:text-underline-type', 'single');
    }

    // Append properties to the style.
    $style->appendChild($properties);

    // Append style to the content.
    $document->content->styles->appendChild($style);
  }

}
