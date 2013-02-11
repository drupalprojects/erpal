<?php
/**
 *  @file commander/inc/client.inc
 *  @author Thiemo Müller
 *  @version 1.0
 *  
 *  All handling of client interaction is to be done here.
 */

/**
 *  AJAX request to simply execute the given command
 *  
 *  @return NULL
 */
function _commander_ajax_execute() {
  if( !isset($_GET['input']) || !isset($_GET['environment']) )
    die( 'Input/Environment missing!' );
  
  $form_state = array(
    'environment' => json_decode( $_GET['environment'] ),
    'values'      => array(
      'command'     => $_GET['input'],
    ),
  );
  
  $messages = commander_execute_form_submit_handler( $form_state );
  
  $rendered = '';
  foreach( $messages as $entry )
    $rendered .= theme( 'commander_log_entry', array('entry'=>$entry) );
  
  drupal_json_output( array(
    'result'    => $form_state['result'],
    'messages'  => $messages,
    'display'   => $rendered,
  ) );
}

/**
 *  AJAX request to simply display the console only (no surrounding page elements)
 *
 *  @return NULL
 */
function _commander_console() {
  if( !isset($_GET['environment']) )
    die( 'Environment missing!' );
  
  $console  = theme( 'commander_console_overlay', array( 'environment'=>json_decode( $_GET['environment'] ) ) );
  
  die( $console );
}

/**
 *  AJAX request for auto completion
 *  
 *  @param value The entered value
 *  @return An associative array containing the suggestions
 */
function _commander_autocomplete( $value ) {
  
  global $user;
  $commands = commander_get_commands( $user );
  $types    = commander_get_argument_types();
  
  $vlen     = strlen( $value );
  $space_at = strpos( $value, ' ' );
  
  // If no space was entered yet, we'll suggest command names
  if( $space_at===FALSE ) {
    
    $command_names  = array();
    // foreach loop, since we also want to suggest aliases
    foreach( $commands as $name=>$command ) {
      if( substr($name,0,$vlen)==$value )
        $command_names[$name] = $name;
      
      if( isset($command['alias']) && substr($command['alias'],0,$vlen)==$value )
        $command_names[ $command['alias'] ]  = $command['alias'];
    }
    
    ksort( $command_names );
    
    drupal_json_output( $command_names );
    return;
    
  }
  
  // Get the definition of the entered command
  $name       = substr( $value, 0, $space_at );
  $command    = NULL;
  foreach( $commands as $cname=>$c ) {
    
    if( $cname==$name || (isset($c['alias']) && $c['alias']==$name) ) {
      $command  = $c;
      break;
    }
    
  }
  
  if( !$command ) {
    drupal_json_output( array() );
    return;
  }
  
  // Load parser and parse as far as we can
  module_load_include( 'php', 'commander', 'lib/morpol_cl_parser' );
  
  $environment            = commander_get_environment( TRUE );
  $environment['command'] = $command;
  $environment['input']   = $value;
  
  $flags            = _commander_get_command_parsing_flags( $command );
  
  $defaults         = commander_get_command_defaults( $environment, $command );
  $result           = MORPOL_CommandLineParser::parse( substr( $value, $space_at+1 ), $flags, $defaults, TRUE, '\\', NULL, MODULE_COMMANDER_UNNAMED_ARGUMENTS_INDEX );
  $arguments        = $result[ 'arguments' ];
  $unknown          = $result[ 'unknown' ];
  $suggestions      = array();
  $limit            = MODULE_COMMANDER_MAX_SUGGESTIONS;
  
  // For commands with unnamed arguments, the module itself may give suggestions. Else there simply are none.
  if( $command['type']==COMMANDER_COMMAND_TYPE_UNNAMED_ARGUMENTS || !isset($command['arguments']) ) {
    
    if( isset($command['autocomplete']) ) {
      if( isset($command['file']) )
        module_load_include( '', $command['module'], $command['file'] );
      
      $suggestions  = $command['autocomplete']( $environment, $arguments, $limit );
    }
    
  }
  else {
    $name     = NULL;
    $argument = NULL;
    
    // Get last entered name/argument
    foreach( $arguments as $key=>$val ) {
      if( $val['start']<0 )
        continue;
      
      if( !$argument || $val['start']>$argument['start'] ) {
        $name     = $key;
        $argument = $val;
      }
    }
    
    // Anything entered yet?
    if( $name || count($unknown) ) {
      
      $join_unknown = !!count($unknown);
      $prepend      = $environment['input'];
      if( $join_unknown ) {
        $given        = $unknown[ 0 ];
        $join_unknown &= isset($command['auto_argument']) && !$given['name'] && !count($arguments[ $command['auto_argument'] ][ 'values' ]);
      }
      
      if( $join_unknown ) {
        
        $prepend  = $environment['input'] . (in_array($environment['input'][ strlen($environment['input'])-1 ],array(' ','-','+'))?'':' ');
        $entered  = '';
        $start    = strlen($prepend);
        $end      = -1;
        
        foreach( $given['values'] as $value ) {
          //$entered  .= ($entered?' ':'') . $value['value'];
          if( $value['start']<$start )
            $start  = $value['start'];
          if( $value['end']>$end )
            $end    = $value['end'];
        }
        
        $start    += $space_at+1;
        $end      += $space_at;
        
        $entered  = substr( $prepend, $start, $end-$start+1 );
        $prepend  = substr( $prepend, 0, $start-1 ) . ' ' . ($command['type']==COMMANDER_COMMAND_TYPE_SIGNED_ARGUMENTS ? '-'.$command['auto_argument'].' ' : $command['auto_argument'].'=') . _commander_argument( $entered ) . substr( $prepend, $end+1 );
        
      }
      
      // Suggest argument name
      if( !$name || (count($unknown) && $unknown[count($unknown)-1]['start']>$argument['start']) ) {
        
        $given    = $unknown[ count( $unknown ) - 1 ];
        
        if( !count($given['values']) ) {
          
          $name = $given['name'];
          $len  = strlen( $name );
          ksort( $command['arguments'] );
          
          foreach( $command['arguments'] as $arg_name=>$arg ) {
            
            if( substr($arg_name,0,$len)==$name ) {
              $suggestions[]  =  $prepend . substr($arg_name,$len) . ($command['type']==COMMANDER_COMMAND_TYPE_SIGNED_ARGUMENTS ? ' ' : '=');
              if( count($suggestions)==$limit )
                break;
            }
            elseif( isset($arg['alias']) && substr($arg['alias'],0,$len)==$name ) {
              $suggestions[]  = $prepend . substr($arg['alias'],$len) . ($command['type']==COMMANDER_COMMAND_TYPE_SIGNED_ARGUMENTS ? ' ' : '=');
              if( count($suggestions)==$limit )
                break;
            }
            
          }
          
          $join_unknown = FALSE;
          
        }
        
      }
      
      // Suggest argument values
      elseif( !count($unknown) ) {
        
        $arg    = _commander_get_by_name_or_alias( $command['arguments'], $name );
        $type   = $types[ $arg[ 'type' ] ];
        $value  = count($argument['values']) ? $argument['values'][ count($argument['values'])-1 ][ 'value' ] : NULL;
        if( isset($type['list']) ) {
          if( isset($type['file']) )
            module_load_include( '', $type['module'], $type['file'] );
          
          $suggestions  = $type['list']( $environment, $value, $limit, $arg );
          foreach( $suggestions as $i=>$suggestion )
            $suggestions[$i]  = ($value ? substr($prepend,0,-strlen($value)) : $prepend.' ') . $suggestion . ' ';
            //$suggestions[$i]  = ($value ? substr($environment['input'],0,-strlen($value)) : $environment['input'].' ') . $suggestion . ' ';
        }
        
        $join_unknown = FALSE;
        
      }
      
      if( $join_unknown )
        $suggestions[]  = $prepend;
      
    }
    // Nothing entered - suggest argument names
    else {
      
      foreach( $command['arguments'] as $arg_name=>$arg ) {
        
        if( $command['type']==COMMANDER_COMMAND_TYPE_SIGNED_ARGUMENTS )
          $suggestions[]  = $environment['input']  . '-' . $arg_name . ' ';
        else
          $suggestions[]  = $environment['input']  . $arg_name . '=';
        
        if( count($suggestions)==$limit )
          break;
        
      }
      
    }
    
  }
  
  $result = array();
  foreach( $suggestions as $suggestion )
    $result[$suggestion]  = $suggestion;
  
  drupal_json_output( $result );
  
}
