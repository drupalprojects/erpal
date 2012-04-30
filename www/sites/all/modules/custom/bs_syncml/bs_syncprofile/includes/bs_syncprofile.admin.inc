<?php


/*
 * Returns the Profile Add Form.
 */
function bs_syncprofile_addprofile_page() {
  
  return drupal_get_form('bs_syncprofile_addprofile_form');
}

/*
 * Constructs the Form for creating a new profile
 */
function bs_syncprofile_addprofile_form($form, &$form_state) {
  
  $form['profilename'] = array(
      '#type'         => 'textfield',
      '#title'        => t("Profile name"),
      '#required'     => true,
      '#description'  => t("Choose a human readable name for this profile.")
  );
  
  $form['serverurl'] = array(
      '#type'         => 'textfield',
      '#title'        => t("Server URL"),
      '#required'     => true,
      '#description'  => t("e.g. <em>http://my.funambol.com:8888/ds</em>")
  );
  
  $form['machinename'] = array(
      '#type'         => 'textfield',
      '#title'        => t("Profile machine name"),
      '#required'     => true,
      '#description'  => t("Choose a machine readable name for this profile. Avoid whitespace and special characters.")
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t("Create Profile")
  );
  return $form;
}

/*
 * Validates the form
 */
function bs_syncprofile_addprofile_form_validate($form, &$form_state) {
  
  $values = $form_state['values'];
  
  // Machine Name validieren
  $machinenamevalid = preg_replace ('/[^a-zA-Z0-9_]/' , "" , $values['machinename']);
  if($machinenamevalid != $values['machinename']) {
    form_set_error("machinename", t("The machine name must not contain whitespace or special characters."));
  }
  
  // Url validieren
  if(!valid_url($values['serverurl'], true)) {
    form_set_error("serverurl", t("Please enter a valid URL (with http://)."));
  }
  
  
  // Check if Profile with machinename already exists:
  $profile = new BsSyncMlProfile();  
  if( $profile->load($values['machinename']) ) {    
    form_set_error("machinename", t("A profile with this name already exists."));
  }
}

/*
 * Saves the new Profile
 */
function bs_syncprofile_addprofile_form_submit($form, &$form_state) {
  
  $values = $form_state['values'];
  
  // Create a new Profile
  $profile = new BsSyncMlProfile($values['machinename']);
  
  $data = array();
  $data['profilename']  = $values['profilename'];
  $data['serverurl']    = $values['serverurl'];
  
  $profile->setData($data);
  $profile->save();
  
}
  