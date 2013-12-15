api = 2
core = 7.x

projects[drupal][type] = core
projects[drupal][version] = 7.23

; Patches for Core
projects[drupal][patch][] = "http://drupal.org/files/node-access-records-1146244-110.patch"
projects[drupal][patch][] = "http://drupal.org/files/issues/1349080-149-d7-move-access-to-join-condition-update-do-not-test.patch"

projects[drupal][patch][] = "http://drupal.org/files/issues/install-redirect-on-empty-database-728702-36.patch"
projects[drupal][patch][] = "http://drupal.org/files/drupal-1470656-14.patch"
projects[drupal][patch][] = "http://drupal.org/files/drupal7-allow_change_system-requirements-1772316-18.patch"


; Download the install profile and recursively build all its dependencies:
projects[erpal][download][type] = git
projects[erpal][download][url] = http://git.drupal.org/project/erpal.git
projects[erpal][download][branch] = 7.x-stable
projects[erpal][type] = profile
