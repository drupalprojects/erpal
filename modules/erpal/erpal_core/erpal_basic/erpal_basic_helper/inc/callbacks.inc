<?php

/**
* @file just some helping callback function for menus
*/

/**
* returns rendered quicktab
*/
function _erpal_basic_helper_render_quicktab($quicktab) {

  return quicktabs_build_quicktabs($quicktab->machine_name);
}