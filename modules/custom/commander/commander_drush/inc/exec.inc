<?php
/**
 *  @file commander_drush/inc/exec.inc
 *  @author Thiemo Müller
 *  @version 1.0
 *  
 *  Here we store all drush command and argument type handlers.
 */

/**
 *  Execute the given drush command
 *  
 *  @param environment (array) The commander-style environment array
 *  @param arguments (array) An associative list of all arguments. Each argument's value is an array with the values that have been given
 *  @return (bool) Whether or not the command has been executed successfully
 */
function _commander_drush_execute( $environment, $arguments ) {
  
  if( $environment['command']['machine_name']=='drush-version' ) {
    $version  = commander_drush_get_version();
    drupal_set_message( $version );
    return TRUE;
  }
  
  switch( $environment['command']['machine_name'] ) {
    case 'cache-clear':
      $pass = 'cc '.$arguments['type'][0];
      break;
  }
  
  $result     = NULL;
  $successful = commander_drush_execute( $pass, $result );
  
  if( $successful )
    drupal_set_message( $result );
  else
    drupal_set_message( $result, 'warning' );
  
  return TRUE;
  
}




/*  drush argument type: cache name */
function _commander_validate_cache_name( $environment, $values, $arg_def ) {
  return in_array( $values[0], _commander_list_cache_name( $environment, '', -1 ) );
}
function _commander_list_cache_name( $environment, $input, $limit ) {
  $lines  = NULL;
  $result = commander_drush_execute( 'cc', $lines, "0\n" );
  $lines  = explode( "\n", $lines );
  $lines  = array_slice( $lines, 3 );
  
  $names  = array();
  foreach( $lines as $line ) {
    $parts    = explode( ':', $line );
    if( count($parts)==1 )
      continue;
    
    $name     = trim( $parts[1] );
    if( $input && substr($name,0,strlen($input))!==$input )
      continue;
    
    $names[]  = $name;
    
    if( $limit>=0 && count($names)==$limit )
      break;
  }
  
  return $names;
}