<?php

/**
* Runtime cache for saving values during script processing
*/
function _erpal_invoice_helper_cache($key, $value=false) {
  static $cache = array();

  $ret = false;
  if (isset($cache[$key]))
    $ret = $cache[$key];
    
  if ($value)
    $cache[$key] = $value;
    
  return $ret;
}