<?php
/**
 * @file
 * erpal_crm_reports.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function erpal_crm_reports_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: page_manager_pages
  $overrides["page_manager_pages.reports.default_handlers|page_reports_panel_context"] = (object) array(
      'disabled' => FALSE,
      'api_version' => 1,
      'name' => 'page_reports_panel_context',
      'task' => 'page',
      'subtask' => 'reports',
      'handler' => 'panel_context',
      'weight' => 0,
      'conf' => array(
        'title' => 'CRM Reports',
        'no_blocks' => 1,
        'pipeline' => 'standard',
        'body_classes_to_remove' => '',
        'body_classes_to_add' => '',
        'css_id' => '',
        'css' => '',
        'contexts' => array(),
        'relationships' => array(),
        'access' => array(
          'logic' => 'and',
          'plugins' => array(
            1 => array(
              'name' => 'string_equal',
              'settings' => array(
                'operator' => '=',
                'value' => 'crm',
                'case' => 0,
              ),
              'context' => 'argument_string_1',
              'not' => FALSE,
            ),
          ),
        ),
        'display' => unserialize('O:14:"panels_display":16:{s:4:"args";a:0:{}s:7:"content";a:2:{s:40:"new-fa48df8b-e9dd-49b7-bef7-3bd2ec90110b";O:8:"stdClass":13:{s:3:"pid";s:40:"new-fa48df8b-e9dd-49b7-bef7-3bd2ec90110b";s:5:"panel";s:19:"sidebar_first_right";s:4:"type";s:12:"page_actions";s:7:"subtype";s:12:"page_actions";s:5:"shown";b:1;s:6:"access";a:0:{}s:13:"configuration";a:0:{}s:5:"cache";a:0:{}s:3:"css";a:0:{}s:6:"extras";a:0:{}s:8:"position";i:0;s:5:"locks";a:0:{}s:4:"uuid";s:36:"fa48df8b-e9dd-49b7-bef7-3bd2ec90110b";}s:40:"new-5f371012-2225-daa4-7926-06738368d2fe";O:8:"stdClass":13:{s:3:"pid";s:40:"new-5f371012-2225-daa4-7926-06738368d2fe";s:5:"panel";s:19:"sidebar_second_left";s:4:"type";s:5:"block";s:7:"subtype";s:25:"quicktabs-crm_report_tabs";s:5:"shown";b:1;s:6:"access";a:0:{}s:13:"configuration";s:0:"";s:5:"cache";a:0:{}s:3:"css";a:0:{}s:6:"extras";a:0:{}s:8:"position";i:0;s:5:"locks";a:0:{}s:4:"uuid";s:36:"5f371012-2225-daa4-7926-06738368d2fe";}}s:6:"panels";a:2:{s:19:"sidebar_first_right";a:1:{i:0;s:40:"new-fa48df8b-e9dd-49b7-bef7-3bd2ec90110b";}s:19:"sidebar_second_left";a:1:{i:0;s:40:"new-5f371012-2225-daa4-7926-06738368d2fe";}}s:16:"incoming_content";N;s:6:"css_id";N;s:7:"context";a:0:{}s:3:"did";s:3:"new";s:8:"renderer";s:8:"standard";s:6:"layout";s:20:"erpal_content_layout";s:15:"layout_settings";a:0:{}s:14:"panel_settings";a:1:{s:14:"style_settings";a:5:{s:7:"default";N;s:18:"sidebar_first_left";N;s:19:"sidebar_first_right";N;s:19:"sidebar_second_left";N;s:20:"sidebar_second_right";N;}}s:5:"cache";a:0:{}s:5:"title";s:11:"CRM Reports";s:4:"uuid";s:36:"a49f290f-4ec0-8424-5d0f-4915236294fc";s:10:"hide_title";i:0;s:10:"title_pane";s:1:"0";}'),
      ),
    );

 return $overrides;
}
