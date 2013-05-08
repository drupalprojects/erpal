
Views better combine

--------------------------------------------------------------------------------

Module provides some improvements for Views combine filter.

When we want add conditions into combine filter we must add fields first. And
sometimes when we have some relations in views(or we have many fields) it can
cause duplication of views rows (even if we used DISTINCT and fields are
excluded from display).

This module provides "Exclude from SELECT" checkbox for global combine filters.
Fields are excluded from SELECT area to avoid duplications of results.

All fields that are in CONCAT_WS area will be deleted from SELECT section.

1)enable "Views better combine" module;
2)than flush caches;
3)create/edit view;
4)create/edit combine filter;
4)check "Exclude from SELECT" checkbox (very last option);
5)save view.
