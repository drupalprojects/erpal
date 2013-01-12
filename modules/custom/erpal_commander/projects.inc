<?php

module_load_include('inc', 'node', 'node.pages');

function erpal_commander_command_addtask($args, $nid) {
    global $user;

    $details = array();
    $form_state = array();

    $node = node_load($nid);
    if (!$node) {
        $details['error'] = t('The command should to be executed on the projects page.');
        return $details;
    }

    $project_nid = _erpal_projects_helper_has_project($node);
    if (!$project_nid) {
        $details['error'] = t('The command should to be executed on the projects page.');
        return $details;
    }

    $node = (object)array(
        'type' => 'erpal_task',
        'language' => LANGUAGE_NONE
    );

    $node->field_project_ref[LANGUAGE_NONE][0]['target_id'] = $project_nid;

    if (isset($args['user'])) {
        $author = user_load_by_name($args['user']);
        if ($author === false) {
            $details['error'][] = t('Unable to get user id by provided user name.');
        } else {
//            $form_state['values']['field_task_assigned_users'][LANGUAGE_NONE][0]['target_id'] = $author->uid;
            $node->field_task_assigned_users[LANGUAGE_NONE][0]['target_id'] = $author->uid;
        }
    }

    if (isset($args['startdate'])) {
        $startdate = $args['startdate'];
//        $startdate = erpal_date_as_unix_timestamp($args['startdate']);
        if ($startdate === false) {
            $details['error'][] = t('"startdate" is malformed.');
        } else {
            $form_state['values']['field_date'][LANGUAGE_NONE][0]['value']['date'] = $startdate;
        }
    }

    if (isset($args['enddate'])) {
        $enddate = $args['enddate'];
//        $enddate = erpal_date_as_unix_timestamp($args['enddate']);
        if ($enddate === false) {
            $details['error'][] = t('"enddate" is malformed.');
        } else {
            $form_state['values']['field_date'][LANGUAGE_NONE][0]['show_todate'] = 1;
            $form_state['values']['field_date'][LANGUAGE_NONE][0]['value2']['date'] = $enddate;
        }
    }

    if (isset($args['title'])) {
        $form_state['values']['title'] = $args['title'];
    }

    if (isset($args['description'])) {
        $node->body[LANGUAGE_NONE][0]['value'] = $args['description'];
    }

    if (isset($args['priority'])) {
        $terms = taxonomy_get_term_by_name($args['priority']);
        if (count($terms) != 1) {
            $details['error'][] = t('Priority is malformed.');
        } else {
            $term = array_pop($terms);
            $form_state['values']['field_priority_term'][LANGUAGE_NONE] = $term->tid;
        }
    }

    if (isset($args['status'])) {
        $terms = taxonomy_get_term_by_name($args['status']);
        if (count($terms) != 1) {
            $details['error'][] = t('Status is malformed.');
        } else {
            $term = array_pop($terms);
            $form_state['values']['field_task_status_term'][LANGUAGE_NONE] = $term->tid;
        }
    }

    if (isset($args['estimation'])) {
        $node->field_estimated_time[LANGUAGE_NONE][0]['value'] = $args['estimation'];
    }

    if (isset($args['parent']) && is_numeric($args['parent'])) {
        $parent = $args['parent'];
        $node_parent = node_load($parent);

        if ($node_parent->type == 'erpal_task') {
            $parent_project_nid = $project_nid = _erpal_projects_helper_has_project($node_parent);
            if ($parent_project_nid == $project_nid) {
                $node->field_parent[LANGUAGE_NONE][0]['target_id'] = $parent;
            }
        }
    }

    if (isset($details['error'])) {
        return $details;
    }

    node_object_prepare($node);

    $form_state['values']['name'] = $user->name;
//        $form_state['values']['field_project_ref'][LANGUAGE_NONE][0]['target_id'] = $project_nid;
    $form_state['values']['op'] = t('Save');

    drupal_form_submit('erpal_task_node_form', $form_state, $node);

//    $details['error'] = t('The command should to be executed on the projects page2.');
//    return $details;

    $errors = form_get_errors();
    if (count($errors)) {
        foreach ($errors as $k => $v) {
            $details['error'][] = $v;
        }
    }

    if (isset($details['error'])) {
        return $details;
    }

    $details['status'] = t('New task has been successfully created.');
    return $details;
}