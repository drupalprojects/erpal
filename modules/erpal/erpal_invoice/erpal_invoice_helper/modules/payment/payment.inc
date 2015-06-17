<?php

/**
 * @file
 * class of payment entity.
 */

/**
 * PaymentControllerInterface definition.
 *
 * We create an interface here because anyone could come along and
 * use hook_entity_info_alter() to change our controller class.
 * We want to let them know what methods our class needs in order
 * to function with the rest of the module, so here's a handy list.
 *
 * @see hook_entity_info_alter()
 */

interface PaymentControllerInterface
  extends DrupalEntityControllerInterface {
  public function create();
  public function save($entity);
  public function delete($entity);
}

/**
 * PaymentController extends DrupalDefaultEntityController.
 *
 * Our subclass of DrupalDefaultEntityController lets us add a few
 * important create, update, and delete methods.
 */
class PaymentController
  extends DrupalDefaultEntityController
  implements PaymentControllerInterface {

  /**
   * Create and return a new payment entity.
   */
  public function create() {
    $entity = new stdClass();
    $entity->pid = 0;
    $entity->type = 'booked_payment';
    $entity->subject = '';
    $entity->settings = array();
    return $entity;
  }

  /**
   * Saves the custom fields using drupal_write_record()
   */
  public function save($entity) {
    // If our entity has no pid, then we need to give it a
    // time of creation.
    if (empty($entity->pid)) {
      $entity->created = REQUEST_TIME;
    }
    // Invoke hook_entity_presave().
    module_invoke_all('entity_presave', $entity, 'payment');
    // The 'primary_keys' argument determines whether this will be an insert
    // or an update. So if the entity already has an ID, we'll specify
    // pid as the key.
    $primary_keys = $entity->pid ? 'pid' : array();
    // Write out the entity record.
    drupal_write_record('payment', $entity, $primary_keys);
    // We're going to invoke either hook_entity_update() or
    // hook_entity_insert(), depending on whether or not this is a
    // new entity. We'll just store the name of hook_entity_insert()
    // and change it if we need to.
    $invocation = 'entity_insert';
    // Now we need to either insert or update the fields which are
    // attached to this entity. We use the same primary_keys logic
    // to determine whether to update or insert, and which hook we
    // need to invoke.
    if (empty($primary_keys)) {
      field_attach_insert('payment', $entity);
    }
    else {
      field_attach_update('payment', $entity);
      $invocation = 'entity_update';
    }
    // Invoke either hook_entity_update() or hook_entity_insert().
    module_invoke_all($invocation, $entity, 'payment');
    return $entity;
  }

  /**
   * Delete a single entity.
   *
   * Really a convenience function for delete_multiple().
   */
  public function delete($entity) {
    $this->delete_multiple(array($entity));
  }

  /**
   * Delete one or more payment entities.
   *
   * Deletion is unfortunately not supported in the base
   * DrupalDefaultEntityController class.
   *
   * @param $pids
   *   An array of entity IDs or a single numeric ID.
   */
  public function delete_multiple($entities) {
    $pids = array();

    if (!empty($entities)) {
      $transaction = db_transaction();
      try {
        foreach ($entities as $entity) {
          //load the payment if only id is given
          if (!is_object($entity)) {
            $entity = payment_load($entity);
          }

          // Load all billables with current payment.
          $billables_ids = payment_load_billables($entity);

          // Invoke hook_entity_delete().
          module_invoke_all('entity_delete', $entity, 'payment');
          field_attach_delete('payment', $entity);
          $pids[] = $entity->pid;          
          //Update all billables with current payment.
          if (!empty($billables_ids)) {
            payment_update_billables($entity, $billables_ids);
          }
        }
        db_delete('payment')
          ->condition('pid', $pids, 'IN')
          ->execute();
      }
      catch (Exception $e) {
        $transaction->rollback();
        watchdog_exception('payment', $e);
        throw $e;
      }
    }
  }
}
