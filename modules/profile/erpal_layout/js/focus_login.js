(function($) {
  /**
   * Add focus on username input.
   */
  Drupal.behaviors.erpal_focus_login = {
    attach: function(context) {
      $("body.front.not-logged-in input#edit-name").focus();
    }
  };
  
}(jQuery));