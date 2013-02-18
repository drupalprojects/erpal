<?php
/**
 *  @file commander/inc/exec.inc
 *  @author Thiemo Müller
 *  @version 1.0
 *  
 *  Here we store all base command and argument type handlers.
 */

/* Base argument type: bool */
function _commander_validate_bool( $environment, $values, $arg_def ) {
  foreach( $values as $value )
    if( !in_array( $values[0], array( 'yes', 'no', 'true', 'false', '0', '1' ) ) )
      return FALSE;
  
  return TRUE;
}
function _commander_load_bool( $environment, $values, $arg_def ) {
  foreach( $values as $i=>$value )
    $values[$i] = $value=='yes' || $value=='true' || $value=='1';
  
  return $values;
}

/* Base argument type: int */
function _commander_validate_int( $environment, $values, $arg_def ) {
  foreach( $values as $value )
    if( !is_numeric( $value ) || strpos( $value, '.' )!==FALSE )
      return FALSE;
  
  return TRUE;
}
function _commander_load_int( $environment, $values, $arg_def ) {
  foreach( $values as $i=>$value )
    $values[$i] = (int)$value;
  
  return $values;
}

/* Base argument type: float */
function _commander_validate_float( $environment, $values, $arg_def ) {
  foreach( $values as $value )
    if( !is_numeric( $value ) )
      return FALSE;
  
  return TRUE;
}
function _commander_load_float( $environment, $values, $arg_def ) {
  foreach( $values as $i=>$value )
    $values[$i] = (float)$value;
  
  return $values;
}



/* Extended argument type: datetime */
function _commander_validate_datetime( $environment, $values, $arg_def ) {
  foreach( $values as $value )
    if( strtotime($value)===FALSE )
      return FALSE;
  
  return TRUE;
}
function _commander_load_datetime( $environment, $values, $arg_def ) {
  foreach( $values as $i=>$value )
    $values[$i] = strtotime( $value );
  
  return $values;
}
function _commander_default_datetime_now( $environment, $arg_def ) {
  return $environment['timestamp'];
}



/* Entity argument type: user */
function _commander_validate_user( $environment, $values, $arg_def ) {
  $values = _commander_load_user( $environment, $values, $arg_def );
  foreach( $values as $value )
    if( !$value )
      return FALSE;
  
  return TRUE;
}
function _commander_load_user( $environment, $values, $arg_def ) {
  
  foreach( $values as $i=>$value ) {
    
    $u  = db_select( 'users', 'u' )
      ->fields( 'u', array( 'uid' ) )
      ->condition( db_or()
        ->condition( 'u.uid', $value )
        ->condition( 'u.name', $value )
        ->condition( 'u.mail', $value )
      )
      ->condition( 'status', 1 )
      ->execute()
      ->fetchAssoc();
    
    $values[$i] = $u && $u['uid'] ? user_load( $u['uid'] ) : NULL;
    
  }
  
  return $values;
}
function _commander_list_user( $environment, $input, $limit ) {
  $users  = array();
  
  $query  = db_select( 'users', 'u' )
    ->fields( 'u', array( 'name' ) )
    ->condition( db_or()
      ->condition( 'u.uid', $input.'%', 'LIKE' )
      ->condition( 'u.name', $input.'%', 'LIKE' )
      ->condition( 'u.mail', $input.'%', 'LIKE' )
    )
    ->condition( 'status', 1 )
    ->orderBy( 'u.name', 'ASC' );
  
  if( $limit>=0 )
    $query
      ->range( 0, $limit );
  
  $query  = $query
    ->execute();
  
  foreach( $query as $u )
    $users[]  = _commander_argument( $u->name );
  
  return $users;
}
function _commander_default_user_current_user( $environment, $arg_def ) {
  return $environment['user']->uid;
}



/* Entity argument type: node */
function _commander_validate_node( $environment, $values, $arg_def ) {
  $values = _commander_load_node( $environment, $values, $arg_def );
  foreach( $values as $value )
    if( !$value )
      return FALSE;
  
  return TRUE;
}
function _commander_load_node( $environment, $values, $arg_def ) {
  
  foreach( $values as $i=>$value ) {
    $value  = preg_replace( '@^(.*?)\\(([0-9]+)\\)$@', '$2', $value );
    
    //drupal_set_message( 'nid: ' . $value );
    
    $values[$i] = node_load( $value );
  }
  
  return $values;
  
}
function _commander_list_node( $environment, $input, $limit ) {
  $nodes  = array();
  
  $query = new EntityFieldQuery;
  $result = $query
    ->entityCondition( 'entity_type', 'node' )
    ->fieldCondition( 'nid', $input.'%', 'LIKE' )
    ->propertyOrderBy( 'title', 'ASC' );
  
  if( $limit>=0 )
    $query
      ->range( 0, $limit );
  
  $query  = $query
    ->execute();
  /*$query  = db_select( 'node', 'n' )
    ->fields( 'n', array( 'nid' ) )
    ->condition( 'n.nid', $input.'%', 'LIKE' )
    ->orderBy( 'n.nid', 'ASC' )
    ->range( 0, $limit )
    ->execute();*/
  
  $query  = entity_load( 'node', array_keys( $query['node'] ) );
  foreach( $query as $n )
    $nodes[]  = $n->title . ' ('.$n->nid.')';
  
  return $nodes;
}
function _commander_default_node_viewed_node( $environment, $arg_def ) {
  $url  = $environment[ 'q' ];
  
  //drupal_set_message( $url );
  
  if( substr($url,0,5)=='node/' ) {
    
    $parts  = explode( '/', $url );
    
    if( is_numeric( $parts[1] ) ) {
      $node = node_load( $parts[1] );
      
      if( $node )
        return $node->title . ' ('.$node->nid.')';
      
    }
    
  }
  
  return 0;
}



/* Entity argument type: taxonomy term */
function _commander_validate_term( $environment, $values, $arg_def ) {
  $values = _commander_load_term( $environment, $values, $arg_def );
  foreach( $values as $value )
    if( !$value )
      return FALSE;
  
  return TRUE;
}
function _commander_load_term( $environment, $values, $arg_def ) {
  foreach( $values as $i=>$value ) {
    $value        = taxonomy_get_term_by_name( $value, $arg_def['vocabulary'] );
    $value        = array_values( $value );
    $values[ $i ] = $value[ 0 ];
  }
  
  return $values;
}
function _commander_list_term( $environment, $input, $limit, $arg_def=NULL ) {
  $terms  = array();
  
  $vocabulary = isset($arg_def['vocabulary']) ? taxonomy_vocabulary_machine_name_load( $arg_def['vocabulary'] ) : FALSE;
  
  $query  = db_select( 'taxonomy_term_data', 't' )
    ->fields( 't', array( 'name' ) )
    ->orderBy( 't.weight', 'ASC' );
  
  if( $input )
    $query
      ->condition( 't.name', $input.'%', 'LIKE' );
  
  if( $vocabulary )
    $query
      ->condition( 't.vid', $vocabulary->vid, '=' );
  
  if( $limit>=0 )
    $query
      ->range( 0, $limit );
  
  $query  = $query
    ->execute();
  
  foreach( $query as $t )
    $terms[]  = _commander_argument( $t->name );
  
  return $terms;
}



/* Form argument types */
function _commander_validate_form_element( $environment, $values, $arg_def ) {
  return TRUE;
}
function _commander_load_form_element( $environment, $values, $arg_def ) {
  return $values;
}
function _commander_list_form_element( $environment, $input, $limit, $arg_def=NULL ) {
  return $values;
}
function _commander_default_form_element_value( $environment, $arg_def ) {
  return NULL;
}



/**
 *  Execute the "set-message" command: Display the given message as a result
 *
 *  @param environment (array) The commander-style environment array
 *  @param arguments (array) An associative list of all arguments. Each argument's value is an array with the values that have been given
 *  @return (bool) Whether or not the command has been executed successfully
 */
function _commander_execute_set_message( $environment, $arguments ) {
  
  $arguments	= $arguments[MODULE_COMMANDER_UNNAMED_ARGUMENTS_INDEX];
  
  $message  = implode( ' ', $arguments );
  drupal_set_message( $message );
  
  return TRUE;
  
}


/**
 *  Execute the "list-commands" command: Display a detailed description of the given command or a list of all commands and their descriptions
 *
 *  @param environment (array) The commander-style environment array
 *  @param arguments (array) An associative list of all arguments. Each argument's value is an array with the values that have been given
 *  @return (bool) Whether or not the command has been executed successfully
 */
function _commander_execute_list( $environment, $arguments ) {
  
  $arguments	= isset($arguments[MODULE_COMMANDER_UNNAMED_ARGUMENTS_INDEX]) ? $arguments[MODULE_COMMANDER_UNNAMED_ARGUMENTS_INDEX] : array();
  $filter     = count($arguments)>0;
  $detailed   = $filter;
  
  $commands = commander_get_commands( $environment['user'] );
  $types    = commander_get_argument_types();
  
  $result   = array();
  foreach( $commands as $name=>$command ) {
    
    if( !$filter || in_array($name,$arguments) || (isset($command['alias']) && in_array($command['alias'],$arguments)) ) {
      
      $item     = $name.(isset($command['alias'])?' ('.$command['alias'].')':'').' - '.$command['description'];
      
      if( $detailed ) {
        
        if( isset($command['arguments']) ) {
          
          $list = array();
          
          foreach( $command['arguments'] as $name=>$argument ) {
            
            $description  = $name . (isset($argument['alias'])?'|'.$argument['alias'].'|':'');
            $description  .= ' (' . $types[ $argument['type'] ]['name'] . ')';
            if( isset($argument['description']) )
              $description  .= ' - ' . $argument['description'];
            
            $list[] = $description;
            
          }
          
          if( $list )
            $item .= theme( 'item_list', array( 'items'=>$list ) );
          
        }
      }
      
      $result[] = $item;
      
    }
    
  }
  
  $result   = theme( 'item_list', array( 'items'=>$result ) );
  
  drupal_set_message( $result );
  
  return TRUE;
  
}


/**
 *  Execute the "alias-command" command: Store/Overwrite the given alias. The first argument gives the name, the second the command to be executed
 *
 *  @param environment (array) The commander-style environment array
 *  @param arguments (array) An associative list of all arguments. Each argument's value is an array with the values that have been given
 *  @return (bool) Whether or not the command has been executed successfully
 */
function _commander_execute_alias( $environment, $arguments ) {
  
  $arguments	= $arguments[MODULE_COMMANDER_UNNAMED_ARGUMENTS_INDEX];
  
  if( count($arguments)<2 ) {
    drupal_set_message( t('The command %command requires exactly two arguments!',array('%command'=>'alias-command')), 'warning' );
    return FALSE;
  }
  
  $name       = $arguments[0];
  $command    = $arguments[1];
  
  $commands   = commander_get_commands();
  $aliases    = variable_get( MODULE_COMMANDER_VARIABLE_ALIASES, array() );
  
  if( isset($commands[$name]) && !isset($aliases[$name]) ) {
    drupal_set_message( t('There is already a command named %name!',array('%name'=>$name)), 'warning' );
    return FALSE;
  }
  
  // Machine name valid?
  if( preg_replace( '@([a-z0-9\-]+)@', '', $name ) ) {
    drupal_set_message( t('Please enter a valid alias name!'), 'warning' );
    return FALSE;
  }
  
  $overwrite  = isset($aliases[$name]);
  $aliases[$name] = array( 'command'=>$command );
  variable_set( MODULE_COMMANDER_VARIABLE_ALIASES, $aliases );
  
  if( $overwrite )
    drupal_set_message( t('The alias %name has been overwritten.',array('%name'=>$name)) );
  else
    drupal_set_message( t('The alias %name has been created.',array('%name'=>$name)) );
  
  return TRUE;
  
}


/**
 *  Execute the "execute-commands" command: Each argument will be interpreted as a command
 *
 *  @param environment (array) The commander-style environment array
 *  @param arguments (array) An associative list of all arguments. Each argument's value is an array with the values that have been given
 *  @return (bool) Whether or not the command has been executed successfully
 */
function _commander_execute_execute( $environment, $arguments ) {
  
  $arguments	= $arguments[MODULE_COMMANDER_UNNAMED_ARGUMENTS_INDEX];
  
  foreach( $arguments as $command ) {
    if( !commander_execute( $environment, $command ) )
      return FALSE;
  }
  
  return TRUE;
  
}


/**
 *  Execute the given aliased command: The command for the alias is stored as a drupal variable
 *
 *  @param environment (array) The commander-style environment array
 *  @param arguments (array) An associative list of all arguments. Each argument's value is an array with the values that have been given
 *  @return (bool) Whether or not the command has been executed successfully
 */
function _commander_execute_alias_command( $environment, $arguments ) {
  
  $aliases  = variable_get( MODULE_COMMANDER_VARIABLE_ALIASES, array() );
  
  return commander_execute( $environment, $aliases[ $environment['command']['machine_name'] ]['command'] );
  
}