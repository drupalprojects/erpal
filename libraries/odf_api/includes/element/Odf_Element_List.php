<?php

class Odf_Element_List extends Odf_Element implements ArrayAccess {

  // XML name of an element.
  const elementName = 'text:list';

  private $items;

  public function offsetSet($offset, $value) {
    $item = new Odf_Element_List_Item($value);
    if (is_null($offset)) {
      $this->items[] = $item;
    }
    else {
      $this->items[$offset] = $item;
    }
  }

  public function offsetExists($offset) {
    return isset($this->items[$offset]);
  }

  public function offsetUnset($offset) {
    unset($this->items[$offset]);
  }

  public function offsetGet($offset) {
    if (isset($this->items[$offset]) && $this->items[$offset] instanceof Odf_Element_List_Item) {
      return $this->items[$offset];
    }
    return NULL;
  }

  protected function _render(Odf_File $document) {

    $list = $document->content->DOM->createElement($this::elementName);
    foreach ($this->items as $item) {
      if ($item instanceof Odf_Element_List_Item) {
        $item->appendTo($document, $list);
      }
    }

    foreach ($this->styles as $style) {
      if ($style instanceof Odf_Style_List) {
        $style->render($document, $list);
      }
    }

    return $list;
  }

}
