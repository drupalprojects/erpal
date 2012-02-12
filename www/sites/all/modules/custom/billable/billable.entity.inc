<?php


/**
 * Fetch a billable object. Make sure that the wildcard you choose 
 * in the billable entity definition fits the function name here.
 *
 * @param $billable_id
 *   Integer specifying the billable id.
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * @return
 *   A fully-loaded $billable object or FALSE if it cannot be loaded.
 *
 * @see billable_load_multiple()
 */
function billable_load($billable_id, $reset = FALSE) {
  $billables = billable_load_multiple(array($billable_id), array(), $reset);
  return reset($billables);
}


/**
 * Load multiple billables based on certain conditions.
 *
 * @param $billable_ids
 *   An array of billable IDs.
 * @param $conditions
 *   An array of conditions to match against the {billable} table.
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * @return
 *   An array of billable objects, indexed by billable_id.
 *
 * @see entity_load()
 * @see billable_load()
 */
function billable_load_multiple($billable_ids = array(), $conditions = array(), $reset = FALSE) {
  return entity_load('billable', $billable_ids, $conditions, $reset);
}


/**
 * Deletes a billable.
 */
function billable_delete(Billable $billable) {
  $billable->delete();
}


/**
 * Delete multiple billables.
 *
 * @param $billable_ids
 *   An array of billable IDs.
 */
function billable_delete_multiple(array $billable_ids) {
  entity_get_controller('billable')->delete($billable_ids);
}


/**
 * Create a billable object.
 */
function billable_create($values = array()) {
  return entity_get_controller('billable')->create($values);
}


/**
 * Saves a billable to the database.
 *
 * @param $billable
 *   The billable object.
 */
function billable_save(Billable $billable) {
  return $billable->save();
}


/**
 * Saves a billable type to the db.
 */
function billable_type_save(BillableType $type) {
  $type->save();
}


/**
 * Deletes a billable type from the db.
 */
function billable_type_delete(BillableType $type) {
  $type->delete();
}


/**
 * URI callback for billables
 */
function billable_uri(Billable $billable){
  return array(
    'path' => 'billable/' . $billable->billable_id,
  );
}


/**
 * Menu title callback for showing individual entities
 */
function billable_page_title(Billable $billable){
  return $billable->subject;
}


/**
 * Sets up content to show an individual billable
 * @todo - get rid of drupal_set_title();
 */
function billable_page_view($billable, $view_mode = 'full') {    
  $controller = entity_get_controller('billable');  
  $content = $controller->view(array($billable->billable_id => $billable));
  drupal_set_title($billable->subject);
  return $content;
}


/**
* @return
*   Themes of our billable entity
*/
function _billable_entity_theme() {
  
  return array(    
    'billable_view' => array(
      'variables' => array('billable' => false),
      'template' => 'billable_view',
    ),
  );
}




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
    $this->single_price = $this->force_float($this->single_price, true);
  }
  
  /**
  * Calculate price with given values of quantity and single_price
  */
  private function calculate_total_price_no_vat() {
    $total_price_no_vat = $this->quantity * $this->single_price;
    $this->total_price_no_vat = $this->force_float($total_price_no_vat, true);
  }
  
  /**
  * Calculate single vat with given values of single_price and vat_rate
  */
  private function calculate_total_vat() {
    $total_vat = $this->single_price * ($this->vat_rate / 100);
    $this->total_vat = $this->force_float($total_vat, true);
  }
  
  /**
  * Calculate total price with given values of single price and vat_rate
  */
  private function calculate_total_price() {
    $total_price = $this->total_price_no_vat + $this->total_vat;
    $this->total_price = $this->force_float($total_price, true);
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
  
  protected function defaultLabel() {
    return $this->subject;
  }

  protected function defaultUri() {
    return array('path' => 'billable/' . $this->billable_id);
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
      'subject' => '',
      'created' => time(),
      'changed' => time(),
      'data' => '',
      'date_delivery' => 0,
      'weight' => 0,
      'parent_billable' => 0,
      'subject_nid' => 0,
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
  
}
