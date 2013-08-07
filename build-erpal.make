api = 2
core = 7.x

; Include the definition for how to build Drupal core directly, including patches:
includes[] = drupal-org-core.make

; Download the install profile and recursively build all its dependencies:
projects[erpal][download][type] = git
projects[erpal][download][url] = http://git.drupal.org/project/erpal.git
projects[erpal][download][branch] = 7.x-stable
;projects[erpal][download][tag] = TAG_PLACEHOLDER
projects[erpal][type] = profile
