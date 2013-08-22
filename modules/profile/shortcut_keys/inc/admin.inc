<?php
/**
 *  @file shortcut_keys/inc/admin.inc
 *  @author Thiemo Müller
 *  @version 1.0
 *  
 *  All handling of administration is to be done here.
 */

/**
 *  Add/Edit a shortcut (form)
 */
function shortcut_keys_admin_shortcut_edit_form( $form, &$form_state, $shortcut=NULL, $show_expanded=FALSE ) {
  
  $form         = array();
  
  $editing      = !!$shortcut;
  $title        = $editing ? t('Edit @shortcut_name',array('@shortcut_name'=>$shortcut['name'])) : t('Add shortcut');
  if( $editing )
    $form_state['shortcut']  = $shortcut;
  
  $types          = shortcut_keys_get_shortcut_types();
  $type_names     = array();
  foreach( $types as $machine_name=>$type )
    $type_names[$machine_name]  = $type['name'];
  
  $shortcut_groups = shortcut_keys_get_shortcut_groups();
  $group_names    = array();
  foreach( $shortcut_groups as $machine_name=>$group )
    $group_names[$machine_name] = $group['name'];
  
  $form['fieldset']     = array(
    '#type'               => 'fieldset',
    '#title'              => $title,
    '#collapsible'        => !$editing && !$show_expanded,
    '#collapsed'          => !$editing && !$show_expanded,
  );
  
  $form['fieldset']['name']           = array(
    '#title'                  => t('Name'),
    '#type'                   => 'textfield',
    '#default_value'          => $shortcut ? $shortcut['name'] : '',
    '#required'               => TRUE,
  );
  
  $form['fieldset']['machine_name']   = array(
    '#title'                  => $editing && isset($shortcut['module']) ? t('Machine name (as given by providing module %name)',array('%name'=>$shortcut['module'])) : t('Machine name'),
    '#type'                   => 'textfield',
    '#default_value'          => $shortcut ? $shortcut['machine_name'] : '',
    '#required'               => TRUE,
  );
  
  $form['fieldset']['groups']         = array(
    '#title'                  => t('Groups'),
    '#description'            => t('The groups of this shortcut, used for permission management. If no group is assigned, only users with the %permission_name permission will be allowed to use this shortcut key.',array('%permission_name'=>t('Use any shortcut key'))),
    '#type'                   => 'checkboxes',
    '#default_value'          => $shortcut ? $shortcut['groups'] : array(),
    '#options'                => $group_names,
  );
  
  $form['fieldset']['type']           = array(
    '#title'                  => t('Type'),
    '#type'                   => 'radios',
    '#default_value'          => $shortcut ? $shortcut['type'] : NULL,
    '#options'                => $type_names,
    '#required'               => TRUE,
  );
  
  $form['fieldset']['value']          = array(
    '#title'                  => t('Value'),
    '#type'                   => 'textfield',
    '#default_value'          => $shortcut ? $shortcut['value'] : '',
    '#maxlength'              => 1023,
  );
  
  $form['fieldset']['keys']           = array(
    '#title'                  => t('Shortcut keys'),
    '#type'                   => 'textfield',
    '#default_value'          => $shortcut ? $shortcut['keys'] : '',
    '#required'               => TRUE,
  );
  
  $form['fieldset']['press_double']   = array(
    '#title'                  => t('Press double'),
    '#description'            => t('If checked, The shortcut key will have to be pressed twice before it gets executed.'),
    '#type'                   => 'checkbox',
    '#default_value'          => $shortcut ? $shortcut['press_double'] : FALSE,
  );
  
  $form['fieldset']['confirm_dialog'] = array(
    '#title'                  => t('Confirm dialog'),
    '#description'            => t('If checked, a modal dialog will be shown asking the user to confirm the execution of this shortcut.'),
    '#type'                   => 'checkbox',
    '#default_value'          => $shortcut ? $shortcut['confirm_dialog'] : FALSE,
  );
  
  $form['fieldset']['always_execute'] = array(
    '#title'                  => t('Always execute this shortcut'),
    '#description'            => t('By default shortcuts will only be executed if no input element (including textareas and select boxes) is currently focused. This will enable the shortcut even if an element is focused.'),
    '#type'                   => 'checkbox',
    '#default_value'          => $shortcut ? $shortcut['always_execute'] : FALSE,
  );
  
  $form['fieldset']['active']         = array(
    '#title'                  => t('Active'),
    '#type'                   => 'checkbox',
    '#default_value'          => $shortcut ? $shortcut['active'] : TRUE,
  );
  
  $form['fieldset']['save']           = array(
    '#value'                  => t('Save'),
    '#type'                   => 'submit',
  );
  
  if( $editing && isset($shortcut['module']) ) {
    $form['fieldset']['machine_name']['#disabled']  = TRUE;
    $form['fieldset']['type']['#disabled']          = TRUE;
    $form['fieldset']['value']['#disabled']         = TRUE;
  }
  
  foreach( $_GET as $key=>$value ) {
    if( !isset($form['fieldset'][$key]) || isset($form['fieldset'][$key]['#disabled']) )
      continue;
    
    $form['fieldset'][$key]['#default_value'] = $value;
    $form['fieldset']['#collapsed']           = FALSE;
  }
  
  return $form;
  
}
function shortcut_keys_admin_shortcut_edit_form_validate( $form, &$form_state ) {
  $values   = $form_state['values'];
  $previous = isset($form_state['shortcut']) ? $form_state['shortcut'] : NULL;
  $editing  = !!$previous;
  $shortcuts = shortcut_keys_get_shortcuts( NULL, TRUE );
  
  // Machine name available?
  if( $editing && $previous['machine_name']!=$values['machine_name'] ) {
    if( isset($shortcuts[ $values['machine_name'] ]) ) {
      form_set_error( 'machine_name', t('This machine name is already taken!') );
    }
  }
  
  // Machine name valid?
  if( preg_replace( '@([a-z0-9_]+)@', '', $values['machine_name'] ) ) {
    form_set_error( 'machine_name', t('Please enter a valid machine name!') );
  }
  
  $key_list = explode( '+', $values[ 'keys' ] );
  
  // Shortcut valid?
  $keys     = shortcut_keys_get_javascript_keycodes();
  foreach( $key_list as $key ) {
    if( !isset($keys[$key]) ) {
      form_set_error( 'keys', t('Unknown key @key! Please don\'t manipulate the value of this input element.',array('@key'=>$key)) );
      break;
    }
  }
  
  // Shortcut available?
  foreach( $shortcuts as $shortcut ) {
    if( $editing && $shortcut[ 'machine_name' ]==$previous['machine_name'] )
      continue;
    
    $cmd_keys = explode( '+', $shortcut[ 'keys' ] );
    if( $cmd_keys==$key_list ) {
      form_set_error( 'keys', t('A shortcut with the given keys already exists!') );
      break;
    }
  }
  
}
function shortcut_keys_admin_shortcut_edit_form_submit( $form, &$form_state ) {
  
  $values   = $form_state['values'];
  $previous = isset($form_state['shortcut']) ? $form_state['shortcut'] : NULL;
  $editing  = !!$previous;
  $shortcuts = shortcut_keys_get_shortcuts( NULL, TRUE );
  
  
  if( $editing ) {
    $shortcuts[ $previous[ 'machine_name' ] ]  = NULL;
    unset( $shortcuts[ $previous[ 'machine_name' ] ] );
    
    if( isset($previous['module']) )
      $values['module'] = $previous['module'];
  }
  
  // Pass by reference!
  foreach( module_implements( MODULE_SHORTCUT_KEYS_API_HOOK ) as $module ) {
    
    $function = $module . '_' . MODULE_SHORTCUT_KEYS_API_HOOK;
    $function( 'save_shortcut', $values, $previous );
    
  }
  
  $remove = array( 'op', 'save', 'form_build_id', 'form_id', 'form_token' );
  foreach( $remove as $key )
    unset( $values[$key] );
  
  $shortcuts[ $values[ 'machine_name' ] ]  = $values;
  
  shortcut_keys_set_shortcuts( $shortcuts );
  
  if( $editing )
    drupal_set_message( t('The shortcut %shortcut_name has been edited.',array('%shortcut_name'=>$values['name'])) );
  else
    drupal_set_message( t('The shortcut %shortcut_name has been added.',array('%shortcut_name'=>$values['name'])) );
  
}

/**
 *  Delete shortcut (form)
 */
function shortcut_keys_admin_shortcut_delete_form( $form, &$form_state, $shortcut ) {
  
  $form_state['shortcut'] = $shortcut;
  
  $form             = array();
  
  $form['message']  = array(
    '#markup'          => t('Are you sure you want to permanently delete the shortcut %shortcut_name?',array('%shortcut_name'=>$shortcut['name'])),
    '#type'           => 'item',
  );
  
  $form['delete']   = array(
    '#value'          => t('Delete'),
    '#type'           => 'submit',
  );
  
  return $form;
  
}
function shortcut_keys_admin_shortcut_delete_form_submit( $form, &$form_state ) {
  
  $shortcut   = $form_state['shortcut'];
  
  shortcut_keys_delete_shortcut( $shortcut[ 'machine_name' ] );
  
  drupal_set_message( t('The shortcut %shortcut_name has been permanently deleted.',array('%shortcut_name'=>$shortcut['name'])) );
  
}

/**
 *  Administer shortcuts (list of shortcuts)
 */
function _shortcut_keys_admin_shortcuts() {
  
  $shortcuts        = shortcut_keys_get_shortcuts( NULL, TRUE );
  $shortcut_groups  = shortcut_keys_get_shortcut_groups();
  $shortcut_types   = shortcut_keys_get_shortcut_types();
  
  $add_form = drupal_get_form( 'shortcut_keys_admin_shortcut_edit_form', NULL, !count( $shortcuts ) );
  $result   = drupal_render( $add_form );
  
  if( count( $shortcuts ) ) {
    
    $table          = array(
      'header'        => array(
        t('Name'),
        t('Type'),
        t('Value'),
        t('Groups'),
        t('Active'),
        t('Actions'),
      ),
      'rows'          => array(),
    );
    
    foreach( $shortcuts as $machine_name=>$config ) {
      
      $group_names  = array();
      foreach( $config['groups'] as $group_name )
        $group_names[]  = check_plain( $shortcut_groups[ $group_name ][ 'name' ] );
      
      $actions      = array();
      $actions[]    = l( t('Edit'), 'admin/config/user-interface/shortcut-keys/shortcuts/edit/'.$machine_name, array( 'query'=>array( 'destination'=>$_GET['q'] ) ) );
      
      if( !isset($config['module']) ) {
        $actions[]    = l( t('Delete'), 'admin/config/user-interface/shortcut-keys/shortcuts/delete/'.$machine_name, array( 'query'=>array( 'destination'=>$_GET['q'] ) ) );
      }
      
      $table['rows'][]  = array(
        check_plain( $config['name'] ),
        check_plain( $shortcut_types[ $config['type'] ][ 'name' ] ),
        check_plain( $config['value'] ),
        implode( ', ', $group_names ),
        $config['active'] ? t('Yes') : t('No'),
        implode( ' ', $actions ),
      );
      
    }
    
    $result   .= theme( 'table', $table );
    
  }
  
  return $result;
  
}

/**
 *  Add/Edit group (form)
 */
function shortcut_keys_admin_shortcut_group_edit_form( $form, &$form_state, $group=NULL, $show_expanded=FALSE ) {
  
  $form         = array();
  
  $editing      = !!$group;
  $title        = $editing ? t('Edit @group_name',array('@group_name'=>$group['name'])) : t('Add group');
  if( $editing )
    $form_state['group']  = $group;
  
  $form['fieldset']     = array(
    '#type'               => 'fieldset',
    '#title'              => $title,
    '#collapsible'        => !$editing && !$show_expanded,
    '#collapsed'          => !$editing && !$show_expanded,
  );
  
  $form['fieldset']['name']           = array(
    '#title'                  => t('Name'),
    '#type'                   => 'textfield',
    '#default_value'          => $group ? $group['name'] : '',
    '#required'               => TRUE,
  );
  
  $form['fieldset']['machine_name']   = array(
    '#title'                  => t('Machine name'),
    '#type'                   => 'textfield',
    '#default_value'          => $group ? $group['machine_name'] : '',
    '#required'               => TRUE,
  );
  
  $form['fieldset']['save']           = array(
    '#value'                  => t('Save'),
    '#type'                   => 'submit',
  );
  
  return $form;
  
}
function shortcut_keys_admin_shortcut_group_edit_form_validate( $form, &$form_state ) {
  
  $values   = $form_state['values'];
  $previous = isset($form_state['group']) ? $form_state['group'] : NULL;
  $editing  = !!$previous;
  $groups   = shortcut_keys_get_shortcut_groups();
  
  // Machine name available?
  if( $editing && $previous['machine_name']!=$values['machine_name'] ) {
    
    if( isset($groups[ $values['machine_name'] ]) ) {
      form_set_error( 'machine_name', t('This machine name is already taken!') );
    }
    
  }
  
  // Machine name valid?
  if( preg_replace( '@([a-z0-9_]+)@', '', $values['machine_name'] ) ) {
    form_set_error( 'machine_name', t('Please enter a valid machine name!') );
  }
  
}
function shortcut_keys_admin_shortcut_group_edit_form_submit( $form, &$form_state ) {
  
  $values   = $form_state['values'];
  $previous = isset($form_state['group']) ? $form_state['group'] : NULL;
  $editing  = !!$previous;
  $groups   = shortcut_keys_get_shortcut_groups();
  
  if( $editing ) {
    
    if( $previous[ 'machine_name' ]!=$values[ 'machine_name' ] ) {
      $groups[ $previous[ 'machine_name' ] ]  = NULL;
      unset( $groups[ $previous[ 'machine_name' ] ] );
      
      drupal_set_message( t( 'You have changed this group\'s machine name! Make sure to rebuild the permissions!' ), 'warning' );
      
      // Update references to new machine name
      $shortcuts  = shortcut_keys_get_shortcuts( NULL, TRUE );
      
      foreach( $shortcuts as $machine_name=>$shortcut ) {
        
        if( isset( $shortcut['groups'][ $previous['machine_name'] ] ) ) {
          
          unset( $shortcuts[$machine_name]['groups'][ $previous['machine_name'] ] );
          
          $shortcuts[$machine_name]['groups'][ $values[ 'machine_name' ] ]  = $values[ 'machine_name' ];
          
        }
        
      }
      
      shortcut_keys_set_shortcuts( $shortcuts );
      
    }
    
  }
  
  // Pass by reference!
  foreach( module_implements( MODULE_SHORTCUT_KEYS_API_HOOK ) as $module ) {
    
    $function = $module . '_' . MODULE_SHORTCUT_KEYS_API_HOOK;
    $function( 'save_shortcut_group', $values, $previous );
    
  }
  
  $groups[ $values[ 'machine_name' ] ]  = $values;
  
  shortcut_keys_set_shortcut_groups( $groups );
  
  if( $editing )
    drupal_set_message( t('The group %group_name has been edited.',array('%group_name'=>$values['name'])) );
  else
    drupal_set_message( t('The group %group_name has been added.',array('%group_name'=>$values['name'])) );
  
}

/**
 *  Delete group (form)
 */
function shortcut_keys_admin_shortcut_group_delete_form( $form, &$form_state, $group ) {
  
  $form_state['group'] = $group;
  
  $form             = array();
  
  $form['message']  = array(
    '#markup'          => t('Are you sure you want to permanently delete the group %group_name?',array('%group_name'=>$group['name'])),
    '#type'           => 'item',
  );
  
  $form['delete']   = array(
    '#value'          => t('Delete'),
    '#type'           => 'submit',
  );
  
  return $form;
  
}
function shortcut_keys_admin_shortcut_group_delete_form_submit( $form, &$form_state ) {
  
  $group   = $form_state['group'];
  
  shortcut_keys_delete_shortcut_group( $group );
  
  drupal_set_message( t('The group %group_name has been permanently deleted.',array('%group_name'=>$group['name'])) );
  
}

/**
 *  Administer shortcut groups (list of groups)
 */
function _shortcut_keys_admin_groups() {
  
  $shortcut_groups  = shortcut_keys_get_shortcut_groups();
  $shortcuts        = shortcut_keys_get_shortcuts( NULL, TRUE );
  
  $add_form = drupal_get_form( 'shortcut_keys_admin_shortcut_group_edit_form', NULL, !count( $shortcut_groups ) );
  $result   = drupal_render( $add_form );
  
  if( count( $shortcut_groups ) ) {
    
    $table          = array(
      'header'        => array(
        t('Name'),
        t('Commands'),
        t('Actions'),
      ),
      'rows'          => array(),
    );
    
    foreach( $shortcut_groups as $machine_name=>$group ) {
      
      $command_names  = array();
      foreach( $shortcuts as $shortcut )
        if( in_array( $group['machine_name'], $shortcut['groups'] ) )
          $command_names[]  = check_plain( $shortcut[ 'name' ] );
      
      $actions      = array();
      if( !isset($group['module']) ) {
        $actions[]    = l( t('Edit'), 'admin/config/user-interface/shortcut-keys/groups/edit/'.$machine_name, array( 'query'=>array( 'destination'=>$_GET['q'] ) ) );
        $actions[]    = l( t('Delete'), 'admin/config/user-interface/shortcut-keys/groups/delete/'.$machine_name, array( 'query'=>array( 'destination'=>$_GET['q'] ) ) );
      }
      
      $table['rows'][]  = array(
        check_plain( $group['name'] ),
        implode( ', ', $command_names ),
        implode( ' ', $actions ),
      );
      
    }
    
    $result   .= theme( 'table', $table );
    
  }
  
  return $result;
  
}