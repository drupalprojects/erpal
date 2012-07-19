<?php

/**
 * @file
 * budget editing UI.
 *
 * We make very little use of the EntityAPI interface for this - preferring instead to use
 * views. That offers more flexibility to change a UI that will, more often than not,
 * be end-user facing.
 */
 
/**
 * UI controller.
 */
class budgetUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults. Main reason for doing this is that
   * parent class hook_menu() is optimized for entity type administration.
   */
  public function hook_menu() {
    
    $items = array();
  
    
    // Add menu items to add a budget (no other bundles)
    $items['budget/add'] = array( //budget is the only bundle!
      'title' => 'Add budget',
      'page callback' => 'budget_form_wrapper',
      'page arguments' => array(budget_create(array('type' => 'budget'))),
      'access callback' => 'budget_access',
      'access arguments' => array('edit', 'edit budget'),
      'file' => 'budget.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );

    // Loading and editing budget entities
    $items['budget/%budget/edit'] = array(
      'title' => 'Edit',      
      'page callback' => 'budget_form_wrapper',
      'page arguments' => array(1),
      'access callback' => 'budget_access',
      'access arguments' => array('edit', ),
      'weight' => 0,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
      'type' => MENU_DEFAULT_LOCAL_TASK,
      'file' => 'budget.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );
   
    
    $items['budget/%budget/delete'] = array(
      'title' => 'Delete',
      'page callback' => 'budget_delete_form_wrapper',
      'page arguments' => array(1),
      'access callback' => 'budget_access',
      'access arguments' => array('edit', 1),
      'type' => MENU_LOCAL_TASK,
      'context' => MENU_CONTEXT_INLINE,
      'weight' => 10,
      'file' => 'budget.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );
    
    // Menu item for viewing budgets
    $items['budget/%budget'] = array(
      //'title' => 'Title',
      'title callback' => 'budget_page_title',
      'title arguments' => array(1),
      'page callback' => 'budget_page_view',
      'page arguments' => array(1),
      'access callback' => 'budget_access',
      'access arguments' => array('view', 1),
      'type' => MENU_CALLBACK,
    );
    
    
    return $items;
  }
  
  //prepare some form values bevor saving the entity
  public function entityFormSubmitBuildEntity($form, &$form_state) {
    $values = $form_state['values'];
    $date_from = $values['date_from'];
    $date_till = $values['date_till'];
    
    //date must be unix timestamp!
    $form_state['values']['date_from'] = strtotime($date_from);
    $form_state['values']['date_till'] = strtotime($date_till);
    
    entity_form_submit_build_entity($this->entityType, $form_state[$this->entityType], $form, $form_state);
    return $form_state[$this->entityType];
  }
  
  /**
   * Create the markup for the add budget Entities page within the class
   * so it can easily be extended/overriden.
   */ 
  public function addPage() {
    $item = menu_get_item();
    $content = system_admin_menu_block($item);

    if (count($content) == 1) {
      $item = array_shift($content);
      drupal_goto($item['href']);
    }    
        
    return theme('budget_add_list', array('content' => $content));
  }
  
}


/**
 * Form callback wrapper: create or edit a budget.
 *
 * @param $budget
 *   The budget object being edited by this form.
 *
 * @see budget_edit_form()
 */
function budget_form_wrapper($budget) {
  // Add the breadcrumb for the form's location.
  budget_set_breadcrumb();
  return drupal_get_form('budget_edit_form', $budget);
}

/**
 * Form callback wrapper: delete a budget.
 *
 * @param $budget
 *   The budget object being edited by this form.
 *
 * @see budget_edit_form()
 */
function budget_delete_form_wrapper($budget) {
  // Add the breadcrumb for the form's location.
  //budget_set_breadcrumb();
  return drupal_get_form('budget_delete_form', $budget);
}

/**
 * Form callback: create or edit a budget.
 *
 * @param $budget
 *   The budget object to edit or for a create form an empty budget object
 *     with only a budget type defined.
 */
function budget_edit_form($form, &$form_state, $budget) {
  // Add the default field elements.
  $form['budget_id'] = array(
    '#type' => 'value',
    '#value' => isset($budget->budget_id) ? $budget->budget_id : 0,
  );

  $form['total_hours'] = array(
    '#type' => 'textfield',
    '#title' => t('Total budget'),
    '#default_value' => isset($budget->total_hours) ? $budget->total_hours : 0,
    '#required' => TRUE,
  );
  
  $form['available_hours'] = array(
    '#type' => 'value',
    '#value' => isset($budget->available_hours) ? $budget->available_hours : 0,
  );
  
  $date_from = $budget->date_from;
  $date_till = $budget->date_till;

  $format = _budget_get_date_format(false);
  $popup_default_format = 'Y-m-d H:i:s';
  
  $form['date_from'] = array(
    '#type' => 'date_popup',
    '#date_format' => $format,
    '#title' => t('Available from'),
    '#default_value' => $date_from ? date($popup_default_format, $date_from) : date($date_from),
    '#required' => FALSE,
  );
  
  $form['date_till'] = array(
    '#type' => 'date_popup',
    '#date_format' => $format,
    '#title' => t('Available till'),
    '#default_value' => $date_till ? date($popup_default_format, $date_till) : date($date_till),
    '#required' => FALSE,
  );
  
  
  $form['data']['#tree'] = TRUE;

  // Add the field related form elements.
  $form_state['budget'] = $budget;
  field_attach_form('budget', $budget, $form, $form_state);

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
    '#value' => t('Save budget'),
    '#submit' => $submit + array('budget_edit_form_submit'),
  );
  
  if (!empty($budget->budget_id)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete budget'),
      '#suffix' => l(t('Cancel'), 'admin/content/budgets'),
      '#submit' => $submit + array('budget_form_submit_delete'),
      '#weight' => 45,
    );
  }

  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 'budget_edit_form_validate';
  return $form;
}


/**
 * Form API validate callback for the budget form
 */
function budget_edit_form_validate(&$form, &$form_state) {
  $budget = $form_state['budget'];
  
  $values = $form_state['values'];
  $total_hours = $values['total_hours'];
  $available_hours = $values['available_hours'];
  
  //Validate that available_hours is not bigger than total budget
  if ($available_hours > $total_hours)
    form_set_error('available_hours', t('Available hours must be less or equal than total hours'));

  //allow only numbers in total_hours field
  if ($total_hours && !is_numeric($total_hours)) {
    form_set_error('total_hours', t('Please enter only numeric values.'));
  }
  
  // Notify field widgets to validate their data.
  field_attach_form_validate('budget', $budget, $form, $form_state);
}


/**
 * Form API submit callback for the budget form.
 * 
 */
function budget_edit_form_submit(&$form, &$form_state) {
 
  $budget = entity_ui_controller('budget')->entityFormSubmitBuildEntity($form, $form_state);
  // Save the budget and go back to the list of budgets
  
  // Add in created and changed times.
  if ($budget->is_new = isset($budget->is_new) ? $budget->is_new : 0){
    $budget->created = time();
    
    //set available budget to total budget if node is new
    $budget->available_hours = $budget->total_hours;
  }
  
  $budget->changed = time();
  
  $budget->save();
  $form_state['redirect'] = 'budget/'.$budget->budget_id;
}

/**
 * Form API submit callback for the delete button.
 * 
 * @todo Remove hard-coded path
 */
function budget_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'budget/' . $form_state['budget']->budget_id . '/delete';
}


/**
 * Form callback: confirmation form for deleting a budget.
 *
 * @param $budget
 *   The budget to delete
 *
 * @see confirm_form()
 */
function budget_delete_form($form, &$form_state, $budget) {
  $form_state['budget'] = $budget;

  $form['#submit'][] = 'budget_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete budget %subject?', array('%subject' => $budget->subject)),
    'budget/'.$budget->budget_id,
    '<p>' . t('This action cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );
  
  return $form;
}

/**
 * Submit callback for budget_delete_form
 */
function budget_delete_form_submit($form, &$form_state) {
  $budget = $form_state['budget'];

  budget_delete($budget);

  drupal_set_message(t('The budget %subject has been deleted.', array('%subject' => $budget->subject)));
  watchdog('budget', 'Deleted budget %subject.', array('%subject' => $budget->subject));
}



/**
 * Page to add budget Entities.
 *
 * @todo Pass this through a proper theme function
 */
function budget_add_page() {
  $controller = entity_ui_controller('budget');
  return $controller->addPage();
}


/**
 * Displays the list of available budget types for budget creation.
 *
 * @ingroup themeable
 */
function theme_budget_add_list($variables) {
  $content = $variables['content'];
  $output = '';
  if ($content) {
    $output = '<dl class="budget-type-list">';
    foreach ($content as $item) {
      $output .= '<dt>' . l($item['title'], $item['href']) . '</dt>';
      $output .= '<dd>' . filter_xss_admin($item['description']) . '</dd>';
    }
    $output .= '</dl>';
  }
  else {
    if (user_access('administer budget types')) {
      $output = '<p>' . t('budget Entities cannot be added because you have not created any budget types yet. Go to the <a href="@create-budget-type">budget type creation page</a> to add a new budget type.', array('@create-budget-type' => url('admin/structure/budget_types/add'))) . '</p>';
    }
    else {
      $output = '<p>' . t('No budget types have been created yet for you to use.') . '</p>';
    }
  }

  return $output;
}

/**
 * Sets the breadcrumb for administrative budget pages.
 */
function budget_set_breadcrumb() {
  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l(t('Administration'), 'admin'),
    l(t('Content'), 'admin/content'),
    l(t('budgets'), 'budgets'),
  );

  drupal_set_breadcrumb($breadcrumb);
}

