<?php

/**
 * @file
 * JQuery jQuery UI MultiSelect Widget admin/configuration functionality.
 */

/**
 * jquery_ui_multiselect_widget.admin settings form.
 */
function jquery_ui_multiselect_widget_settings_form() {
  $module_path = drupal_get_path('module', 'jquery_ui_multiselect_widget');
  // Selector
  $form['jquery_ui_multiselect_widget_multiple'] = array(
    '#type' => 'checkbox',
    '#title' => t('Multiple ([multiple=multiple]) selects only'),
    '#description' => t(
      "Only use jQuery UI MultiSelect Widget on select's with attribute '[multiple=multiple]' activated (select multiple values). Leave single selects untouched."),
    '#default_value' => variable_get('jquery_ui_multiselect_widget_multiple',
      FALSE));
  $form['jquery_ui_multiselect_widget_filter'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use Filter functionality'),
    '#description' => t(
      "Uses the additional !filterplugin functionality to let the user search in the selectable values for easier selection.",
      array(
        '!filterplugin' => l(t('Filter Plugin'),
          'http://www.erichynds.com/examples/jquery-ui-multiselect-widget/demos/index.htm#filter'))),
    '#default_value' => variable_get('jquery_ui_multiselect_widget_filter',
      FALSE));
  // Filter Settings
  $form['jquery_ui_multiselect_widget_filter_width'] = array(
    '#type' => 'textfield',
    '#size' => 5,
    '#title' => t('Filter: Width'),
    '#required' => FALSE,
    '#description' => t(
      "The width of the input in pixels. Defaults to '100' (px) in the style sheet, but you can override this for each instance."),
    '#default_value' => variable_get(
      'jquery_ui_multiselect_widget_filter_width'),
    '#states' => array(
      'visible' => array(
        "input[name='jquery_ui_multiselect_widget_filter']" => array(
          'checked' => TRUE))));
  $form['jquery_ui_multiselect_widget_filter_auto_reset'] = array(
    '#type' => 'checkbox',
    '#title' => t('Filter: Auto Reset'),
    '#required' => FALSE,
    '#description' => t(
      "A boolean value denoting whether or not to reset the search box & any filtered options when the widget closes. Defaults to false."),
    '#default_value' => variable_get(
      'jquery_ui_multiselect_widget_filter_auto_reset', FALSE),
    '#states' => array(
      'visible' => array(
        "input[name='jquery_ui_multiselect_widget_filter']" => array(
          'checked' => TRUE))));

  $form['jquery_ui_multiselect_widget_subselector'] = array(
    '#type' => 'textfield',
    '#title' => t('JQuery subselector'),
    '#description' => t(
      "You may optionally use this subselector to reduce the '&lt;select&gt;' DOM context which to use jQuery UI Multiselect Widget on. For example add '.my-select' to only use for selects with this class."),
    '#required' => FALSE,
    '#default_value' => variable_get('jquery_ui_multiselect_widget_subselector',
      ''));

  // Options
  $form['jquery_ui_multiselect_widget_header'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display Header'),
    '#description' => t(
      "Either a boolean value denoting whether or not to display the header, or a string value. If you pass a string, the default “check all”, “uncheck all”, and “close” links will be replaced with the specified text."),
    '#default_value' => variable_get('jquery_ui_multiselect_widget_header',
      TRUE));

  $form['jquery_ui_multiselect_widget_autoOpen'] = array(
    '#type' => 'checkbox',
    '#title' => t('Automatically open on init'),
    '#description' => t(
      "Automatically open the menu when the widget has been initialized."),
    '#default_value' => variable_get('jquery_ui_multiselect_widget_autoOpen',
      TRUE));

  $form['jquery_ui_multiselect_widget_height'] = array(
    '#type' => 'textfield',
    '#size' => 5,
    '#title' => t('Height'),
    '#required' => TRUE,
    '#description' => t(
      "Height of the checkbox container (scroll area) in pixels. If set to “auto”, the height will calculate based on the number of checkboxes in the menu."),
    '#default_value' => variable_get('jquery_ui_multiselect_widget_height'));

  $form['jquery_ui_multiselect_widget_classes'] = array(
    '#type' => 'textfield',
    '#title' => t('Additional classes'),
    '#description' => t(
      "Additional class(es) to apply to BOTH the button and menu for further customization. Separate multiple classes
with a space."),
    '#required' => FALSE,
    '#default_value' => variable_get('jquery_ui_multiselect_widget_classes', ''));

  return system_settings_form($form);
}