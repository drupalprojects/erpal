<?php

/**
 * @file
 * Implements hook that manipulate contact communications.
 */

/**
 * Implement hook_preprocess_field() to add the content as class for field_communication_type fields.
 */
function erpal_basic_preprocess_field(&$vars){
  if(isset($vars['element']['#field_name']) && $vars['element']['#field_name'] == 'field_communication_type'){
    $vars['classes_array'][] = "-label-communication-".$vars['element']['#items'][0]['value'];
  }
}
