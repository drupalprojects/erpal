<?php

/**
 * @file
 * timetracking editing UI.
 *
 * We make very little use of the EntityAPI interface for this - preferring instead to use
 * views. That offers more flexibility to change a UI that will, more often than not,
 * be end-user facing.
 */
 
/**
 * UI controller.
 */
class timetrackingUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults. Main reason for doing this is that
   * parent class hook_menu() is optimized for entity type administration.
   */
  public function hook_menu() {
    
    $items = array();
  
    
    // Add menu items to add a timetracking (no other bundles)
    $items['timetracking/add'] = array( //timetracking is the only bundle!
      'title' => 'Add timetracking',
      'page callback' => 'timetracking_form_wrapper',
      'page arguments' => array(timetracking_create(array('type' => 'timetracking'))),
      'access callback' => 'timetracking_access',
      'access arguments' => array('edit', 'edit timetracking'),
      'file' => 'timetracking.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );

    // Loading and editing timetracking entities
    $items['timetracking/%timetracking/edit'] = array(
      'title' => 'Edit',      
      'page callback' => 'timetracking_form_wrapper',
      'page arguments' => array(1),
      'access callback' => 'timetracking_access',
      'access arguments' => array('edit', 1),
      'weight' => 0,
     // 'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
      'type' => MENU_LOCAL_TASK,
      'file' => 'timetracking.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
      'weight' => 1,
    );
   
    
    $items['timetracking/%timetracking/delete'] = array(
      'title' => 'Delete',
      'page callback' => 'timetracking_delete_form_wrapper',
      'page arguments' => array(1),
      'access callback' => 'timetracking_access',
      'access arguments' => array('edit', 1),
      'type' => MENU_CALLBACK,
      'context' => MENU_CONTEXT_INLINE,
      'weight' => 10,
      'file' => 'timetracking.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );
    
    
    return $items;
  }
  
  //prepare some form values bevor saving the entity
  public function entityFormSubmitBuildEntity($form, &$form_state) {
    $values = $form_state['values'];
    $time_start = $values['time_start'];
    $time_end = $values['time_end'];
    
    //date must be unix timestamp!
    $form_state['values']['time_start'] = strtotime($time_start);
    $form_state['values']['time_end'] = strtotime($time_end);
    
    entity_form_submit_build_entity($this->entityType, $form_state[$this->entityType], $form, $form_state);
    return $form_state[$this->entityType];
  }
  
  /**
   * Create the markup for the add timetracking Entities page within the class
   * so it can easily be extended/overriden.
   */ 
  public function addPage() {
    $item = menu_get_item();
    $content = system_admin_menu_block($item);

    if (count($content) == 1) {
      $item = array_shift($content);
      drupal_goto($item['href']);
    }    
        
    return theme('timetracking_add_list', array('content' => $content));
  }
  
}


/**
 * Form callback wrapper: create or edit a timetracking.
 *
 * @param $timetracking
 *   The timetracking object being edited by this form.
 *
 * @see timetracking_edit_form()
 */
function timetracking_form_wrapper($timetracking) {
  // Add the breadcrumb for the form's location.
  timetracking_set_breadcrumb();
  return drupal_get_form('timetracking_edit_form', $timetracking);
}

/**
 * Form callback wrapper: delete a timetracking.
 *
 * @param $timetracking
 *   The timetracking object being edited by this form.
 *
 * @see timetracking_edit_form()
 */
function timetracking_delete_form_wrapper($timetracking) {
  // Add the breadcrumb for the form's location.
  //timetracking_set_breadcrumb();
  return drupal_get_form('timetracking_delete_form', $timetracking);
}

/**
 * Form callback: create or edit a timetracking.
 *
 * @param $timetracking
 *   The timetracking object to edit or for a create form an empty timetracking object
 *     with only a timetracking type defined.
 */
function timetracking_edit_form($form, &$form_state, $timetracking) {
  // Add the default field elements.
  $form['timetracking_id'] = array(
    '#type' => 'value',
    '#value' => isset($timetracking->timetracking_id) ? $timetracking->timetracking_id : 0,
  );  
  
  $time_start = $timetracking->time_start ? $timetracking->time_start : time();
  $time_end = $timetracking->time_end;

  $format = _timetracking_get_date_format(true);
  $popup_default_format = 'Y-m-d H:i:s';
  
  $form['time_start'] = array(
    '#type' => 'date_popup',
    '#date_format' => $format,
    '#title' => t('Start time'),
    '#default_value' => $time_start ? date($popup_default_format, $time_start) : date($time_start),
    '#required' => TRUE,
  );
  
  $form['time_end'] = array(
    '#type' => 'date_popup',
    '#date_format' => $format,
    '#title' => t('End time'),
    '#default_value' => $time_end ? date($popup_default_format, $time_end) : date($time_end),
    '#required' => FALSE,
  );
  
  $form['duration'] = array(
    '#type' => 'textfield',
    '#title' => t('Duration'),
    '#default_value' => isset($timetracking->duration) ? $timetracking->duration : 0,
    '#required' => FALSE,
  );
  
  $subjects = _timetracking_get_possible_timetracking_subjects();
  $subjects[0] = '';  

  $form['subject_id'] = array(
    '#type' => 'select',
    '#options' => $subjects,
    '#title' => t('Subject'),
    '#default_value' => isset($timetracking->subject_id) ? $timetracking->subject_id : 0,
    '#required' => FALSE,
  );
  
  $form['description'] = array(
    '#type' => 'textfield',
    '#title' => t('Description'),
    '#default_value' => isset($timetracking->description) && $timetracking->description ? $timetracking->description : '',
    '#required' => TRUE,
  );

  $form['data']['#tree'] = TRUE;

  // Add the field related form elements.
  $form_state['timetracking'] = $timetracking;
  field_attach_form('timetracking', $timetracking, $form, $form_state);

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
    '#value' => t('Save timetracking'),
    '#submit' => $submit + array('timetracking_edit_form_submit'),
  );
  
  if (!empty($timetracking->timetracking_id)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete timetracking'),
      '#suffix' => l(t('Cancel'), 'admin/content/timetrackings'),
      '#submit' => $submit + array('timetracking_form_submit_delete'),
      '#weight' => 45,
    );
  }

  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 'timetracking_edit_form_validate';
  return $form;
}


/**
 * Form API validate callback for the timetracking form
 */
function timetracking_edit_form_validate(&$form, &$form_state) {
  $timetracking = $form_state['timetracking'];
  
  $values = $form_state['values'];
  $time_start = strtotime($values['time_start']);
  $time_end = strtotime($values['time_end']);
  $duration = $values['duration'];
  
  //Validate that time start is not bigger or equal than time end
  if ($time_start >= $time_end && $time_end)
    form_set_error('time_end', t('Time end hours must be less than time start'));

  $calculated_duration = false;
  if ($time_start && $time_end)
    $calculated_duration = round(($time_end - $time_start) / (60*60), 2);

  //allow only numbers in total_hours field
  dpm($duration ."--". $calculated_duration);
  if ($duration && $calculated_duration && $duration != $calculated_duration) {
    form_set_error('duration', t('Duration is not equal with difference of start and end time'));
  }
  
  // Notify field widgets to validate their data.
  field_attach_form_validate('timetracking', $timetracking, $form, $form_state);
}


/**
 * Form API submit callback for the timetracking form.
 * 
 */
function timetracking_edit_form_submit(&$form, &$form_state) {
 
  $timetracking = entity_ui_controller('timetracking')->entityFormSubmitBuildEntity($form, $form_state);
  // Save the timetracking and go back to the list of timetrackings
  
  // Add in created and changed times.
  if ($timetracking->is_new = isset($timetracking->is_new) ? $timetracking->is_new : 0){
    $timetracking->created = time();    
  }
  
  $timetracking->changed = time();
    
  $timetracking->save();
}

/**
 * Form API submit callback for the delete button.
 * 
 * @todo Remove hard-coded path
 */
function timetracking_form_submit_delete(&$form, &$form_state) {
  $timetracking = entity_ui_controller('timetracking')->entityFormSubmitBuildEntity($form, $form_state);
}


/**
 * Form callback: confirmation form for deleting a timetracking.
 *
 * @param $timetracking
 *   The timetracking to delete
 *
 * @see confirm_form()
 */
function timetracking_delete_form($form, &$form_state, $timetracking) {
  $form_state['timetracking'] = $timetracking;

  $form['#submit'][] = 'timetracking_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete timetracking %subject?', array('%subject' => $timetracking->defaultLabel())),
    'timetracking/'.$timetracking->timetracking_id,
    '<p>' . t('This action cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );
  
  return $form;
}

/**
 * Submit callback for timetracking_delete_form
 */
function timetracking_delete_form_submit($form, &$form_state) {
  $timetracking = $form_state['timetracking'];

  $result = timetracking_delete($timetracking);
  if ($result) {
    drupal_set_message(t('The timetracking %subject has been deleted.', array('%subject' => $timetracking->defaultLabel())));
    watchdog('timetracking', 'Deleted timetracking %subject.', array('%subject' => $timetracking->defaultLabel()));
  }
}



/**
 * Page to add timetracking Entities.
 *
 * @todo Pass this through a proper theme function
 */
function timetracking_add_page() {
  $controller = entity_ui_controller('timetracking');
  return $controller->addPage();
}


/**
 * Displays the list of available timetracking types for timetracking creation.
 *
 * @ingroup themeable
 */
function theme_timetracking_add_list($variables) {
  $content = $variables['content'];
  $output = '';
  if ($content) {
    $output = '<dl class="timetracking-type-list">';
    foreach ($content as $item) {
      $output .= '<dt>' . l($item['title'], $item['href']) . '</dt>';
      $output .= '<dd>' . filter_xss_admin($item['description']) . '</dd>';
    }
    $output .= '</dl>';
  }
  else {
    if (user_access('administer timetracking types')) {
      $output = '<p>' . t('timetracking Entities cannot be added because you have not created any timetracking types yet. Go to the <a href="@create-timetracking-type">timetracking type creation page</a> to add a new timetracking type.', array('@create-timetracking-type' => url('admin/structure/timetracking_types/add'))) . '</p>';
    }
    else {
      $output = '<p>' . t('No timetracking types have been created yet for you to use.') . '</p>';
    }
  }

  return $output;
}

/**
 * Sets the breadcrumb for administrative timetracking pages.
 */
function timetracking_set_breadcrumb() {
  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l(t('Administration'), 'admin'),
    l(t('Content'), 'admin/content'),
    l(t('timetrackings'), 'timetrackings'),
  );

  drupal_set_breadcrumb($breadcrumb);
}

