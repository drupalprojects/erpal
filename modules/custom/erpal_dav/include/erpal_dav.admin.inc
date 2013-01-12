<?php

/**
 * @author Roman Sztyler
 * @created December 2012
 * @copyright 2012 © Bright Solutions GmbH - All rights reserved.
 * 
 * 
 */

function erpal_dav_admin_form() {
	
	
	
	$form['create'] = array(
		'#type' => 'submit',
		'#value' => 'Create Addressbook',
		'#submit' => array('erpal_dav_admin_form_create')
	);
	$form['sync'] = array(
	  '#type' => 'submit',
	  '#value' => 'Sync',
	  '#submit' => array('erpal_dav_admin_form_update')
	);
	
		
	
	return $form;
}

function erpal_dav_admin_form_create($form, $form_state) {
	//dpm($form_state);
	return $form;
}

function erpal_dav_admin_form_update($form, $form_state) {
	global $user;
	$nids = erpal_dav_update_user_addressbook($user->uid);
	//dpm($nids);	
}

/**
 * Updates the adressbook for a user in the database
 */
function erpal_dav_update_user_addressbook($user = NULL) {
  //dpm("Update addressbook of user #$user");  
  module_load_include('inc','erpal_dav', 'include/erpal_dav_contact_backend');
  module_load_include('inc','erpal_dav', 'include/erpal_dav_auth_backend');
  module_load_include('php', 'erpal_dav', 'include/SabreDAV/vendor/autoload');
  
  if (!$user) global $user;
  if (is_numeric($user)) $user = user_load($user);
  $nids = erpal_dav_get_contact_nodes_for_user($user->uid);
  
  $cardbackend = ErpalContactBackend::getInstance();
  $addressbooks = $cardbackend->getAddressBooksForUser('principals/'.$user->name);
  if (!$addressbooks) {
  	$cardbackend->createAddressBook('principals/'.$user->name, $user->name . '_default', array());
    $adddressbooks = $cardbackend->getAddressBooksForUser('principals/'.$user->name);
  }
/*	
	// delete existing addressbook(s)
	foreach ($addressbooks as $addressbook) {
		$cardbackend->deleteAddressbook($addressbook['id']);
	}
*/
  $addressbookid = $addressbooks[0]['id'];
  $existing_cards = $cardbackend->getCardUrisAndTimes($addressbookid);
  foreach ($nids as $nid) {
  	$carduri = _erpal_dav_get_carduri($nid);
    if (!$carduri) {
      //dpm('Carduri not found');
      $carduri = _erpal_dav_create_new_carduri($nid);
      $data = _erpal_dav_node_to_vcard($nid);
      $cardbackend->createCard($addressbookid, $carduri, $data);
    } else {
      $node = node_load($nid);
      $modtime = $node->changed;
	  //dpm($modtime);
	  //dpm($existing_cards[$carduri]);
      if (!isset($existing_cards[$carduri])) {
      	$data = _erpal_dav_node_to_vcard($nid);
		//dpm($data);
        $cardbackend->createCard($addressbookid, $carduri, $data);
	    break;
	  } else
      if ($modtime > $existing_cards[$carduri]->lastmodified) {
        $data = _erpal_dav_node_to_vcard($nid);
		//dpm($data);
        $cardbackend->updateCard($addressbookid, $carduri, $data);
      }
    }
  }
  return $nids;
}

function _test() {
  module_load_include('php', 'erpal_dav', '/include/IMF/Build');
  module_load_include('php', 'erpal_dav', '/include/IMF/Exception');
  module_load_include('php', 'erpal_dav', '/include/IMF/Vcard');	
  module_load_include('php', 'erpal_dav', '/include/IMF/FileIMC');
	
  $node = node_load(1);
  $wrapper = entity_metadata_wrapper('node', $node);
  $cardBuilder = new File_IMC_Build_Vcard();

  foreach ($wrapper->field_addresses as $address_wrap) {
  	
  	//dpm($address_wrap->field_country_term->value());
  }
	return 'HI :)';
}




function _erpal_dav_get_address_type($name) {
	switch($name) {
		case 'privat' : return 'HOME';
		case 'arbeit' : return 'WORK';
		default : return FALSE;
	}
	
}

function _erpal_dav_get_phone_type($name) {
	switch($name) {
		case 'privat' : return 'HOME';
		case 'arbeit' : return 'WORK';
		case 'handy'  : return 'CELL';
		case 'mobil'  : return 'CELL';
		default : return FALSE;
	}
	

}



/**
 * Converts a contact node to a vcard
 */
function _erpal_dav_node_to_vcard($nid){

  //dpm("Getting vCard for node $nid");

  module_load_include('php', 'erpal_dav', '/include/IMF/Build');
  module_load_include('php', 'erpal_dav', '/include/IMF/Exception');
  module_load_include('php', 'erpal_dav', '/include/IMF/Vcard');	
  module_load_include('php', 'erpal_dav', '/include/IMF/FileIMC');

  // load wrapper and builder
  $node = node_load($nid);
  $wrapper = entity_metadata_wrapper('node', $node);
  $cardBuilder = new File_IMC_Build_Vcard();

  // set basic settings
  $cardBuilder->setVersion();
  $cardBuilder->set('UID', _erpal_dav_get_carduri($nid));
  
  
  // set name
  if ($wrapper->field_contact_type->value() == 'company') {
  	$cardBuilder->set('FN', $wrapper->field_company_name->value());
	$name = array(
      'given-name' => $wrapper->field_company_name->value(),
    );
    $cardBuilder->set('N', $name);
  } else {
    $name = array(
      'given-name' => $wrapper->field_firstname->value(),
      'family-name' => $wrapper->field_lastname->value(),
    );
    $cardBuilder->set('N', $name);
    $cardBuilder->set('FN', null);
  }
  
  // set phone numbers
  foreach ($wrapper->field_phone as $phone_wrap) {
  	//dpm($phone_wrap->value());
	//dpm($phone_wrap->field_phone_number->value());
    $cardBuilder->set('TEL', $phone_wrap->field_phone_number->value(),'new');
    // set number types
    $cardBuilder->addParam('TYPE', 'VOICE');
    foreach ($phone_wrap->field_number_type_terms as $term) {
      $type_name = $term->value()->name;
      $type = _erpal_dav_get_phone_type($type_name);
      if ($type) $cardBuilder->addParam('TYPE', $type);
	}
  }

  // set fax numbers
  foreach ($wrapper->field_fax as $fax_wrap) {
    $cardBuilder->set('TEL', $fax_wrap->value(),'new');
    $cardBuilder->addParam('TYPE', 'FAX');
  }
  
  
  
  // set addresses
  foreach ($wrapper->field_addresses as $address_wrap) {
  	$country=$address_wrap->field_country_term->value();
  	$city=$address_wrap->field_city->value();
  	$zip=$address_wrap->field_zip_code->value();
  	$street=$address_wrap->field_street->value();;
  	$address = array(
      'locality' => isset($city) ? $city : NULL,
      'postal-code' => isset($zip) ? $zip : NULL,
      'street-address' => isset($street) ? $street : NULL,
      'country_name' => isset($country) ? $country->name : null,
    );
    $cardBuilder->set('ADR', $address, 'new');
//	dpm('Set new address');
//	dpm($address_wrap->field_address_type_terms->value());
    // set address types
    foreach ($address_wrap->field_address_type_terms as $key => $term) {
    	
      $type_name = $term->value()->name;
      $type = _erpal_dav_get_address_type($type_name);
      if ($type) {
        $cardBuilder->addParam('TYPE', $type);
      }
//	  dpm("With parameter $type_name as $type");
      
    }
  }
  
  // set email
  foreach($wrapper->field_email as $email_wrapper){
  	$cardBuilder->set('EMAIL', $email_wrapper->value(),'new');
	$cardBuilder->addParam('TYPE', 'INTERNET');
  }
  
  // TODO Implement Url, birthday, etc..
  
    
  return $cardBuilder->fetch();
  }

/**
 * Creates a carduri for a node, returns it and saves it in the database 
 */
function _erpal_dav_create_new_carduri($nid) {
  
  module_load_include('php', 'erpal_dav', 'include/vendor/autoload.php');	
  $carduri=Sabre\DAV\UUIDUtil::getUUID();
  	
  db_insert('erpal_dav_carduris')
    ->fields(array('nid'=>$nid, 'carduri' => $carduri))
    ->execute();
  return $carduri;
}


/**
 * Returns the uri of the card that corresponds to the node
 * @param $nid Node ID
 * @return carduri or false if no entry exists
 */
function _erpal_dav_get_carduri($nid) {
  $result = db_select('erpal_dav_carduris', 'edc')
    ->fields('edc', array('carduri'))
    ->condition('nid', $nid)
    ->execute();
  $carduri= $result->fetchAssoc();
  if (!$carduri) return false;
  return $carduri['carduri'];
}

/**
 * Returns an array with nids of contacts that this user has flagged and can access
 * 
 * @param $uid User ID
 * @return array nids of contacts
 */
function erpal_dav_get_contact_nodes_for_user($uid) {
  	
  $flag = flag_get_flag('contact_subscriptions');
  $nids = _erpal_dav_get_flagged_contacts($uid, $flag);
  //$nids = _erpal_dav_delete_nodes_no_access($uid, $nids);
	
return $nids;
}

/**
 * Filters out nids of nodes that cannot be accessed by the user
 * 
 * @param $uid User ID
 * @param array $nids Node IDs
 * 
 * @return Filtered array of Node IDs
 */
function _erpal_dav_delete_nodes_no_access($uid, array $nids) {
  $new_nodes = array();
      
  foreach ($nids as $nid) {
    $a_user = user_load($uid);
    if (node_access('view', $nid, $a_user)) {
      $new_nodes[] = $nid;
    }
  }
  
  return $new_nodes;
}

/**
 * Returns list of contacts that the user has flagged
 * @param $uid User ID
 * @param $flag Flag with fid & entity type
 * @return array nids of flagged contacts
 */

function _erpal_dav_get_flagged_contacts($uid, $flag) {
		
	$result = db_select('flagging', 'fc')
    ->fields('fc', array('entity_id'))
    ->condition('entity_type', $flag->entity_type)
    ->condition('uid', $uid)
    ->condition('fid', $flag->fid)
    ->execute();
  return $result->fetchCol();
  	
}


/**
 * Creates an addressbook for the current or given user.
 * 
 * @param $user user-object, uid or null. If null, currently logged in user will be used.
 * @param $url Uri of the new addressbook
 * @param $props Properties of the new addressbook
 * 
 * @return boolean success?
 */

function erpal_dav_create_addressbook($user = NULL, $url = 'default', $props = array()) {
  	
  modul_load_include('erpal_dav', 'include/erpal_dav_contact_backend', 'inc');	
	
  if (!$user) global $user; else
  if (is_numeric($user)) $user = user_load($user);
  return false;
  
	
  if (!$user->name) return false;
  $principalUri = '/principals/' . $user->name;
  $backend = ErpalContactBackend::getInstance();
  
  $backend->createAdressBook($principalUri, $url, $props);
  
  return true;
  
}	

