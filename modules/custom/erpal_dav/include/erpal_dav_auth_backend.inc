<?php

/**
 * @author Roman Sztyler
 * @created December 2012
 * @copyright 2012 © Bright Solutions GmbH - All rights reserved.
 * 
 */

module_load_include('php', 'erpal_dav', 'include/SabreDav/vendor/autoload');

class ErpalAuthenticationBackend extends Sabre\DAV\Auth\Backend\AbstractBasic {
	
	/**
     * Validates a username and password
     *
     * This method should return true or false depending on if login
     * succeeded.
     *
     * @param string $username
     * @param string $password
     * @return bool
     */
    protected function validateUserPass($username, $password) {
    	
		global $user;
		if (isset($user->name) && $user->name != $username) return FALSE;
		$auth = user_authenticate($username, $password);
		if ($auth != FALSE) return TRUE;
		return FALSE;
		
    }
	
  /**
   * Returns an instance of the class
   */
  public static function getInstance() {
  	if (!self::$instance) self::$instance = new ErpalAuthBackend(Database::getConnection());
	return self::$instance;
  }
	
}
