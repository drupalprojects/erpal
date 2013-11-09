<?php

class Odf_Element_Table_Row extends Odf_Element implements ArrayAccess {

  private $cells = array();

  public function __construct(array $cells = array()) {
    $this->cells = $cells;
    return $this;
  }

  public function offsetSet($offset, $value) {
    if (is_null($offset)) {
      $this->cells[] = $value;
    }
    else {
      $this->cells[$offset] = $value;
    }
  }

  public function offsetExists($offset) {
    return isset($this->cells[$offset]);
  }

  public function offsetUnset($offset) {
    unset($this->cells[$offset]);
  }

  public function offsetGet($offset) {
    return isset($this->cells[$offset]) ? $this->cells[$offset] : NULL;
  }

  protected function _render(Odf_File $document) {

    $row = $document->content->DOM->createElement('table:table-row');
    foreach ($this->styles as $style) {
      if ($style instanceof Odf_Style_Table_Row) {
        $style->render($document, $row);
      }
    }

    foreach ($this->cells as $text) {

      $cell = $document->content->DOM->createElement('table:table-cell');
      foreach ($this->styles as $style) {
        if ($style instanceof Odf_Style_Table_Cell) {
          $style->render($document, $cell);
        }
      }

      $span = $document->content->DOM->createElement('text:p', $text);
      foreach ($this->styles as $style) {
        if ($style instanceof Odf_Style_Text) {
          $style->render($document, $span);
        }
      }

      $cell->appendChild($span);
      $row->appendChild($cell);
    }

    return $row;
  }

}
