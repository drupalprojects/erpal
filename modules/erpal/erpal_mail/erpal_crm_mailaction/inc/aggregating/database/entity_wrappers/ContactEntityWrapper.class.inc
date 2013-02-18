<?php
/**
 * @author    Marc Sven Kleinboehl
 * @created   12/01/2012
 * @copyright 2012 © Bright Solutions GmbH 
 * 
 * This is a simple wrapper for creating contact nodes for the type "person".
 */

namespace erpal_crm_mailaction\aggregating\database\entity_wrappers;

class ContactEntityWrapper extends EntityWrapperBase {

  /**
   * Default values for the wrapped node entity.
   */
  const ENTITY_TYPE   = 'erpal_contact';
  const ENTITY_AUTHOR = 1;

  /**
   * CTor.
   * 
   * @param   string    $firstName    The first name of the contact.
   * @param   string    $lastName     The last name of the contact.
   * @param   string    $emailAddress The email address of the contact.
   */
  public function __construct ($firstName, $lastName, $emailAddress) {

    $this->initEntity (self::ENTITY_TYPE, self::ENTITY_AUTHOR);
    
    $this->createPropertyValue ('title', $firstName . ' ' . $lastName);
    $this->createEntitySimpleValue ('field_contact_type', 'person');
    $this->createEntitySimpleValue ('field_contact_firstname', $firstName);
    $this->createEntitySimpleValue ('field_contact_lastname', $lastName);
    $this->createEntitySimpleValue ('field_contact_firstname', $firstName);
    $this->createEntitySimpleValue ('field_email', $emailAddress); 
    
    return;
  }
  
  /**
   * Implements EntityWrapper::save ().
   */
  public function save () {

    return $this->saveEntity ();
  }
}
