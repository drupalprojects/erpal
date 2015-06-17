<?php

/**
 * @file
 * Contains the Payment title field handler.
 */

/**
 * Field handler to provide simple renderer that allows linking to a map.
 */
class payment_handler_field_title extends views_handler_field {
  function init(&$view, &$options) {
    parent::init($view, $options);

    if (!empty($this->options['link_to_payment'])) {
      $this->additional_fields['pid'] = 'pid';
    }
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['link_to_payment'] = array('default' => FALSE);

    return $options;
  }

  /**
   * Provide the link to product option.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['link_to_payment'] = array(
      '#title'         => t("Link this field to the Payment view page"),
      '#description'   => t('This will override any other link you have set.'),
      '#type'          => 'checkbox',
      '#default_value' => !empty($this->options['link_to_payment']),
    );
  }

  /**
   * Render whatever the data is as a link to the product.
   *
   * Data should be made XSS safe prior to calling this function.
   */
  function render_link($data, $values) {
    if (!empty($this->options['link_to_payment']) && $data !== NULL && $data !== '') {
      $pid = $this->get_value($values, 'pid');
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = 'payment/' . $pid;
    }

    return $data;
  }

  function render($values) {
    $value = $this->get_value($values);
    return $this->render_link($this->sanitize_value($value), $values);
  }
}
