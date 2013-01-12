<?php

/* ################################################################################
 * 
 *      Profile Configuration Forms
 * 
 * ###############################################################################
 */

function bs_syncprofile_profile_page($profilename, $tab=null) {

  drupal_add_css(drupal_get_path('module', 'bs_syncprofile') . "/css/syncprofile.css");

  $profile = new BsSyncMlProfile();

  if ($profile->load($profilename)) {

    $profiledata = $profile->getData();

    if ($tab) {

      switch ($tab) {
        case 'serversettings':
          return drupal_get_form("bs_syncprofile_serversettings_form", $profile->getData(), $profilename);
          break;
        case 'useraccounts':
          return drupal_get_form("bs_syncprofile_useraccounts_form", $profile->getData(), $profilename);
          break;
        case 'access':
          return drupal_get_form("bs_syncprofile_access_form", $profile->getData(), $profilename);
          break;
        case 'content':
          // Find the config form for the currently set Plugin to this profile.
          $plugins = bs_syncprofile_getAllPlugins();
          return drupal_get_form($plugins[$profiledata['plugin']]['form'], $profile->getData(), $profilename);
          break;
      }
    } else {
      // Render Data of current Profile
      $out = "<h2>" . t('Data of %profile', array('%profile' => $profiledata['profilename'])) . "</h2>";

      $out .="<label>" . t('Profile ID') . "</label>";
      $out .="<div>" . $profile->getPid() . "</div>";
      $out .="<label>" . t('Machine Name') . "</label>";
      $out .="<div>" . $profile->getName() . "</div>";
      $out .= "<h2>" . t('Profile Data') . "</h2>";

      if (is_array($profiledata))
        foreach ($profiledata as $key => $value) {
          $out .="<label>$key</label>";
          $out .="<div>$value</div>";
        }
      return $out;
    }
  } else {
    return t("Invalid parameters");
  }
}

/* #########################################################################
 * 
 *  Server Settings Form
 * 
 * #########################################################################
 */

function bs_syncprofile_serversettings_form($form, $form_state, $profile, $profilename) {


  $form = array();

  $form['profilemachinename'] = array(
      '#type' => 'hidden',
      '#value' => $profilename,
  );

  $form['profilename'] = array(
      '#type' => 'textfield',
      '#title' => t('Profile Name'),
      '#required' => true,
      '#default_value' => isset($profile['profilename']) ? $profile['profilename'] : "",
      '#description' => t("Choose a human readable name for this profile.")
  );

  $form['serverurl'] = array(
      '#type' => 'textfield',
      '#title' => t("Server URL"),
      '#required' => true,
      '#default_value' => isset($profile['serverurl']) ? $profile['serverurl'] : "",
      '#description' => t("e.g. <em>http://my.funambol.com:8888/ds</em>")
  );
  
  $form['plugin'] = array(
      '#type'         => 'select',
      '#title'        => t("Content Plugin"),
      '#required'     => true,
      '#options'      => bs_syncprofile_getPluginSelection(),
      '#default_value' => isset($profile['plugin']) ? $profile['plugin'] : null,
      '#description'  => t("Choose a Content Plugin.")
  );

  $form['accountsettings'] = array(
      '#type' => 'radios',
      '#title' => t('Account Settings'),
      '#required' => true,
      '#options' => array(
          'global' => t('One global account'),
          'user' => t('User specific account')
      ),
      '#default_value' => isset($profile['accountsettings']) ? $profile['accountsettings'] : 'global',
      '#description' => t("Choose, whether every user has his own account, or if there is one account for all users.")
  );

  $form['globalaccount'] = array(
      '#type' => 'textfield',
      '#title' => t("Account name"),
      '#default_value' => isset($profile['globalaccount']) ? $profile['globalaccount'] : "",
      '#states' => array(
          'disabled' => array(// action to take.
              ':input[name=accountsettings]' => array('value' => 'user'),
          ),
          'required' => array(// action to take.
              ':input[name=accountsettings]' => array('value' => 'global'),
          ),
      ),
  );
  $form['globalpassword'] = array(
      '#type' => 'textfield',
      '#title' => t("Password"),
      '#default_value' => isset($profile['globalpassword']) ? $profile['globalpassword'] : "",
      '#states' => array(
          'disabled' => array(// action to take.
              ':input[name=accountsettings]' => array('value' => 'user'),
          ),
          'required' => array(// action to take.
              ':input[name=accountsettings]' => array('value' => 'global'),
          ),
      ),
  );


  $syncurl = url("fsync/" . $profilename, array('absolute' => true));
  $form['information'] = array(
      '#markup' => t("This page allows you to enter the Server URL. You can specify whether you want to use one specific funambol account for this server, or if every user has his/her own Account. The Accounts can be managed under 'User Accounts'. 
                    If you want to activate the sync process for this profile, go to the following URL: !url", array('!url' => l($syncurl, $syncurl))),
  );

  $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t("Save")
  );

  return $form;
}

function bs_syncprofile_serversettings_form_validate($form, $form_state) {

  $values = $form_state['values'];

  // Url validieren
  if (!valid_url($values['serverurl'], true)) {
    form_set_error("serverurl", t("Please enter a valid URL (with http://)."));
  }

  if ($values['accountsettings'] == 'global') {

    if (!$values['globalaccount'])
      form_set_error('globalaccount', t('Please enter a global account name.'));
    if (!$values['globalpassword'])
      form_set_error('globalpassword', t('Please enter a global account password.'));
  }
}

function bs_syncprofile_serversettings_form_submit($form, $form_state) {

  $values = $form_state['values'];
  
  // Check if Profile with machinename already exists:
  $profile = new BsSyncMlProfile();
  if ($profile->load($values['profilemachinename'])) {
    
    $data = $profile->getData();
    $data['serverurl']        = $values['serverurl'];
    $data['accountsettings']  = $values['accountsettings'];
    $data['globalaccount']    = $values['globalaccount'];
    $data['globalpassword']   = $values['globalpassword'];
    $data['profilename']      = $values['profilename'];
    $data['plugin']           = $values['plugin'];
    
    $profile->setData($data);
    $profile->save();
    
    drupal_set_message(t('The settings have been saved.'));
  }
}

/* #########################################################################
 * 
 *  User Accounts Settings Form
 * 
 * #########################################################################
 */

function bs_syncprofile_useraccounts_form($form, $form_state, $profile, $profilename) {

  $values = _bs_syncprofile_useraccounts_getFormSession();

  $form = array();

  $form['profilename'] = array(
      '#type' => 'hidden',
      '#value' => $profilename,
  );

  $form['useraccount'] = array(
      '#type' => 'fieldset',
      '#collapsible' => false,
      '#collapsed' => false,
      '#title' => t("User Accounts"),
      '#prefix' => '<div id="useraccountdata">',
      '#suffix' => '</div>',
  );
  $form['useraccount']['user'] = array(
      '#type' => 'select',
      '#size' => 15,
      '#title' => t("Select user"),
      '#options' => _bs_syncprofile_get_users(isset($values['userfilter']) ? $values['userfilter'] : null),
      '#value' => isset($values['user']) ? $values['user'] : null,
      '#description' => t("Select a user to edit his account credentials"),
      '#ajax' => array(
          'callback' => 'bs_syncprofile_useraccounts_form_ajax',
          'wrapper' => 'useraccountcredentials',
          'method' => 'replace',
          'effect' => 'fade',
      )
  );

  $form['useraccount']['userfilter'] = array(
      '#type' => 'textfield',
      '#title' => t("Filter Username"),
      '#value' => isset($values['userfilter']) ? $values['userfilter'] : null,
  );

  $form['useraccount']['filterbutton'] = array(
      '#type' => 'submit',
      '#value' => t("Filter"),
  );


  $form['accountcredentials'] = array(
      '#type' => 'fieldset',
      '#collapsible' => false,
      '#collapsed' => false,
      '#title' => t('Account Credentials'),
      '#prefix' => '<div id="useraccountcredentials">',
      '#suffix' => '</div>',
  );

  if (isset($values['user'])) {

    $useraccountdata = BsSyncProfileUserAccounts::read($values['user'], $profilename);

    $form['accountcredentials']['accountenabled'] = array(
        '#type' => 'checkbox',
        '#title' => t("Enable this account for this profile"),
        '#value' => isset($values['accountenabled']) ? $values['accountenabled'] : isset($useraccountdata['enabled']) ? $useraccountdata['enabled'] : null ,
    );
    $form['accountcredentials']['accountname'] = array(
        '#type' => 'textfield',
        '#title' => t("Account name"),
        '#value' => isset($values['accountname']) ? $values['accountname'] : isset($useraccountdata['account']) ? $useraccountdata['account'] : null ,
    );
    $form['accountcredentials']['accountpassword'] = array(
        '#type' => 'textfield',
        '#title' => t("Account password"),
        '#value' => isset($values['accountpassword']) ? $values['accountpassword'] : isset($useraccountdata['pass']) ? $useraccountdata['pass'] : null ,
    );

    $form['accountcredentials']['savebutton'] = array(
        '#type' => 'submit',
        '#value' => t("Save"),
    );
  } else {
    $form['accountcredentials']['info'] = array(
        '#markup' => t('Please select a user first'),
    );
  }

  return $form;
}

/**
 * Returns the Ajax-part of the form
 * @param type $form
 * @return type 
 */
function bs_syncprofile_useraccounts_form_ajax($form) {

  return $form['accountcredentials'];
}

/**
 * Validates the form input.
 * 
 * @param type $form
 * @param type $form_state 
 */
function bs_syncprofile_useraccounts_form_validate($form, $form_state) {

  $oldvalues = _bs_syncprofile_useraccounts_getFormSession();

  $values = _bs_syncprofile_useraccounts_inputvaluesmerge($form_state['input']);

  $oldvaluesuser = isset($oldvalues["user"]) ? $oldvalues["user"] : null;
  $valuesuser = isset($values["user"]) ? $values["user"] : null;
  if ($oldvaluesuser != $valuesuser) {
    unset($values['accountenabled']);
    unset($values['accountname']);
    unset($values['accountpassword']);
  }


  if ($form_state['clicked_button']['#value'] == $form_state['values']['filterbutton']) {
    unset($values['user']);
  }

  // Wenn der Save Button geklickt wurde:
  if (isset($form_state['values']['savebutton'])) {
    if ($form_state['clicked_button']['#value'] == $form_state['values']['savebutton']) {

      // Do Validation for things here
      if (!isset($values['user']))
        form_set_error('user', t('Please select a user'));
    }
  }

  _bs_syncprofile_useraccounts_setFormSession($values);
}

function bs_syncprofile_useraccounts_form_submit($form, $form_state) {

  // Wenn der Save Button geklickt wurde:
  if (isset($form_state['values']['savebutton'])) {
    if ($form_state['clicked_button']['#value'] == $form_state['values']['savebutton']) {

      $values = _bs_syncprofile_useraccounts_getFormSession();

      if (!isset($values['accountenabled']))
        $values['accountenabled'] = 0;
      if (!isset($values['accountname']))
        $values['accountname'] = '';
      if (!isset($values['accountpassword']))
        $values['accountpassword'] = '';

      // Write/update the data:
      BsSyncProfileUserAccounts::write($values['user'], $values['profilename'], $values['accountenabled'], $values['accountname'], $values['accountpassword']);
      
       drupal_set_message(t('The user settings have been saved.'));
    }
  }
}

/**
 * Merges the input values of the form
 * @param type $newvals
 * @return type 
 */
function _bs_syncprofile_useraccounts_inputvaluesmerge($newvals) {

  $savedvals = _bs_syncprofile_useraccounts_getFormSession();

  foreach ($newvals as $key => $item) {
    if (!empty($item))
      $savedvals[$key] = $item;
  }

  $savedvals['userfilter'] = $newvals['userfilter'];
  $savedvals['accountenabled'] = isset($newvals['accountenabled']) ? 1 : 0;

  _bs_syncprofile_useraccounts_setFormSession($savedvals);

  return $savedvals;
}

function _bs_syncprofile_useraccounts_getFormSession() {

  if (isset($_SESSION['useraccountsettings'])) {
    return $_SESSION['useraccountsettings'];
  }
  else
    return array();
}

function _bs_syncprofile_useraccounts_setFormSession($value) {

  $_SESSION['useraccountsettings'] = $value;
}

/* #########################################################################
 * 
 *  Access Settings Form
 * 
 * #########################################################################
 */

function bs_syncprofile_access_form($form, $form_state, $profile, $profilename) {
  
  $form['profilemachinename'] = array(
      '#type' => 'hidden',
      '#value' => $profilename,
  );

  $form['accessrestriction'] = array(
      '#type' => 'radios',
      '#title' => t('Users'),
      '#required' => true,
      '#options' => array(
          'none' => t('No access restriction'),
          'perm' => t('Use a permission for this profile')
      ),
      '#default_value' => isset($profile['accessrestriction']) ? $profile['accessrestriction'] : null,
  );

  $form['accesspermission'] = array(
      '#type' => 'textfield',
      '#title' => t("Permission for this profile"),
      '#value' => "access $profilename synchronization",
      '#disabled' => true,
  );

  $form['information'] = array(
      '#markup' => t("This screen allows to restrict access to this funambol profile based on a permission. This is additional to whatever options you have chosen in 
      the Server Settings and User Accounts panel. This can be used to allow synchronization for certain user groups to a profile that uses a single funambol login."),
  );

  $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t("Save")
  );
  return $form;
}

function bs_syncprofile_access_form_submit($form, $form_state) {
  
  $values = $form_state['values'];
  
  // Check if Profile with machinename already exists:
  $profile = new BsSyncMlProfile();
  if ($profile->load($values['profilemachinename'])) {
    
    $data = $profile->getData();
    $data['accessrestriction']  = $values['accessrestriction'];
    $data['accesspermission']   = $values['accesspermission'];
    
    $profile->setData($data);
    $profile->save();
    
    drupal_set_message(t('The settings have been saved.'));
  }
}


/* ################################################### */

function _bs_syncprofile_get_users($userfilter) {

  $query = db_select('users', 'u')
          ->fields('u', array('uid', 'name'))
          ->condition('status', 1, '=');

  if (isset($userfilter)) {
    $query->condition('name', "%%$userfilter%%", 'LIKE');
  }

  $queryresult = $query->execute();

  // Fetch all results into an array:
  $results = array();
  while ($result = $queryresult->fetchAssoc()) {
    $results[$result['uid']] = $result['name'];
  }

  return $results;
}