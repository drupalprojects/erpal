shortcut_keys Module Copyright (c) 2013 Bright Solutions GmbH
Authors: Thiemo Müller

Having trouble implementing the module? Any fancy feature requests or other questions? Please feel free to contact us at: info@brightsolutions.de



=== GENERAL INFO ===
The shortcut_keys module provides you with an interface to easily add keyboard shortcuts to your page. Due to its design you can easily extend it adding your very custom command types etc.
By default the module adds
- an "url" shortcut type to simply open the entered URL when a user with the according permissions presses the given shortcut.
- an "javascript" shortcut type to simply execute the given JavaScript snippet when a user with the according permissions presses the given shortcut.

When using the "url" shortcut type you can use "<front>" to link to the frontpage and add dynamic arguments to be replaced with the values of the currently viewed page before visiting the new one. Like:
node/add/erpal-project?field_value=[1]&destination=[q]
When viewing a node, this would automatically set field_value to the ID of the viewed node and redirect to the current page once the new node has been added.
But use with caution! If the user was viewing a user profile, this link would add an ID that has a quite different meaning.
You can also use external URLs as well as "mailto:".

For permission management each shortcut belongs to one or more groups that you can then assign users to. If a shortcut doesn't have any groups assigned only administrators will be able to execute the shortcut.

A user may execute the given shortcut if:
  - He is allowed to execute the given shortcut type
  AND
  - He is allowed to access one of the groups that this shortcut belongs to
OR
  - He has the "Use any shortcut key" permission

Each shortcut has a name, machine_name, type, value (like the URL or JavaScript snippet), keys to be pressed (like SHIFT+T) and the following options:
- Press double - Double tap the given shortcut keys to execute it. The "commander" module for example provides a double-tap shortcut for accessing the console by default.
- Confirm dialog - Whether or not the user shall confirm to execute the shortcut first using a simple JavaScript modal dialog box.
- Always execute this shortcut - By default shortcuts will only be executed if no input element (including textareas and select boxes) is currently focused. This will enable the shortcut even if an element is focused.
- Active - Whether or not the shortcut is active or disabled



=== SHORTCUT KEYS API ===
Each shortcut has got the following properties:

name (string) - The human-readable name of the shortcut.
machine_name (string) The name of the shortcut.
groups (array) The groups this shortcut belongs to as group_machine_name=>group_machine_name.
type (string) The type of the shortcut.
value (string) The value to be used when executing (by default a URL or JS snippet)
keys (string) The keys to execute this command. Multiple keys are separated by the plus sign. Order of pressing doesn't matter.
press_double (boolean) See above.
confirm_dialog (boolean) See above.
always_execute (boolean) See above.
active (boolean) See above.



Using the "shortcut_keys_shortcut_type" hook you can add your custom shortcut types. You may also use "hook_form_alter" for the "shortcut_keys_admin_shortcut_edit_form" form to add your custom values. All entered values will automatically be saved to the database.
Each type gives it's name in the associative array returned by the function call. This name must be added as a JavaScript like: "shortcut_keys.callbacks.[NAME_OF_MY_CUSTOM_TYPE] = function( command ) {...}".
Each type gives may provide the following properties:

name (string, required) The human-readable name of the type.
access callback (function-name, optional) The access callback just like when defining menu items (defaults to user_access).
access arguments (array, optional) The arguments to be passed to the access callback. Defaults to array(MODULE_SHORTCUT_KEYS_PERMISSION_USE_ALL) if no callback was given or array() if only the arguments were skipped.
block (function-name, optional) A function to be called when the block gets rendered. This way you may either add/remove shortcuts from being displayed or add custom HTML code to be appended to the block by returning it.



Using the "shortcut_keys_api" hook you'll stay informed about changes of shortcuts and groups. Arguments are:
- $type (string) The type of operation (save_shortcut, delete_shortcut, save_shortcut_group, delete_shortcut_group, use_shortcuts)
- &$reference (array) The shortcut-definition, group-definition or list of shortcuts to be used
- $previons=NULL (array) The previous definition of the group or command (for save-operations. NULL if the shortcut/group was just added).



The shortcut_keys provides the following publicly accessible methods:
shortcut_keys_get_javascript_keycodes () - Get a list of all keys and their correspondig JavaScript KeyCode equivalents.
shortcut_keys_get_shortcut_groups ( $user=NULL ) - Get all registered shortcut groups, optionally filtered by permission check for the given user.
shortcut_keys_get_shortcut_types ( $user=NULL ) - Get all registered shortcut types, optionally filtered by permission check for the given user.
shortcut_keys_get_shortcuts ( $user=NULL, $include_inactive=FALSE ) - Get all registered shortcuts, optionally filtered by permission check for the given user.
shortcut_keys_set_shortcut_groups ( $groups ) - Set all shortcut groups.
shortcut_keys_delete_shortcut_group ( $group ) - Delete the given shortcut group, removing all links to it from all current shortcuts.
shortcut_keys_delete_shortcut ( $name ) - Remove the given shortcut.
shortcut_keys_import_shortcuts ( $shortcuts, $overwrite_existing=FALSE ) - Import a set of shortcuts, optionally overwriting existing.
shortcut_keys_set_shortcuts ( $shortcuts ) - Set all shortcuts.
shortcut_keys_shortcut_load ( $machine_name ) - Implements hook_load() for pseudo entity shortcut.
shortcut_keys_shortcut_group_load ( $machine_name ) - Implements hook_load() for pseudo entity shortcut group.