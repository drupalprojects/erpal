api = 2
core = 7.x

projects[drupal][type] = core
projects[drupal][version] = 7.22

; Patches for Core
projects[drupal][patch][] = "http://drupal.org/files/1146244-82-node-save-on-insert.patch"
projects[drupal][patch][] = "http://drupal.org/files/d7-move-access-to-join-condition-1349080-131.patch"

projects[drupal][patch][] = "http://drupal.org/files/issues/1074108-skip-profile-2.patch"
projects[drupal][patch][] = "http://drupal.org/files/drupal-1630110-1-hide_other_profiles.patch"
projects[drupal][patch][] = "http://drupal.org/files/issues/install-redirect-on-empty-database-728702-36.patch"
projects[drupal][patch][] = "http://drupal.org/files/drupal-1470656-14.patch"
projects[drupal][patch][] = "http://drupal.org/files/allow_change_system-requirements-1772316-4.patch"


; Download the install profile and recursively build all its dependencies:
projects[erpal][download][type] = git
projects[erpal][download][url] = http://git.drupal.org/project/erpal.git
projects[erpal][download][branch] = 7.x-stable
projects[erpal][type] = profile
