<?php

require_once (dirname(__FILE__) . '/commander_core.inc');

define('COMMANDER_FRONT_INC', basename(dirname(__FILE__)) . '/' . basename(__FILE__));

/**
 * Callback to show commander prompt once the menu link is clicked. Handled by javascript only.
 */
function commander_front_prompt_show() {
}

/**
 * Renders a commander prompt form.
 */
function commander_front_prompt() {
    $nid = isset($_GET['nid']) ? $_GET['nid'] : (isset($_POST['nid']) ? $_POST['nid'] : "");

    $form = drupal_get_form('commander_front_prompt_form', $nid);
    print drupal_render($form);

    drupal_exit();
}

/**
 * Generates a command prompt form.
 */
function commander_front_prompt_form() {
    $args = func_get_args();
    $nid = $args[1]['build_info']['args'][0];

    $form = array();
    $form['commander']['prompt'] = array(
        '#tree' => false,
        '#prefix' => '<div id="commander-prompt">',
        '#suffix' => '</div>',
        '#attributes' => array('class' => array('commander-prompt')),
    );

    $form['commander']['prompt']['status'] = array(
        '#tree' => false,
        '#prefix' => '<div id="commander-prompt-status"></div>',
        '#attributes' => array('class' => array('commander-prompt-status')),
    );

    $form['commander']['prompt']['command'] = array(
        '#type' => 'textfield',
        '#maxlength' => 500,
        '#size' => 80,
        '#attributes' => array('class' => array('commander-prompt-command')),
    );

    $form['commander']['prompt']['nid'] = array(
        '#type' => 'hidden',
        '#value' => $nid
    );

    $form['commander']['prompt']['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Run'),
        '#attributes' => array('class' => array('use-ajax-submit', 'commander-prompt-run')),
    );

    $form['commander']['prompt']['close'] = array(
        '#type' => 'button',
        '#value' => t('Close'),
        '#attributes' => array('class' => array('commander-prompt-close')),
    );

    return $form;
}


/**
 * Processes submission of the command prompt form.
 */
function commander_front_prompt_form_submit($form, &$form_state) {
    $form_state['rebuild'] = true;

    $commands = array();
    $details = _commander_core_execute_command($form_state['values']['command'], is_numeric($form_state['values']['nid']) ? $form_state['values']['nid'] : null, $args);

    foreach ($details as $k => $v) {
        if (is_array($v)) {
            foreach ($v as $item) {
                drupal_set_message($item, $k);
            }
        } else {
            drupal_set_message($v, $k);
        }
    }

    $html = '';
    $messages = drupal_get_messages('error');
    foreach ($messages['error'] as $message) {
        $html .= _commander_front_get_prompt_status_record($message, 'error');
    }

    $messages = drupal_get_messages('status');
    foreach ($messages['status'] as $message) {
        $html .= _commander_front_get_prompt_status_record($message, 'status');
    }

    $commands[] = ajax_command_replace('#commander-prompt-status', _commander_front_get_prompt_status_html($html));

    ajax_deliver(array('#type' => 'ajax', '#commands' => $commands));
    drupal_exit();
}

/**
 * Validates command prompt form.
 */
//function commander_front_prompt_form_validate($form, &$form_state) {
//    $succeed = _commander_core_match_command($form_state['values']['command'], $args);
//
//    if ($succeed == false) {
//        $commands = array();
//
//        $commands[] = ajax_command_replace(
//            '#commander-prompt-status',
//            _commander_front_get_prompt_status_html($args['error'], 'error')
//        );
//
//        ajax_deliver(array('#type' => 'ajax', '#commands' => $commands));
//        drupal_exit();
//    }
//}

/**
 * Implements command.
 */
function commander_echo($args) {
}

/**
 * Implements command.
 */
function commander_hello($args) {
}

/**
 * Get the prompt status html code.
 */
function _commander_front_get_prompt_status_html($html) {
//    strip_tags($status)
    return '<div id="commander-prompt-status">' . $html . '</div>';
}

function _commander_front_get_prompt_status_record($message, $error_class) {
    return '<div class="messages ' . $error_class . '">' . $message . '</div>';
}