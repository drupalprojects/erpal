<?php
/**
 * @file
 * Overridden standard Views filter to output Date range links.
 */

class date_range_links_handler_filter_date_simple extends date_views_filter_handler_simple {

  /**
   * Set default values for the date filter.
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['date_range_links'] = array('default' => 0);
    return $options;
  }

  /**
   * Add the selectors to the value form using the date handler.
   */
  function value_form(&$form, &$form_state) {
    parent::value_form($form, $form_state);

    if (empty($form_state['exposed']) && !empty($this->options['exposed'])) {

      $form['value']['max_group']['date_range_links'] = array(
        '#type' => 'checkbox',
        '#title' => t('Show range links'),
        '#default_value' => !empty($this->options['date_range_links']) ? $this->options['date_range_links'] : 0,
      );
    }
    elseif (!empty($this->options['date_range_links'])) {

      $format = $this->date_handler->views_formats($this->options['granularity'], 'display');

      $links = module_invoke_all('date_range_links', $format);
      drupal_alter('date_range_links', $links);

      $form['value']['max_group']['date_range_links'] = array(
        '#markup' => theme('date_range_links', array('links' => $links)),
        '#attached' => array(
          'css' => array(drupal_get_path('module', 'date_range_links') . '/css/date_range_links.css'),
          'js' => array(drupal_get_path('module', 'date_range_links') . '/js/date_range_links.js'),
        ),
      );
    }
  }

  /**
   * Value validation.
   */
  function value_validate($form, &$form_state) {
    parent::value_validate($form, $form_state);
    $options = &$form_state['values']['options'];
    $this->options['date_range_links'] = $options['value']['max_group']['date_range_links'];
    $options['value']['date_range_links'] = $options['value']['max_group']['date_range_links'];
  }
}
