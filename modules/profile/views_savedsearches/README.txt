$Id: README.txt,v 1.7 2010/01/18 14:34:48 aronnovak Exp $

Description
-----------
This module allows you to save your current configuration of exposed filters
for later use. This can be especially useful for Views with a lot of exposed
filters.

Whenever a View is changed, all saved searches for that View are deleted, to
prevent corruption.
If the user has JavaScript enabled, the saving and deleting process happens
through AHAH, and the new section is displayed below the exposed filters
section. When JavaScript is disabled, the new section is displayed above the
exposed filters section.


Dependencies
------------
* Views (http://drupal.org/project/views)

Submodules
----------
For Notifications integration, enable Views Saved Searches Subscriptions module.

Installation
------------
1) Place this module directory in your modules folder (this will usually be
   "sites/all/modules/").

2) Enable the module.

3) Configure which views will have the Saved Searches functionality at
   admin/build/views/tools/saved-searches.

4) Configure which roles (users) are allowed to use the functionality at
   admin/user/permissions - 'use views savedsearch'

Known issues
------------
Clean URL is neccessary to use the module.

Sponsor
-------
Paul Ektov of http://autobin.ru.
Inovae: http://agenceinovae.com/


Authors
-------
Wim Leers (Original Author) - http://wimleers.com/work
Nathan Haug (Drupal 6 Maintainer) - http://quicksketch.org
Aron Novak (current maintainer) @ Inovae

