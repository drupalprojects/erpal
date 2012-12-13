(function ($) {
  $(document).ready(function() {
    $(".local_tasks_menu li:has(ul)").hover(
      function(){
        $(this).find("ul").slideDown();
        console.log('sf');
      }, 
      function(){
        $(this).find("ul").hide();
        console.log('sfx');
      }
    );
  });
})(jQuery);