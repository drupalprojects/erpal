<?php

/**
 * @file
 * Contains the list style plugin.
 */

/**
 * Style plugin to render each item in a slideshow of an ordered or unordered list.
 *
 * @ingroup views_style_plugins
 */
class views_jstree_plugin_style_tree extends views_plugin_style_list {

  /**
   * Set default options
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['class'] = array('default' => '');
    $options['wrapper_class'] = array('default' => 'item-list');
    $options['id_field'] = array('default' => '');
    $options['results_id'] = array('default' => false);
    $options['parent_field'] = array('default' => '');
    $options['weight_field'] = array('default' => false);
    $options['type_field'] = array('default' => false);
    $options['ajax_child_view'] = array('default' => false);
    $options['ajax_child_view_top_types'] = array('default' => false);
    $hook_implemented = hook_jstree_context_implemented();
    $options['context_menu']['use_context_menu_hook'] = array('default' => $hook_implemented);
    $options['context_menu']['custom_context_menu'] = array('default' => '');
    return $options;
  }

  /**
   * Render the given style.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $fields = array('' => t('<None>'));

    foreach ($this->display->handler->get_handlers('field') as $field => $handler) {
      if ($label = $handler->label()) {
        $fields[$field] = $label;
      }
      else {
        $fields[$field] = $handler->ui_name();
      }
    }

    $form['results_id'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use to query by'),
      '#default_value' => $this->options['results_id'],
      '#description' => t('This query will return all entites with the ids given as argument'),
      '#required' => FALSE,
    );
    
    $form['id_field'] = array(
      '#type' => 'select',
      '#title' => t('ID field'),
      '#options' => $fields,
      '#default_value' => $this->options['id_field'],
      '#description' => t('Select the field with the unique identifier for each record.'),
      '#required' => TRUE,
    );

    $form['parent_field'] = array(
      '#type' => 'select',
      '#title' => t('Parent field'),
      '#options' => $fields,
      '#default_value' => $this->options['parent_field'],
      '#description' => t('Select the field that contains the unique identifier of the record\'s parent.'),
    );
    
    $form['weight_field'] = array(
      '#type' => 'select',
      '#title' => t('Weight field'),
      '#options' => $fields,
      '#default_value' => $this->options['weight_field'],
      '#description' => t('Select the field that contains the weight to order the tree.'),
    );
    
    $form['type_field'] = array(
      '#type' => 'select',
      '#title' => t('Type field'),
      '#options' => $fields,
      '#default_value' => $this->options['type_field'],
      '#description' => t('Select the field that contains the type of the node in the selected row.'),
      '#required' => true,
    );
    
    $form['ajax_child_view'] = array(
      '#type' => 'checkbox',
      '#title' => t('AJAX child view'),
      '#default_value' => $this->options['ajax_child_view'],
      '#description' => t('Check, if this is the display for loading the children using ajax'),
    );
    
    $node_types = node_type_get_types();
    $node_type_options = array();
    foreach ($node_types as $type_name => $type_obj) {
      $node_type_options[$type_name] = $type_obj->name;
    }
    $form['ajax_child_view_top_types'] = array(
      '#type' => 'checkboxes',
      '#options' => $node_type_options,
      '#title' => t('AJAX child view for first children with parent of type'),
      '#default_value' => $this->options['ajax_child_view_top_types'],
      '#description' => t('If you select a content type here, this view is only for nodes with the selected type as parent (like book is container for book pages or project is container for tasks)'),
    );
    
    $form['context_menu'] = array(
      '#type' => 'fieldset',
      '#title' => t('Context menu settings'),
      '#collapsible' => true,
      '#collapsed' => true,
    );
    
    $hook_implemented = hook_jstree_context_implemented();
    $form['context_menu']['use_context_menu_hook'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use implemented hook'),
      '#description' => t('If checked, an implementation of hook_jstree_context_menu will create the context menu, only enabled if a module implements that hook'),
      '#default_value' => $hook_implemented && $this->options['context_menu']['use_context_menu_hook'],
      '#disabled' => !$hook_implemented, //we cannot say, use a hook if there is no hook implemented
    );

    $form['context_menu']['custom_context_menu'] = array(
      '#type' => 'textarea',
      '#title' => t('Custom menu'),
      '#description' => t('Each line enter a menu item like title|path. You could use tokens of your fields'),
      '#default_value' => $this->options['context_menu']['custom_context_menu'],
      '#states' => array(
        // Hide the settings when the checkbox is checked notify checkbox is disabled.
        'invisible' => array(
          ':input[id="edit-style-options-context-menu-use-context-menu-hook"]' => array('checked' => TRUE),
        ),
      ),
    );
    
    $token_type = 'views_jstree_'.$this->view->name."_".$this->display->id;

    //add available tokens to the form
    //show available Tokens  
    if (module_exists('token')) {
      $form['context_menu']['token_tree'] = array(
        '#theme' => 'token_tree',   
        '#token_types' => array($token_type),
        '#global_types' => FALSE,
        '#click_insert' => TRUE,
        '#recursion_limit' => 1,
      );
    }
  }  
  
}

/**
* checks if at least one menu implements hook_jstree_context_menu
*/
function hook_jstree_context_implemented() {
 return count(module_implements('jstree_context_menu')) > 0;
}
