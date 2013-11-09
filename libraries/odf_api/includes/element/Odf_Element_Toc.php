<?php

/**
 * Class Odf_Element_Toc.
 * TOC is a Table of Content.
 */
class Odf_Element_Toc extends Odf_Element {

  private $title;
  private $toc_index;
  private $textProtected = 'true';
  private $useIndexMarks = 'false';
  private $outlineLevels = 10;
  private $linkStyleName = 'Toc_L';
  private $headingLevels = array();

  public function __construct($title = '') {
    $this->title = $title;
  }

  public function addHeading(Odf_Element_Text_Heading $heading, Odf_File $document) {

    $heading->generateRefID();

    $title = $document->content->DOM->createElement('text:a', $this->getHeadingPrefix($heading) . $heading->getTitle());
    $title->setAttribute('xlink:type', 'simple');
    $title->setAttribute('xlink:href', '#' . $heading->getRefID());
    $title->setAttribute('text:style-name', $this->linkStyleName);
    $title->setAttribute('text:visited-style-name', $this->linkStyleName);

    $tab = $document->content->DOM->createElement('text:tab');
    $title->appendChild($tab);

    $page = $document->content->DOM->createElement('text:a', 0); // @todo: corrent page number.
    $page->setAttribute('xlink:type', 'simple');
    $page->setAttribute('xlink:href', '#' . $heading->getRefID());
    $page->setAttribute('text:style-name', $this->linkStyleName);
    $page->setAttribute('text:visited-style-name', $this->linkStyleName);

    $paragraph = $document->content->DOM->createElement('text:p');
    $paragraph->appendChild($title);
    $paragraph->appendChild($page);

    foreach ($this->styles as $style) {
      if ($style instanceof Odf_Style_Text) {
        $style->render($document, $paragraph);
      }
    }

    $this->toc_index->appendChild($paragraph);
  }

  public function _render(Odf_File $document) {

    if (!empty($this->toc)) {
      throw new Exception('This Table of Content is already rendered.');
    }

    $toc = $document->content->DOM->createElement('text:table-of-content');
    $toc->setAttribute('text:protected', $this->textProtected);

    $toc_source = $document->content->DOM->createElement('text:table-of-content-source');
    $toc_source->setAttribute('text:outline-level', $this->outlineLevels);
    $toc_source->setAttribute('text:use-index-marks', $this->useIndexMarks);

    $toc_title = $document->content->DOM->createElement('text:index-title-template', $this->title);
    $toc_source->appendChild($toc_title);

    // Link style.
    $link_style = $document->styles->DOM->createElement('style:style');
    $link_style->setAttribute('style:name', $this->linkStyleName);
    $link_style->setAttribute('style:family', 'text');
    $document->styles->styles_root->appendChild($link_style);

    for ($level = 1; $level <= $this->outlineLevels; $level++) {

      $entry_template = $document->content->DOM->createElement('text:table-of-content-entry-template');
      $entry_template->setAttribute('text:outline-level', $level);

      $entry = $document->content->DOM->createElement('text:index-entry-link-start');
      $entry->setAttribute('text:style-name', $this->linkStyleName);
      $entry_template->appendChild($entry);

      $entry = $document->content->DOM->createElement('text:index-entry-chapter');
      $entry_template->appendChild($entry);

      $entry = $document->content->DOM->createElement('text:index-entry-text');
      $entry_template->appendChild($entry);

      $entry = $document->content->DOM->createElement('text:index-entry-tab-stop');
      $entry->setAttribute('style:type', 'right');
      $entry->setAttribute('style:leader-char', '.');
      $entry_template->appendChild($entry);

      $entry = $document->content->DOM->createElement('text:index-entry-page-number');
      $entry_template->appendChild($entry);

      $entry = $document->content->DOM->createElement('text:index-entry-link-end');
      $entry_template->appendChild($entry);

      $toc_source->appendChild($entry_template);
    }

    // Create a title for table of content.
    $this->toc_index = $document->content->DOM->createElement('text:index-body');
    $index_title = $document->content->DOM->createElement('text:index-title');
    $title = new Odf_Element_Text_Heading($this->title, 1, FALSE);
    $title->appendTo($document, $index_title);
    $this->toc_index->appendChild($index_title);

    $toc->appendChild($toc_source);
    $toc->appendChild($this->toc_index);
    return $toc;
  }

  private function getHeadingPrefix(Odf_Element_Text_Heading $heading) {

    if ($heading->isNumberable()) {

      $parents = array();
      $arr = &$this->headingLevels;
      for ($i = 1; $i < $heading->getLevel(); $i++) {
        $max_index = count($arr);
        if ($max_index == 0) {
          $arr[$max_index = 1] = array();
        }
        $parents[] = $max_index;
        $arr = &$arr[$max_index];
      }

      $siblings = $this->_get_nested_value($this->headingLevels, $parents);

      $current_index = count($siblings) + 1;
      $prefix = $parents ? implode('.', $parents) . '.' : '';
      $prefix .= $current_index . ' ';

      $parents[] = $current_index;
      $this->_set_nested_value($this->headingLevels, $parents, array(), TRUE);
    }

    return !empty($prefix) ? $prefix : '';
  }

  private function _get_nested_value(array &$array, array $parents, &$key_exists = NULL) {
    $ref = &$array;
    foreach ($parents as $parent) {
      if (is_array($ref) && array_key_exists($parent, $ref)) {
        $ref = &$ref[$parent];
      }
      else {
        $key_exists = FALSE;
        $null = NULL;
        return $null;
      }
    }
    $key_exists = TRUE;
    return $ref;
  }

  private function _set_nested_value(array &$array, array $parents, $value, $force = FALSE) {
    $ref = &$array;
    foreach ($parents as $parent) {
      // PHP auto-creates container arrays and NULL entries without error if $ref
      // is NULL, but throws an error if $ref is set, but not an array.
      if ($force && isset($ref) && !is_array($ref)) {
        $ref = array();
      }
      $ref = &$ref[$parent];
    }
    $ref = $value;
  }

}
