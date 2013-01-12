<?php

define('COMMANDER_PERMISSION_ACCESS_COMMANDER', 'access commander');

require_once (dirname(__FILE__) . '/../lib/GetOptionKit/Init.php');

use GetOptionKit\GetOptionKit;

/**
 * Validates command, returns true if command recognized and filled args, otherwise returns false.
 */
function _commander_core_execute_command($text, $nid, &$args = array()) {
    $details = array();

    $text = trim($text);
    preg_match_all('/^([^\s\t\d]{1}[^\s\t]*)(.*)$/', $text, $matches);

    if (!$matches || count($matches[1]) == 0) {
        $details['error'] = t('Command is not recognized.');
        return $details;
    }

    $command_key = strtolower($matches[1][0]);
    $commands = _commander_core_collect_commands();

    $succeed = false;
    $succeed |= array_key_exists($command_key, $commands);

    if (!$succeed) {
        $details['error'] = t('Command is not recognized.');
        return $details;
    }

    $opt = new GetOptionKit;
    $command = $commands[$command_key];

    $required_fields_count = 0;
    if (isset($command['options'])) {
        $options = $command['options'];

        foreach ($options as $k => $v) {
            $spec = $v['short'] . '|' . $v['long'];
            $spec .= isset($v['required']) && $v['required'] ? ':' : '?';
            $spec .= isset($v['type']) ? '=' . $v['type'] : '';

            $opt->add($spec, isset($v['description']) ? $v['description'] : '', $k);

            if (isset($v['required']) && $v['required']) {
                $required_fields_count++;
            }
        }
    }

//            $opt->specs->printOptions();

    $argv = array_filter(explode(' ', trim($matches[2][0])), '_commander_core_filter_array_non_empty');
    try {
        $result = $opt->parse($argv);
        foreach ($result as $key => $spec) {
            $args[$key] = trim($spec);
        }

        if ($required_fields_count > count($args)) {
            $details['error'] = t('Missing required fields.');
            return $details;
        } /*else if (count($args) == 0) {
                    $succeed = true;
                    $status['status'] = $opt->specs->outputOptions();
                }*/
    } catch (Exception $e) {
        $details['error'] = t('@message', array('@message' => $e->getMessage()));
        return $details;
    }

    if (isset($command['access callback'])) {
        $acallback = $command['access callback'];

        if (isset($command['access arguments'])) {
            $r = call_user_func_array($acallback, $command['access arguments']);
        } else {
            $r = call_user_func($acallback);
        }

        if (!$r) {
            $details['error'] = t('You don’t have access to execute the command.');
            return $details;
        }
    }

    if (!isset($command['execution callback'])) {
        $details['error'] = t('Execution callback handler is not found.');
        return $details;
    }

    $acallback = $command['execution callback'];
    if (isset($command['include file'])) {
        require_once($command['include file']);
    }

    $r = call_user_func_array($acallback, array($args, $nid));

    if ($r === null) {
        $details['error'] = t('Unable to invoke command callback.');
    } else if ($r === false) {
        $details['error'] = t('Command callback failed to execute.');
    } else if (isset($r['error'])) {
//        $details['error'] = is_array($r['error']) ? implode(". ", $r['error']) : $r['error'];
        $details['error'] = $r['error'];
    } else if (isset($r['status'])) {
//        $details['status'] = is_array($r['status']) ? implode(" ", $r['status']) : $r['status'];
        $details['status'] = $r['status'];
    } else {
        $details['status'] = t('Command has been executed successfully.');
    }

    return $details;
}

/**
 * Returns an array of the registered commands.
 */
function _commander_core_collect_commands() {
    $commands = array();
    foreach (module_implements('command') as $module) {
        $items = call_user_func($module . '_command');
        if (isset($items) && is_array($items)) {
            foreach (array_keys($items) as $item) {
                $items[$item]['module'] = $module;
                if (isset($items[$item]['file'])) {
                    $file_path = isset($item['file path']) ? $item['file path'] : drupal_get_path('module', $items[$item]['module']);
                    $items[$item]['include file'] = $file_path . '/' . $items[$item]['file'];
                }
            }
            $commands = array_merge($commands, $items);
        }
    }

    return $commands;
}

function _commander_core_filter_array_non_empty($item) {
    $item = trim($item);
    return !empty($item);
}