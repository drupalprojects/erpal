********************************************************************
                     D R U P A L    M O D U L E
********************************************************************
Name: Ajax Checklist
Author: Anton de Wet (ascii at drupal dot phun dot net)
Drupal: 5
********************************************************************

The Ajax Checklist module implements a filter and associated javascript that allows you
to put something like this in a node:

Version 1.2 fixes the problem that the nodes with checklist values didn't work
in views, viewing only of checklists when you dont have save access

--------------------------------------------
Things to do before leaving the house for DrupalCon 2009:

[cb all1 Discuss flights]
[cb some1 Book group flights]

[cb user-step1 Did you check if the heating is off?]
[cb user-step2 Did you feed the cat?]
[cb user-step3 Do you have your credit card?]
--------------------------------------------

This will generate checkboxes in the node text that will update their settings in the
database (associated with the node and the checkbox id (the 2nd field with eg. step2))
with an ajax call.

Any checkbox id that starts with user- will be linked to the user, 
all other ids will be linked to the node.

Installation:
-------------

Enable the module. (Administer->Site building->Modules)
Set the user access. (Administer->User management->Access control)
   Find ajax_checklist module, assign update ajax checklists to the appropriate roles.

   NB: Any role will be able to see and toggle the checklists. Only roles allowed here
       will save that info to the database.

Create an input format. (Administer->Site configuration->Input formats)
   Add an input format (eg. Checklist)
     For filters select Ajax Checkbox filter and any others you'd like, 
       eg. URL and the line break converter.
     Save

Create a node of some type. Set the input format to your input filter (eg. Checklist).
In the body add something like the example above. Click some options. Open the same URL in
a different tab and see your checkbox status retained!

Have phun

Anton
