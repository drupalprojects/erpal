<?php
/**
 * @file
 * erpal_project.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function erpal_project_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_advanced|node|erpal_timetracking|form';
  $field_group->group_name = 'group_advanced';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_timetracking';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '4',
    'children' => array(
      0 => 'field_billing_duration',
      1 => 'field_date_time',
      2 => 'field_budget',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Advanced',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_advanced|node|erpal_timetracking|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_comment_data|comment|comment_node_erpal_task|form';
  $field_group->group_name = 'group_comment_data';
  $field_group->entity_type = 'comment';
  $field_group->bundle = 'comment_node_erpal_task';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Comment Data',
    'weight' => '9',
    'children' => array(
      0 => 'group_comment_details',
      1 => 'group_comment',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_comment_data|comment|comment_node_erpal_task|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_comment_details|comment|comment_node_erpal_task|form';
  $field_group->group_name = 'group_comment_details';
  $field_group->entity_type = 'comment';
  $field_group->bundle = 'comment_node_erpal_task';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_comment_data';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '11',
    'children' => array(
      0 => 'field_commit_id',
      1 => 'comment_alter_field_date',
      2 => 'comment_alter_field_estimated_time',
      3 => 'comment_alter_field_progress_percent',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_comment_details|comment|comment_node_erpal_task|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_comment|comment|comment_node_erpal_task|form';
  $field_group->group_name = 'group_comment';
  $field_group->entity_type = 'comment';
  $field_group->bundle = 'comment_node_erpal_task';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_comment_data';
  $field_group->data = array(
    'label' => 'Comment',
    'weight' => '10',
    'children' => array(
      0 => 'comment_body',
      1 => 'comment_alter_field_priority_term',
      2 => 'comment_alter_field_task_assigned_users',
      3 => 'comment_alter_field_task_status_term',
      4 => 'comment_alter_field_task_type_term',
      5 => 'group_files',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_comment|comment|comment_node_erpal_task|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_files|comment|comment_node_erpal_task|form';
  $field_group->group_name = 'group_files';
  $field_group->entity_type = 'comment';
  $field_group->bundle = 'comment_node_erpal_task';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_comment';
  $field_group->data = array(
    'label' => 'Files',
    'weight' => '12',
    'children' => array(
      0 => 'comment_alter_field_asset_files',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Files',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-files field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_files|comment|comment_node_erpal_task|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_form_advanced|node|erpal_project|form';
  $field_group->group_name = 'group_project_form_advanced';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '7',
    'children' => array(
      0 => 'field_activity_ref',
      1 => 'field_project_contacts',
      2 => 'path',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Advanced',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-advanced',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_project_form_advanced|node|erpal_project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_form_basics|node|erpal_project|form';
  $field_group->group_name = 'group_project_form_basics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basics',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_customer_ref',
      2 => 'field_date',
      3 => 'field_estimated_time',
      4 => 'field_project_tags',
      5 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Basics',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-project',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_project_form_basics|node|erpal_project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_form_files|node|erpal_project|form';
  $field_group->group_name = 'group_project_form_files';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Files',
    'weight' => '3',
    'children' => array(
      0 => 'field_asset_files',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Files',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-file',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_project_form_files|node|erpal_project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_form_pricing|node|erpal_project|form';
  $field_group->group_name = 'group_project_form_pricing';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Pricing',
    'weight' => '2',
    'children' => array(
      0 => 'field_pricing',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Pricing',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-pricing',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_project_form_pricing|node|erpal_project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_form_progress|node|erpal_project|form';
  $field_group->group_name = 'group_project_form_progress';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Progress',
    'weight' => '1',
    'children' => array(
      0 => 'field_priority_term',
      1 => 'field_project_status_term',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Progress',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-progress',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_project_form_progress|node|erpal_project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_form_specs|node|erpal_project|form';
  $field_group->group_name = 'group_project_form_specs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Specification',
    'weight' => '5',
    'children' => array(
      0 => 'field_books_ref',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Specification',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-specs',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_project_form_specs|node|erpal_project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_form_team|node|erpal_project|form';
  $field_group->group_name = 'group_project_form_team';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Team',
    'weight' => '4',
    'children' => array(
      0 => 'field_project_team',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Team',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-team',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_project_form_team|node|erpal_project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_task_form_advanced|node|erpal_task|form';
  $field_group->group_name = 'group_task_form_advanced';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_task';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '4',
    'children' => array(
      0 => 'field_parent',
      1 => 'field_project_ref',
      2 => 'field_task_exclude_from',
      3 => 'field_depends_on_tasks',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Advanced',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-advanced',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_task_form_advanced|node|erpal_task|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_task_form_basics|node|erpal_task|form';
  $field_group->group_name = 'group_task_form_basics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_task';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basics',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_date',
      2 => 'field_estimated_time',
      3 => 'field_project_tags',
      4 => 'field_task_type_term',
      5 => 'field_is_ticket',
      6 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Basics',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-task',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_task_form_basics|node|erpal_task|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_task_form_files|node|erpal_task|form';
  $field_group->group_name = 'group_task_form_files';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_task';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Files',
    'weight' => '3',
    'children' => array(
      0 => 'field_asset_files',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Files',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-file',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_task_form_files|node|erpal_task|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_task_form_pricing|node|erpal_task|form';
  $field_group->group_name = 'group_task_form_pricing';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_task';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Pricing',
    'weight' => '2',
    'children' => array(
      0 => 'field_pricing',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Pricing',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-pricing',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_task_form_pricing|node|erpal_task|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_task_form_progress|node|erpal_task|form';
  $field_group->group_name = 'group_task_form_progress';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_task';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Progress',
    'weight' => '1',
    'children' => array(
      0 => 'field_progress_percent',
      1 => 'field_task_assigned_users',
      2 => 'field_task_status_term',
      3 => 'field_priority_term',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Progress',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-progress',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_task_form_progress|node|erpal_task|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_urls|node|erpal_project|form';
  $field_group->group_name = 'group_urls';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'URL locations',
    'weight' => '6',
    'children' => array(
      0 => 'field_commit_deeplink_url',
      1 => 'field_development_url',
      2 => 'field_live_url',
      3 => 'field_repository_url',
      4 => 'field_stage_url',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'URL locations',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-url',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_urls|node|erpal_project|form'] = $field_group;

  return $export;
}
