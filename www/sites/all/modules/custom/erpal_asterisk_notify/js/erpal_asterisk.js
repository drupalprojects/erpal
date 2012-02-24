WEB_SOCKET_SWF_LOCATION = "sites/all/modules/custom/erpal_asterisk_notify/nicokaiser-php-websocket/client/js/WebSocketMain.swf";

(function($) {
$(document).ready(function() {

    WebPush.log = function(msg){ $('body').append(msg + '<br/>') }; // function(msg){};

    var server = new WebPush('ws://localhost:3081/erpal_asterisk');

    // WebPush events

    server.bind('open', function() {
        /*$('#status').removeClass().addClass('online').html('online');
        $('#disconnect').show();
        $('#subscribe').show();*/
		WebPush.log('Opened.');
    });

    server.bind('connection_disconnected', function() {
        //$('#status').removeClass().addClass('offline').html('offline');
		WebPush.log('Disconnected.');
    });

    server.bind('close', function() {
        //$('#status').removeClass().addClass('offline').html('offline');
		WebPush.log('Closed.');
    });

    server.bind('connection_failed', function() {
        //$('#status').removeClass().addClass('error').html('error');
		WebPush.log('Connection failed.');
    });

    server.bind('message', function(data) {
        WebPush.log('Received: ' + data);
    });

    // Click events

    /*$('#send').click(function(){
        var text = $('#message').val();
        WebPush.log('Sent: ' + text);
        server.send(text);
        $('#message').val("");
    });*/

});
})(jQuery);