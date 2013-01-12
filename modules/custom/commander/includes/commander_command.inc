<?php

module_load_include('inc', 'node', 'node.pages');

function commander_command_commander($args, $nid) {
    $status = array();

    if (isset($args['list'])) {
        $status['status'] = t('Lists all the commands');
    }

    return $status;
}

function commander_command_addpage($args, $nid) {
    global $user;

    $status = array();
    $form_state = array();

    if (isset($args['title'])) {
        $form_state['values']['title'] = $args['title'];
    }

    if (isset($args['description'])) {
        $form_state['values']['body']['und'][0]['value'] = $args['description'];
    }

    $node = (object)array(
        'type' => 'page',
        'language' => LANGUAGE_NONE
    );

    node_object_prepare($node);

    $form_state['values']['name'] = $user->name;
    $form_state['values']['op'] = t('Save');

    drupal_form_submit('page_node_form', $form_state, $node);
    $errors = form_get_errors();

    if (count($errors)) {
        foreach ($errors as $k => $v) {
            $status['error'][] = $v;
        }
    }

    if (!isset($status['error'])) {
        $status['status'] = t('New page has been successfully created.');
    }

    return $status;
}