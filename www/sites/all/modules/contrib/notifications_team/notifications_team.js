(function ($) {
  Drupal.behaviors.notifications_team = {
    attach: function (context, settings) {
      if ($('.notifications-team-selected').size() > 0) {
        notifications_team_init();
      }
      $("#edit-team-checkall").click(notifications_checkall);
    }
  };

  function notifications_team_init () {
    // Add "subscribed" class to subscribed users
    var active = $('.notifications-team-selected').val().split(',');
    $.each(active, function(i, n){
      $('.notifications-team-selected').siblings('div').children('span.uid-'+n).addClass('subscribed');
    });

    // Add click handler
    $('.notifications-team-selected').siblings('div').children('span').click(function(){
      var active = $('.notifications-team-selected').val().split(',');
      var classes = $(this).attr('class').split(' ');
      var uid;

      $.each(classes, function(i ,n) {
        var pos = n.search('uid-');
        if (pos != -1) {
          uid = n.substr(pos+4);
          return;
        };
      });

      if ($(this).is('.subscribed')){
        var index;
        $.each(active, function(i, n){if (n == uid) {index = i;};});
        active.splice(index,1);
      }
      else{
        active.push(uid);
      }

      $('.notifications-team-selected').val(active.join(','))
      $(this).toggleClass('subscribed');
    });
  }

  function notifications_checkall() {
    var checked = this.checked;
    $('.notifications-team-selected').siblings('div').children('span').each(function() {
      if((checked && !$(this).is('.subscribed')) || (!checked && $(this).hasClass('allchecked'))) {
        $(this).click();
        $(this).toggleClass('allchecked');
      }
    });
  }
}(jQuery));
