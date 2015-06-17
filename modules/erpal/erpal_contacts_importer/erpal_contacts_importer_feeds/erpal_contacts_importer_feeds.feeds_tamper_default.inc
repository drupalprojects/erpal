<?php
/**
 * @file
 * erpal_contacts_importer_feeds.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function erpal_contacts_importer_feeds_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-account_number-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'Account number';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_company-account_number-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-bank_name-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'Bank name';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_company-bank_name-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-bank_number-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'Bank number';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_company-bank_number-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-birthday-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'Birthday';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_company-birthday-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-blank_source_title-rewrite';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'Blank source Title';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '[company name]  ',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite';
  $export['erpal_contact_nodes_contact_company-blank_source_title-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-city-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'City';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_company-city-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-company_name-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'Company Name';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_company-company_name-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-contact_tags-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'Contact Tags';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_company-contact_tags-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-contact_type-keyword_filter';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'Contact Type';
  $feeds_tamper->plugin_id = 'keyword_filter';
  $feeds_tamper->settings = array(
    'words' => 'company',
    'word_boundaries' => 0,
    'exact' => 1,
    'case_sensitive' => 0,
    'invert' => 0,
    'word_list' => array(
      0 => '/^\\Qcompany\\E$/iu',
    ),
    'regex' => TRUE,
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Keyword filter';
  $export['erpal_contact_nodes_contact_company-contact_type-keyword_filter'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-contact_type-required';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'Contact Type';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Required field';
  $export['erpal_contact_nodes_contact_company-contact_type-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-contact_type-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'Contact Type';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_company-contact_type-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-country-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'Country';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_company-country-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-email-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'Email';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_company-email-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-facebook-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'Facebook';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_company-facebook-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-fax-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'Fax';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_company-fax-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-firstname-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'Firstname';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_company-firstname-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-gender-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'Gender';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_company-gender-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-google_-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'Google+';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_company-google_-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-iban-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'IBAN';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_company-iban-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-id-rewrite';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'ID';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '[contact type][company name]',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Rewrite';
  $export['erpal_contact_nodes_contact_company-id-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-id-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'ID';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_company-id-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-image-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'Image';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_company-image-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-lastname-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'Lastname';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_company-lastname-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-mobile-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'Mobile';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_company-mobile-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-other_legal_information-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'Other legal information';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_company-other_legal_information-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-phone___home_-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'Phone  (home)';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_company-phone___home_-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-phone__work_-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'Phone (work)';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_company-phone__work_-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-street-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'Street';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_company-street-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-swift-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'SWIFT';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_company-swift-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-twitter-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'Twitter';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_company-twitter-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-vat_number-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'VAT Number';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_company-vat_number-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-website-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'Website';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_company-website-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-xing-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'XING';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_company-xing-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_company-zip_code-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_company';
  $feeds_tamper->source = 'ZIP Code';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_company-zip_code-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-account_number-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'Account number';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-account_number-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-bank_name-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'Bank name';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-bank_name-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-bank_number-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'Bank number';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-bank_number-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-birthday-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'Birthday';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-birthday-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-blank_source_title-rewrite';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'Blank source Title';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => ' [firstname] [lastname]',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite';
  $export['erpal_contact_nodes_contact_person-blank_source_title-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-blank_source_title-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'Blank source Title';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-blank_source_title-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-city-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'City';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-city-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-company_name-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'Company Name';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-company_name-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-contact_tags-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'Contact Tags';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-contact_tags-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-contact_type-keyword_filter';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'Contact Type';
  $feeds_tamper->plugin_id = 'keyword_filter';
  $feeds_tamper->settings = array(
    'words' => 'person',
    'word_boundaries' => 0,
    'exact' => 1,
    'case_sensitive' => 0,
    'invert' => 0,
    'word_list' => array(
      0 => '/^\\Qperson\\E$/iu',
    ),
    'regex' => TRUE,
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Keyword filter';
  $export['erpal_contact_nodes_contact_person-contact_type-keyword_filter'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-contact_type-required';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'Contact Type';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Required field';
  $export['erpal_contact_nodes_contact_person-contact_type-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-contact_type-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'Contact Type';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-contact_type-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-country-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'Country';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-country-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-email-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'Email';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-email-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-facebook-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'Facebook';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-facebook-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-fax-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'Fax';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-fax-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-firstname-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'Firstname';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-firstname-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-gender-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'Gender';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-gender-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-google_-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'Google+';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-google_-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-iban-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'IBAN';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-iban-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-id-rewrite';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'ID';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '[contact type][firstname][lastname]',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Rewrite';
  $export['erpal_contact_nodes_contact_person-id-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-id-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'ID';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-id-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-image-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'Image';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-image-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-lastname-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'Lastname';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-lastname-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-mobile-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'Mobile';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-mobile-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-other_legal_information-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'Other legal information';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-other_legal_information-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-phone___home_-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'Phone  (home)';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-phone___home_-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-phone__work_-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'Phone (work)';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-phone__work_-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-relation_tags-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'Relation Tags';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-relation_tags-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-street-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'Street';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-street-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-swift-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'SWIFT';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-swift-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-twitter-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'Twitter';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-twitter-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-vat_number-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'VAT Number';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-vat_number-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-website-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'Website';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-website-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-works_at-explode';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'Works at';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Explode';
  $export['erpal_contact_nodes_contact_person-works_at-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-works_at-rewrite';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'Works at';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '[works at],[relation tags]',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Rewrite';
  $export['erpal_contact_nodes_contact_person-works_at-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-works_at-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'Works at';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-works_at-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-xing-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'XING';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-xing-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'erpal_contact_nodes_contact_person-zip_code-trim';
  $feeds_tamper->importer = 'erpal_contact_nodes_contact_person';
  $feeds_tamper->source = 'ZIP Code';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['erpal_contact_nodes_contact_person-zip_code-trim'] = $feeds_tamper;

  return $export;
}
