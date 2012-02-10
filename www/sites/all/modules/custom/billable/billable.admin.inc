<?php

/**
 * @file
 * Billable editing UI.
 *
 * We make very little use of the EntityAPI interface for this - preferring instead to use
 * views. That offers more flexibility to change a UI that will, more often than not,
 * be end-user facing.
 */

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
    $id_count = count(explode('/', $this->path));
    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%' . $this->entityType;

    $items[$this->path] = array(
      'title' => 'Billables',
      'description' => 'Add edit and update billables.',
      'page callback' => 'system_admin_menu_block_page',
      'access arguments' => array('access administration pages'),
      'file path' => drupal_get_path('module', 'system'),
      'file' => 'system.admin.inc',
    );
    
    // Change the overview menu type for the list of billables.
    $items[$this->path]['type'] = MENU_LOCAL_TASK;
    
    
    // Add menu items to add a billable (no other bundles)
    $items[$this->path . '/add/billable'] = array( //billable is the only bundle!
      'title' => 'Add billable',
      'page callback' => 'billable_form_wrapper',
      'page arguments' => array(billable_create(array('type' => 'billable'))),
      'access callback' => 'billable_access',
      'access arguments' => array('edit', 'edit billable'),
      'file' => 'billable.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );

    // Loading and editing billable entities
    $items[$this->path . '/billable/' . $wildcard] = array(
      'page callback' => 'billable_form_wrapper',
      'page arguments' => array($id_count + 1),
      'access callback' => 'billable_access',
      'access arguments' => array('edit', $id_count + 1),
      'weight' => 0,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
      'file' => 'billable.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );
    $items[$this->path . '/billable/' . $wildcard . '/edit'] = array(
      'title' => 'Edit',
      'type' => MENU_DEFAULT_LOCAL_TASK,
      'weight' => -10,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
    );
    
    $items[$this->path . '/billable/' . $wildcard . '/delete'] = array(
      'title' => 'Delete',
      'page callback' => 'billable_delete_form_wrapper',
      'page arguments' => array($id_count + 1),
      'access callback' => 'billable_access',
      'access arguments' => array('edit', $id_count + 1),
      'type' => MENU_LOCAL_TASK,
      'context' => MENU_CONTEXT_INLINE,
      'weight' => 10,
      'file' => 'billable.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );
    
    // Menu item for viewing billables
    $items['billable/' . $wildcard] = array(
      //'title' => 'Title',
      'title callback' => 'billable_page_title',
      'title arguments' => array(1),
      'page callback' => 'billable_page_view',
      'page arguments' => array(1),
      'access callback' => 'billable_access',
      'access arguments' => array('view', 1),
      'type' => MENU_CALLBACK,
    );
    return $items;
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
* So we can make the user change the date format by changing this variable 
*/
function _billable_get_date_format(){
  return variable_get('date_format_short_date_only', 'Y/m/d');
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
  $form['subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => isset($billable->subject) ? $billable->subject : '',
    '#maxlength' => 255,
    '#required' => TRUE,
  );
 
  $form['amount'] = array(
    '#type' => 'textfield',
    '#title' => t('Amount'),
    '#default_value' => isset($billable->amount) ? $billable->amount : 1,
    '#maxlength' => 255,
    '#required' => TRUE,
  );

  $delivery_date = $billable->date_delivery;
  $format = _billable_get_date_format();
  $popup_default_format = 'y-m-d';
  $form['date_delivery'] = array(
    '#type' => 'date_popup',
    '#date_format' => $format,
    '#title' => t('Delivery date'),
    '#default_value' => isset($delivery_date) ? date($popup_default_format, $delivery_date) : date($popup_default_format, time()),
    '#required' => TRUE,
  );
  
  $form['vat_rate'] = array(
    '#type' => 'select',
    '#title' => t('VAT rate'),
    '#options' => _billable_vat_rates(),
    '#default_value' => isset($billable->vat_rate) ? $billable->vat_rate : 19,
    '#maxlength' => 255,
    '#required' => TRUE,
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
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete billable'),
      '#suffix' => l(t('Cancel'), 'admin/content/billables'),
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
  $form_state['redirect'] = 'admin/content/billables';
}

/**
 * Form API submit callback for the delete button.
 * 
 * @todo Remove hard-coded path
 */
function billable_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/content/billables/billable/' . $form_state['billable']->billable_id . '/delete';
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
    t('Are you sure you want to delete billable %name?', array('%name' => $billable->name)),
    'admin/content/billables/billable',
    '<p>' . t('This action cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );
  
  return $form;
}

/**
 * Submit callback for billable_delete_form
 */
function billable_delete_form_submit($form, &$form_state) {
  $billable = $form_state['billable'];

  billable_delete($billable);

  drupal_set_message(t('The billable %name has been deleted.', array('%name' => $billable->name)));
  watchdog('billable', 'Deleted billable %name.', array('%name' => $billable->name));

  $form_state['redirect'] = 'admin/content/billables';
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
      $output = '<p>' . t('Billable Entities cannot be added because you have not created any billable types yet. Go to the <a href="@create-billable-type">billable type creation page</a> to add a new billable type.', array('@create-billable-type' => url('admin/structure/billable_types/add'))) . '</p>';
    }
    else {
      $output = '<p>' . t('No billable types have been created yet for you to use.') . '</p>';
    }
  }

  return $output;
}





/**
 * Sets the breadcrumb for administrative billable pages.
 */
function billable_set_breadcrumb() {
  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l(t('Administration'), 'admin'),
    l(t('Content'), 'admin/content'),
    l(t('Billables'), 'admin/content/billables'),
  );

  drupal_set_breadcrumb($breadcrumb);
}



