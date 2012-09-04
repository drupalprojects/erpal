<?php

/**
 * This field handler aggregates operations that can be done on a budget
 * under a single field providing a more flexible way to present them in a view
 */
class budget_handler_budget_operations_field extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['budget_id'] = 'budget_id';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {

    $budget_id = $this->get_value($values, 'budget_id');
    $links = menu_contextual_links('budget', 'budget/%budget', array($this->get_value($values, 'budget_id')));
    
    if (!empty($links)) {
      return theme('links', array('links' => $links, 'attributes' => array('class' => array('links', 'inline', 'operations'))));
    }
  }
}
