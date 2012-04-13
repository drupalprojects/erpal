(function($) {
$(document).ready(function() {

  // fetching settings defined in erpal_asterisk_notify.module
  var client_ip = Drupal.settings.erpal_asterisk_notify.client_ip;
  var nodejs_host = Drupal.settings.erpal_asterisk_notify.nodejs_host;
  var nodejs_http_port = Drupal.settings.erpal_asterisk_notify.nodejs_http_port;
  var nodejs_socket_port = Drupal.settings.erpal_asterisk_notify.nodejs_socket_port;

  var socket = io.connect('http://' + nodejs_host + ':' + nodejs_socket_port);
  socket.on('caller_data', function (data) {
    $("body").append(data.caller_data);
    $('.erpal-asterisk-notify').css('bottom', '-' + $('.erpal-asterisk-notify').css('height'));
    $('.erpal-asterisk-notify').animate({
          bottom: 0
     }, 'fast');
  });
  
  socket.on('status', function (data) {
    if(data.status == "ok") {
      registerClient();
    }
  });

  function registerClient() {
        $.post('http://' + nodejs_host + ':' + nodejs_http_port + '/register', { ip : client_ip, phone_numbers : '[ "004961513910793" ]' }, function(data, textStatus) {
          console.log(data);
        });
  }
  
  $(document).delegate('.erpal-asterisk-notify .status-buttons a.button', 'click', function () {
    if($(this).hasClass('available')) {
      socket.emit('action', { name: 'available' });
    }
    else if($(this).hasClass('not-available')) {
      socket.emit('action', { name: 'not available' });
      var notification = $(this).parentsUntil('.erpal-asterisk-notify').parent();
      notification.animate({
          bottom: '-' + notification.css('height')
        }, 'fast', function() {
          notification.remove();
      });
    }
  });

});
})(jQuery);