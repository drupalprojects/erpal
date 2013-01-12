<?php

/**
 * @author Roman Sztyler
 * @created 13/12/12
 * @copyright 2012 © Bright Solutions GmbH - All rights reserved.
 *
 * This class extends the standard CardDAV Backend and adds some useful
 * functionality for the integration in ERPAL 
 *  
 */

module_load_include('php', 'erpal_dav', 'include/SabreDAV/vendor/autoload');
 
class ErpalContactBackend extends \Sabre\CardDAV\Backend\PDO{
 
   	
  protected static $instance = NULL;
	
  
 /**
  * Uses parent constructor
  */
  public function __construct(\PDO $pdo, $addressBooksTableName = 'erpal_dav_addressbooks', $cardsTableName = 'erpal_dav_cards') {
    parent::__construct($pdo, $addressBooksTableName, $cardsTableName);
  }

  /**
   * Returns an array keyed by the carduris in an addressbook with the timestamps
   * of their last modifications as values
   */
  public function getCardUrisandTimes($addressbookid) {
    $result = db_select($this->cardsTableName, 'edt')
    ->fields('edt', array('uri','lastmodified'))
    ->condition('addressbookid', $addressbookid)
    ->execute();
    return $result->fetchAllAssoc('uri');
  }

   
  /**
   * Returns an instance of the class
   */
  public static function getInstance() {
  	if (!self::$instance) self::$instance = new ErpalContactBackend(Database::getConnection());
	return self::$instance;
  }
}
