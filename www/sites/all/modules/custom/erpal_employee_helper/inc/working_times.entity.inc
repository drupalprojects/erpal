<?php


/**
 * Fetch a working_times object. Make sure that the wildcard you choose 
 * in the working_times entity definition fits the function name here.
 *
 * @param $working_times_id
 *   Integer specifying the working_times id.
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * @return
 *   A fully-loaded $working_times object or FALSE if it cannot be loaded.
 *
 * @see working_times_load_multiple()
 */
function working_times_load($working_times_id, $reset = FALSE) {
  $working_timess = working_times_load_multiple(array($working_times_id), array(), $reset);
  return reset($working_timess);
}

/**
* Returns the working_times entity by user, year and optional month
*/
function working_times_load_by_user($uid, $year=false, $month=false) {
  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'working_times')
    ->propertyCondition('uid', $uid)
    ->addMetaData('account', user_load(1)); // Run the query as user 1.

  if ($year)
    $query->propertyCondition('year', $year);
  
  if ($month)
    $query->propertyCondition('month', $month);
  
  $result = $query->execute();

  $items = array();
  if (isset($result['working_times'])) {
    $working_times_ids = array_keys($result['working_times']);
    $items = entity_load('node', $working_times_ids);
  }
  
  return $items;
}


/**
 * Load multiple working_timess based on certain conditions.
 *
 * @param $working_times_ids
 *   An array of working_times IDs.
 * @param $conditions
 *   An array of conditions to match against the {working_times} table.
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * @return
 *   An array of working_times objects, indexed by working_times_id.
 *
 * @see entity_load()
 * @see working_times_load()
 */
function working_times_load_multiple($working_times_ids = array(), $conditions = array(), $reset = FALSE) {
  $working_timess = entity_load('working_times', $working_times_ids, $conditions, $reset);
  return $working_timess;
}


/**
 * Deletes a working_times.
 */
function working_times_delete(working_times $working_times) {
  $working_times->delete();
}


/**
 * Delete multiple working_timess.
 *
 * @param $working_times_ids
 *   An array of working_times IDs.
 */
function working_times_delete_multiple(array $working_times_ids) {
  entity_get_controller('working_times')->delete($working_times_ids);
}


/**
 * Create a working_times object.
 */
function working_times_create($values = array()) {
  return entity_get_controller('working_times')->create($values);
}


/**
 * Saves a working_times to the database.
 *
 * @param $working_times
 *   The working_times object.
 */
function working_times_save(working_times $working_times) {
  return $working_times->save();
}


/**
 * Saves a working_times type to the db.
 */
function working_times_type_save(working_timesType $type) {
  $type->save();
}


/**
 * Deletes a working_times type from the db.
 */
function working_times_type_delete(working_timesType $type) {
  $type->delete();
}


/**
 * Menu title callback for showing individual entities
 */
function working_times_page_title(working_times $working_times){
  $user = user_load($working_times->uid);
  $date_str = $working_times->year;
  if ($working_times->month)
    $date_str = $working_times->month.'/'.$working_times->year;
    
  return t('Working time for !user in !date_str', array('!user' => $user->name, '!date_str' => $date_str));
}


/**
 * The class used for working_times entities
 */
class WorkingTimes extends Entity {
  
  public function __construct($values = array()) {
    parent::__construct($values, 'working_times');
  }
  
  protected function defaultLabel() {
    return working_times_page_title($this);
  }
  
  /*
  protected function defaultUri() {
    return array('path' => 'working_times/' . $this->working_times_id);
  }
  */
  
  
}


/**
 * The Controller for working_times entities
 */
class WorkingTimesController extends EntityAPIController {
  public function __construct($entityType) {
    parent::__construct($entityType);
  }


  /**
   * Create a working_times entity - we first set up the values that are specific
   * to our working_times schema but then also go through the EntityAPIController
   * function.
   * 
   * @param $type
   *   The machine-readable type of the working_times.
   *
   * @return
   *   A working_times object with all default fields initialized.
   */
  public function create(array $values = array()) {
    // Add values that are specific to our working_times
    $values += array( 
      'id' => '',
      'is_new' => TRUE,
      'type' => 'working_times', //allways fixed because we have no bundles
      'uid' => 0,
      'booking_time' => 0,
      'month' => 0,
      'year' => 1,
      'overtime' => 0,
      'ill_days' => 0,
      'holidays_used' => 0,
      'holidays_available' => 0,
      'total_hours' => 0,     
      'project_time' => 0, 
      'overtime_reduce' => 0,     
    );
    
    $working_times = parent::create($values);
    return $working_times;
  }
}
