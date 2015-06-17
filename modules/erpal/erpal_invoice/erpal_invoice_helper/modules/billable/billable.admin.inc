<?php

/**
* All functions to administer billables
*/

/**
* Callback for the administration form
*/
function billable_adminsettings($form_state) {
  $form = array();
  
  $form['billable_customer_type'] = array(
    '#type' => 'select',
    '#options' => _billable_get_node_types(),
    '#title' => t('Customer node type'),
    '#description' => t('Select which node type could be referenced as customer of a billable'),
    '#default_value' => _billable_customer_type(),
  );
  
  return system_settings_form($form);
}



/**
 * UI controller.
 */
class BillableUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults. Main reason for doing this is that
   * parent class hook_menu() is optimized for entity type administration.
   */
  public function hook_menu() {
    
    $items = array();
  
    // Add menu items to add a billable (no other bundles)
    foreach (billable_get_types() as $type) {
      $items['billable/add/' . $type->type] = array(
        'title' => 'Add ' . $type->label,
        'page callback' => 'billable_form_wrapper',
        'page arguments' => array(billable_create(array('type' => $type->type))),
        'access callback' => 'billable_access',
        'access arguments' => array('create'),
        'file' => 'billable.admin.inc',
        'file path' => drupal_get_path('module', $this->entityInfo['module'])
      );
    }
    
    // Add menu items to add a billable
    $items['billable/add'] = array(
      'title' => 'Add billable',
      'page callback' => 'billable_add_page',
      'page arguments' => array(billable_create(array('type' => 'billable'))),
      'access callback' => 'billable_access',
      'access arguments' => array('edit', 'edit billable'),
      'file' => 'billable.entity.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );

    // Loading and editing billable entities
    $items['billable/%billable/edit'] = array(
      'title' => 'Edit',      
      'page callback' => 'billable_form_wrapper',
      'page arguments' => array(1),
      'access callback' => 'billable_access',
      'access arguments' => array('edit', 1),
      'weight' => 0,
      //'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
      'type' => MENU_LOCAL_TASK,
      'file' => 'billable.entity.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );
   
    
    $items['billable/%billable/delete'] = array(
      'title' => 'Delete',
      'page callback' => 'billable_delete_form_wrapper',
      'page arguments' => array(1),
      'access callback' => 'billable_access',
      'access arguments' => array('edit', 1),
      'type' => MENU_LOCAL_TASK,
      'context' => MENU_CONTEXT_INLINE,
      'weight' => 10,
      'file' => 'billable.entity.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );
    
    // Menu item for viewing billables
    $items['billable/%billable'] = array(
      'title callback' => 'billable_page_title',
      'title arguments' => array(1),
      'page callback' => 'billable_page_view',
      'page arguments' => array(1),
      'access callback' => 'billable_access',
      'access arguments' => array('view', 1),
      'weight' => 0,
    );
    
    // Menu item for viewing billables
    $items['billable/%billable/view'] = array(
      //'title' => 'Title',
      'title callback' => 'billable_page_title',
      'title arguments' => array(1),
      'page callback' => 'billable_page_view',
      'page arguments' => array(1),
      'access callback' => 'billable_access',
      'access arguments' => array('view', 1),
      'type' => MENU_DEFAULT_LOCAL_TASK,
    );
    
    $items['billable/%billable/ungroup'] = array(           
      'page callback' => 'drupal_get_form',
      'page arguments' => array('billable_page_ungroup_form', 1),
      'access callback' => 'billable_access',
      'access arguments' => array('edit', 1),
      'type' => MENU_CALLBACK,
    );
    
    
    return $items;
  }
  
  //prepare some form values bevor saving the entity
  public function entityFormSubmitBuildEntity($form, &$form_state) {
    $values = $form_state['values'];
    $date_delivery = $values['date_delivery'];
    
    //date must be unix timestamp!
    $form_state['values']['date_delivery'] = strtotime($date_delivery);
    
    entity_form_submit_build_entity($this->entityType, $form_state[$this->entityType], $form, $form_state);
    return $form_state[$this->entityType];
  }
  
  /**
   * Create the markup for the add Billable Entities page within the class
   * so it can easily be extended/overriden.
   */ 
  public function addPage() {
    $item = menu_get_item();
    $content = system_admin_menu_block($item);

    if (count($content) == 1) {
      $item = array_shift($content);
      drupal_goto($item['href']);
    }    
        
    return theme('billable_add_list', array('content' => $content));
  }
  
}


/**
 * Form callback wrapper: create or edit a billable.
 *
 * @param $billable
 *   The billable object being edited by this form.
 *
 * @see billable_edit_form()
 */
function billable_form_wrapper($billable) {
  // Add the breadcrumb for the form's location.
  billable_set_breadcrumb();
  return drupal_get_form('billable_edit_form', $billable);
}

/**
 * Form callback wrapper: delete a billable.
 *
 * @param $billable
 *   The billable object being edited by this form.
 *
 * @see billable_edit_form()
 */
function billable_delete_form_wrapper($billable) {
  // Add the breadcrumb for the form's location.
  //billable_set_breadcrumb();
  return drupal_get_form('billable_delete_form', $billable);
}

/**
 * Form callback: create or edit a billable.
 *
 * @param $billable
 *   The billable object to edit or for a create form an empty billable object
 *     with only a billable type defined.
 */
function billable_edit_form($form, &$form_state, $billable) {
  
  // Add the default field elements.
  $form['billable_id'] = array(
    '#type' => 'value',
    '#value' => isset($billable->billable_id) ? $billable->billable_id : 0,
  );

  $form['subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => isset($billable->subject) ? $billable->subject : '',
    '#maxlength' => 255,
    '#required' => TRUE,
  );

  $form['contractor_nid'] = array(
    '#type' => 'select',
    '#options' => _billable_get_customers(),
    '#title' => t('Contractor'),
    '#default_value' => isset($billable->contractor_nid) ? $billable->contractor_nid : '',
    '#required' => TRUE,
  );
  
  $form['customer_nid'] = array(
    '#type' => 'select',
    '#options' => _billable_get_customers(),
    '#title' => t('Customer'),
    '#default_value' => isset($billable->customer_nid) ? $billable->customer_nid : '',
    '#required' => TRUE,
  );  
 
  $form['quantity'] = array(
    '#type' => 'textfield',
    '#title' => t('Quantity'),
    '#default_value' => isset($billable->quantity) ? $billable->quantity : 1,
    '#maxlength' => 255,
    '#required' => TRUE,
  );
  
  $currencies = _billable_get_currencies();
  $form['currency'] = array(
    '#type' => 'select',
    '#title' => t('Currency'),
    '#options' => $currencies,
    '#default_value' => isset($billable->currency) ? $billable->currency : 'EUR',
    '#maxlength' => 255,
    '#required' => TRUE,
  );
  
  $form['single_price'] = array(
    '#type' => 'textfield',
    '#title' => t('Single Price'),
    '#default_value' => isset($billable->single_price) ? $billable->single_price : '',
    '#maxlength' => 255,
    '#description' => t('The single price excluding tax'),
    '#required' => TRUE,
  );

  $delivery_date = !empty($billable->date_delivery) ? $billable->date_delivery : false;

  $format = erpal_lib_get_date_format(false);
  $popup_default_format = 'Y-m-d H:i:s';

  $form['date_delivery'] = array(
    '#type' => 'date_popup',
    '#date_format' => $format,
    '#title' => t('Delivery date'),
    '#default_value' => $delivery_date ? date($popup_default_format, $delivery_date) : date($popup_default_format),
    '#required' => TRUE,
  );

  $form['vat_rate'] = array(
    '#type' => 'select',
    '#title' => t('Tax rate'),
    '#options' => _billable_vat_rates(),
    '#default_value' => !empty($billable->vat_rate) ? $billable->vat_rate : '19.000',
    '#maxlength' => 6,
    '#required' => TRUE,
  );
  
  $form['billed'] = array(
    '#type' => 'checkbox',
    '#title' => t('Billed'),
    '#default_value' => isset($billable->billed) ? $billable->billed : 0,
    '#description' => t('Check, if this billable has already been billed'),
  );
  
  $form['data']['#tree'] = TRUE;

  // Add the field related form elements.
  $form_state['billable'] = $billable;
  field_attach_form('billable', $billable, $form, $form_state);

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
    '#value' => t('Save billable'),
    '#submit' => $submit + array('billable_edit_form_submit'),
  );
  
  if (!empty($billable->subject)) {
    $destination = drupal_get_destination();
    $cancel_url = $destination['destination'];
    if ($cancel_url == $_GET['q']) {
      $cancel_url = 'billable/'.$billable->billable_id.'/view';
    }
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete billable'),
      '#suffix' => l(t('Cancel'), $cancel_url),
      '#submit' => $submit + array('billable_form_submit_delete'),
      '#weight' => 45,
    );
  }

  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 'billable_edit_form_validate';
  return $form;
}


/**
 * Form API validate callback for the billable form
 */
function billable_edit_form_validate(&$form, &$form_state) {
  $billable = $form_state['billable'];
  
  $values = $form_state['values'];
  $quantity = floatval($values['quantity']);
  if (!$quantity || $quantity != $values['quantity']) 
    form_set_error('quantity', t('Please enter valid quantity'));
  
  $single_price = floatval($values['single_price']);
  if ($single_price != $values['single_price']) 
    form_set_error('single_price', t('Please enter valid single price.'));
  
  
  // Notify field widgets to validate their data.
  field_attach_form_validate('billable', $billable, $form, $form_state);
}


/**
 * Form API submit callback for the billable form.
 * 
 * @todo remove hard-coded link
 */
function billable_edit_form_submit(&$form, &$form_state) {
 
  $billable = entity_ui_controller('billable')->entityFormSubmitBuildEntity($form, $form_state);
  // Save the billable and go back to the list of billables
  
  // Add in created and changed times.
  if ($billable->is_new = isset($billable->is_new) ? $billable->is_new : 0){
    $billable->created = time();
  }

  $billable->changed = time();
  
  $billable->save();
 
  $form_state['redirect'] = 'billable/'.$billable->billable_id;
}

/**
 * Form API submit callback for the delete button.
 * 
 * @todo Remove hard-coded path
 */
function billable_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'billable/' . $form_state['billable']->billable_id . '/delete';
}


/**
 * Form callback: confirmation form for deleting a billable.
 *
 * @param $billable
 *   The billable to delete
 *
 * @see confirm_form()
 */
function billable_delete_form($form, &$form_state, $billable) {
  $form_state['billable'] = $billable;

  $form['#submit'][] = 'billable_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete billable %subject?', array('%subject' => $billable->subject)),
    'billable/'.$billable->billable_id.'/view',
    '<p>' . t('This action cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );
  
  return $form;
}


/**
 * Page to add Billable Entities.
 *
 * @todo Pass this through a proper theme function
 */
function billable_add_page() {
  $controller = entity_ui_controller('billable');
  return $controller->addPage();
}


/**
 * Sets the breadcrumb for administrative billable pages.
 */
function billable_set_breadcrumb() {
  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l(t('Administration'), 'admin'),
    l(t('Content'), 'admin/content'),
    l(t('Billables'), 'billables'),
  );

  drupal_set_breadcrumb($breadcrumb);
}


/**
 * Displays the list of available billable types for billable creation.
 *
 * @ingroup themeable
 */
function theme_billable_add_list($variables) {
 $content = $variables['content'];
  $output = '';
  if ($content) {
    $output = '<dl class="billable-type-list">';
    foreach ($content as $item) {
      $output .= '<dt>' . l($item['title'], $item['href']) . '</dt>';
      $output .= '<dd>' . filter_xss_admin($item['description']) . '</dd>';
    }
    $output .= '</dl>';
  }
  else {
    if (user_access('administer billable types')) {
      $output = '<p>' . t('Billable Entities cannot be added because you have not created any billable types yet. Go to the <a href="@create-billable-type">billable type creation page</a> to add a new billable type.', array('@create-billable-type' => url('admin/structure/billable/add'))) . '</p>';
    }
    else {
      $output = '<p>' . t('No billable types have been created yet for you to use.') . '</p>';
    }
  }

  return $output;
}

/**
 * Submit callback for billable_delete_form
 */
function billable_delete_form_submit($form, &$form_state) {
  $billable = $form_state['billable'];

  billable_delete($billable);

  drupal_set_message(t('The billable %subject has been deleted.', array('%subject' => $billable->subject)));
  watchdog('billable', 'Deleted billable %subject.', array('%subject' => $billable->subject));
}


/**
 * Generates the billable type editing form.
 */
function billable_type_form($form, &$form_state, $billable_type, $op = 'edit') {

  if ($op == 'clone') {
    $billable_type->label .= ' (cloned)';
    $billable_type->type = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $billable_type->label,
    '#description' => t('The human-readable name of this billale type.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($billable_type->type) ? $billable_type->type : '',
    '#maxlength' => 32,
    '#disabled' => $billable_type->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'billable_type_load',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this billable type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['description'] = array(
    '#title' => t('Description'),
    '#type' => 'textarea',
    '#default_value' => isset($billable_type->description) ? $billable_type->description : '',
    '#description' => t('Description about the billable type.'),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save billable type'),
    '#weight' => 40,
  );

  if (!$billable_type->isLocked() && $op != 'add') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete billable type'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('billable_type_form_submit_delete'), //@TODO: implement
    );
  }

  return $form;
}

/**
 * Submit handler for creating/editing billable_type.
 */
function billable_type_form_submit(&$form, &$form_state) {
  $billable_type = entity_ui_form_submit_build_entity($form, $form_state);
  // Save and go back.
  $billable_type->save();

  // If we create new billable type we need to add default fields to it.
  if ($form_state['op'] == 'add') {
    //billable_add_default_fields($billable_type);
  }

  // Redirect user back to list of activity types.
  $form_state['redirect'] = 'admin/structure/billable';
}

/**
* Returns the current selected node type for customers
*/
function _billable_customer_type() {
  return variable_get('billable_customer_type', false);
}