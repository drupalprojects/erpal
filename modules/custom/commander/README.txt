commander Module Copyright (c) 2013 Bright Solutions GmbH
Authors: Thiemo Müller
Credits: MORPOL Softwareentwicklung for the "CommandLineParser" PHP Class (see /lib/morpol_cl_parser.php)

Having trouble implementing the module? Any fancy feature requests or other questions? Please feel free to contact us at: info@brightsolutions.de



=== GENERAL INFO ===
The commander module provides you with the ability to execute command-style patterns right from your webpage.
Other modules may extend this module by providing their own commands and argument types.
The aim of this module is to provide a way for users to interact with these commands, so the module itself defines the most basic commands only:

set-message (echo) - Simply echo the given text
list-commands - List all available commands
alias-command - Create an alias for another command (usually shortening something)
execute-commands - Execute multiple commands at once


The module automatically adds a shortcut to open the console, if the shortcut_keys module is installed (defaults to double-tapping the BACKSLASH key (=> "^" at german keyboards)).
You can also use the commander-block to execute commands right on your webpage without any overlay. All results will be shown right within the block.
The console will not only show you command-related messages in the log, but also system-relevant messages right out of watchdog (for privileged users only) as well as all messages drupal has shown to your specific user account recently.
When executing a command using the interface, commander will automatically exclude all messages that were created during the execution and display them separately (either in the console or the block).



=== COMMANDER API ===
The commander module gives you two ways of extending it's functionality: You can either add commands or argument-types (or both of course).
Each command is an array defining it with the following keys:

description (string, required) The description of the command
machine_name (string, automatically derived) The name of the command
module (string, automatically derived) The name of the module defining the command
execute (function-name, required) The function to be called when the command is to be executed. The function will receive: $environment (see below) and $arguments (see below).
auto_argument (argument-name, optional) The name of the argument to add values to that have no key given.
alias (string, optional) An optional alias name for the command.
type (command-type, optional) The type of command. Must be one of the following:
  COMMANDER_COMMAND_TYPE_UNNAMED_ARGUMENTS - Arguments are given without any name. You can find all arguments in the MODULE_COMMANDER_UNNAMED_ARGUMENTS_INDEX argument-index.
  COMMANDER_COMMAND_TYPE_SIGNED_ARGUMENTS (default) - Arguments are given like '-name my_name' or '+title "my fancy title"'.
  COMMANDER_COMMAND_TYPE_EQUAL_ARGUMENTS - Arguments are given like 'name=value'.
file (filename, optional) The filename where to find all functions, if not stored in the module itself. This must be a relative path to the module defining the command.
access callback (function-name, optional) The access callback just like when defining menu items (defaults to user_access).
access arguments (array, optional) The arguments to be passed to the access callback. Defaults to array(MODULE_COMMANDER_PERMISSION_EXECUTE_ALL) if no callback was given or array() if only the arguments were skipped.
defaults (associative array, optional) Default values as an associative array like name=>function to allow defaults. Each default-function will receive: 
arguments (associative array, optional) The allowed arguments of the command. Each argument gives its name as the array-key and may define the following keys:
  machine_name (string, automatically derived) The name of the argument
  type (string, required) The type of the argument. See below for examples.
  required (boolean, optional) Whether or not this argument is required.
  name (string, required) The human-readable name of the argument.
  description (string, required) The human-readable description of the argument.
  alias (string, optional) An alias name for the argument.
  default (string, optional) How to get the default. Each argument type may define it's own default value callbacks. This may give a name of one of these. *ALL* argument types have an "static_value" default that will read the "default_value" key of the argument definition and use it as the default value.
  ... () Any additional parameters that related functions (such as the argument type's validate-function etc.) may require or use.
prepare (function-name, optional) A function to prepare the given arguments before they are validated and loaded.
validate (function-name, optional) A function to validate all given values once they have been validated and loaded.
autocomplete (function-name, optional) For commands of type COMMANDER_COMMAND_TYPE_UNNAMED_ARGUMENTS you may add a callback to return your own suggestions (return drupal autocomplete suggestions), like: $environment (see below), $arguments as an array containing the defined arguments and $limit as the max number of suggestions to provide.



Each argument type is an array defining it with the following keys:

name (string, required) The human-readable name of the command.
alias (string, optional) The alias name of the argument type.
file (filename, optional) The filename where to find all functions, if not stored in the module itself. This must be a relative path to the module defining the argument type.
validate (function-name, optional) A function to be called for validating a given plain value. It receives: $environment (see below), $values An array of the given string values and $arg_def The definition of the argument as given by the called command
load (function-name, optional) A function to be called for loading the PHP value from the string. Nodes for example will resolve to the actual node entity object. It receives the same values as validate and returns an array containing the loaded values in the same order it received them.
list (function-name, optional) A function to be called to get a list of suggested values for the value the user just entered (may be empty). It receives: $environment (see below), $input The input string, $limit How many results to return at last, may be -1 for no limit.
defaults (array, optional) An array defining defaults for the given type. Each entry gives it's name as the key and the function be called to get the value as the value. It receives: $environment (See below) and $arg_def The definition of the argument as given by the called command
argc (integer, optional) How much values this argument type must contain, defaults to -1 for no limit.


The following argument types are given by default:
bool (boolean) - A simple boolean value accepting true/false/yes/no/1/0 as values
int (integer) - A simple integer value
float (number) - A simple floating point number
string - A string value
datetime - A unix timestamp, gotten from strtotime(). Defaults: "now"
user - A user object, gotten by name/mail/uid. Defaults: "current_user"
node - A node object, gotten by "title (nid)". Defaults: "viewed_node"
taxonomy_term - A taxonomy term, gotten by "name". Add "vocabulary" entry to the argument definition wherever possible, giving the machine name of the corresponding vocabulary.
form_* - All standard drupal form elements. This is currently being refactored and moved into a submodule and thus shouldn't be used yet.



Each command is executed in a so called "environment". This environment contains information about where the command is being executed and who executes it.

By default the environment contains the following information:
user (user entity) The user executing the command.
q (path) The path under which the command is being executed. Since we're heavily working with JavaScript this is rarely the same as $_GET['q'] but that of the page where the console/block is being displayed. Mainly interesting for default values.
timestamp (timestamp) The time at which the command started executing.
remote (boolean) Whether or not the command is being executed from remote (i.e. console, block etc. or directly from within the current page being processed).
The following information is added as soon as specific input is available:
command (command definition) The definition of the command being executed, if available (no typos or access restrictions).
input (string) The original input string.



The commander module provides the following hooks to allow interaction (adding/altering):

commander_command () - Return an array of all commands your module defines with their names as the keys.
commander_command_alter ( &$commands ) - Alter all commands once they've been loaded. The base module uses this to add custom aliases for example.
commander_argument_type () - Return an array of all argument types your module defines with their names as the keys.
commander_argument_type_alter ( &$types ) - Alter all argument types once they've been loaded.
commander_environment ( &$environment ) - Alter the environment variable (extend it/overwrite it).



The commander module provides the following publicly available functions:

commander_execute ( $environment, $input ) - The heart of this module: Execute the given command in the given environment.
commander_get_commands ( $user=NULL ) - Get a list of all available commands, optionally filtered by user.
commander_get_argument_types () - Get a list of all available argument types.
commander_get_environment () - Create the environment variable.
commander_get_command_defaults ( $environment, $command ) - Get a list of all defaults of the given argument.
_commander_argument ( $value, $add_quotes=TRUE ) - Escape the given sequence.
commander_get_command_name ( $input )  - Get the name of the command to be executed.
commander_log ( $message, $global=FALSE ) - Add a message to be displayed in the console.
commander_get_log () - Get commander log messages.
commander_check_user_command_access ( $user, $command ) - Check whether the given user has access to the given command.