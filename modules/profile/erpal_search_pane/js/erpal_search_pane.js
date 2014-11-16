jQuery(document).ready(function($) {

  var pathname = window.location.pathname;

  if(pathname == "/erpal-search") {
    var search_string = $('.hidden-search-string').attr('value');
    if(search_string != '') {
      $('input#edit-search-api-views-fulltext').attr('value',search_string)
      $('.views-submit-button input').trigger('click');
    }
  }
});