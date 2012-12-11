<?php

function command_prompt_show() {
}

function command_prompt() {
    $form = drupal_get_form('command_prompt_form');
    print drupal_render($form);

    drupal_exit();
}

function command_prompt_form() {
    $form = array();

    $form['command']['prompt'] = array(
        '#tree' => FALSE,
        '#prefix' => '<div id="command-prompt">',
        '#suffix' => '</div>',
        '#attributes' => array('class' => array('command-prompt')),
    );

    $form['command']['prompt']['status'] = array(
        '#tree' => FALSE,
        '#prefix' => '<div id="command-prompt-status"></div>',
        '#attributes' => array('class' => array('command-prompt-status')),
    );

    $form['command']['prompt']['command'] = array(
        '#type' => 'textfield',
        '#attributes' => array('class' => array('command-prompt-command')),
    );

    $form['command']['prompt']['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Run'),
        '#attributes' => array('class' => array('use-ajax-submit', 'command-prompt-run')),
    );

    $form['command']['prompt']['close'] = array(
        '#type' => 'button',
        '#value' => t('Close'),
        '#attributes' => array('class' => array('command-prompt-close')),
    );

    return $form;
}

function command_prompt_form_submit($form, &$form_state) {
    $form_state['rebuild'] = TRUE;

    $commands = array();
    $commands[] = ajax_command_replace(
        '#command-prompt-status',
        '<div id="command-prompt-status" class="messages status">Command executed successfully.</div> '
    );

    ajax_deliver(array('#type' => 'ajax', '#commands' => $commands));
    drupal_exit();
}

function command_prompt_form_validate($form, &$form_state) {
    if (strlen(trim($form_state['values']['command'])) == 0) {
        $errors = 'Command is unknown.';
    }

    if (!empty($errors)) {
        $commands = array();
        $commands[] = ajax_command_replace(
            '#command-prompt-status',
            '<div id="command-prompt-status" class="messages error">' . $errors . '</div>'
        );

        ajax_deliver(array('#type' => 'ajax', '#commands' => $commands));
        drupal_exit();
    }
}