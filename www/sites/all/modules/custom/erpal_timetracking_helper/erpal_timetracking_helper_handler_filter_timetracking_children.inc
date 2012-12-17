<?php

/**
 * "Show subtasks" erpal_timetracking_helper filter
 * Get timetrackings of subtasks
 */
class erpal_timetracking_helper_handler_filter_timetracking_children extends views_handler_filter {

  /**
   * Clear query alter
   */
  function query() {
    
  }

  /**
   * Subtasks checkbox. Provides show/hide choise
   */
  function value_form(&$form, &$form_state) {
    $options = array(
      '0' => 'No',
      '1' => 'Yes',
    );
    $form['value'] = array(
      '#type' => 'select',
      '#title' => t('Show subtasks'),
      '#default_value' => isset($this->value) ? $this->value : NULL,
      '#options' => $options,
    );
    return $form;
  }

}
