function timetracking_toggle(id)
{
  (function ($) {
    var currentState;
    //the current state is set in link, so get it
    currentState = $('#timetracking_button_'+id).attr("rel");

    //prepare variables
    if (currentState == 'on')
    {
      var toggleURL = Drupal.settings.timetracking.on.togglepath+id+'/off/ajax';
      var newState = 'off';
      var newText = Drupal.settings.timetracking.off.linktext;
      var newImage = Drupal.settings.timetracking.off.imagepath;
    } else if (currentState == 'off')
    {
      var toggleURL = Drupal.settings.timetracking.on.togglepath+id+'/on/ajax';
      var newState = 'on';
      var newText = Drupal.settings.timetracking.on.linktext;
      var newImage = Drupal.settings.timetracking.on.imagepath;
    }

    $.get(toggleURL,
        function(data){	
          $('#timetracking_button_'+id).attr("rel", newState);  //set new state
          $('#timetracking_button_image_'+id).attr("src", newImage)//set new image
          $('#timetracking_text_'+id).text(newText)//set new text
        }
      );
        
  })(jQuery);
  
  return false;
}