<?php


function erpaldav_init_server() {



/*
 
Addressbook/CardDAV server example

This server features CardDAV support

*/

// settings
date_default_timezone_set('Canada/Eastern');

// Make sure this setting is turned on and reflect the root url for your WebDAV server.
// This can be for example the root / or a complete path to your server script
$baseUri = '/erpaldav';

/* Database */
$pdo = new PDO('mysql:host=localhost;dbname=Erpal','root','root');
$pdo->setAttribute(PDO::ATTR_ERRMODE,PDO::ERRMODE_EXCEPTION);

//Mapping PHP errors to exceptions
/*
 
 function exception_error_handler($errno, $errstr, $errfile, $errline ) {
    throw new ErrorException($errstr, 0, $errno, $errfile, $errline);
}
set_error_handler("exception_error_handler");
*/
$module_path = drupal_get_path('module', 'erpaldav');
require_once($module_path. '/include/SabreDAV/vendor/autoload.php');
module_load_include('inc','erpaldav','include/erpaldav_auth_backend');

// Backends
$authBackend      = new ErpalAuthenticationBackend();
$principalBackend = new Sabre\DAVACL\PrincipalBackend\PDO($pdo, 'erpaldav_principals', 'erpaldav_groupmembers');
$carddavBackend   = new Sabre\CardDAV\Backend\PDO($pdo,'erpaldav_addressbooks', 'erpaldav_cards');
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
$server->addPlugin(new Sabre\DAVACL\Plugin());

// And off we go!
$server->exec();
die();
}