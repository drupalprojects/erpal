<?php

class Odf_Element_Image_Box extends Odf_Element_Image {

  private $description;
  private static $sequenseCounter = 1;

  public function __construct($filepath, $description = '') {
    parent::__construct($filepath);
    $this->description = $description;
  }

  public function _render(Odf_File $document) {
    foreach ($this->styles as $style) {
      if ($style instanceof Odf_Style_Image) {
        if (!empty($this->description)) {
          if (!empty($style->relWidth)) {
            $style->boxrelWidth = $style->relWidth;
            $style->relWidth = '100%';
          }
          if (!empty($style->relHeight)) {
            $style->boxrelHeight = $style->relHeight;
            $style->relHeight = 'scale';
          }
        }
      }
    }

    $image = parent::_render($document);
    $image->setAttribute('draw:z-index', 2);

    if (!empty($this->description)) {

      $frame = $document->content->DOM->createElement('draw:frame');
      $frame->setAttribute('draw:z-index', 1);

      $textbox = $document->content->DOM->createElement('draw:text-box');

      $paragraph = new Odf_Element_Text_Paragraph();
      $paragraph->addData($image);

      $paragraph_style = new Odf_Style_Text_Paragraph();
      $paragraph_style->setFontStyle('italic');
      $paragraph_style->setLineHeight('150%');
      $paragraph_style->setFontFamily('Verdana');
      $paragraph->applyStyle($paragraph_style);

      $parsed_text = explode('@sequence', $this->description);
      for ($i = 0; $i < count($parsed_text); $i++) {

        $text = new Odf_Element_Text_Span($parsed_text[$i]);
        $paragraph->addData($text);

        if ($i != count($parsed_text) - 1) {
          $sequence = $document->content->DOM->createElement('text:sequence', self::$sequenseCounter);
          $sequence->setAttribute('text:formula', 'ooow:Illustration+1');
          $sequence->setAttribute('style:num-format', '1');
          $paragraph->addData($sequence);
        }
      }

      if (count($parsed_text) > 1) {
        self::$sequenseCounter++;
      }

      foreach ($this->styles as $style) {
        if ($style instanceof Odf_Style_Image) {
          $image_box_style = new Odf_Style_Image_Box($style);
          if ($image_box_style->imageStyle->getheight()) {
            $textbox->setAttribute('fo:min-height', $image_box_style->imageStyle->getheight());
          }
          if ($image_box_style->imageStyle->getwidth()) {
            $textbox->setAttribute('fo:min-width', $image_box_style->imageStyle->getwidth());
          }
          $image_box_style->render($document, $frame);
        }
      }

      $paragraph->appendTo($document, $textbox);
      $frame->appendChild($textbox);
    }

    return isset($frame) ? $frame : $image;
  }

}