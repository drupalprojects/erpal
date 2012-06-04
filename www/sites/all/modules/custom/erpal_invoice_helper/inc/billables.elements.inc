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
  //dpm($items);
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
  );
  $element['subject'] =  array(
    '#title' => t('subject'),
    '#type' => 'textfield', 
    '#size' => 60, 
    '#default_value' => isset($billable) ? $billable->subject : '',
  );

  $element['date_delivery'] =  array(
    '#type' => 'date', 
    '#title' => t('delivery date'),
    '#default_value' => isset($billable) ? array(
      'day' => date('d', $billable->date_delivery), 
      'month' => date('m', $billable->date_delivery), 
      'year' => date('Y', $billable->date_delivery),
    ) : 0
    
  );
  
  $element['quantity'] =  array(
    '#title' => t('quantity'),
    '#type' => 'textfield', 
    '#size' => 3,  
    '#default_value' => isset($billable) ? $billable->quantity : '',
  );
  
  $element['single_price'] =  array(
    '#title' => t('single price'),
    '#type' => 'textfield', 
    '#size' => 3, 
    '#default_value' => isset($billable) ? $billable->single_price : '',
  );
  
  $element['vat_rate'] =  array(
    '#title' => t('vat rate'),
    '#type' => 'select', 
    '#options' => _erpal_invoice_helper_vat_rates_arr(),  
    '#default_value' => isset($billable) ? $billable->vat_rate : _erpal_invoice_helper_get_default_vat_rate(),
  );
  
  return $element;
}

/**
* Value callback for billable_element
*/
function _billable_element_value_callback($element, $input = FALSE, &$form_state) {  
  if (isset($element['billable_id']) && $element['billable_id']) {
    return $element['billable_id'];
  } else
    return 0; // no billable, it has to be created
}

/**
* Validateion handler for billable element
*/
function _billable_element_validate(&$element, &$form_state) {
  //if one element is filled, all must be filled
  $delta = $element['#delta']; // TODO: Isn't there a better way to find out which element?
  $field = $form_state['field'][$element['#field_name']][$element['#language']]['field'];
  $field_name = $field['field_name'];

  if (isset($form_state['values'][$field_name][$element['#language']][$delta])) {
    $values = $form_state['values'][$field_name][$element['#language']][$delta]['target_id'];
    
    $subject = $values['subject'];
    $date_delivery = $values['date_delivery'];
    $date_delivery = mktime(0,0,0, $date_delivery['month'], $date_delivery['day'], $date_delivery['year']);
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
      if (!$single_price) {
        form_error($element['single_price'], t('Please enter a single price'));
        $has_error = true;
      }
      
      //set the other values so we have them in invoice form submit handler, otherwise we have only the billable_id but no values of the widget
      if (!$has_error) {
        $billable_values = array('subject' => $subject, 'quantity' => $quantity, 'single_price' => $single_price, 'date_delivery' => $date_delivery, 'vat_rate' => $vat_rate);
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