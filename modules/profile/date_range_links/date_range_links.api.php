<?php

/**
 * @file
 * Hooks provided by Date range links module.
 */

/**
 * Provides custom Date range links.
 *
 * @param string $format
 *   Format of date field.
 *
 * @return array
 *   An array of link elements.
 */
function hook_date_range_links($format) {
  $start_date = REQUEST_TIME;
  $end_date = strtotime('+3 day', $start_date);

  $links = array();
  $links[] = date_range_links_link_element(t('3 days'), $format, $start_date, $end_date);

  return $links;
}

/**
 * Alter the Date range links.
 *
 * Modules may implement this hook to alter the information that defines
 * date_range_links. All properties that are available in
 * hook_date_range_links() can be altered here.
 *
 * @param array $links
 *   The link elements array.
 *
 * @see hook_date_range_links()
 */
function hook_date_range_links_alter(array &$links) {

  // Change title of first link.
  $links[0]['#title'] = t('Now');
}
