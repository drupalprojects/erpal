(function ($) {

  Drupal.behaviors.timetracking = {
    attach: function (context, settings) {
      // Timer Class
      Timer = function(timetrackingId){
        this.timerId;
        this.timetrackingId = timetrackingId;
        // time
        this.hours = 0;
        this.minutes = 0;
        this.seconds = 0;
        this.setDefaultTime();
      }
      // Timer Methods
      Timer.prototype = {
        // start timer
        start: function(){
          this.timerId = setInterval(this.updateTime.bind(this), 1000);
        },
        // stop timer
        stop: function(){
          clearTimeout(this.timerId);
        },
        // Update timer
        updateTime: function(){
          var time = [], secText, minText, timeText;
          // increment time
          this.seconds++
          if(this.seconds == 60){
            this.minutes++;
            this.seconds = 0;
          }
          if(this.minutes == 60)
            this.hours++
          // digitals in format 01
          secText = this.formatDigital(this.seconds);
          minText = this.formatDigital(this.minutes);
          // collect time
          if(this.hours > 0)
            time.push(this.hours)
          time.push(minText)
          time.push(secText)
          //time = [this.hours, minText, secText];
          // format time h:mm:ss
          timeText = this.implode(':', time);
          // Print time
          $('.timetracking_duration_' + this.timetrackingId).text(timeText);
        },
        // Convert default time in format 9.99 in h:mm:ss and set default values
        setDefaultTime: function(){
          var hoursText, minutesText, defaultText, min, secondsText, sec;
          defaultText = $('.timetracking_duration_' + this.timetrackingId).text();
          // default hours
          hoursText = defaultText.split('.').slice(0)[0];
          hoursText = hoursText.replace(/\s*/, '');
          ;
          this.hours = hoursText;
          // default minutes
          minutesText = defaultText.split('.').slice(-1)[0];
          minutesText = minutesText.replace(/ +[a+-z]+\s*/, '');
          if(!minutesText)
            return
          min = 60 * minutesText / 100;
          min = min + '';
          // default seconds
          this.mimutes = min.split('.').slice(0)[0];
          if(secondsText = min.split('.').slice(-1)[0]){
            sec = 60 * secondsText / 100;
            this.seconds = Math.round(sec);
          }
        },
        // Digitals in format 01
        formatDigital: function(number){
          var numberText
          if(number < 10)
            numberText = '0' + number;
          else
            numberText = number;
          return numberText
        },
        // Join array elements with a string
        implode: function( glue, pieces ){	
          return ( ( pieces instanceof Array ) ? pieces.join ( glue ) : pieces );
        }
      }
      var timer;
      
      // Autostart
      $('.timetracking_button').each(function(index, item){
        // get id of timer
        var lastClass = $(this).attr('class').split(' ').slice(-1);
        var id = lastClass[0].split('timetracking_button_').join('');     
        currentState = $(this).attr("rel");
        if(currentState == 'on'){
          timer = new Timer(id);
          timer.start();
        }
      });
      
      // Start / Stop timer button
      $('.timetracking_button', context).click(function () {
        // get id of timer
        var lastClass = $(this).attr('class').split(' ').slice(-1);
        var id = lastClass[0].split('timetracking_button_').join('');
        // initialize timer if undefined
        if(!timer)
          timer = new Timer(id);
        // track time
        timetrackingToggle(id, timer);
        return false;
      });
    }
  };
  
  timetrackingToggle = function(id, timer) {
    var currentState;
    //the current state is set in link, so get it
    $('.timetracking_button_'+id).each(function(index, item){     
      currentState = $(this).attr("rel");
    });
    
    //prepare variables
    if (currentState == 'on')
    {
      var toggleURL = Drupal.settings.timetracking.on.togglepath+id+'/off/ajax';
    } else 
    if (currentState == 'off')
    {
      var toggleURL = Drupal.settings.timetracking.on.togglepath+id+'/on/ajax';
    }
    
    //now change all buttons of the class. We cannot use IDs because one button could appear multiple times at one page.
    $.get(toggleURL, function(data){	
      //prepare variables
      if (currentState == 'on')
      {
        timer.stop()
        var newState = 'off';
        var newText = Drupal.settings.timetracking.off.linktext;
        var newImage = Drupal.settings.timetracking.off.imagepath;
      } else 
      if (currentState == 'off')
      {
        timer.start()
        var newState = 'on';
        var newText = Drupal.settings.timetracking.on.linktext;
        var newImage = Drupal.settings.timetracking.on.imagepath;
      }
    
      //first stop all timetrackings
      $('.timetracking_button').each(function(index, button_element){
        $(this).attr("rel", 'off');  //set off state
      });
      $('.timetracking_button_image').each(function(index, button_element){
        offImage = Drupal.settings.timetracking.off.imagepath
        $(this).attr("src", offImage)//set off image
      });
      $('.timetracking_text').each(function(index, button_element){
        offText = Drupal.settings.timetracking.off.linktext;
        $(this).text(offText)//set off text
      });
      
      $('.timetracking_button_'+id).each(function(index, button_element){
        $(this).attr("rel", newState);  //set new state
      });
      $('.timetracking_button_image_'+id).each(function(index, button_element){
        $(this).attr("src", newImage)//set new image
      });
      $('.timetracking_text_'+id).each(function(index, button_element){
        $(this).text(newText)//set new text
      });
    });
  }
  
})(jQuery);
