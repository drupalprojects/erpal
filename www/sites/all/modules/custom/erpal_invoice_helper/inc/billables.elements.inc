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
  $value = isset($items[$delta]['rgb']) ? $items[$delta]['rgb'] : '';
 
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

function _erpal_invoice_helper_relace_billabel_ref_widget(&$form) {

  foreach ($form['field_billables_ref'][LANGUAGE_NONE] as $delta => $widget) {
    if (!is_numeric($delta)) 
      continue;
    
    //get the currenct billable and extract default values from it
    $billable_id = false;
    if (isset($form['field_billables_ref'][LANGUAGE_NONE][$delta]['target_id']['#default_value']))
      $billable_id = $form['field_billables_ref'][LANGUAGE_NONE][$delta]['target_id']['#default_value'];
    
    if (is_numeric($billable_id) && $billable_id) {
      $billable = billable_load($billable_id);
      $subject = $billable->subject;
      $date_delivery = $billable->date_delivery;
      $quantity = $billable->quantity;
      $single_price = $billable->single_price;
      $vat_rate = $billable->vat_rate;
    }
    
    $form['field_billables_ref'][LANGUAGE_NONE][$delta]['target_id']['#type'] = 'billable_element';
    $form['field_billables_ref'][LANGUAGE_NONE][$delta]['target_id']['#default_value'] = array(
      'billable_id' => $billable_id,
      'subject' => isset($subject) ? $subject : '',
      'date_delivery' => isset($date_delivery) ? $date_delivery : 0,
      'quantity' => isset($quantity) ? $quantity : 0,
      'single_price' => isset($single_price) ? $single_price : 0,
      'vat_rate' => isset($vat_rate) ? $vat_rate : 0,
    );
  }
  
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

  // Normal FAPI field definitions, except that #value is defined. This is done by '#default' value
  //if the element is used in concrete.
  
  $element['billable_id'] = array(
    '#type' => 'value', //just to keep the id of a billable that already exists
  );
  $element['subject'] =  array(
    '#title' => t('subject'),
    '#type' => 'textfield', 
    '#size' => 60, 
    //'#required' => TRUE,
  );
  
  $element['date_delivery'] =  array(
    '#type' => 'date', 
    '#title' => t('delivery date'),
    //'#required' => TRUE,
  );
  
  $element['quantity'] =  array(
    '#title' => t('quantity'),
    '#type' => 'textfield', 
    '#size' => 3,  
    //'#required' => TRUE,
  );
  
  $element['single_price'] =  array(
    '#title' => t('single price'),
    '#type' => 'textfield', 
    '#size' => 3, 
    //'#required' => TRUE,
  );
  
  $element['vat_rate'] =  array(
    '#title' => t('vat_rate'),
    '#type' => 'select', 
    '#options' => _erpal_invoice_helper_vat_rates_arr(),  
    //'#required' => TRUE,
  );
  
  return $element;
}

/**
* definies the widget form
*/
function _billable_element_widget_form() {
  $element['billable_id'] = array(
    '#type' => 'value', //just to keep the id of a billable that already exists
  );
  $element['subject'] =  array(
    '#title' => t('subject'),
    '#type' => 'textfield', 
    '#size' => 60, 
    //'#required' => TRUE,
  );
  
  $element['date_delivery'] =  array(
    '#type' => 'date', 
    '#title' => t('delivery date'),
    //'#required' => TRUE,
  );
  
  $element['quantity'] =  array(
    '#title' => t('quantity'),
    '#type' => 'textfield', 
    '#size' => 3,  
    //'#required' => TRUE,
  );
  
  $element['single_price'] =  array(
    '#title' => t('single price'),
    '#type' => 'textfield', 
    '#size' => 3, 
    //'#required' => TRUE,
  );
  
  $element['vat_rate'] =  array(
    '#title' => t('vat rate'),
    '#type' => 'select', 
    '#options' => _erpal_invoice_helper_vat_rates_arr(),  
    //'#required' => TRUE,
  );
  
  return $element;
}

/**
* Value callback for billable_element
*/
function _billable_element_value_callback($element, $input = FALSE, &$form_state) {
  
  if ($input !== FALSE && $input !== NULL) {
    //copy all the input values from form state to element
    if (!isset($input['billable_id']))
      return $element;
      
    $element['billable_id'] = $input['billable_id'];
    $element['subject'] =$input['subject'];
    $element['date_delivery'] = mktime(0,0,0, $input['date_delivery']['month'], $input['date_delivery']['day'], $input['date_delivery']['year']);
    $element['quantity'] = $input['quantity'];
    $element['single_price'] = $input['single_price'];
    $element['vat_rate'] = $input['vat_rate'];
  }
  
  //map the value to a entity reference widget
  return array(
    'id' => 12,  das gibt noch fehler, hier aber weiter
  );
  return $element;
}

/**
* Validateion handler for billable element
*/
function _billable_element_validate(&$element, &$form_state) {
  //if one element is filled, all must be filled
//  dpm($element);

}