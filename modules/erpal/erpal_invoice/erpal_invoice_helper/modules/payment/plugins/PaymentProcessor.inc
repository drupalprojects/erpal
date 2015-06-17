<?php

/**
 * @file
 * PaymentProcessor class.
 */

/**
 * Feeds processor plugin. Create payment from feed items.
 */
class PaymentProcessor extends FeedsProcessor {
  /**
   * Define entity type.
   */
  public function entityType() {
    return 'payment';
  }

  /**
   * Implements parent::entityInfo().
   */
  protected function entityInfo() {
    $info = parent::entityInfo();
    $info['label plural'] = t('Payments');
    return $info;
  }

  /**
   * Creates a new payment in memory and returns it.
   */
  protected function newEntity(FeedsSource $source) {
    return entity_get_controller('payment')->create();
  }

  /**
   * Override setTargetElement to operate on a target item that is a payment.
   */
  public function setTargetElement(FeedsSource $source, $payment, $target_element, $value) {
    switch ($target_element) {
      case 'date':
        if (!empty($value)) {
          $date = new DateTime($value);
          $payment->date = $date->getTimestamp();
        }
        break;
      
      case 'value':        
        if (!empty($value)) {
          //remove blanks that that separate the - from the value sometimes
          $value = str_replace(' ', '', $value);
          if ($value < 0) {
            
            $payment->field_negative[field_language('payment', $payment, 'field_negative')][0]['value'] = 1;
          }
          else {
            $payment->field_negative[field_language('payment', $payment, 'field_negative')][0]['value'] = 0;
          }
          $payment->value = abs(payment_float($value));
          $payment->field_saldo[field_language('payment', $payment, 'field_saldo')][0]['value'] = $payment->value;
        }
        break;
      
      case 'currency':
        if (empty($value)) {
          $payment->currency = 'EUR';
        }
        break;
      case 'guid':
        $payment->feeds_item->$target_element = $payment->feeds_item->hash;
        break;

      default:
        parent::setTargetElement($source, $payment, $target_element, $value);
        break;
    }
  }

  /**
   * Validates a term.
   */
  protected function entityValidate($payment) {
    if (drupal_strlen($payment->subject) == 0) {
      throw new FeedsValidationException(t('Payment name missing.'));
    }
  }

  /**
   * Saves a payment.
   */
  protected function entitySave($payment) {
    payment_save($payment);
  }

  /**
   * Deletes a series of payment.
   */
  protected function entityDeleteMultiple($pids) {
    foreach ($pids as $pid) {
      payment_delete(payment_load($pid));
    }
  }

  /**
   * Return available mapping targets.
   */
  public function getMappingTargets() {
    $targets = parent::getMappingTargets();
    $targets += array(
      'subject' => array(
        'name' => t('Payment subject'),
        'description' => t('Subject of the Payment.'),
      ),
      'date' => array(
        'name' => t('Date'),
        'description' => t('Date of payment'),
      ),
      'value' => array(
        'name' => t('Value'),
        'description' => t('Value of patment.'),
      ),
      'currency' => array(
        'name' => t('Currency'),
        'description' => t('Currency of payment.'),
      ),
    );

    return $targets;
  }

  /**
   * Get id of an existing feed item payment if available.
   */
  protected function existingEntityId(FeedsSource $source, FeedsParserResult $result) {
    if ($pid = parent::existingEntityId($source, $result)) {
      return $pid;
    }

    // The only possible unique target is subject.
    foreach ($this->uniqueTargets($source, $result) as $target => $value) {
      if ($target == 'guid') {
        $pid = db_select('feeds_item')
          ->fields('feeds_item', array('entity_id'))
          ->condition('feed_nid', $source->feed_nid)
          ->condition('entity_type', $this->entityType())
          ->condition('id', $source->id)
          ->condition('guid', $this->hash($result->currentItem()))
          ->execute()
          ->fetchField();
       
        if ($pid) {
          return $pid;
        }
      }
    }
    return 0;
  }

}
