<?php
/**
 * @file
 * erpal_mail.finder_default.inc
 */

/**
 * Implements hook_finder_default_finders().
 */
function erpal_mail_finder_default_finders() {
  $export = array();

  $finder = new finder();
  $finder->disabled = FALSE; /* Edit this to true to make a default finder disabled initially */
  $finder->api_version = 2;
  $finder->name = 'erpal_task_or_activity_finder';
  $finder->views_view = 'erpal_tasks_and_activities';
  $finder->views_display = 'page_1';
  $finder->title = 'Erpal Task or Activity finder';
  $finder->description = '';
  $finder->path = 'erpal_task_or_activity_finder';
  $finder->block = TRUE;
  $finder->status = TRUE;
  $finder->settings = array(
    'block' => TRUE,
    'form_on_page' => TRUE,
    'find_button' => TRUE,
    'find_text' => 'Find',
    'go_text' => 'Go',
    'ajax_effect' => 'none',
    'show_results' => 'completed',
    'results_style' => 'views',
    'no_results' => 'default',
    'pager' => 10,
    'redirect' => 'never',
    'element_logic' => 'AND',
    'url' => 'enabled',
    'url_delimiter' => ',',
  );
  $finder->elements = array(
    'find_tasks_and_activities' => (object) array(
      'id' => 'find_tasks_and_activities',
      'finder' => 'erpal_task_or_activity_finder',
      'settings' => array(
        'field_logic' => 'OR',
        'value_logic' => 'AND',
        'match' => 'e',
        'max_suggestions' => 10,
        'autocomplete_field_logic' => 'OR',
        'autocomplete_value_logic' => 'OR',
        'autocomplete_match' => 'c',
        'fields' => array(
          'node.title' => (object) array(
            'table' => 'node',
            'field' => 'title',
            'relationship' => NULL,
            'format' => 'filter_xss',
          ),
        ),
        'choice_display' => 'rendered',
        'choices_style' => 'used_values',
        'available_options' => 'test|jojojo',
        'available_options_php' => '',
        'choices_rewrite' => '',
        'value_rewrite' => '<?php
return $row->node_title.\' (\'.$row->nid.\')\';',
      ),
      'weight' => 0,
      'title' => 'Find Tasks and Activities',
      'parent' => '',
      'element' => 'autocomplete',
    ),
  );
  $export['erpal_task_or_activity_finder'] = $finder;

  return $export;
}
