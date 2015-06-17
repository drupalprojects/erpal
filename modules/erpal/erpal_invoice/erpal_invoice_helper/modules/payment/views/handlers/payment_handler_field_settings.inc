<?php

/**
 * @file
 * Contains the Payment settings field handler.
 */

/**
 * Field handler to provide simple renderer that allows linking to a map.
 */
class payment_handler_field_settings extends views_handler_field {

  function render($values) {
    if ($values->payment_settings) {
      $settings = unserialize($values->payment_settings);
      $options = array();
      if ($settings) {
        foreach ($settings as $item) {
          $options[] = array(
            date('d-m-Y', $item['date']),
            l($item['title'], 'billable/' . $item['id']),
            $item['price'],
          );
        }
        return array(
          '#theme' => 'table',
          '#header' => array(),
          '#rows' => $options,
          '#attributes' => array('class' => array('mytable'))
        );
      }
    }
  }
}
