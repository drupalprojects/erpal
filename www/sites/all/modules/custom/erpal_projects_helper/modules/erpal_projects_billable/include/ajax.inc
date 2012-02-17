<?php

/**
* @file this file handles all functions needed for ajax requests in the module erpal_projects_billable
*/
function _erpal_projects_billable_ajax_pricing_preselect_callback($form, $form_state) {
  dpm($form['field_pricing']['und'][0]);
  return $form['field_pricing']['und'][0];  //for has already been processed, so just return the elements
}