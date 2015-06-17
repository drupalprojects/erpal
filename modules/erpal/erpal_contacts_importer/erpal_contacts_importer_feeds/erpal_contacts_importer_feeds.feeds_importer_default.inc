<?php
/**
 * @file
 * erpal_contacts_importer_feeds.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function erpal_contacts_importer_feeds_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'erpal_contact_nodes_contact_company';
  $feeds_importer->config = array(
    'name' => 'ERPAL_Contact-Nodes-Contact_Company',
    'description' => 'Import ERPAL company contact nodes.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'csv',
        'direct' => 0,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'ID',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Contact Type',
            'target' => 'field_contact_type',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Gender',
            'target' => 'field_gender',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Company Name',
            'target' => 'field_company_name',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Image',
            'target' => 'field_contact_image',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Birthday',
            'target' => 'field_birthday:start',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'VAT Number',
            'target' => 'field_vat_number',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Other legal information',
            'target' => 'field_legal_other',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'Contact Tags',
            'target' => 'field_contact_tags',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Blank source Title',
            'target' => 'title',
            'unique' => 1,
          ),
          10 => array(
            'source' => 'Fax',
            'target' => 'erpal_contacts_importer_field_communication',
            'field_communication_type' => 'phone',
            'field_communication_category' => 'Fax',
          ),
          11 => array(
            'source' => 'Email',
            'target' => 'erpal_contacts_importer_field_communication',
            'field_communication_type' => 'mail',
            'field_communication_category' => '',
          ),
          12 => array(
            'source' => 'Website',
            'target' => 'erpal_contacts_importer_field_communication',
            'field_communication_type' => 'link',
            'field_communication_category' => 'Homepage',
          ),
          13 => array(
            'source' => 'XING',
            'target' => 'erpal_contacts_importer_field_communication',
            'field_communication_type' => 'other',
            'field_communication_category' => 'XING',
          ),
          14 => array(
            'source' => 'Facebook',
            'target' => 'erpal_contacts_importer_field_communication',
            'field_communication_type' => 'other',
            'field_communication_category' => 'Facebook',
          ),
          15 => array(
            'source' => 'Twitter',
            'target' => 'erpal_contacts_importer_field_communication',
            'field_communication_type' => 'other',
            'field_communication_category' => 'Twitter',
          ),
          16 => array(
            'source' => 'Google+',
            'target' => 'erpal_contacts_importer_field_communication',
            'field_communication_type' => 'other',
            'field_communication_category' => 'Google+',
          ),
          17 => array(
            'source' => 'Mobile',
            'target' => 'erpal_contacts_importer_field_communication',
            'field_communication_type' => 'phone',
            'field_communication_category' => 'Mobile',
          ),
          18 => array(
            'source' => 'Phone  (home)',
            'target' => 'erpal_contacts_importer_field_communication',
            'field_communication_type' => 'phone',
            'field_communication_category' => 'Home',
          ),
          19 => array(
            'source' => 'Phone (work)',
            'target' => 'erpal_contacts_importer_field_communication',
            'field_communication_type' => 'phone',
            'field_communication_category' => 'Work',
          ),
          20 => array(
            'source' => 'Street',
            'target' => 'field_addresses:field_street',
            'unique' => FALSE,
          ),
          21 => array(
            'source' => 'ZIP Code',
            'target' => 'field_addresses:field_zip_code',
            'unique' => FALSE,
          ),
          22 => array(
            'source' => 'City',
            'target' => 'field_addresses:field_city',
            'unique' => FALSE,
          ),
          23 => array(
            'source' => 'Country',
            'target' => 'field_addresses:field_country_term',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          24 => array(
            'source' => 'Bank name',
            'target' => 'field_bank_accounts:field_bank_name',
            'unique' => FALSE,
          ),
          25 => array(
            'source' => 'Bank number',
            'target' => 'field_bank_accounts:field_bank_number',
            'unique' => FALSE,
          ),
          26 => array(
            'source' => 'IBAN',
            'target' => 'field_bank_accounts:field_iban',
            'unique' => FALSE,
          ),
          27 => array(
            'source' => 'SWIFT',
            'target' => 'field_bank_accounts:field_swift',
            'unique' => FALSE,
          ),
          28 => array(
            'source' => 'Account number',
            'target' => 'field_bank_accounts:field_bank_account_number',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'erpal_contact',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['erpal_contact_nodes_contact_company'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'erpal_contact_nodes_contact_person';
  $feeds_importer->config = array(
    'name' => 'ERPAL_Contact-Nodes-Contact_Person',
    'description' => 'Import ERPAL person contact nodes.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'csv',
        'direct' => 0,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'ID',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Contact Type',
            'target' => 'field_contact_type',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Gender',
            'target' => 'field_gender',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Firstname',
            'target' => 'field_firstname',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Lastname',
            'target' => 'field_lastname',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Image',
            'target' => 'field_contact_image',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Birthday',
            'target' => 'field_birthday:start',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'VAT Number',
            'target' => 'field_vat_number',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'Other legal information',
            'target' => 'field_legal_other',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Contact Tags',
            'target' => 'field_contact_tags',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Blank source Title',
            'target' => 'title',
            'unique' => 0,
          ),
          11 => array(
            'source' => 'Fax',
            'target' => 'erpal_contacts_importer_field_communication',
            'field_communication_type' => 'phone',
            'field_communication_category' => 'Fax',
          ),
          12 => array(
            'source' => 'Email',
            'target' => 'erpal_contacts_importer_field_communication',
            'field_communication_type' => 'mail',
            'field_communication_category' => '',
          ),
          13 => array(
            'source' => 'Website',
            'target' => 'erpal_contacts_importer_field_communication',
            'field_communication_type' => 'link',
            'field_communication_category' => 'Homepage',
          ),
          14 => array(
            'source' => 'XING',
            'target' => 'erpal_contacts_importer_field_communication',
            'field_communication_type' => 'other',
            'field_communication_category' => 'XING',
          ),
          15 => array(
            'source' => 'Facebook',
            'target' => 'erpal_contacts_importer_field_communication',
            'field_communication_type' => 'other',
            'field_communication_category' => 'Facebook',
          ),
          16 => array(
            'source' => 'Twitter',
            'target' => 'erpal_contacts_importer_field_communication',
            'field_communication_type' => 'other',
            'field_communication_category' => 'Twitter',
          ),
          17 => array(
            'source' => 'Google+',
            'target' => 'erpal_contacts_importer_field_communication',
            'field_communication_type' => 'other',
            'field_communication_category' => 'Google+',
          ),
          18 => array(
            'source' => 'Mobile',
            'target' => 'erpal_contacts_importer_field_communication',
            'field_communication_type' => 'phone',
            'field_communication_category' => 'Mobile',
          ),
          19 => array(
            'source' => 'Phone  (home)',
            'target' => 'erpal_contacts_importer_field_communication',
            'field_communication_type' => 'phone',
            'field_communication_category' => 'Home',
          ),
          20 => array(
            'source' => 'Phone (work)',
            'target' => 'erpal_contacts_importer_field_communication',
            'field_communication_type' => 'phone',
            'field_communication_category' => 'Work',
          ),
          21 => array(
            'source' => 'Works at',
            'target' => 'erpal_contacts_importer_relation_works_at',
            'unique' => FALSE,
          ),
          22 => array(
            'source' => 'Relation Tags',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          23 => array(
            'source' => 'Street',
            'target' => 'field_addresses:field_street',
            'unique' => FALSE,
          ),
          24 => array(
            'source' => 'ZIP Code',
            'target' => 'field_addresses:field_zip_code',
            'unique' => FALSE,
          ),
          25 => array(
            'source' => 'City',
            'target' => 'field_addresses:field_city',
            'unique' => FALSE,
          ),
          26 => array(
            'source' => 'Country',
            'target' => 'field_addresses:field_country_term',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          27 => array(
            'source' => 'Bank name',
            'target' => 'field_bank_accounts:field_bank_name',
            'unique' => FALSE,
          ),
          28 => array(
            'source' => 'Bank number',
            'target' => 'field_bank_accounts:field_bank_number',
            'unique' => FALSE,
          ),
          29 => array(
            'source' => 'IBAN',
            'target' => 'field_bank_accounts:field_iban',
            'unique' => FALSE,
          ),
          30 => array(
            'source' => 'SWIFT',
            'target' => 'field_bank_accounts:field_swift',
            'unique' => FALSE,
          ),
          31 => array(
            'source' => 'Account number',
            'target' => 'field_bank_accounts:field_bank_account_number',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'erpal_contact',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['erpal_contact_nodes_contact_person'] = $feeds_importer;

  return $export;
}
