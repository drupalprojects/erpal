Private files download permission
=================================

DESCRIPTION
----------------------------

This module aims to provide two useful features which Drupal itself is missing:
a simple permission to allow downloading of private files by role, plus the
ability to combine both public and private downloads.

Idea and code were inspired by
http://www.beacon9.ca/labs/drupal-7-private-files-module.

INSTALLATION / CONFIGURATION
----------------------------

Just browse to Configuration > Media > Private files download permission (url:
/admin/config/media/private-files-download-permission) and enter the path of
the subfolder to be considered as unprotected (and therefore "public"!).
This allows you to configure the site under Configuration > Media > Filesystem
(url: /admin/config/media/file-system) to use a full private filesystem, while
also enabling some of the files (those under the unprotected subfolder) to be
publicly accessible, thus taking advantage of the best of both methods.

Also configure which roles have access to your private files under People >
Permissions (url: /admin/people/permissions).

