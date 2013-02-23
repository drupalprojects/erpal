<?php

/**
 * Implements of hook_views_data().
 */
function erpal_timetracking_helper_views_data() {
  return array(
    'field_data_field_timetracking_subject' => array(
      'timetracking_subtasks' => array(
        'group' => t('Timetracking'),
        'title' => t('Show subtasks'),
        'help' => t('Get timetrackings of subtasks'),
        'filter' => array(
          'handler' => 'erpal_timetracking_helper_handler_filter_timetracking_children'
        ),
      )
    )
  );
}
