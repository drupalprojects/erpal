<?php
/**
 * @file
 * Field handler to present a link to delete a payment.
 *
 * @ingroup views_field_handlers
 */
class payment_handler_field_link_delete extends views_handler_field_node_link {

  /**
   * Renders the link.
   */
  function render_link($entity, $values) {
    $this->options['alter']['make_link'] = TRUE;
    $this->options['alter']['path'] = "payment/{$entity->pid}/delete";
    $this->options['alter']['query'] = drupal_get_destination();

    $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
    return $text;
  }
}
