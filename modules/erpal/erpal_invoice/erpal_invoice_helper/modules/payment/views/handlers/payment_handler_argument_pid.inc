<?php
/**
 * @file
 * Provide payment pid argument handler.
 */

/**
 * Argument handler to accept a payment pid.
 */
class payment_handler_argument_pid extends views_handler_argument_numeric {

  /**
   * Override the behavior of title(). Get the title of the payment.
   */
  function title_query() {
    $titles = array();
    $result = db_select('payment')
      ->fields('payment', array('subject'))
      ->condition('pid', $this->value)
      ->execute();
    foreach ($result as $payment) {
      $titles[] = check_plain($payment->title);
    }
    return $titles;
  }
}