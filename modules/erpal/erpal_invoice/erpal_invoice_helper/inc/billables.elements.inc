<?php

/**
* @file functions to replace the billables_ref field with a simple form field to enter 
* invoice line items (billables)
*/

/**
* Implements hook_field_widget_info() 
*/
function erpal_invoice_helper_field_widget_info() {
  return array(
    'field_billable_inline' => array(
      'label' => t('Enter billable inline'),
      'field types' => array('entityreference'),
    ),
  );
}

/**
* Implements hook_field_widget_form().
*/
function erpal_invoice_helper_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {

  $value = isset($items[$delta]['target_id']) ? $items[$delta]['target_id'] : '';
 
  $widget = $element;
  $widget['#delta'] = $delta;
  
  switch ($instance['widget']['type']) {

    case 'field_billable_inline': 
      $widget += array(
        '#type' => 'billable_element',
        '#default_value' => $value,
        // Allow a slightly larger size that the field length to allow for some
        // configurations where all characters won't fit in input field.
        '#size' => 7,
        '#maxlength' => 7, 
      );
    break;
  }
  
  $element['#prefix'] = '<div id="billable_element_wrapper_'.$delta.'">';
  $element['#suffix'] = '</div>';
  
  $element['remove_group'] = array(
    '#type' => 'fieldset',
    '#collapbsilbe' => false,
    '#collapsed' => false,
    '#prefix' => '<span class="remove_group">',
    '#suffix' => '</span>',
  );

  $element['remove_group']['remove_'.$delta] = array(
    '#type' => 'submit',
    '#value' => t('remove'),
    '#delta' => $delta,
    '#name' => 'remove_'.$delta,
    '#ajax' => array(
      'callback' => '_erpal_invoice_helper_ajax_remove_billable_from_invoice',
      'wrapper' => 'billable_element_wrapper_'.$delta,
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  $element['remove_group']['keep_billable'] = array(
    '#type' => 'checkbox',
    '#title' => t('keep billable'),
    '#default_value' => true,
  );
  
  
  $element['target_id'] = $widget;
  
  return $element;
}

/**
* Implements hook_element_info
*/
function erpal_invoice_helper_element_info() {
  return array(
    'billable_element' => array(
      '#input' => TRUE,
      '#tree' => TRUE,
      '#process' => array('_billable_element_process'),
      '#value_callback' => '_billable_element_value_callback',
      '#element_validate' => array('_billable_element_validate'),
      '#theme_wrappers' => array('form_element'),
      '#default_value' => array(
        'billable_id' => false,
        'subject' => '',
        'date_delivery' => 0,
        'quantity' => 0,
        'single_price' => 0,
        'vat_rate' => 0,
      ),
  ));
}

/**
* AJAX Callback to remove a billable from the invoice form
*/
function _erpal_invoice_helper_ajax_remove_billable_from_invoice($form, &$form_state) {
  $values = $form_state['values'];
  $button = $form_state['triggering_element'];
  //$delta = $button['#delta'];

  //get the submitted delta, bad way to do this may be, but i dont know how to get the delta of the submitted remove button...
  $delta = false;
  foreach ($values as $key=>$value) {
    //is there a value key starting with "remove_"?
    if (strpos($key, 'remove_') === 0) {
      $key_arr = explode('_', $key);
      $delta = $key_arr[1];      
      break;
    }
  }
  
  //check if billable should be deleted
  $keep_billable = $values['field_billables_ref'][LANGUAGE_NONE][$delta]['remove_group']['keep_billable'];

  $field_billables_ref_new = array();
  $field_billables_ref_new['remove_group'] = array(
    '#type' => 'fieldset',
  );
  
  $field_billables_ref_new['remove_group']['keep_billable'] = $form['field_billables_ref'][LANGUAGE_NONE][$delta]['remove_group']['keep_billable'];
  
  //just a text to give some information to the user
  /*
  $field_billables_ref_new['remove_group']['remove_info'] = array(    
    '#type' => 'item',
    '#markup' => t('Will be removed on form submit'),
  );
  */
  
  $field_billables_ref_new['remove_group']['mark_remove'] = $form['field_billables_ref'][LANGUAGE_NONE][$delta]['remove_group']['mark_remove'];
  $field_billables_ref_new['remove_group']['mark_remove'] = array (
    '#type' => 'checkbox',
    '#title' => t('remove on save'),
    '#name' => 'removed_billables['.$delta.']',
    '#checked' => true,
  );
  
  return $field_billables_ref_new;
}

/**
* Process function for billable_element
*/
function _billable_element_process($element, &$form_state, $complete_form) {
  $element['#tree'] = TRUE;

  $billable_id = $element['#default_value'];

  if ($billable_id)
    $billable = billable_load($billable_id);
  // Normal FAPI field definitions, except that #value is defined. This is done by '#default' value
  //if the element is used in concrete.

  $element['billable_id'] = array(
    '#type' => 'value', //just to keep the id of a billable that already exists
    '#value' => isset($billable) ? $billable->billable_id : '',
    '#attributes' => array(
      'class' => array('billable_id'),
    ),
  );
  $element['subject'] =  array(
    '#title' => t('subject'),
    '#type' => 'textfield', 
    '#size' => 60, 
    '#default_value' => isset($billable) ? $billable->subject : '',
    '#attributes' => array(
      'class' => array('subject'),
    ),
    '#maxlength' => 255,
  );

  $element['date_delivery'] =  array(
    '#type' => 'date_select', 
    '#title' => t('delivery date'),
    /*'#default_value' => isset($billable) ? array(
      'day' => date('d', $billable->date_delivery), 
      'month' => date('m', $billable->date_delivery), 
      'year' => date('Y', $billable->date_delivery),
    ) : 0,*/
    '#default_value' => date('Y-m-d', isset($billable->date_delivery) ? $billable->date_delivery : time()),
    '#date_format' => 'Y-m-d',
    '#attributes' => array(
      'class' => array('date_delivery'),
    ),
    
  );
  
  $element['quantity'] =  array(
    '#title' => t('quantity'),
    '#type' => 'textfield', 
    '#size' => 3,  
    '#default_value' => isset($billable) ? $billable->quantity : '',
    '#attributes' => array(
      'class' => array('quantity'),
    ),
  );
  
  $element['single_price'] =  array(
    '#title' => t('single price'),
    '#type' => 'textfield', 
    '#size' => 3, 
    '#default_value' => isset($billable) ? $billable->single_price : '',
    '#attributes' => array(
      'class' => array('single_price'),
    ),
  );

  //_erpal_invoice_helper_preselect_address_form($complete_form, $form_state);  //this function will set the invoice address id. To make sure it is set for default invoice calculation, set here.
  
  //set vat default for customer
  //for new nodes set the default vat rate of the first billable entity form widget   
  $address_id = isset($complete_form['field_invoice_address_id'][LANGUAGE_NONE][0]) ? $complete_form['field_invoice_address_id'][LANGUAGE_NONE][0]['value'] : false;

  //may be in default values?
  if (!$address_id) {
    $address_id = isset($complete_form['field_invoice_address_id'][LANGUAGE_NONE]['#default_value']) ? $complete_form['field_invoice_address_id'][LANGUAGE_NONE]['#default_value'] : false;
  }

  //if there is no address_id in the form set, it may be set in the $_POST variable
  if (!$address_id) {
    $address_id = isset($form_state['input']['field_invoice_address_id'][LANGUAGE_NONE]) ? $form_state['input']['field_invoice_address_id'][LANGUAGE_NONE] : false;
    $address_id = check_plain($address_id);    
  }
  
  $default_vat_rate = _erpal_invoice_helper_get_vat_rate_by_address($address_id);

  $default_vat_rate = !empty($default_vat_rate) || $default_vat_rate === '0' ? $default_vat_rate : _erpal_invoice_helper_get_default_vat_rate();

  if (!isset($default_vat_rate)) {
    //if we dont have a vat rate, the altering of the form is not processed in first run and so we have no address_nid yet. So get the customer and if it has only one address, use this, otherwise take the default address
    $customer_node = _erpal_invoice_helper_get_customer_form_invoice($complete_form, $form_state);    

    if ($customer_node) {
      $customer_defaults = _erpal_invoice_helper_get_customer_defaults($customer_node);
      $default_vat_rate = $customer_defaults['vat_rate'];
    } else {
      $default_vat_rate = _erpal_invoice_helper_get_default_vat_rate();
    }
  }
  $element['vat_rate'] =  array(
    '#title' => t('tax rate'),
    '#type' => 'select', 
    '#options' => _erpal_invoice_helper_vat_rates_arr(),  
    '#default_value' => isset($billable) ? $billable->vat_rate : $default_vat_rate,
    '#attributes' => array(
      'class' => array('vat_rate'),
    ),
  );
  
  //attach other fields that are attached to a billable if there are some
  if (!isset($billable) || (isset($billable) && !$billable))
    $billable = billable_create();  //just create a dummy billable in order to have it for attaching form fields
    
  field_attach_form('billable', $billable, $element, $form_state);

  return $element;
}

/**
* Value callback for billable_element
*/
function _billable_element_value_callback($element, $input = FALSE, &$form_state) {  

  if (isset($element['billable_id']) && $element['billable_id']) {
    return $element['billable_id'];
  } elseif (isset($element['#default_value']) && $element['#default_value']) {
    
    $billable = billable_load($element['#default_value']);
    return $element['#default_value'];  //after update, we need this...
  } else
    return 0; // no billable, it has to be created
}

/**
* Validateion handler for billable element
*/
function _billable_element_validate(&$element, &$form_state) {
  //if one element is filled, all must be filled
  $delta = $element['#delta']; // TODO: Isn't there a better way to find out which element?
  $field_name = $element['#field_name'];

  if (isset($form_state['values'][$field_name][$element['#language']][$delta])) {
    $values = $form_state['values'][$field_name][$element['#language']][$delta]['target_id'];
    $subject = $values['subject'];
    $date_delivery = $values['date_delivery'];    
    $date_delivery = erpal_lib_as_unix_timestamp($values['date_delivery']);
    //$date_delivery = mktime(0,0,0, $date_delivery['month'], $date_delivery['day'], $date_delivery['year']);
    $quantity = $values['quantity'];
    $single_price = $values['single_price'];
    $vat_rate = $values['vat_rate'];
    $billable_id = $values['billable_id'] ? $values['billable_id'] : ''; //if no billable id is set, set to '' we create it on invoice form submit
    //otherwise, like file field does, we have to create it here and will finalize it on invoice form save
    
    $one_is_set = $subject || $quantity || $single_price;
    if ($one_is_set) {
      $has_error = false;
      if (!$subject) {
        form_error($element['subject'], t('Please enter a subject'));
        $has_error = true;
      }
      if (!$quantity) {
        form_error($element['quantity'], t('Please enter a quantity'));
        $has_error = true;
      }
      if (!$single_price && !is_numeric($single_price)) {
        form_error($element['single_price'], t('Please enter a single price'));
        $has_error = true;
      }
      
      //set the other values so we have them in invoice form submit handler, otherwise we have only the billable_id but no values of the widget
      if (!$has_error) {
        $service_category_tid = isset($element['field_service_category_term'][LANGUAGE_NONE]['#value']) ? $element['field_service_category_term'][LANGUAGE_NONE]['#value'] : false;
        $expense_category_tid = isset($element['field_expense_category'][LANGUAGE_NONE]['#value']) ? $element['field_expense_category'][LANGUAGE_NONE]['#value'] : false;
        $billable_values = array('subject' => $subject, 'quantity' => $quantity, 'single_price' => $single_price, 'date_delivery' => $date_delivery, 'vat_rate' => $vat_rate, 'service_category_tid' => $service_category_tid, 'expense_category_tid' => $expense_category_tid);
        $new_element = array('#parents' => array('field_billables_ref_values', LANGUAGE_NONE, $delta, 'widget_values'));
        form_set_value($new_element, $billable_values, $form_state);
        
      }
      
      //set the real value of the entityreference field
      form_set_value($element, $billable_id, $form_state);      
    } else {
      // If they left all empty, we'll set the value empty and quit.      
      form_set_value($element, '', $form_state);
      return;
    }
  }
  

}