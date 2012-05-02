<?php

/* ################################################################################
 * 
 *      Profile Configuration Forms
 * 
 * ###############################################################################
 */

function bs_syncprofile_profile_page($profilename, $tab=null) {
  $profile = new BsSyncMlProfile();
  
  if( $profile->load($profilename) ) {
    
    if($tab) {

      switch($tab) {

        case 'serversettings':
          return drupal_get_form("bs_syncprofile_serversettings_form", $profile->getData(), $profilename);
          break;
        case 'useraccounts':
          return drupal_get_form("bs_syncprofile_useraccounts_form", $profile->getData(), $profilename);
          break;
        case 'access':
          return drupal_get_form("bs_syncprofile_access_form", $profile->getData(), $profilename);
          break;
      }
    }
    else {
      // Render Data of current Profile
      $out = "<pre>".var_export($profile, true)."</pre>";
      return $out;
    }
    
  }  
  else return t("Invalid parameters");
}

function bs_syncprofile_serversettings_form($form, $form_state, $profile, $profilename) {
  
  $form = array();
  
   $form['profilename'] = array(
      '#type'         => 'textfield',
      '#title'        => t('Profile Name'),
      '#required'     => true,
      '#default_value' =>   isset($profile['profilename']) ? $profile['profilename'] : "",
      '#description'  => t("Choose a human readable name for this profile.")
  );
  
  $form['serverurl'] = array(
      '#type'         => 'textfield',
      '#title'        => t("Server URL"),
      '#required'     => true,
      '#default_value' =>   isset($profile['serverurl']) ? $profile['serverurl'] : "",
      '#description'  => t("e.g. <em>http://my.funambol.com:8888/ds</em>")
  );
  
  $form['accountsettings'] = array(
      '#type'         => 'radios',
      '#title'        => t('Account Settings'),
      '#required'     => true,
      '#options'      => array(
          'global'  => t('One global account'),
          'user'    => t('User specific account')
      ),
      '#default_value' =>   isset($profile['accountsettings']) ? $profile['accountsettings'] : null,
      '#description'  => t("Choose, whether every user has his own account, or if there is one account for all users.")
  );
  
  $form['globalaccount'] = array(
      '#type'         => 'textfield',
      '#title'        => t("Account name"),
      '#default_value' =>   isset($profile['globalaccount']) ? $profile['globalaccount'] : "",
      
      '#states' => array(
        'disabled' => array(   // action to take.
          ':input[name=accountsettings]' => array('value' => 'user'),
        ),
        'required' => array(   // action to take.
          ':input[name=accountsettings]' => array('value' => 'global'),
        ),
      ),
  );
  $form['globalpassword'] = array(
      '#type'         => 'textfield',
      '#title'        => t("Password"),
      '#default_value' =>   isset($profile['globalpassword']) ? $profile['globalpassword'] : "",
      
      '#states' => array(
        'disabled' => array(   // action to take.
          ':input[name=accountsettings]' => array('value' => 'user'),
        ),
        'required' => array(   // action to take.
          ':input[name=accountsettings]' => array('value' => 'global'),
        ),
      ),
  );
  
  
  $syncurl = url("fsync/".$profilename, array('absolute'=>true));
  $form['information'] = array(
    '#markup' => t("This page allows you to enter the Server URL. You can specify whether you want to use one specific funambol account for this server, or if every user has his/her own Account. The Accounts can be managed under 'User Accounts'. 
                    If you want to activate the sync process for this profile, go to the following URL: !url", 
                    array('!url' => l($syncurl, $syncurl))),
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t("Save")
  );
  
  return $form;
}


function bs_syncprofile_useraccounts_form($form, $form_state, $profile, $profilename) {
  
  dpm($profile);
  
  $form = array();
  $form['a'] = array(
      '#type'         => 'textfield',
      '#title'        => t("bbbb"),
      '#description'  => t(".")
  );
  return $form;
}

function bs_syncprofile_access_form($form, $form_state, $profile, $profilename) {
  
  $form['accessrestriction'] = array(
      '#type'         => 'radios',
      '#title'        => t('Users'),
      '#required'     => true,
      '#options'      => array(
          'none'  => t('No access restriction'),
          'perm'    => t('Use a permission for this profile')
      ),
      '#default_value' =>   isset($profile['accessrestriction']) ? $profile['accessrestriction'] : null,
  );
  
  $form['accesspermission'] = array(
      '#type'       => 'textfield',
      '#title'      => t("Permission for this profile"),      
      '#value'      => "access $profilename synchronization",
      '#disabled'   => true,
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