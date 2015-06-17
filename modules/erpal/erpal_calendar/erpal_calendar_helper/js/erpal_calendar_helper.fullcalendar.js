(function($) {

  $(document).ready(function() {
    erpal_calendar_helper_page_handler();
  });

  Drupal.behaviors.erpal_calendar_helper = {
    attach: function(context) {
      erpal_calendar_helper_page_handler();
    }
  };

  /**
   * Helper function. Handles page process.
   */
  function erpal_calendar_helper_page_handler() {
    // Append "add date" link into each day cell of the month view.
    $('div.view-full-calendar div.fc-view-month td > div > div.fc-day-number').each(function() {
      // Check if link already exists.
      if ($(this).find('a.erpal-fc-add-date-day').size() == 0) {
        // Append "add date" link.
        $(this).append('<a style="color: black;" onclick="return false;" href="#" class="erpal-fc-add-date-day">+</a>');
      }
    });
    
    // Append "add date" link into each day cell of the day view.
    $('div.view-full-calendar .fc-view-agendaDay .fc-agenda-slots tr > td').each(function() {
      // Check if link already exists.
      if ($(this).find('a.erpal-fc-add-date-hour').size() == 0) {
        // Append "add date" link.
        $(this).append('<a style="float: right; color: black;" onclick="return false;" href="#" class="erpal-fc-add-date-hour">+</a>');
      }
    });
  }


  /**
   * Add custom erpal_fullcalendar plugin
   */
  Drupal.fullcalendar.plugins.erpal_fullcalendar = {
    options: function(fullcalendar, settings) {

      var options = {
        dayClick: function(date, allDay, jsEvent, view) {
          // Get date of current clicked day
                    
          // Redirect to "add date" page on "+" click
          if($(jsEvent.target).hasClass('erpal-fc-add-date-day')){
            var formatted_date = $.fullCalendar.formatDate(date, 'yyyy-MMM-dd');
            var link = Drupal.settings.basePath+'node/add/erpal-date?erpal_date=' + formatted_date;
            window.open(link, '_blank');
          }
          
          // Redirect to "add date" page on "+" click
          if($(jsEvent.target).hasClass('erpal-fc-add-date-hour')){
            var formatted_date = $.fullCalendar.formatDate(date, 'yyyy-MMM-dd HH:mm');
            var link = Drupal.settings.basePath+'node/add/erpal-date?erpal_date=' + encodeURIComponent(formatted_date);
            window.open(link, '_blank');
          }
          
          return false;
        }
       
      };

      // Merge  options in settings.
      $.extend(options, settings.fullcalendar);

      return options;
    }
  };

}(jQuery));
