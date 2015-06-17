<?php
/**
 * @file
 * erpal_project_notify.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function erpal_project_notify_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_message_type().
 */
function erpal_project_notify_default_message_type() {
  $items = array();
  $items['task_assigned_message'] = entity_import('message_type', '{
    "name" : "task_assigned_message",
    "description" : "Task assigned message",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "de",
    "arguments" : null,
    "message_text" : { "en" : [
        {
          "value" : "TASK assigned to you ([message:user:name]):\\n\\nStatus: [message:field-task-ref:field_task_status_term]\\n\\n[message:field-task-ref:body]",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003ETASK assigned to you ([message:user:name]):\\u003C\\/p\\u003E\\n\\u003Cp\\u003EStatus: [message:field-task-ref:field_task_status_term]\\u003C\\/p\\u003E\\n\\u003Cp\\u003E[message:field-task-ref:body]\\u003C\\/p\\u003E\\n"
        }
      ]
    }
  }');
  $items['task_comment_message'] = entity_import('message_type', '{
    "name" : "task_comment_message",
    "description" : "Task comment message",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "de",
    "arguments" : null,
    "message_text" : { "en" : [
        {
          "value" : "Comment [message:field-message-operation]:\\n\\n[message:field-message-comment:comment-body:value]",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003EComment [message:field-message-operation]:\\u003C\\/p\\u003E\\n\\u003Cp\\u003E[message:field-message-comment:comment-body:value]\\u003C\\/p\\u003E\\n"
        }
      ]
    }
  }');
  $items['task_node_message'] = entity_import('message_type', '{
    "name" : "task_node_message",
    "description" : "Task node message",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "de",
    "arguments" : null,
    "message_text" : { "en" : [
        {
          "value" : "TASK [message:field-message-operation]:\\n\\nStatus: [message:field-task-ref:field_task_status_term]\\n\\n[message:field-task-ref:body]",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003ETASK [message:field-message-operation]:\\u003C\\/p\\u003E\\n\\u003Cp\\u003EStatus: [message:field-task-ref:field_task_status_term]\\u003C\\/p\\u003E\\n\\u003Cp\\u003E[message:field-task-ref:body]\\u003C\\/p\\u003E\\n"
        }
      ]
    }
  }');
  $items['task_notification_message'] = entity_import('message_type', '{
    "name" : "task_notification_message",
    "description" : "Task notification message",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "de",
    "arguments" : null,
    "message_text" : { "en" : [
        {
          "value" : "[message:field-project-ref:title] - [message:field-task-ref:title] - DIGEST\\n",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003E[message:field-project-ref:title] - [message:field-task-ref:title] - DIGEST\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "[message:field_aggregated_text] \\n\\nProject: [message:field-project-ref:title] at [message:field-project-ref:url] \\nTask: [message:field-task-ref:title] at [message:field-task-ref:url]",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003E[message:field_aggregated_text] \\u003C\\/p\\u003E\\n\\u003Cp\\u003EProject: [message:field-project-ref:title] at [message:field-project-ref:url]\\u003Cbr \\/\\u003E\\nTask: [message:field-task-ref:title] at [message:field-task-ref:url]\\u003C\\/p\\u003E\\n"
        }
      ]
    }
  }');
  return $items;
}
