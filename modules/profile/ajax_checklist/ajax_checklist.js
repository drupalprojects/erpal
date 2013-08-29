(function ($) {
  Drupal.behaviors.ajax_checklist_init = {
    attach: function(context, settings) {
      //console.log(Drupal.settings.basePath)
      $('form.ajaxchecklist input.ajaxchecklist-nid').each(    
        function () {
          // get the node id from where we left it in the header
          var nodeid = $(this).val();

          // load the current state of the checkboxes once on loading page
          $.getJSON(settings.basePath + "ajaxchecklist/loadnid/"+nodeid,
            function(json) {
              
              for( var i=0; i < json.length; i++ ) {
                $(".form-item #"+json[i].qid).removeAttr("disabled");
                if (json[i].state == "1") {
                  $(".form-item #"+json[i].qid).attr("checked","checked");
                } 
                else {
                  $(".form-item #"+json[i].qid).removeAttr("checked");
                }
                if (json[i].access == false) {
                  $(".form-item #"+json[i].qid).attr("disabled","true");
                }
              }
            }
          );
        }
      );
    }

  }
  Drupal.behaviors.ajax_checklist = {
    attach: function (context, settings) {
    
      // setup an onclick for each checkbox that writes it state back to the database
      // when toggled. The label text is turned red while writing to the db.  
      $.getJSON(Drupal.settings.basePath + "ajaxchecklist/update-access",
        function(json) {      
          $.ajaxchecklist_access=json.update;
          $("form.ajaxchecklist label.form-item :input").each(
            function () {
              if ($.ajaxchecklist_access == true ) {
                $(this).removeAttr("disabled");
                $(this).click( 
                  function () {
                    var nodeid=$(this).parents("form").children(":input:eq(0)").val();
                    var thislabel=$(this).parent();
                    var colorbefore=thislabel.css("color");
                    if ( $(this).attr("checked") === false || !$(this).attr("checked") ) {
                      $(thislabel).css("color","red"); 
                      $.get(Drupal.settings.basePath + "ajaxchecklist/save/"+nodeid+"/"+$(this).attr("id")+"/0",
                        function() {
                           $(thislabel).css("color",colorbefore); 
                         }
                      );
                    } else {
                      $(this).parent().css("color","red"); 
                      $.get(Drupal.settings.basePath + "ajaxchecklist/save/"+nodeid+"/"+$(this).attr("id")+"/1",
                        function() {
                          $(thislabel).css("color",colorbefore); 
                        }
                      );
                    }
                  }
                );
              } 
            }
          );
        }
      );
    }
  };
})(jQuery);
