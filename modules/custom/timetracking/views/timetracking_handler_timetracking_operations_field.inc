<?php

/**
 * This field handler aggregates operations that can be done on a timetracking
 * under a single field providing a more flexible way to present them in a view
 */
class timetracking_handler_timetracking_operations_field extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['timetracking_id'] = 'timetracking_id';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {

    $timetracking_id = $this->get_value($values, 'timetracking_id');
    $links = menu_contextual_links('timetracking', 'timetracking/%timetracking', array($this->get_value($values, 'timetracking_id')));
    
    if (!empty($links)) {
      return theme('links', array('links' => $links, 'attributes' => array('class' => array('links', 'inline', 'operations'))));
    }
  }
}
