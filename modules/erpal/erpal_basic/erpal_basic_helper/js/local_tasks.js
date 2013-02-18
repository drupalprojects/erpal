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
  });
})(jQuery);