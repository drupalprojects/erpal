(function($) {
  /**
   * Initialization
   */
  Drupal.behaviors.jquery_ui_multiselect_widget = {
    /**
     * Run Drupal module JS initialization.
     * 
     * @param context
     * @param settings
     */
    attach : function(context, settings) {
      // Global context!
      var filter = "select";
      if(settings.jquery_ui_multiselect_widget.multiple){
        // Multiple only
        filter = filter+'[multiple=multiple]';
      }
      var elements = $(context).find(filter);
      if(jQuery.trim(settings.jquery_ui_multiselect_widget.subselector) != ''){
        // Subselector
        elements = elements.find(settings.jquery_ui_multiselect_widget.subselector);
      }
      // Convert int 1 to boolean so that the header works correctly.
      if(settings.jquery_ui_multiselect_widget.header === 1){
        settings.jquery_ui_multiselect_widget.header = true;
      }
      var multiselect = elements.multiselect({
        // Get default options from drupal to make them easier accessible.
        selectedList: settings.jquery_ui_multiselect_widget.selectedlist,
        selectedText: function(numChecked, numTotal, checkedItems){
          // Override text to make it translateable.
          return Drupal.t('@numChecked of @numTotal checked', { '@numChecked': numChecked, '@numTotal': numTotal });
        },
        multiple: settings.jquery_ui_multiselect_widget.multiple,
        autoOpen: settings.jquery_ui_multiselect_widget.autoOpen,
        header: settings.jquery_ui_multiselect_widget.header,
        height: settings.jquery_ui_multiselect_widget.height,
        classes: settings.jquery_ui_multiselect_widget.classes,
        checkAllText: Drupal.t('Check all'),
        uncheckAllText: Drupal.t('Uncheck all'),
        noneSelectedText: Drupal.t('Select option(s)'),
        selectedText: Drupal.t('# selected'),
      });        
      if(settings.jquery_ui_multiselect_widget.filter){
        // Allow filters
        multiselect.multiselectfilter({
          label: Drupal.t('Filter'),
          placeholder: Drupal.t('Enter keywords'),
          width: settings.jquery_ui_multiselect_widget.filter_width,
          autoReset: settings.jquery_ui_multiselect_widget.filter_auto_reset,
        });
      }
      
      // Attach object globally to make access easy for custom usage.
      Drupal.behaviors.jquery_ui_multiselect_widget.multiselect = multiselect;
    }
  };
})(jQuery);