<?php
/**
 * @file
 * Functions to output links of date range.
 */

/**
 * Returns link element to chose current day.
 *
 * @param string $date
 *   Date.
 * @param string $format
 *   Date format.
 *
 * @return array
 *   Array containing link element.
 */
function _date_range_links_get_range_today($date, $format) {

  return date_range_links_link_element(t('Today'), $format, $date, $date);
}

/**
 * Returns link element to chose current week.
 *
 * @param string $date
 *   Date.
 * @param string $format
 *   Date format.
 *
 * @return array
 *   Array containing link element.
 */
function _date_range_links_get_range_this_week($date, $format) {

  // Get Last Monday.
  $start_date = $date;
  if (format_date($date, 'custom', 'D') != 'Mon') {
    $start_date = strtotime('last Monday', $date);
  }

  // Get Next Sunday.
  $end_date = $date;
  if (format_date($date, 'custom', 'D') != 'Sun') {
    $end_date = strtotime('next Sunday', $date);
  }

  return date_range_links_link_element(t('This week'), $format, $start_date, $end_date);
}

/**
 * Returns link element to chose current month.
 *
 * @param string $date
 *   Date.
 * @param string $format
 *   Date format.
 *
 * @return array
 *   Array containing link element.
 */
function _date_range_links_get_range_this_month($date, $format) {
  $start_date = strtotime('first day of this month', $date);
  $end_date = strtotime('last day of this month', $date);

  return date_range_links_link_element(t('This month'), $format, $start_date, $end_date);
}
