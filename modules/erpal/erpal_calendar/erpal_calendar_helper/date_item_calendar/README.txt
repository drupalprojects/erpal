
Date Item Calendar module

--------------------------------------------------------------------------------

Provides special field "field_date_item_date" for date_item entity
http://drupal.org/project/date_item
This is ordinary DATE field that contains date in UNIX format.

"field_date_item_date" is created for integration with full calendar module.
http://drupal.org/project/fullcalendar

Full calendar can only update fields of entities(but not properties).

This module also provides sync between "date_from" and "date_till" properties in
date_item entity and "field_date_item_date" "from" and "to" date values in
this entity.