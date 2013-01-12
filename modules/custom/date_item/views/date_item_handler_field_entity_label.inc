<?php

/**
 * @file
 * Definition of date_item_handler_field_entity_label.
 */

/**
 * A field handler which allows to display a generic entity label handler,
 * that uses just the entity id and the entity type.
 */
class date_item_handler_field_entity_label extends views_handler_field {
  /**
   * Stores all entities keyed by entity type.
   *
   * @var array
   */
  public $entities = array();

  /**
   * Overrides views_handler_field::init().
   */
  function init(&$view, &$options) {
    parent::init($view, $options);

    $this->additional_fields['src_type'] = 'src_type';
  }

  /**
   * Overrides views_handler_field::option_definition().
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['link_to_entity'] = array('default' => FALSE, 'bool' => TRUE);

    return $options;
  }

  /**
   * Overrides views_handler_field::options_form().
   */
  function options_form(&$form, &$form_state) {
    $form['link_to_entity'] = array(
      '#title' => t('Link this label to the entity'),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_to_entity']),
    );

    parent::options_form($form, $form_state);
  }


  /**
   * Implements views_handler_field::pre_render().
   */
  function pre_render(&$values) {
    // Load all entities involved in the result.
    $entity_id_by_type = array();
    foreach ($values as $row) {
      $entity_type = $this->get_value($row, 'src_type');
      $entity_id = $this->get_value($row);
      $entity_id_by_type[$entity_type][] = $entity_id;
    }

    foreach ($entity_id_by_type as $type => $entity_ids) {
      $this->entities[$type] = entity_load($type, $entity_ids);
    }

    parent::pre_render($values);
  }

  /**
   * Overrides views_handler_field::render().
   */
  function render($values) {
    $entity_type = $this->get_value($values, 'src_type');
    $entity_id = $this->get_value($values);
    $entity = $this->entities[$entity_type][$entity_id];

    $label = check_plain(entity_label($entity_type, $entity));

    if ($this->options['link_to_entity']) {
      $uri = entity_uri($entity_type, $entity);
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = $uri['path'];
    }

    return $label;
  }

}
