<?php

/**
 * @author Roman Sztyler
 * @created December 2012
 * @copyright 2012 © Bright Solutions GmbH - All rights reserved.
 * 
 */


function erpal_dav_init_server() {


// settings
date_default_timezone_set('Canada/Eastern');

// Make sure this setting is turned on and reflect the root url for your WebDAV server.
// This can be for example the root / or a complete path to your server script
$baseUri = '/erpal_dav';

/* Database */
$pdo = Database::getConnection();

//Mapping PHP errors to exceptions
/*
 
 function exception_error_handler($errno, $errstr, $errfile, $errline ) {
    throw new ErrorException($errstr, 0, $errno, $errfile, $errline);
}
set_error_handler("exception_error_handler");
*/
$module_path = drupal_get_path('module', 'erpal_dav');
require_once($module_path. '/include/SabreDAV/vendor/autoload.php');
module_load_include('inc','erpal_dav','include/erpal_dav_auth_backend');
module_load_include('inc','erpal_dav','include/erpal_dav_contact_backend');

// Backends
$authBackend      = new ErpalAuthenticationBackend();
$principalBackend = new Sabre\DAVACL\PrincipalBackend\PDO($pdo, 'erpal_dav_principals', 'erpal_dav_groupmembers');
$carddavBackend   = new ErpalContactBackend($pdo,'erpal_dav_addressbooks', 'erpal_dav_cards');
//$caldavBackend    = new Sabre\CalDAV\Backend\PDO($pdo);

// Setting up the directory tree //
$nodes = array(
    new Sabre\DAVACL\PrincipalCollection($principalBackend),
//    new Sabre\CalDAV\CalendarRootNode($authBackend, $caldavBackend),
    new Sabre\CardDAV\AddressBookRoot($principalBackend, $carddavBackend),
);

// The object tree needs in turn to be passed to the server class
$server = new Sabre\DAV\Server($nodes);
$server->setBaseUri($baseUri);

// Plugins
$server->addPlugin(new Sabre\DAV\Auth\Plugin($authBackend,'SabreDAV'));
$server->addPlugin(new Sabre\DAV\Browser\Plugin());
//$server->addPlugin(new Sabre\CalDAV\Plugin());
$server->addPlugin(new Sabre\CardDAV\Plugin());

$aclPlugin = new Sabre\DAVACL\Plugin();
$aclplugin->hideNodesFromListings = TRUE;
$server->addPlugin($aclPlugin);


// And off we go!
$server->exec();
die();
}