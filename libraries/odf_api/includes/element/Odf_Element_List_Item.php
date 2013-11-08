<?php

class Odf_Element_List_Item extends Odf_Element {

  // XML name of an element.
  const elementName = 'text:list-item';

  private $children = array();
  private $data;

  public function __construct($data) {
    $this->data = $data;
  }

  public function setChildren(Odf_Element_List $children) {
    $this->children = $children;
  }

  public function getChildren() {
    return $this->children;
  }

  protected function _render(Odf_File $document) {

    $item = $document->content->DOM->createElement($this::elementName);

    if (!empty($this->data)) {

      if ($this->data instanceof Odf_Element_Text_Paragraph) {
        $paragraph = $this->data;
      }
      else {
        $paragraph = new Odf_Element_Text_Paragraph($this->data);
      }
      $paragraph->appendTo($document, $item);
    }

    if (!empty($this->children) && $this->children instanceof Odf_Element_List) {
      $this->children->appendTo($document, $item);
    }

    return $item;
  }

}
