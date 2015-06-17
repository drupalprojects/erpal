<?php
/**
 * This class represents a automated test for the erpal_docs_services module.
 * 
 * @package     erpal_core/erpal_docs/erpal_docs_service/tests
 * @file        ErpalDocsServiceTest.class.inc
 * @author      Marc Sven Kleinböhl
 * @copyright   2013+ © by Bright Solutions GmbH
 */

class ErpalDocsServiceTest extends ServicesWebTestCase {
  
  /**
   * Overrides ServicesWebTestCase::getInfo().
   */
  public static function getInfo() {
    return array(
      'name'        => t('ERPAL documents service'),
      'description' => t('Test cases for the ERPAL documents service.'),
      'group'       => t('ERPAL'),
    );
  }
  
  /**
   * Overrides ServicesWebTestCase::setUp().
   */
  public function setUp() {
   
    parent::setUp(
      'ctools',
      'services',
      'rest_server',
      'erpal_core',
      'erpal_docs',
      'erpal_docs_helper',
      'erpal_docs_access',
      'erpal_docs_services'
    );
    
    $account = $this->drupalCreateUser();
    $this->drupalLogin($account);
    
    return;
  }
  
  /**
   * This test case is for testing the "create" ability of the ERPAL documents service module.
   */
  public function testCreatingERPALFiles() {
    
    // Try to create an erpal_file document.
    $responseCreate = $this->servicesPost(
      '/rest/erpal_files/erpal_file', 
      array(
        'filename'  => 'test.txt', 
        'binary'    => 'VGhpcyBpcyBhIG5ldyB0ZXh0ZmlsZS4=',
        'tags'      => array(
          'test-tag-1',
          'test-tag-2',
          'test-tag-3',
        )
      )
    );
    $this->assertEqual(
      intval($responseCreate['status']),
      200,
      t('New erpal_file document successfuly created.')
    );
    
    // Try to load the previously created erpal_file document.
    $responseRetrieve = $this->servicesGet(
      $responseCreate->data['body']['url'],
      array(),
      array(
        'Accept' => 'application/json'
      )
    );
    $this->assertEqual(
      intval($responseRetrieve['status']),
      200,
      t('Previously created erpal_file document successfuly loaded.')
    );
    
    return;
  }
}

