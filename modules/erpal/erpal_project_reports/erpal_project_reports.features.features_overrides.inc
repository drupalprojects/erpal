<?php
/**
 * @file
 * erpal_project_reports.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function erpal_project_reports_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: page_manager_pages
  $overrides["page_manager_pages.reports.default_handlers|page_reports_panel_context_2"] = (object) array(
      'disabled' => FALSE,
      'api_version' => 1,
      'name' => 'page_reports_panel_context_2',
      'task' => 'page',
      'subtask' => 'reports',
      'handler' => 'panel_context',
      'weight' => 1,
      'conf' => array(
        'title' => 'Project Reports',
        'no_blocks' => 1,
        'pipeline' => 'standard',
        'body_classes_to_remove' => '',
        'body_classes_to_add' => '',
        'css_id' => '',
        'css' => '',
        'contexts' => array(),
        'relationships' => array(),
        'access' => array(
          'plugins' => array(
            0 => array(
              'name' => 'string_equal',
              'settings' => array(
                'operator' => '=',
                'value' => 'project',
                'case' => 0,
              ),
              'context' => 'argument_string_1',
              'not' => FALSE,
            ),
          ),
          'logic' => 'and',
        ),
        'display' => unserialize('O:14:"panels_display":16:{s:4:"args";a:0:{}s:7:"content";a:1:{s:40:"new-2df00bd0-a967-5a14-a5d5-09cdf9208046";O:8:"stdClass":14:{s:3:"pid";s:40:"new-2df00bd0-a967-5a14-a5d5-09cdf9208046";s:5:"panel";s:18:"sidebar_first_left";s:4:"type";s:5:"block";s:7:"subtype";s:29:"quicktabs-project_report_tabs";s:5:"shown";b:1;s:6:"access";a:0:{}s:13:"configuration";a:2:{s:14:"override_title";i:0;s:19:"override_title_text";s:0:"";}s:5:"cache";a:0:{}s:5:"style";a:1:{s:8:"settings";N;}s:3:"css";a:0:{}s:6:"extras";a:0:{}s:8:"position";i:0;s:5:"locks";a:0:{}s:4:"uuid";s:36:"2df00bd0-a967-5a14-a5d5-09cdf9208046";}}s:6:"panels";a:1:{s:18:"sidebar_first_left";a:1:{i:0;s:40:"new-2df00bd0-a967-5a14-a5d5-09cdf9208046";}}s:16:"incoming_content";N;s:6:"css_id";N;s:7:"context";a:0:{}s:3:"did";s:3:"new";s:8:"renderer";s:8:"standard";s:6:"layout";s:20:"erpal_content_layout";s:15:"layout_settings";a:0:{}s:14:"panel_settings";a:1:{s:14:"style_settings";a:2:{s:7:"default";N;s:6:"middle";N;}}s:5:"cache";a:0:{}s:5:"title";s:15:"Project Reports";s:4:"uuid";s:36:"41987fe2-3b60-ecd4-fd04-52a676ba4a0e";s:10:"hide_title";i:0;s:10:"title_pane";s:1:"0";}'),
      ),
    );

 return $overrides;
}
