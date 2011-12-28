
(function ($) {

Drupal.behaviors.nodejsWatchdog = {
  attach: function () {
    $("#admin-dblog tr:even").removeClass('odd').addClass('even');
    $("#admin-dblog tr:odd").removeClass('even').addClass('odd');
  }
};

}(jQuery));

