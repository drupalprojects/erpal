<?php

define('FILEEDIT_PERMISSION_ACCESS_FILEEDIT', 'access filedit');

define('FILEEDIT_URL_PATTERN_DOWNLOAD', 'fileedit/download/%/%');
define('FILEEDIT_URL_PATTERN_UPLOAD', 'fileedit/upload/%/%');
define('FILEEDIT_URL_PATTERN_APPLET', 'fileedit/monitor');

/**
 * Callback for applet page.
 */
function fileedit_monitor() {
    $out = theme('fileedit_applet', array('args' => array('fileedit_codebase' => url(drupal_get_path('module', 'fileedit') . '/assets/jar/'))));
    die ($out);
}

/**
 * Callback for downloading file.
 */
function fileedit_download($fid, $sid) {
    $file_usage = null;

    // look for the single node where the file is used.
    $result = db_select('file_usage', 'f')
        ->fields('f', array('fid', 'module', 'type', 'id', 'count'))
        ->condition('fid', $fid)
        ->condition('type', 'node')
        ->condition('count', 0, '>')
        ->range(0, 1)
        ->execute();

    foreach ($result as $usage) {
        $file_usage = $usage;
    }

    // look for the recent fid for the specified node, assuming the id represents the node type as file.
    $query = db_select('file_usage', 'f')
        ->fields('f', array('fid', 'module', 'type', 'id', 'count'))
        ->condition('id', $file_usage->id)
        ->condition('type', 'node')
        ->condition('count', 0, '>')
        ->range(0, 1);
    $query->addExpression('MAX(fid)', 'lid');
    $result = $query->execute();

    foreach ($result as $usage) {
        $file_usage = $usage;
    }

    $file = file_load($file_usage->lid);

    $headers = array(
        'Content-Type' => 'force-download',
        'Content-Disposition' => 'attachment; filename="' . $file->filename . '"',
        'Content-Length' => $file->filesize,
        'Content-Transfer-Encoding' => 'binary',
        'Pragma' => 'no-cache',
        'Cache-Control' => 'must-revalidate, post-check=0, pre-check=0',
        'Expires' => '0',
        'Accept-Ranges' => 'bytes'
    );

    $uri = $file->uri;

    file_transfer($uri, $headers);
}

/**
 * Callback URL for uploading URL
 *
 * @TODO evaluate whether a drupal_submit_form after readjusting the _FILES-array might be easier/less error-prone
 */
function fileedit_upload($fid, $sid) {
//    _drupal_session_read($sid);

    // Thiemo; Save updates, reload page
//    session_id($sid);
//    session_start();
//    drupal_save_session(TRUE);

    $_SESSION['fileedit']['updated'][$fid] = TRUE;

    // Thiemo; Fancy revision handling
    $revisions = array();
    $file_then = file_load($fid);
    $per_module = file_usage_list($file_then);

    foreach ($per_module as $module => $per_type) {
        foreach ($per_type as $type => $per_type_id) {
            foreach ($per_type_id as $id => $count) {
                if ($type == 'node') {
                    $node = node_load($id);
                    //file_put_contents( 'C:\xampp\htdocs\froebus_com_showroom\www\sites\all\modules\custom\showroom_helper\template\loading.txt', "\n".$node->type." = ".$node->nid, FILE_APPEND );
                    $options = variable_get('node_options_' . $node->type, array());

                    if (in_array('revision', $options)) {
                        $revisions[] = array($node, $node, $type);
                    }
                } elseif ($type == 'field_collection_item') {
                    $entities = array_values(entity_load('field_collection_item', array($id)));
                    $root_entity = $entities[0];
                    $entity = $root_entity;
                    // Yo dawg...
                    while (($node = $entity->hostEntity()) && $entity->hostEntityType != 'node')
                        $entity = $node;

                    if ($node) {
                        $options = variable_get('node_options_' . $node->type, array());
                        if (in_array('revision', $options)) {
                            $revisions[] = array($node, $root_entity, $type);
                        }
                    }
                }
                // @TODO Someone smart would allow drop-ins here
                // else ???
            }
        }
    }

    if (count($revisions)) {
        // Thiemo; Bad revisioning if the user isn't known...
//        global $user;
        $user = _fileedit_user_by_sid($sid);

        $name = 'userfile';

        // Make it a multiple-upload form submit...
        $_FILES = array(
            'files' => array(
                'name' => array(
                    $name => $file_then->filename, //$_FILES[$name]['name'],
                ),
                'type' => array(
                    $name => $_FILES[$name]['type'],
                ),
                'tmp_name' => array(
                    $name => $_FILES[$name]['tmp_name'],
                ),
                'error' => array(
                    $name => $_FILES[$name]['error'],
                ),
                'size' => array(
                    $name => $_FILES[$name]['size'],
                ),
            ),
        );

        foreach ($revisions as $collection) {
            $node = $collection[0];
            $entity = $collection[1];
            $type = $collection[2];
            $changed = false;

            foreach ((array)$entity as $name => $value) {
                if (substr($name, 0, 6) == 'field_') {
                    $info = field_info_field($name);

                    if ($info['type'] == 'file' && isset($value[LANGUAGE_NONE])) {
                        foreach ($value[LANGUAGE_NONE] as $delta => $file) {
//                            if ($file['fid'] == $fid) {
                                $instance = field_info_instance($type, $name, $node->type);
                                $destination = file_field_widget_uri($info, $instance);
                                $validators = file_field_widget_upload_validators($info, $instance);
                                //file_put_contents( 'C:\xampp\htdocs\froebus_com_showroom\www\sites\all\modules\custom\showroom_helper\template\file-go.txt', print_r(array($_FILES,$file_then,$info,$instance,$destination,$validators),1) );
                                $file_now = file_save_upload( /*$file_then->filename*/
                                    'userfile', $validators, $destination);
                                //file_put_contents( 'C:\xampp\htdocs\froebus_com_showroom\www\sites\all\modules\custom\showroom_helper\template\file-now.txt', print_r($file_now,1) );

                                if ($file_now) {
                                    $changed = true;
                                    $field = &$entity->$name;
                                    $field[LANGUAGE_NONE][$delta]['fid'] = $file_now->fid;
                                }
//                            }
                        }
                    }
                }
            }

            if ($changed) {
                $entity->revision = TRUE;

                if ($type == 'node')
                    node_save($entity);
                else
                    $entity->save();

                if ($node != $entity) {
                    $node->revision = TRUE;
                    node_save($node);
                }
            }
        }

        //session_write_close();
        die();

    }


    //print_r($_FILES);
    $tmp_name = $_FILES['userfile']['tmp_name'];

    //load the file
    $file = file_load($fid);
    $uri = $file->uri;
    //save the new file back to its uri
    drupal_move_uploaded_file($tmp_name, $uri);

    //print_r($file);

    //session_write_close();
    die();
    echo $fid . "--" . $tmp_name;
    die();

    //@todo do something if the file was not uploaded successfully

    //file_save_upload($tmp_name, );
}

/**
 * Access Callback for downloading URL.
 */
function fileedit_download_access($fid, $sid) {
    $user = _fileedit_user_by_sid($sid); //user must have a valid session ID

    if (!is_object($user)) {
        return false;
    }

    return _fileedit_access_filedit($fid, $user);
}

/**
 * Checks if user has rights to edit this file.
 */
function _fileedit_access_filedit($fid, $user) {
    if (!is_object($user)) {
        return false;
    }

    if (!user_access(FILEEDIT_PERMISSION_ACCESS_FILEEDIT, $user)) {
        return false; //use has no rights, so change nothing here
    }

    if (!is_numeric($fid)) {
        return false;
    }

    $fid = intval($fid);
    if (!$fid) {
        return false;
    }

    $file = file_load($fid);
    if ($file === false || !$file->status) {
        return false;
    }

    return true;
}

/**
 * returns the User logged in with a session ID
 * @see mostly copied from session.inc _drupal_session_read()
 */
function _fileedit_user_by_sid($sid) {
    global $is_https;

    // Write and Close handlers are called after destructing objects
    // since PHP 5.0.5.
    // Thus destructors can use sessions but session handler can't use objects.
    // So we are moving session closure before destructing objects.
    drupal_register_shutdown_function('session_write_close');


    // Otherwise, if the session is still active, we have a record of the
    // client's session in the database. If it's HTTPS then we are either have
    // a HTTPS session or we are about to log in so we check the sessions table
    // for an anonymous session with the non-HTTPS-only cookie.
    if ($is_https) {
        $user = db_query("SELECT u.*, s.* FROM {users} u INNER JOIN {sessions} s ON u.uid = s.uid WHERE s.ssid = :ssid", array(':ssid' => $sid))->fetchObject();
        if (!$user) {
            if (isset($_COOKIE[$insecure_session_name])) {
                $user = db_query("SELECT u.*, s.* FROM {users} u INNER JOIN {sessions} s ON u.uid = s.uid WHERE s.sid = :sid AND s.uid = 0", array(
                    ':sid' => $_COOKIE[$insecure_session_name],
                ))
                    ->fetchObject();
            }
        }
    } else {
        $user = db_query("SELECT u.*, s.* FROM {users} u INNER JOIN {sessions} s ON u.uid = s.uid WHERE s.sid = :sid", array(':sid' => $sid))->fetchObject();
    }

    return $user;
}
