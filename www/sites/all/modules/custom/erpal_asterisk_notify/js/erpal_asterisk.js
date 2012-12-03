(function($) {
  Drupal.behaviors.asteriskClient = {
  	attach: function() {

  // fetching settings defined in erpal_asterisk_notify.module
  var client_ip = Drupal.settings.erpal_asterisk_notify.client_ip;
  var nodejs_host = Drupal.settings.erpal_asterisk_notify.nodejs_host;
  var nodejs_http_port = Drupal.settings.erpal_asterisk_notify.nodejs_http_port;
  var nodejs_socket_port = Drupal.settings.erpal_asterisk_notify.nodejs_socket_port;
  var client_phone_numbers = Drupal.settings.erpal_asterisk_notify.client_phone_numbers;
  // establish socket.io connection to node.js server
  var socket = io.connect('http://' + nodejs_host + ':' + nodejs_socket_port);
  
  // incoming call arrives - display notification
  socket.on('caller_data', function (data) {
  	
    $("body").append(data.caller_data);
    $('.erpal-asterisk-notify').css('bottom', '-' + $('.erpal-asterisk-notify').css('height'));
    $('.erpal-asterisk-notify').animate({
          bottom: 0
     }, 'fast');
  });
  
  
  // if node.js server acknowledged connection, register the client
  socket.on('status', function (data) {
    console.log(data);
    if(data.status == "ok") {
      registerClient();
    }
  });

  // TODO: replace hardcoded phone number
  // send AJAX request to node.js server to register client with his phone number(s)
  function registerClient() {
    $.post(
      'http://' + nodejs_host + ':' + nodejs_http_port + '/register', 
      { 
        ip : client_ip, 
        phone_numbers : '[ "'+client_phone_numbers.join('", "')+'" ]' 
      }, 
      function(data, textStatus) {
        console.log(data);
      }
    );
  }
  
  // listen to click on status buttons (available / not available) and send response via socket.io
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

    }
  }
}(jQuery));	