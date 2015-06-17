(function($) {

  $(document).ready(function() {
    // remove resize div from excluded elements
    if (Drupal.settings.date_item_calendar_not_resizable != undefined) {
      var disabled = Drupal.settings.date_item_calendar_not_resizable;
      date_item_calendar_disabled(disabled);
    }
  });

  Drupal.behaviors.date_item_calendar = {
    attach: function(context) {
      // remove resize div from excluded elements
      if (Drupal.settings.date_item_calendar_not_resizable != undefined) {
        var disabled = Drupal.settings.date_item_calendar_not_resizable;
        date_item_calendar_disabled(disabled);
      }
    }
  };

  function date_item_calendar_disabled(disabled) {
    $('div.fullcalendar a.fc-event-field-field-date-item-date').once('processed').each(function() {
      var href = $(this).attr('href');
      id = href.replace(/.*\//, '');
      if ($.inArray(id, disabled) != -1) {
        $(this).find('div.ui-resizable-handle').remove();
      }
    });
  }

}(jQuery));
