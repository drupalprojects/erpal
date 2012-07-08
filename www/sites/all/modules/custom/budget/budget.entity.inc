<?php


/**
 * Fetch a budget object. Make sure that the wildcard you choose 
 * in the budget entity definition fits the function name here.
 *
 * @param $budget_id
 *   Integer specifying the budget id.
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * @return
 *   A fully-loaded $budget object or FALSE if it cannot be loaded.
 *
 * @see budget_load_multiple()
 */
function budget_load($budget_id, $reset = FALSE) {
  $budgets = budget_load_multiple(array($budget_id), array(), $reset);
  return reset($budgets);
}


/**
 * Load multiple budgets based on certain conditions.
 *
 * @param $budget_ids
 *   An array of budget IDs.
 * @param $conditions
 *   An array of conditions to match against the {budget} table.
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * @return
 *   An array of budget objects, indexed by budget_id.
 *
 * @see entity_load()
 * @see budget_load()
 */
function budget_load_multiple($budget_ids = array(), $conditions = array(), $reset = FALSE) {
  $budgets = entity_load('budget', $budget_ids, $conditions, $reset);
  return $budgets;
}


/**
 * Deletes a budget.
 */
function budget_delete(budget $budget) {
  $budget->delete();
}


/**
 * Delete multiple budgets.
 *
 * @param $budget_ids
 *   An array of budget IDs.
 */
function budget_delete_multiple(array $budget_ids) {
  entity_get_controller('budget')->delete($budget_ids);
}


/**
 * Create a budget object.
 */
function budget_create($values = array()) {
  return entity_get_controller('budget')->create($values);
}


/**
 * Saves a budget to the database.
 *
 * @param $budget
 *   The budget object.
 */
function budget_save(budget $budget) {
  
  //if budget is new, we set available budget value to total budget
  if (!$budget->budget_id)
   $budget->available_hours = $budget->total_hours;
  
  return $budget->save();
}


/**
 * Saves a budget type to the db.
 */
function budget_type_save(budgetType $type) {
  $type->save();
}


/**
 * Deletes a budget type from the db.
 */
function budget_type_delete(budgetType $type) {
  $type->delete();
}


/**
 * URI callback for budgets
 */
function budget_uri(budget $budget){
  return array(
    'path' => 'budget/' . $budget->budget_id,
  );
}


/**
 * Menu title callback for showing individual entities
 */
function budget_page_title(budget $budget){
  return $budget->defaultLabel();
}


/**
 * Sets up content to show an individual budget
 * @todo - get rid of drupal_set_title();
 */
function budget_page_view($budget, $view_mode = 'full') {    
  $controller = entity_get_controller('budget');  
  $content = $controller->view(array($budget->budget_id => $budget));
  drupal_set_title($budget->defaultLabel());
  return $content;
}


/**
* @return
*   Themes of our budget entity
*/
function _budget_entity_theme() {
  
  return array(    
    'budget_view' => array(
      'variables' => array('budget' => false),
      'template' => 'budget_view',
    ),
  );
}




/**
 * The class used for budget entities
 */
class budget extends Entity {
  //numers to round
  protected $round_digits = 2;
  
  /**
  * Adds a amount (may be negative) of hours to a budget. 
  *@param $negative if true the resulting value for available_hours could be negative
  *  if false and resulting available_hours is negative, function returns false, amount is not added
  * if the added amount + available_hours is more than total hours, adding fails ans result is false
  *@return true if success false otherwise
  */
  public function add_hours($amount, $negative=false) {
    //prepare values, especially float values
    $available_hours = $this->available_hours;
    $total_hours = $this->total_hours;
    $new_value = $available_hours + $amount;
    
    if (!$negative && $new_value < 0)
      return false;
      
    if ($total_hours < $available_hours + $amount)
      return false;
      
    $this->available_hours = $new_value;
      
    return true;
  }
 
  
  public function __construct($values = array()) {
    parent::__construct($values, 'budget');
  }
  
  public function defaultLabel() {
    return t('Budget').' ('.$this->available_hours." / ".$this->total_hours.")";
  }

  protected function defaultUri() {
    return array('path' => 'budget/' . $this->budget_id);
  }
  
  
}



/**
 * The Controller for budget entities
 */
class budgetController extends EntityAPIController {
  public function __construct($entityType) {
    parent::__construct($entityType);
  }


  /**
   * Create a budget - we first set up the values that are specific
   * to our budget schema but then also go through the EntityAPIController
   * function.
   * 
   * @param $type
   *   The machine-readable type of the budget.
   *
   * @return
   *   A budget object with all default fields initialized.
   */
  public function create(array $values = array()) {
    // Add values that are specific to our budget
    $values += array( 
      'budget_id' => '',
      'is_new' => TRUE,
      'type' => 'budget', //allways fixed because we have no bundles      
      'created' => time(),
      'changed' => time(),
      'data' => '',
      'date_from' => 0,
      'date_till' => 0,
      'total_hours' => 0,
      'available_hours' => 0,
    );
    
    $budget = parent::create($values);
    return $budget;
  }
  
  /**
   * Overriding the buldContent function to add entity specific fields
   */
  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
    $content = parent::buildContent($entity, $view_mode, $langcode, $content);
    $content['budget'] =  array(
      '#markup' => theme('budget_view', array('budget' => $entity)),
    );

    return $content;
  }
  
}
