<?php

module_load_include('php', 'erpaldav', 'include/SabreDav/vendor/autoload');

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
    	
		$auth = user_authenticate($username, $password);
		if ($auth != FALSE) return TRUE;
		else return FALSE;
		
    }
	
	
}
