<?php


/**
 * The class used for billable entities
 */
class Billable extends Entity {
  //numers to round
  protected $round_digits = 2;
  
  private function calculate_values() {
    //prepare values, especially float values
    $this->convert_quantity();
    $this->convert_single_price();

    //prepare some calculated values here!
    //ORDER IS IMPORTANT!
    $this->calculate_total_price_no_vat();    
    $this->calculate_total_vat();
    $this->calculate_total_price();
    $this->round_all_values(); 
  }
  
  /**
  * Returns a value of a filed. Why? If we have fields attached to this entiy, we need to get the values
  * not by calling just ->fieldname, but in some cases 'field_name[und][0]['nid'] etc. Things the callee should not
  * care about
  */
  function field_by_name($field_name) {
    if (is_array($field_name)) {
      $parents = $field_name['parents'];
      $field_name_string = $field_name['field_name'];
      $value = drupal_array_get_nested_value($this->{$field_name_string}, $parents);
      return $value;
    }
    
    if ($field_name == 'customer') {
      return $this->customer_nid;
    } 
    elseif ($field_name == 'contractor') {
      return $this->contractor_nid;
    }else
      return $this->{$field_name};
  }
  
  /**
  * Calculate quantity as a valid float, replace , with .
  */
  private function convert_quantity() {
    $this->quantity = $this->force_float($this->quantity);
  }
  
  /**
  * Calculate quantity as a valid float, replace , with .
  */
  private function convert_single_price() {
    $this->single_price = $this->force_float($this->single_price);
  }
  
  /**
  * Calculate price with given values of quantity and single_price
  */
  private function calculate_total_price_no_vat() {
    $total_price_no_vat = $this->quantity * $this->single_price;
    $this->total_price_no_vat = $this->force_float($total_price_no_vat);
  }
  
  /**
  * Calculate single vat with given values of single_price and vat_rate
  */
  private function calculate_total_vat() {
    $total_vat = $this->total_price_no_vat / 100 *  $this->vat_rate;
    $this->total_vat = $this->force_float($total_vat);
  }
  
  /**
  * Calculate total price with given values of single price and vat_rate
  */
  private function calculate_total_price() {
    $total_price = $this->total_price_no_vat + $this->total_vat;
    $this->total_price = $this->force_float($total_price);
  }

  /**
  * After all calculations need round all values,
  */
  private function round_all_values() {
    $values = array(
      'single_price',
      'total_price_no_vat',
      'total_vat',
      'total_price'
    );
    foreach ($values as $value) {
      $this->$value = $this->force_float($this->$value, true);
    }
  }

  private function force_float($value, $do_round=false) {
    $value = str_replace(',', '.', $value);
    $value = floatval($value);

    if ($do_round)
      $value = round($value, $this->round_digits);

    return $value;
  }
  
  public function __construct($values = array()) {
    parent::__construct($values, 'billable');
  }

  public function save() {
    $this->calculate_values();
    parent::save();
  }
  
  public function set_billed($value) {
    $this->billed = $value;
  }
  
  protected function defaultLabel() {
    return $this->subject;
  }

  protected function defaultUri() {
    return array('path' => 'billable/' . $this->billable_id);
  }
  
  
}


/**
 * Provides a class for billable types.
 *
 * Use a separate class so we can specify some defaults modules may alter.
 */
class BillableType extends Entity {
  public $type;
  public $label;
  public $weight = 0;

  public function __construct($values = array()) {
    parent::__construct($values, 'billable_type');
  }

  function isLocked() {
    return isset($this->status) && empty($this->is_new) && (($this->status & ENTITY_IN_CODE) || ($this->status & ENTITY_FIXED));
  }
}

/**
 * The Controller for Billable entities
 */
class BillableController extends EntityAPIController {
  public function __construct($entityType) {
    parent::__construct($entityType);
  }


  /**
   * Create a billable - we first set up the values that are specific
   * to our billable schema but then also go through the EntityAPIController
   * function.
   * 
   * @param $type
   *   The machine-readable type of the billable.
   *
   * @return
   *   A billable object with all default fields initialized.
   */
  public function create(array $values = array()) {
    // Add values that are specific to our Billable
    $values += array( 
      'billable_id' => '',
      'is_new' => TRUE,
      'type' => 'billable', //allways fixed because we have no bundles
      'subject' => '',
      'created' => time(),
      'changed' => time(),
      'data' => '',
      'date_delivery' => 0,
      'weight' => 0,
      'parent_billable' => 0,
      'subject_nid' => 0,
      'customer_nid' => 0,
      'contractor_nid' => 0,
      'quantity' => 1,
      'single_price' => 0,
      'total_price' => 0,
      'total_price_no_vat' => 0,
      'total_vat' => 0,
      'vat_rate' => 0,     
      'currency' => 'EUR', 
    );
    
    $billable = parent::create($values);
    return $billable;
  }
  
  /**
   * Overriding the buldContent function to add entity specific fields
   */
  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
    $content = parent::buildContent($entity, $view_mode, $langcode, $content);
    $content['billable'] =  array(
      '#markup' => theme('billable_view', array('billable' => $entity)),
    );

    return $content;
  }
  
  /**
  * reduces all entities to a minimum set of entities
  * @param $billable_ids array of all entities that should be reduced to a minimum set of entities with consistent data.
  * @return an array with all ids of the resulting entities which reference to the new created entities
  */
  public function reduce($billable_ids) {
    module_load_include('inc', 'billable', 'billable.reduce');  
    _billable_reduce($billable_ids);
  }
  
}


/**
 * Controller class for billable Type.
 */
class BillableTypeController extends EntityAPIControllerExportable {
  public function create(array $values = array()) {
    $values += array(
      'type' => '',
      'label' => '',
      'is_new' => TRUE,
    );

    return parent::create($values);
  }

  /**
   * Implements EntityAPIControllerInterface.
   *
   * @param array $ids
   *   List of IDs.
   * @param object $transaction
   *   Optionally a DatabaseTransaction object to use. Allows overrides to pass
   *   in their transaction object.
   */
  public function delete($ids, DatabaseTransaction $transaction = NULL) {
    // Delete all instances of the given type.
    $query = new EntityFieldQuery();
    $results = $query
      ->entityCondition('entity_type', 'billable')
      ->entityCondition('bundle_id', $ids, 'IN')
      ->execute();

    if (!empty($results)) {
      $billables_to_remove = array_keys($results['billable']);
      billable_delete_multiple($billables_to_remove);
      watchdog('billable', 'Delete !count billables due to deletion of billable.', array('!count' => count($billables_to_remove)), WATCHDOG_INFO);
    }

    // Finally delete the type itself.
    return parent::delete($ids, $transaction);
  }
}