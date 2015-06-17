<?php

/**
* @file 
*   handles everything todo with vat calculation
*/


/**
* central function that returns vat rates that are provided by other modules 
* implementing hook_vat_rates;
*/
function _billable_vat_rates() {
  
  //provide a hook to let other modules ad vat rates
  $vat_rates = module_invoke_all('vat_rates');

  $rates = array();
  foreach ($vat_rates as $rate_arr) {
    $rates[number_format($rate_arr['value'],3)] = $rate_arr['label'];
  }

  return $rates;
}