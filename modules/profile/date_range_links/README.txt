CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Requirements
 * Installation
 * Configuration
 * API
 * Maintainers


INTRODUCTION
------------
The Date range links module provides range links for date field.
Works with Date field and views exposed filter.Currently supports
only Date popup widget.

 * For a full description of the module, visit the project page:
   https://drupal.org/project/date_range_links

 * To submit bug reports and feature suggestions, or to track changes:
   https://drupal.org/project/issues/date_range_links


REQUIREMENTS
------------
This module requires the following modules:
 * Date (https://drupal.org/project/date)


INSTALLATION
------------
Install as you would normally install a contributed drupal module.
See: https://drupal.org/documentation/install/modules-themes/modules-7
for further information.


CONFIGURATION
-------------
To output range links you have to enable 'Show range links' checkbox on
field/exposed filter settings form.

 * To enable range links for Date field:
   - Go to Date field settings page
   - Enable 'Collect an end date' checkbox
   - Enable 'Show range links' checkbox

 * To enable range links for Date field on views exposed form:
   - Go to exposed Date filter settings
   - Operator should be 'Is between' or 'Is not between'
   - Enable 'Show range links' checkbox


API
---
See date_range_links.api.php


MAINTAINERS
-----------
Current maintainers:
 * Sergey Korzh (korgik) - https://drupal.org/user/813560
