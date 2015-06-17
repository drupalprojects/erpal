<?php

/**
 * The class used for budget entities
 */
class budget extends Entity {
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
    $format_no_time = _budget_get_date_format(false);
    $date_from = $this->date_from;
    $date_till = $this->date_till;
    $date_range = '';
    if ($date_from) {
      $date_range = date($format_no_time, $date_from);
    }
    if ($date_till) {
      $date_range .= ' - '.date($format_no_time, $date_till);
      $date_range = "(".$date_range.")";
    }
    
    $budget_info = $this->available_hours." / ".$this->total_hours;
    return t('Budget')." ".$date_range." ".$budget_info;
  }

  protected function defaultUri() {
    return array('path' => 'budget/' . $this->budget_id);
  }
  
  public function save() {
    //round available_hours to only 2 decimals
    $this->available_hours = round($this->available_hours, 2);
    
    //if the budget is not yet used, we set the available budget to the total budget
    if ($this->available_hours == $this->total_hours || !$this->budget_id) {
      $this->available_hours = $this->total_hours;
    }
    
    parent::save();
  }
  
  public function used() {
    return $this->total_hours - $this->available_hours;
  }
  
  public function delete() {
    
    //check if budget could be delete
    $results = module_invoke_all('budget_delete_validate', $this);

    $can_delete = true;
    foreach ($results as $module => $result_arr) {
      $result = $result_arr['result'];
      if (!$result) {
        $can_delete = false;
        $errors = $result_arr['errors'];
        foreach ($errors as $error)
          drupal_set_message($error, 'error');
      }
      
    }
    
    if ($can_delete) {
      parent::delete();
      return true;
    } else
      return false;
  }
}


/**
 * Provides a class for budget types.
 *
 * Use a separate class so we can specify some defaults modules may alter.
 */
class BudgetType extends Entity {
  public $type;
  public $label;
  public $weight = 0;

  public function __construct($values = array()) {
    parent::__construct($values, 'budget_type');
  }

  function isLocked() {
    return isset($this->status) && empty($this->is_new) && (($this->status & ENTITY_IN_CODE) || ($this->status & ENTITY_FIXED));
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


/**
 * Controller class for budget Type.
 */
class BudgetTypeController extends EntityAPIControllerExportable {
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
      ->entityCondition('entity_type', 'budget')
      ->entityCondition('bundle', $ids, 'IN')
      ->execute();

    if (!empty($results)) {
      $budgets_to_remove = array_keys($results['budget']);
      budget_delete_multiple($budgets_to_remove);
      watchdog('budget', 'Delete !count budgets due to deletion of budget.', array('!count' => count($budgets_to_remove)), WATCHDOG_INFO);
    }

    // Finally delete the type itself.
    return parent::delete($ids, $transaction);
  }
}

