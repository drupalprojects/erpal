The SimpleTest Fixture module allows to use an existing 
database with Drupal configurations as fixture for testing 
(rather than the default SimpleTest behavior of building a 
test site up from install hooks).

The intention is to speed up the test cycle time by skipping 
the time-consuming process to build up test fixtures program-
matically.

INSTALLATION
============

See INSTALL.txt.


USAGE
=====

Instantiate your SimpleTest class from DrupalFixtureTestCase, e.g.

  class MyTestCase extends DrupalFixtureTestCase {}


(see simpletest_fixture.test for a basic example)


DRUSH INTEGRATION
=================

Use "drush fixture-generate" (or "drush fxg") to populate your fixture database with a current snapshot of your default database.

CAUTION: before running fixture-generate, create a backup of your database and make sure you've followed the instructions in INSTALL.txt.
