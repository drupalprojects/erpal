/**
 * @file
 * Basic scripts for the Date range module.
 */

(function ($) {

  Drupal.behaviors.dateRangeLinks = {
    attach: function (context) {

      $('.field-widget-date-popup', context).each(function() {
        var $start_wrapper = $(this).find('.start-date-wrapper');
        var $end_wrapper = $(this).find('.end-date-wrapper');

        $(this).find('.date-range-links a').click(function() {
          $start_wrapper.find('input.popup-date-input').val($(this).data('date'));
          $start_wrapper.find('input.popup-time-input').val($(this).data('time'));

          $end_wrapper.find('input.popup-date-input').val($(this).data('date2'));
          $end_wrapper.find('input.popup-time-input').val($(this).data('time2'));

          return false;
        });
      });

      $('.views-widget .date-range-links', context).each(function() {
        var $widget_block = $(this).parent();

        var $start_wrapper = $widget_block.children().eq(0);
        var $end_wrapper = $widget_block.children().eq(1);

        $(this).find('a').click(function() {
          $start_wrapper.find('input.popup-date-input').val($(this).data('date'));
          $start_wrapper.find('input.popup-time-input').val($(this).data('time'));

          $end_wrapper.find('input.popup-date-input').val($(this).data('date2'));
          $end_wrapper.find('input.popup-time-input').val($(this).data('time2'));

          return false;
        });
      });
    }
  }

})(jQuery);
