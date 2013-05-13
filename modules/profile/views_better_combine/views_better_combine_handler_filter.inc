<?php

/**
 * @file
 * Definition of views_better_combine_handler_filter.
 */

/**
 * Filter handler which allows to search on multiple fields.
 */
class views_better_combine_handler_filter extends views_handler_filter_combine {

  /**
   * Overriden definitions of options.
   * 
   * @return array
   *   definitions of options
   */
  public function option_definition() {
    $options = parent::option_definition();

    $options['exclude_from_select_area'] = array(
      '#type' => 'checkbox',
      '#title' => 'Exclude from SELECT',
      '#description' => 'Exclude fields from SELECT area to avoid duplication of results',
    );

    return $options;
  }

  /**
   * Provide the form which calls through to subforms.
   * 
   * @param array $form
   *   form array
   * @param array $form_state
   *   form state array
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Default value.
    $default = '';
    if (isset($this->options['exclude_from_select_area'])) {
      $default = $this->options['exclude_from_select_area'];
    }

    // Exclude from SELECT checkbox.
    $form['exclude_from_select_area'] = array(
      '#type' => 'checkbox',
      '#title' => 'Exclude from SELECT',
      '#description' => 'Exclude fields from SELECT area to avoid duplication of results',
      '#default_value' => $default,
    );
  }

}
