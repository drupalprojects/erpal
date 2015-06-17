(function ($) {
  $(document).ready(function() {
    $(".local_tasks_menu li:has(ul)").hover(
      function(){
        $(this).find("ul").slideDown();
      }, 
      function(){
        $(this).find("ul").hide();
      }
    );
    
    /**
    * Override Handler for the form redirection error.
    */
    if (Drupal.ajax != undefined) {
      Drupal.ajax.prototype.error = function (response, uri) {
        //alert(Drupal.ajaxError(response, uri));
        // Remove the progress element.
        if (this.progress.element) {
          $(this.progress.element).remove();
        }
        if (this.progress.object) {
          this.progress.object.stopMonitoring();
        }
        // Undo hide.
        $(this.wrapper).show();
        // Re-enable the element.
        $(this.element).removeClass('progress-disabled').removeAttr('disabled');
        // Reattach behaviors, if they were detached in beforeSerialize().
        if (this.form) {
          var settings = response.settings || this.settings || Drupal.settings;
          Drupal.attachBehaviors(this.form, settings);
        }
      };
    }
  });
})(jQuery);