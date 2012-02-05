<?php
/**
 * @file
 * feature_erpal_project_spec.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function feature_erpal_project_spec_default_rules_configuration() {
  $items = array();
  $items['rules_add_project_ref_to_spec_on_save_if_has_parent_spec'] = entity_import('rules_config', '{ "rules_add_project_ref_to_spec_on_save_if_has_parent_spec" : {
      "LABEL" : "Add project ref to spec on save if has parent spec",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "project", "spec" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_presave" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "erpal_project_spec" : "erpal_project_spec" } }
          }
        },
        { "data_is" : {
            "data" : [ "node:field-spec-ref:type" ],
            "value" : "erpal_project_spec"
          }
        },
        { "NOT data_is_empty" : { "data" : [ "node:field-spec-ref" ] } }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "node", "value" : [ "node:field-spec-ref:field-project-ref" ] },
            "PROVIDE" : { "variable_added" : { "project_node_of_parent_spec" : "Project node of parent spec" } }
          }
        },
        { "data_set" : {
            "data" : [ "node:field-project-ref" ],
            "value" : [ "project-node-of-parent-spec" ]
          }
        }
      ]
    }
  }');
  return $items;
}
