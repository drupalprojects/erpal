
ERPAL timetracking bulk export

----------------------


This module for Timetracking export.
Provides action for export nodes in CSV file. 
Provides hook: hook_erpal_timetracking_export.


hook_erpal_timetracking_export:
@return array $export_settings
  An associative array of export settings. Each item has settings for 
  export type. The keys of the array are the names of the export settings, 
  and each corresponding value is an associative array with the following 
  key-value pairs:
  {Required parameters}
  - 'title': string. It's a title of the exported type. Appears in export 
    settings form as radio button.
  - 'callback': callback function that handles node item in bulk operation.
    has parameters:
    - $node. returns $row array. I'll be line in exported file.
    - $context: array with parameters for this action.
    returns: array. Row item of exported file.
  {Non required parameters}
  - 'header': array. Contents header of exported file.
  - 'filename': name of exported file.
  - 'delimiter': string. It's a delimiter of .csv file. Default ';'.
  - 'enclosure': string. It's a enclosure of .csv file. Default '"'.
  You can add custom parameters and use then is $context variable. But be
  very careful and do checks.