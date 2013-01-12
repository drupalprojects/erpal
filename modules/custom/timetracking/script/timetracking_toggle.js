(function ($) {
  
  Drupal.behaviors.timetracking = {
    attach: function (context, settings) {
      // Timer Class
      Timer = function(timetrackingId, button){
        this.timerId;
        this.timetrackingId = timetrackingId;
        this.button = button;
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
          if(!this.timerId)
            this.timerId = setInterval(this.incrementTime.bind(this), 1000);
        },
        // stop timer
        stop: function(){
          if(this.timerId){
            clearTimeout(this.timerId);
            delete this.timerId;
          }
        },
        // increment time
        incrementTime: function(){
          this.seconds++
          if(this.seconds == 60){
            this.minutes++;
            this.seconds = 0;
          }
          if(this.minutes == 60){
            this.hours++;
            this.minutes = 0;
          }
          this.updateTime();
        },
        // Update timer
        updateTime: function(){
          var time = [], secText, minText, timeText;
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
          var id = this.timetrackingId;
          $('.timetracking_button_' + id).find('.timetracking-time-suffix').text('');
          $('.timetracking_button_' + id).find('.timetracking-time').text(timeText);
        },
        // Convert default time in format 9.99 in h:mm:ss and set default values
        convertTime: function(timeText){
          var minutesDecimal, timeDecimal, secondsDecimal, time = {
            hours:0,
            minutes:0,
            seconds:0
          };
          // trim time
          timeDecimal = timeText.replace(/\s*/, '');
          // check time format
          if(timeText.indexOf('.') != -1){
            // hours
            time.hours = timeDecimal.split('.').slice(0)[0];
            
            // minutes
            minutesDecimal = 60 * (timeDecimal - time.hours);
            minutesDecimal = minutesDecimal + '';
            time.minutes =  minutesDecimal.split('.').slice(0)[0];
            
            // seconds
            if(minutesDecimal.indexOf('.') != -1){
              secondsDecimal = 60 * (minutesDecimal - time.minutes);
              time.seconds = Math.round(secondsDecimal);
            }
          }
          return time;
        },
        setDefaultTime: function(){
          var timeText = this.button.find('.timetracking-time').text();
          var time = this.convertTime(timeText);
          this.hours = time.hours;
          this.minutes = time.minutes;
          this.seconds = time.seconds;
          this.updateTime();
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
      
      var timers = [];
      
      // Autostart
      $('.timetracking_button').each(function(index, item){
        // get id of timer
        var timerClass = $(this).attr('class').split(' ')[1];
        var id = timerClass.split('timetracking_button_').join(''); 
        if(!timers[id]){
          timer = new Timer(id, $(this));
          timers[id] = timer;
          // start enabled timer
          currentState = $(this).attr("rel");
          if(currentState == 'on'){
            timer.start();
          }
        }
      });
      
      // Start / Stop timer button
      $('.timetracking_button', context).click(function () {
        if($(this).hasClass('in-progress'))
          return false;
        
        $('.timetracking_button').addClass('in-progress');
        // get id of timer
        var timerClass = $(this).attr('class').split(' ')[1];
        var id = timerClass.split('timetracking_button_').join('');
        // initialize timer if undefined
        if(!timers[id]){
          timer = new Timer(id, $(this));
          timers[id] = timer;
        }
        // track time
        timetrackingToggle(id, timers, $(this));
        return false;
      });
    }
  };
  
  timetrackingToggle = function(id, timers, button) {
    var timer = timers[id];
    var currentState;
    //the current state is set in link, so get it
    currentState = button.attr("rel");
    
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
      
      // first stop all timetrackings
      $('.timetracking_button[rel="on"]').each(function(index, button_element){
        $(this).attr("rel", 'off');  //set off state
        var timerClass = $(this).attr('class').split(' ')[1];
        var otherTimerId = timerClass.split('timetracking_button_').join('');
        // stop other timers
        if(otherTimerId != id && timers[otherTimerId]){
          timers[otherTimerId].stop();
          // set off image
          offImage = Drupal.settings.timetracking.off.imagepath
          $(this).find('.timetracking_button_image').attr("src", offImage);
          // set off text
          offText = Drupal.settings.timetracking.off.linktext;
          $(this).find('.timetracking_text').text(offText);
        }
      });
      
      
      $('.timetracking_button_' + id).attr("rel", newState);  //set new state
      $('.timetracking_button_' + id).find('.timetracking_button_image').attr("src", newImage)//set new image
      $('.timetracking_button_' + id).find('.timetracking_text').text(newText)//set new text
      $('.timetracking_button').removeClass('in-progress');
    });
  }

})(jQuery);
