<?php

/*
 * @author Sebastian Kauschke, Bright Solutions GmbH
 * 
 */


/*
 * Callback for the Administration Pages of the Module.
 * 
 */
function bs_syncml_administration_page() {
  
  $form['a'] = array(
    '#markup'  => "This is the admin page.",
  );
  
  return $form;
}
