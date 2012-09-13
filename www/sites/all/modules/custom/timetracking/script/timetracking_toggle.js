function timetracking_toggle(id)
{
  (function ($) {
    var currentState;
    //the current state is set in link, so get it
    $('.timetracking_button_'+id).each(function(index, item){     
      currentState = $(this).attr("rel");
    });

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
    
    //first stop all timetrackings
    $('.timetracking_button').each(function(index, button_element){
      $(this).attr("rel", 'off');  //set off state
    });
    $('.timetracking_button_image').each(function(index, button_element){
      offImage = Drupal.settings.timetracking.off.imagepath
      $(this).attr("src", offImage)//set off image
    });
    $('.timetracking_text_').each(function(index, button_element){
      offText = Drupal.settings.timetracking.off.linktext;
      $(this).text(offText)//set off text
    });
    
    //now change all buttons of the class. We cannot use IDs because one button could appear multiple times at one page.
    $.get(toggleURL,
      function(data){	
        $('.timetracking_button_'+id).each(function(index, button_element){
          $(this).attr("rel", newState);  //set new state
        });
        $('.timetracking_button_image_'+id).each(function(index, button_element){
          $(this).attr("src", newImage)//set new image
        });
        $('.timetracking_text_'+id).each(function(index, button_element){
          $(this).text(newText)//set new text
        });
      }
    );
    

  })(jQuery);
  
  return false;
}