<?php

/**
* @file 
*   handles everything todo with vat calculation
*/


/**
* @todo we have to provide an admin form to manage vat rates. 
*   so this function could return these vat rates
*/
function _billable_vat_rates() {
  return array(
    7 => '7% '.t('vat'),
    19 => '19% '.t('vat'),
    0 => '0% '.t('vat'),
  );
}