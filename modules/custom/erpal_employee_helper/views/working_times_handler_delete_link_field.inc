<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying deletes links
 * as fields
 */


class working_times_handler_delete_link_field extends working_times_handler_link_field {
  function construct() {
    parent::construct();
    $this->additional_fields['type'] = 'type';
  }


  function render($values) {
    $type = $values->{$this->aliases['type']};
    
    //Creating a dummy working_times to check access against
    $dummy_working_times = (object) array('type' => $type);
    if (!working_times_access('edit', $dummy_working_times)) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
    $working_times_id = $values->{$this->aliases['id']};
    return l($text, 'working_times/' . $working_times_id . '/delete', array('query' => array('destination' => $_GET['q'])));
  }
}
