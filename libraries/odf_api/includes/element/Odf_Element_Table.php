<?php

class Odf_Element_Table extends Odf_Element {

  private $rows;
  private $columns;

  public function __construct(array $rows, $columns) {
    $this->rows = $rows;
    $this->columns = $columns;
  }

  protected function _render(Odf_File $document) {

    $table = $document->content->DOM->createElement('table:table');

    // Add information about number of columns.
    $columns = $document->content->DOM->createElement('table:table-column');
    $columns->setAttribute('table:number-columns-repeated', $this->columns);
    $table->appendChild($columns);

    foreach ($this->styles as $style) {
      if ($style instanceof Odf_Style_Table) {
        $style->render($document, $table);
      }
    }

    foreach ($this->rows as $row) {
      if ($row instanceof Odf_Element_Table_Row) {
        $row->appendTo($document, $table);
      }
    }

    return $table;
  }

}
