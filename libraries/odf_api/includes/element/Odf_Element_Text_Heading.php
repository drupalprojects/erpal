<?php

class Odf_Element_Text_Heading extends Odf_Element {

  const elementName = 'text:h';

  private $title;
  private $level;
  private $toc;
  private $numerable;
  private $refID;
  static private $style;
  static private $xmlID;

  public function __construct($title, $level = 1, $numerable = TRUE, Odf_Element_Toc $toc = NULL) {
    $this->title = $title;
    $this->level = $level;
    $this->numerable = $numerable;
    $this->toc = $toc;
  }

  public function generateRefID() {
    return empty($this->refID) ? $this->refID = '__RefHeading__' . rand(1000, 2000) . '_' . rand(10000, 100000) : FALSE;
  }

  public function getRefID() {
    return $this->refID;
  }

  public function getTitle() {
    return $this->title;
  }

  public function getLevel() {
    return $this->level;
  }

  public function isNumberable() {
    return $this->numerable;
  }

  public function _render(Odf_File $document) {

    if (!empty($this->toc)) {
      $this->toc->addHeading($this, $document);
    }

    $element = $document->content->DOM->createElement($this::elementName);
    $element->setAttribute('text:outline-level', $this->level);

    if (!empty($this->refID)) {
      $bookmark_start = $document->content->DOM->createElement('text:bookmark-start');
      $bookmark_start->setAttribute('text:name', $this->refID);
      $element->appendChild($bookmark_start);
    }

    $span = new Odf_Element_Text_Span($this->title);
    $span->appendTo($document, $element);

    if (!empty($this->refID)) {
      $bookmark_start = $document->content->DOM->createElement('text:bookmark-end');
      $bookmark_start->setAttribute('text:name', $this->refID);
      $element->appendChild($bookmark_start);
    }

    foreach ($this->styles as $style) {
      if ($style instanceof Odf_Style_Text) {
        $style->render($document, $element);
      }
    }

    if ($this->numerable) {

      $root_list = $document->content->DOM->createElement('text:list');
      $root_list->setAttribute('text:continue-numbering', 'true');
      $root_list_item = $document->content->DOM->createElement('text:list-item');
      $root_list->appendChild($root_list_item);

      if (empty(self::$xmlID)) {
        self::$xmlID = 'list' . rand(1000000, 10000000);
        $root_list->setAttribute('xml:id', self::$xmlID);
      }
      else {
        $root_list->setAttribute('text:continue-list', self::$xmlID);
      }

      if (empty(self::$style)) {
        self::$style = new Odf_Style_List('number');
        self::$style->setMarginLeft(0);
        self::$style->setMarginStep(0);
      }
      self::$style->setNumPrefix('');
      self::$style->setNumSuffix('  ');
      self::$style->render($document, $root_list);

      $root = $root_list_item;
      for ($level = 1; $level < $this->level; $level++) {
        $list = $document->content->DOM->createElement('text:list');
        $list_item = $document->content->DOM->createElement('text:list-item');
        $list->appendChild($list_item);
        $root->appendChild($list);
        $root = $list_item;
      }

      $root->appendChild($element);
      $element = $root_list;
    }

    return $element;
  }

}
