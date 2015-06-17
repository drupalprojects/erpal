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
function working_times_load_by_user($type, $uid, $year=false, $month=false) {
  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'working_times')
    ->propertyCondition('uid', $uid)
    ->propertyCondition('type', $type) 
    ->addMetaData('account', user_load(1)); // Run the query as user 1.

  if ($year)
    $query->propertyCondition('year', $year);
  
  if ($month)
    $query->propertyCondition('month', $month);
  
  //order by year, month ascending
  $query->propertyOrderBy('year', 'ASC');
  $query->propertyOrderBy('month', 'ASC');
  
  $result = $query->execute();

  $items = array();
  if (isset($result['working_times'])) {
    $working_times_ids = array_keys($result['working_times']);
    $items = entity_load('working_times', $working_times_ids, array(), TRUE);
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
  $working_times = entity_load('working_times', $working_times_ids, $conditions, $reset);
  return $working_times;
}


/**
 * Deletes a working_times.
 */
function working_times_delete(WorkingTimes $working_times) {
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
function working_times_save(WorkingTimes $working_times) {
  return $working_times->save();
}


/**
 * Saves a working_times type to the db.
 * @todo: work tith working_timesType class
 */
function working_times_type_save(working_timesType $type) {
  $type->save();
}



/**
 * Menu title callback for showing individual entities
 */
function working_times_page_title(WorkingTimes $working_times){
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
  
  public function defaultLabel() {
    return working_times_page_title($this);
  }
  
  public function save() {
    //set the changed date
    $this->changed = time();
 
    if (isset($this->is_new) && $this->is_new) {
      $this->created = time();
    }
    
    parent::save();
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
      'uid' => 0,
      'booking_time' => 0,
      'month' => date('m'),
      'year' => date('Y'),
      'overtime' => 0,
      'ill_days' => 0,
      'holidays_used' => 0,
      'holidays_available' => 0,
      'total_hours' => 0,     
      'booked_working_hours' => 0,    
      'project_time' => 0, 
      'holidays_used_from_before' => 0,
      'overtime_reduce' => 0,     
    );
    
    $working_times = parent::create($values);
    return $working_times;
  }
  
  
}

/**
 * @file
 * working_times editing UI.
 *
 * We make very little use of the EntityAPI interface for this - preferring instead to use
 * views. That offers more flexibility to change a UI that will, more often than not,
 * be end-user facing.
 */

module_load_include('inc', 'working_times', 'working_times.configurable');

/**
 * UI controller.
 */
class WorkingTimesUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults. Main reason for doing this is that
   * parent class hook_menu() is optimized for entity type administration.
   */
  public function hook_menu() {
    
    $items = array();
      
    // Add menu items to add a working_times (no other bundles)
    $items['working_times/add/%'] = array( //working_times offset is the only bundle we want to create!
      'title' => 'Add working time offset',
      'page callback' => 'working_times_form_wrapper',
      'page arguments' => array(false, 2),
      'access callback' => 'working_times_access',
      'access arguments' => array('create'),
      'file' => 'working_times.entity.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']).'/inc',
    );

    // Loading and editing working_times entities
    $items['working_times/%working_times/edit'] = array(
      'title' => 'Edit',      
      'page callback' => 'working_times_form_wrapper',
      'page arguments' => array(1),
      'access callback' => 'working_times_access',
      'access arguments' => array('edit', 1),
      'weight' => 0,
      'file' => 'working_times.entity.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']).'/inc',
    );
   
    
    $items['working_times/%working_times/delete'] = array(
      'title' => 'Delete',
      'page callback' => 'working_times_delete_form_wrapper',
      'page arguments' => array(1),
      'access callback' => 'working_times_access',
      'access arguments' => array('delete', 1),
      'weight' => 10,
      'file' => 'working_times.entity.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']).'/inc',
    );

    return $items;
  }
  
}


/**
 * Form callback wrapper: create or edit a working_times.
 *
 * @param $working_times
 *   The working_times object being edited by this form.
 *
 * @see working_times_edit_form()
 */
function working_times_form_wrapper($working_times=false, $uid=false) {
 
  $working_times = $working_times ? $working_times : working_times_create(array('type' => 'offset', 'uid' => $uid));
  drupal_set_message('The offset data you create here will be used as offset for calculations from the beginning of the month you enter.', 'warning');

  return drupal_get_form('working_times_edit_form', $working_times, $uid);
}

/**
 * Form callback wrapper: delete a working_times.
 *
 * @param $working_times
 *   The working_times object being edited by this form.
 *
 * @see working_times_edit_form()
 */
function working_times_delete_form_wrapper($working_times) {
  // Add the breadcrumb for the form's location.
  //working_times_set_breadcrumb();
  return drupal_get_form('working_times_delete_form', $working_times);
}

/**
 * Form callback: create or edit a working_times.
 *
 * @param $working_times
 *   The working_times object to edit or for a create form an empty working_times object
 *     with only a working_times type defined.
 */
function working_times_edit_form($form, &$form_state, $working_times, $uid=false) {
  // Add the default field elements.
  $form['id'] = array(
    '#type' => 'value',
    '#value' => isset($working_times->id) ? $working_times->id : 0,
  );
  
  $type = isset($working_times->type) ? $working_times->type : 'offset';
  $form['type'] = array(
    '#type' => 'value',
    '#value' => $type,
  );

  $form['uid'] = array(
    '#type' => 'textfield',
    '#title' => t('User ID'),
    '#default_value' => isset($working_times->uid) ? $working_times->uid : $uid,
    '#maxlength' => 255,
    '#required' => TRUE,
  );

  $form['month'] = array(
    '#type' => 'textfield',
    '#title' => t('Month'),
    '#default_value' => isset($working_times->month) ? $working_times->month : 0,
    '#maxlength' => 255,
    '#required' => FALSE,
  );
  
  $form['year'] = array(
    '#type' => 'textfield',
    '#title' => t('Year'),
    '#default_value' => isset($working_times->year) ? $working_times->year : 0,
    '#maxlength' => 255,
    '#required' => FALSE,
  );
  
  $form['overtime'] = array(
    '#type' => 'textfield',
    '#title' => t('Overtime'),
    '#default_value' => isset($working_times->overtime) ? $working_times->overtime : 0,
    '#maxlength' => 255,
    '#required' => TRUE,
  );
  
  $form['ill_days'] = array(
    '#type' => 'textfield',
    '#title' => t('Ill days'),
    '#default_value' => isset($working_times->ill_days) ? $working_times->ill_days : 0,
    '#maxlength' => 255,
    '#required' => TRUE,
  );
  
  $form['holidays_used'] = array(
    '#type' => 'textfield',
    '#title' => t('Holidays used'),
    '#default_value' => isset($working_times->holidays_used) ? $working_times->holidays_used : 0,
    '#maxlength' => 255,
    '#required' => FALSE,
  );
  
  $form['holidays_available'] = array(
    '#type' => 'textfield',
    '#title' => t('Holidays available'),
    '#default_value' => isset($working_times->holidays_available) ? $working_times->holidays_available : 0,
    '#maxlength' => 255,
    '#required' => FALSE,
  );
  
  $format = _erpal_basic_helper_date_format_date_only();
  $end_of_the_year = date('Y').'-12-31';

  $holidays_available_till = isset($working_times->holidays_available_till) ? $working_times->holidays_available_till : false;
  
  if (!$holidays_available_till) {
    $holiday_transfer_months = _erpal_employee_get_holiday_month_transfer();
    $holidays_available_till = strtotime($end_of_the_year.' +'.$holiday_transfer_months.' month');
  }
  
  $holidays_available_till = date('Y-m-d', $holidays_available_till);
  $form['holidays_available_till'] = array(
    '#type' => 'date_popup',
    '#title' => t('Holidays available till date'),
    '#default_value' => $holidays_available_till,
    '#date_format' => $format,
    '#required' => FALSE,
  );
  
  $form['total_hours'] = array(
    '#type' => 'textfield',
    '#title' => t('Total real worked hours'),
    '#default_value' => isset($working_times->total_hours) ? $working_times->total_hours : 0,
    '#maxlength' => 255,
    '#required' => FALSE,
  );
  
  $form['booked_working_hours'] = array(
    '#type' => 'textfield',
    '#title' => t('Total booked hours'),
    '#default_value' => isset($working_times->booked_working_hours) ? $working_times->booked_working_hours : 0,
    '#maxlength' => 255,
    '#required' => FALSE,
  );  
  
  $form['project_time'] = array(
    '#type' => 'textfield',
    '#title' => t('Total project time'),
    '#default_value' => isset($working_times->project_time) ? $working_times->project_time : 0,
    '#maxlength' => 255,
    '#required' => FALSE,
  );
  
  $form['overtime_reduce'] = array(
    '#type' => 'textfield',
    '#title' => t('Overtime reduce'),
    '#default_value' => isset($working_times->overtime_reduce) ? $working_times->overtime_reduce : 0,
    '#maxlength' => 255,
    '#required' => FALSE,
  );
  
  $form['overtime_reduce'] = array(
    '#type' => 'textfield',
    '#title' => t('Overtime reduce'),
    '#default_value' => isset($working_times->overtime_reduce) ? $working_times->overtime_reduce : 0,
    '#maxlength' => 255,
    '#required' => FALSE,
  );
  
  $form['data']['#tree'] = TRUE;

  // Add the field related form elements.
  $form_state['working_times'] = $working_times;
  field_attach_form('working_times', $working_times, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 400,
  );

  // We add the form's #submit array to this button along with the actual submit
  // handler to preserve any submit handlers added by a form callback_wrapper.
  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#submit' => $submit + array('working_times_edit_form_submit'),
  );
  
  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 'working_times_edit_form_validate';
  return $form;
}


/**
 * Form API validate callback for the working_times form
 */
function working_times_edit_form_validate(&$form, &$form_state) {
  $working_times = $form_state['working_times'];
  
  // Notify field widgets to validate their data.
  field_attach_form_validate('working_times', $working_times, $form, $form_state);
}


/**
 * Form API submit callback for the working_times form.
 * 
 * @todo remove hard-coded link
 */
function working_times_edit_form_submit(&$form, &$form_state) {
 
  $working_times = entity_ui_controller('working_times')->entityFormSubmitBuildEntity($form, $form_state);
  // Save the working_times and go back to the list of working_timess
  
  // Add in created and changed times.
  if ($working_times->is_new = isset($working_times->is_new) ? $working_times->is_new : 0){
    $working_times->created = time();
  }

  //convert some dates to timestamp
  $working_times->holidays_available_till = strtotime($working_times->holidays_available_till);
  
  $working_times->changed = time();
  
  $working_times->save();
  drupal_set_message(t('%title has been saved.', array('%title' => $working_times->defaultLabel())));
  $form_state['redirect'] = 'working_times/'.$working_times->id."/edit";
}

/**
 * Form API submit callback for the delete button.
 * 
 * @todo Remove hard-coded path
 */
function working_times_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = '';
  //@TODO set message here?
}


/**
 * Form callback: confirmation form for deleting a working_times.
 *
 * @param $working_times
 *   The working_times to delete
 *
 * @see confirm_form()
 */
function working_times_delete_form($form, &$form_state, $working_times) {
  $form_state['working_times'] = $working_times;

  $form['#submit'][] = 'working_times_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete working times %subject?', array('%subject' => $working_times->defaultLabel())),
    'working_times/'.$working_times->id.'/view',
    '<p>' . t('This action cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );
  
  return $form;
}

/**
 * Submit callback for working_times_delete_form
 */
function working_times_delete_form_submit($form, &$form_state) {
  $working_times = $form_state['working_times'];
  working_times_delete($working_times);
}

