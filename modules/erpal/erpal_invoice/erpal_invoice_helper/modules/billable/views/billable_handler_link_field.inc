<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying links to entities
 * as fields.
 */

class billable_handler_link_field extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['billable_id'] = 'billable_id';
    $this->additional_fields['type'] = 'type';
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['text'] = array('default' => '', 'translatable' => TRUE);
    $options['url_only'] = array('default' => false);
    
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );
        
    $form['url_only'] = array(
      '#type' => 'checkbox',
      '#title' => t('Return only the url'),
      '#default_value' => $this->options['url_only'],
    );
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $text = !empty($this->options['text']) ? $this->options['text'] : t('view');
    $billable_id = $values->{$this->aliases['billable_id']};

    if ($this->options['url_only']) {
      return url('billable/' . $billable_id);
    } else {
      return l($text, 'billable/' . $billable_id);
    }
  }
}
