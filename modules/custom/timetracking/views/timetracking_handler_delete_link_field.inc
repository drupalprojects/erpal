<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying deletes links
 * as fields
 */


class timetracking_handler_delete_link_field extends timetracking_handler_link_field {
  function construct() {
    parent::construct();
    $this->additional_fields['type'] = 'type';
  }


  function render($values) {
    $type = $values->{$this->aliases['type']};
    
    //Creating a dummy timetracking to check access against
    $dummy_timetracking = (object) array('type' => $type);
    if (!timetracking_access('edit', $dummy_timetracking)) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
    $timetracking_id = $values->{$this->aliases['timetracking_id']};
    return l($text, 'timetracking/' . $timetracking_id . '/delete', array('query' => array('destination' => $_GET['q'])));
  }
}
