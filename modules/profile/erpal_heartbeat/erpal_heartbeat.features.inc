<?php
/**
 * @file
 * erpal_heartbeat.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function erpal_heartbeat_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "cat" && $api == "cat") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function erpal_heartbeat_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_message_type().
 */
function erpal_heartbeat_default_message_type() {
  $items = array();
  $items['erpal_heartbeat_comment_message'] = entity_import('message_type', '{
    "name" : "erpal_heartbeat_comment_message",
    "description" : "ERPAL Heartbeat - Comment message",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 1 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "de",
    "arguments" : null,
    "message_text" : {
      "de" : [
        {
          "value" : "\\u003Cdiv class=\\u0022hb_date_time\\u0022\\u003E[message:timestamp:erpal_date_time]\\u003C\\/div\\u003E\\r\\n\\u003Cdiv class=\\u0022hb_message_info\\u0022\\u003E\\u003Ca href=\\u0022[message:user:url]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E [message:field_erpal_hb_operation]ed a comment at [message:field-erpal-hb-node-ref:content-type] \\u003Ca href=\\u0022[message:field-erpal-hb-node-ref:url]\\u0022\\u003E[message:field-erpal-hb-node-ref:title]\\u003C\\/a\\u003E:\\u003C\\/div\\u003E\\r\\n\\u003Cdiv class=\\u0022hb_message_content\\u0022\\u003E[message:field-erpal-hb-comment-ref:comment-body:value]\\u003C\\/div\\u003E\\r\\n",
          "format" : "full_html"
        }
      ],
      "en" : [
        {
          "value" : "\\u003Cdiv class=\\u0022hb_date_time\\u0022\\u003E[message:timestamp:erpal_date_time]\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022hb_message_info\\u0022\\u003E\\u003Ca href=\\u0022[message:user:url]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E [message:field_erpal_hb_operation]ed a comment at [message:field-erpal-hb-node-ref:content-type] \\u003Ca href=\\u0022[message:field-erpal-hb-node-ref:url]\\u0022\\u003E[message:field-erpal-hb-node-ref:title]\\u003C\\/a\\u003E:\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022hb_message_content\\u0022\\u003E[message:field-erpal-hb-comment-ref:comment-body:value]\\u003C\\/div\\u003E\\n",
          "format" : "full_html"
        }
      ],
      "und" : [
        {
          "value" : "\\u003Cdiv class=\\u0022hb_date_time\\u0022\\u003E[message:timestamp:erpal_date_time]:\\u003C\\/div\\u003E\\u003Cdiv class=\\u0022hb_content\\u0022\\u003E \\u003Ca href=\\u0022[message:user:url]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E [message:field_erpal_hb_operation]ed a comment \\u0022[message:field-erpal-hb-comment-ref:comment-body:value]\\u0022 at [message:field-erpal-hb-node-ref:content-type] \\u003Ca href=\\u0022[message:field-erpal-hb-node-ref:url]\\u0022\\u003E[message:field-erpal-hb-node-ref:title]\\u003C\\/a\\u003E\\u003C\\/div\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "[message:field-comment-ref:comment-teaser]",
          "format" : "full_html"
        }
      ]
    }
  }');
  $items['erpal_heartbeat_node_message'] = entity_import('message_type', '{
    "name" : "erpal_heartbeat_node_message",
    "description" : "ERPAL Heartbeat - Node message",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 1 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : [],
    "message_text" : {
      "de" : [
        {
          "value" : "\\u003Cdiv class=\\u0022hb_date_time\\u0022\\u003E[message:timestamp:erpal_date_time]\\u003C\\/div\\u003E\\n\\n\\u003Cdiv class=\\u0022hb_content\\u0022\\u003E\\u003Ca href=\\u0022[message:user:url]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E [message:field_erpal_hb_operation]ed a [message:field-erpal-hb-node-ref:content-type] \\u003Ca href=\\u0022[message:field-erpal-hb-node-ref:url]\\u0022\\u003E[message:field-erpal-hb-node-ref:title]\\u003C\\/a\\u003E\\u003C\\/div\\u003E\\n",
          "format" : "full_html"
        }
      ],
      "en" : [
        {
          "value" : "\\u003Cdiv class=\\u0022hb_date_time\\u0022\\u003E[message:timestamp:erpal_date_time]\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022hb_content\\u0022\\u003E\\u003Ca href=\\u0022[message:user:url]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E [message:field_erpal_hb_operation]ed a [message:field-erpal-hb-node-ref:content-type] \\u003Ca href=\\u0022[message:field-erpal-hb-node-ref:url]\\u0022\\u003E[message:field-erpal-hb-node-ref:title]\\u003C\\/a\\u003E\\u003C\\/div\\u003E\\r\\n",
          "format" : "full_html"
        }
      ],
      "und" : [
        {
          "value" : "\\u003Cdiv class=\\u0022hb_date_time\\u0022\\u003E[message:timestamp:erpal_date_time]:\\u003C\\/div\\u003E\\u003Cdiv class=\\u0022hb_content\\u0022\\u003E \\u003Ca href=\\u0022[message:user:url]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E [message:field_erpal_hb_operation]ed a [message:field-erpal-hb-node-ref:content-type] \\u003Ca href=\\u0022[message:field-erpal-hb-node-ref:url]\\u0022\\u003E[message:field-erpal-hb-node-ref:title]\\u003C\\/a\\u003E\\u003C\\/div\\u003E",
          "format" : "full_html"
        },
        {
          "value" : "[message:field-comment-ref:comment-teaser]",
          "format" : "full_html"
        }
      ]
    }
  }');
  return $items;
}
