<?php

/**
 * @file
 * Helper test case for using an existing fixture database
 */

/**
 * Use an existing fixture database for testing.
 */
class DrupalFixtureTestCase extends DrupalWebTestCase {
  
  protected function setUp() {
    // copied from DrupalWebTestCase::setup() and modified
    
    global $user, $language, $conf;
  
    // How this works:
    // - there needs to be a valid prefix like 'simpletest123456',
    // - the prefix will get passed along with the user agent header information
    // - Drupal will look for 'simpletest..' in the header and use it as db prefix
    //   for requests during testing (SimpleTest & Selenium)
    // => fixture db tables must all be prefixed too!
    
    // Retrieve the static prefix parameter stored in the fixture db info in settings.php
    $fixturedb_connection = Database::getConnectionInfo('fixture');
    $this->databasePrefix = $fixturedb_connection['default']['simpletest_prefix'];

    db_update('simpletest_test_id')
      ->fields(array('last_prefix' => $this->databasePrefix))
      ->condition('test_id', $this->testId)
      ->execute();
    
    // Prepare switch to fixture database
    Database::renameConnection('default', 'simpletest_original_default');
    foreach ($fixturedb_connection as $target => $value) {
      $fixturedb_connection[$target]['prefix'] = array(
        'default' => $value['prefix']['default'] . $this->databasePrefix,
      );
    }    
    Database::addConnectionInfo('default', 'default', $fixturedb_connection['default']);
    
    // Store necessary current values before switching to the fixture database.
    $this->originalLanguage = $language;
    $this->originalLanguageDefault = variable_get('language_default');
    $this->originalFileDirectory = variable_get('file_public_path', conf_path() . '/files');
    $this->originalProfile = drupal_get_profile();
    $this->removeTables = variable_get('simpletest_remove_tables', TRUE);
    $clean_url_original = variable_get('clean_url', 0);

    // Save and clean shutdown callbacks array because it static cached and
    // will be changed by the test run. If we don't, then it will contain
    // callbacks from both environments. So testing environment will try
    // to call handlers from original environment.
    $callbacks = &drupal_register_shutdown_function();
    $this->originalShutdownCallbacks = $callbacks;
    $callbacks = array();

    // Create test directory ahead of installation so fatal errors and debug
    // information can be logged during installation process.
    // Use temporary files directory with the same prefix as the database.
    $public_files_directory  = $this->originalFileDirectory . '/simpletest/' . substr($this->databasePrefix, 10);
    $private_files_directory = $public_files_directory . '/private';
    $temp_files_directory    = $private_files_directory . '/temp';

    // Create the directories
    file_prepare_directory($public_files_directory, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
    file_prepare_directory($private_files_directory, FILE_CREATE_DIRECTORY);
    file_prepare_directory($temp_files_directory, FILE_CREATE_DIRECTORY);
    $this->generatedTestFiles = FALSE;

    // Log fatal errors.
    ini_set('log_errors', 1);
    ini_set('error_log', $public_files_directory . '/error.log');

    // Reset all statics and variables to perform tests in a clean environment.
    $conf = array();
    drupal_static_reset();

    // Set the test information for use in other parts of Drupal.
    $test_info = &$GLOBALS['drupal_test_info'];
    $test_info['test_run_id'] = $this->databasePrefix;
    $test_info['in_child_site'] = FALSE;

    // Rebuild caches.
    // TODO time-consuming. Do we need this?
    // drupal_static_reset();
    // drupal_flush_all_caches();

    // Register actions declared by any modules.
    actions_synchronize();

    // Reload global $conf array and permissions.
    $this->refreshVariables();
    $this->checkPermissions(array(), TRUE);

    // Reset statically cached schema for new database prefix.
    drupal_get_schema(NULL, TRUE);

    // Run cron once in that environment, as install.php does at the end of
    // the installation process.
    // TODO time-consuming. Do we need this?
    // drupal_cron_run();

    // Log in with a clean $user.
    $this->originalUser = $user;
    drupal_save_session(FALSE);
    $user = user_load(1);
    
    // TODO time-consuming. Do we need this?
    // $this->setUpVariables($clean_url_original);

    // Set up English language.
    unset($GLOBALS['conf']['language_default']);
    $language = language_default();

    // Use the test mail class instead of the default mail handler class.
    variable_set('mail_system', array('default-system' => 'TestingMailSystem'));

    drupal_set_time_limit($this->timeLimit);
  }
  
  /**
   * Delete created files and temporary files directory, delete the tables created by setUp(),
   * and reset the database prefix.
   */
  protected function tearDown() {
    // copied from DrupalWebTestCase::tearDown() and modified
    global $user, $language;

    // In case a fatal error occured that was not in the test process read the
    // log to pick up any fatal errors.
    simpletest_log_read($this->testId, $this->databasePrefix, get_class($this), TRUE);

    $emailCount = count(variable_get('drupal_test_email_collector', array()));
    if ($emailCount) {
      $message = format_plural($emailCount, '1 e-mail was sent during this test.', '@count e-mails were sent during this test.');
      $this->pass($message, t('E-mail'));
    }

    // Delete temporary files directory.
    file_unmanaged_delete_recursive($this->originalFileDirectory . '/simpletest/' . substr($this->databasePrefix, 10));

    // Get back to the original connection.
    Database::removeConnection('default');
    Database::renameConnection('simpletest_original_default', 'default');

    // Restore original shutdown callbacks array to prevent original
    // environment of calling handlers from test run.
    $callbacks = &drupal_register_shutdown_function();
    $callbacks = $this->originalShutdownCallbacks;

    // Return the user to the original one.
    $user = $this->originalUser;
    drupal_save_session(TRUE);

    // Ensure that internal logged in variable and cURL options are reset.
    $this->loggedInUser = FALSE;
    $this->additionalCurlOptions = array();

    // Reload module list and implementations to ensure that test module hooks
    // aren't called after tests.
    module_list(TRUE);
    module_implements('', FALSE, TRUE);

    // Reset the Field API.
    field_cache_clear();

    // Rebuild caches.
    $this->refreshVariables();

    // Reset language.
    $language = $this->originalLanguage;
    if ($this->originalLanguageDefault) {
      $GLOBALS['conf']['language_default'] = $this->originalLanguageDefault;
    }

    // Close the CURL handler.
    $this->curlClose();
  }
}