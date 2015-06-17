<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying edit links
 * as fields
 */


class billable_handler_edit_link_field extends billable_handler_link_field {
  function construct() {
    parent::construct();
    $this->additional_fields['type'] = 'type';
  }


  function render($values) {
    $type = $values->{$this->aliases['type']};
    
    //Creating a dummy billable to check access against
    $dummy_billable = (object) array('type' => $type);
    if (!billable_access('edit', $dummy_billable)) {
      return;
    }
    
    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $billable_id = $values->{$this->aliases['billable_id']};
       
    $destination = drupal_get_destination();
    return l($text, 'billable/' . $billable_id . '/edit', array('query' => array('destination' => $destination['destination'])));
  }
}
