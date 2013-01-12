<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying deletes links
 * as fields
 */


class budget_handler_delete_link_field extends budget_handler_link_field {
  function construct() {
    parent::construct();
    $this->additional_fields['type'] = 'type';
  }


  function render($values) {
    $type = $values->{$this->aliases['type']};
    
    //Creating a dummy budget to check access against
    $dummy_budget = (object) array('type' => $type);
    if (!budget_access('edit', $dummy_budget)) {
      return;
    }
    
    $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
    $budget_id = $values->{$this->aliases['budget_id']};
    
    return l($text, 'budget/' . $budget_id . '/delete');
  }
}
