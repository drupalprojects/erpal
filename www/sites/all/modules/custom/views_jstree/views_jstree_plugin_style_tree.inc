<?php

/**
 * @file
 * Contains the list style plugin.
 */

/**
 * Style plugin to render each item in a slideshow of an ordered or unordered list.
 *
 * @ingroup views_style_plugins
 */
class views_jstree_plugin_style_tree extends views_plugin_style_list {

  /**
   * Set default options
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['class'] = array('default' => '');
    $options['wrapper_class'] = array('default' => 'item-list');
    $options['main_field'] = array('default' => '');
    $options['parent_field'] = array('default' => '');

    return $options;
  }

  /**
   * Render the given style.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $fields = array('' => t('<None>'));

    foreach ($this->display->handler->get_handlers('field') as $field => $handler) {
      if ($label = $handler->label()) {
        $fields[$field] = $label;
      }
      else {
        $fields[$field] = $handler->ui_name();
      }
    }
dpm($form);
    $form['id_field'] = array(
      '#type' => 'select',
      '#title' => t('ID field'),
      '#options' => $fields,
      '#default_value' => $this->options['id_field'],
      '#description' => t('Select the field with the unique identifier for each record.'),
      '#required' => TRUE,
    );

    $form['parent_field'] = array(
      '#type' => 'select',
      '#title' => t('Parent field'),
      '#options' => $fields,
      '#default_value' => $this->options['parent_field'],
      '#description' => t('Select the field that contains the unique identifier of the record\'s parent.'),
    );
  }
}
