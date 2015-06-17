<?php

/**
 * This field handler aggregates operations that can be done on a project
 * under a single field providing a more flexible way to present them in a view
 */
class erpal_project_helper_handler_project_quicklinkgs_field extends views_handler_field {
  function construct() {
    parent::construct();    
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    
    $links = '<div class="quicklinks">';
    
    $text = t('Tasks');
    $links .= l($text, 'node/'.$values->nid.'/tasks', array('attributes' => array('title' => $text, 'alt' => $text,'class' => array('tasks'))));
    
    $text = t('Tickets');
    $links .= l($text, 'node/'.$values->nid.'/tickets', array('attributes' => array('title' => $text, 'alt' => $text,'class' => array('tickets'))));
    
    $text = t('Files');
    $links .= l($text, 'node/'.$values->nid.'/files', array('attributes' => array('title' => $text, 'alt' => $text,'class' => array('files'))));
    
    $text = t('Calendar');
    $links .= l($text, 'node/'.$values->nid.'/calendar', array('attributes' => array('title' => $text, 'alt' => $text,'class' => array('calendar'))));
    
    $text = t('Timetracking');
    $links .= l($text, 'node/'.$values->nid.'/timetracking', array('attributes' => array('title' => $text, 'alt' => $text,'class' => array('timetracking'))));

    if (!empty($links)) {
      return $links;
    }
  }
}
