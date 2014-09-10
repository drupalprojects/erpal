jQuery(document).ready(function($) {

  var pathname = window.location.pathname;

  if(pathname == "/erpal-search") {
    var search_string = $('.view-id-erpal_search .hidden-search-string').attr('value');
    if(search_string != '') {
      $('.view-id-erpal_search input#edit-search-api-views-fulltext').attr('value',search_string)
      $('.view-id-erpal_search .views-submit-button input').trigger('click');
    }
  }
});