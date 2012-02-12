<?php

/**
 * This field handler aggregates operations that can be done on a billable
 * under a single field providing a more flexible way to present them in a view
 */
class billable_handler_billable_operations_field extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['billable_id'] = 'billable_id';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {

    $billable_id = $this->get_value($values, 'billable_id');
    $links = menu_contextual_links('billable', 'billable/%billable/view', array($this->get_value($values, 'billable_id')));
    
    if (!empty($links)) {
      return theme('links', array('links' => $links, 'attributes' => array('class' => array('links', 'inline', 'operations'))));
    }
  }
}
