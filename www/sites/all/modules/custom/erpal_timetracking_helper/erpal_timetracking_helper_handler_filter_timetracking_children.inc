<?php

/**
 * "Show subtasks" erpal_timetracking_helper filter
 * Get timetrackings of subtasks
 */
class erpal_timetracking_helper_handler_filter_timetracking_children extends views_handler_filter {
  /**
   * Clear query alter
   */
  function query() { }
  /**
   * Subtasks checkbox. Provides show/hide choise
   */
  function value_form(&$form, &$form_state) {
    $form['value'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show subtasks'),
    );
    return $form;
  }
}
