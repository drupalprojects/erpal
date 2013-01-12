<?php

/**
 * Callback to show commander prompt once the menu link is clicked. Handled by javascript only.
 */
function commander_prompt_show() {
}

/**
 * Renders a commander prompt form.
 */
function commander_prompt() {
    $form = drupal_get_form('commander_prompt_form');
    print drupal_render($form);

    drupal_exit();
}

/**
 * Generates a command prompt form.
 */
function commander_prompt_form() {
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
        '#attributes' => array('class' => array('commander-prompt-command')),
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
function commander_prompt_form_submit($form, &$form_state) {
    $form_state['rebuild'] = true;

    $succeed = _commander_command_arguments($form_state['values']['command'], $args);

    $commands = array();
    $commands[] = ajax_command_replace(
        '#commander-prompt-status',
        _commander_get_prompt_status_html('Command is known.', 'status')
    );

    ajax_deliver(array('#type' => 'ajax', '#commands' => $commands));
    drupal_exit();
}

/**
 * Validates command prompt form.
 */
function commander_prompt_form_validate($form, &$form_state) {
    $succeed = _commander_command_arguments($form_state['values']['command'], $args);

    if ($succeed == false) {
        $commands = array();
        $commands[] = ajax_command_replace(
            '#commander-prompt-status',
            _commander_get_prompt_status_html('Command is unknown.', 'error')
        );

        ajax_deliver(array('#type' => 'ajax', '#commands' => $commands));
        drupal_exit();
    }
}

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
function _commander_get_prompt_status_html($status, $error_class) {
    return '<div id="commander-prompt-status" class="messages ' . $error_class . '">' . $status . '</div>';
}

/**
 * Validates command, returns true if command recognized and filled args, otherwise returns false.
 */
function _commander_command_arguments($command, &$args) {
    $args = array();
    $succeed = false;

    $command = trim($command);
    preg_match_all('/[^\s|\t]+/', $command, $matches);

    if ($matches && count($matches[0]) > 0) {
        $k = strtolower($matches[0][0]);

        $callbacks = _commander_get_callbacks();
        $succeed |= array_key_exists($k, $callbacks);

        if ($succeed) {
            array_shift($matches[0]);
            $args = array('callback' => $k, 'args' => $matches[0]);
        }
    }

    return $succeed;
}

/**
 * Returns an array of the command callbacks.
 */
function _commander_get_callbacks() {
    $callbacks = array();
    foreach (module_implements('command') as $module) {
        $items = call_user_func($module . '_command');
        if (isset($items) && is_array($items)) {
            foreach (array_keys($items) as $item) {
                $items[$item]['module'] = $module;

                // Calculate out the file to be included for each callback, if any.
                if (isset($item['file'])) {
                    $file_path = isset($item['file path']) ? $item['file path'] : drupal_get_path('module', $item['module']);
                    $item['include file'] = $file_path . '/' . $item['file'];
                }
            }
            $callbacks = array_merge($callbacks, $items);
        }
    }

    return $callbacks;
}