/**
 * @file
 * JavaScript to activate "Insert" buttons on file and image fields.
 */

(function ($) {

  /**
   * Behavior to add "Insert" buttons.
   */
  Drupal.behaviors.references_dialog_insert = {};
  Drupal.behaviors.references_dialog_insert.attach = function(context) {
    
    // reference link update on form-autocomplete change
    $('.references-dialog-insert .form-autocomplete').once('processed').change(function(){
      $(this).blur(); // fix for autocomplete change enter press
      var element = $(this);
      references_dialog_insert_link(element);
    });

    // reference link update on autocomplete click change
    $('.references-dialog-insert #autocomplete').live('click', function () {
      var element = $(this).once('processed').closest('.references-dialog-insert').find('.form-autocomplete');
      element.change();
    });
    
    // reference link update on creating entityreference widget
    $('.references-dialog-insert .form-autocomplete').ready(function(){
      $('.references-dialog-insert .form-autocomplete').each(function(){
        var element = $(this);
        references_dialog_insert_link(element, true);
      });
    });
    
    // reference link update
    function references_dialog_insert_link(element, dont_check_entity){
      var container = element.closest('.references-dialog-insert');
      
      if(dont_check_entity){
        if(container.find('.references-dialog-insert-wrapper').length > 0)
          return;
      }
      
      // get value of autocomplete
      var entity_val = element.val();
      if(!entity_val.match(/[\d\w].*\(\d+\)/)){
        container.find('.references-dialog-insert-wrapper').remove();
      } else {
        // get entity id, type and bundles
        var type = container.find('.references-dialog-target-type').val();
        var entity_id = entity_val.replace(/^.*\(/, '').replace(/\).*$/, ''); 
        var bundles = container.find('.references-dialog-target-bundles').val();
       
        var url = Drupal.settings.references_dialog_insert.file_callback_url + '/' + entity_id + '/' + type;
        // call callback to bild "Send to textarea" widget
        if(type && entity_id){          
          $.ajax({
            url: url,
            type: 'POST',
            dataType: 'json',
            async: false,
            data: {
              bundles: bundles
            }
          }).done(function (data) {
            if(data && data.success) {
              // replace surrent link
              if(container.find('.references-dialog-insert-wrapper').length > 0)
                container.find('.references-dialog-insert-wrapper').replaceWith(data.success)
              // create new link
              else
                container.prepend(data.success);
            } else {
              container.find('.references-dialog-insert-wrapper').remove();
            }
          }).error(function (data) {
            container.find('.references-dialog-insert-wrapper').remove();
          });
        }
      }
    }
    
    if (typeof(insertTextarea) == 'undefined') {
      insertTextarea = $('#edit-body textarea.text-full').get(0) || false;
    }
    if (typeof(insertTextarea) == 'undefined' || !insertTextarea) {
      insertTextarea = $('#comment-form textarea.text-full').get(0) || false;
    }
    if (typeof(insertTextarea) == 'undefined' || !insertTextarea) {
      insertTextarea = $('textarea.text-full').get(0) || false;
    }

    // Keep track of the last active textarea (if not using WYSIWYG).
    $('textarea:not([name$="[data][title]"]):not(.insert-processed)', context).addClass('insert-processed').focus(insertSetActive).blur(insertRemoveActive);

    // Add the click handler for the "Send to textarea" button.
    $('.references-dialog-insert-send', context).addClass('insert-processed').die('click').live('click', function(){
      var image_style, content, name;
      // image link
      if($(this).siblings('.references-dialog-insert-image').length != 0){
        image_style = $(this).closest('.references-dialog-insert-wrapper').find('select').val();
        name = 'references-dialog-insert-image-' + image_style;
        content = $(this).siblings('.references-dialog-insert-image[name="' + name + '"]').val();
      } 
      // simple link
      else {
        content = $(this).siblings('.references-dialog-insert-link').val();
      }
      
      // Check if content exists
      if(!content)
        return false;
      
      // Cleanup unused replacements.
      content = content.replace(/"__([a-z0-9_]+)__"/g, '""');

      // Cleanup empty attributes (other than alt).
      content = content.replace(/([a-z]+)[ ]*=[ ]*""/g, function(match, tagName) {
        return (tagName === 'alt') ? match : '';
      });

      // Insert the content in WYSIWYG editor or textarea.
      Drupal.references_dialog_insert.insertIntoActiveEditor(content);
      
      return false;
    });

    function insertSetActive() {
      insertTextarea = this;
      this.insertHasFocus = true;
    }

    function insertRemoveActive() {
      if (insertTextarea == this) {
        var thisTextarea = this;
        setTimeout(function() {
          thisTextarea.insertHasFocus = false;
        }, 1000);
      }
    }
  };

  // General Insert API functions.
  Drupal.references_dialog_insert = {
    /**
     * Insert content into the current (or last active) editor on the page. This
     * should work with most WYSIWYGs as well as plain textareas.
     *
     * @param content
     */
    insertIntoActiveEditor: function(content) {
      var editorElement;

      // Always work in normal text areas that currently have focus.
      if (insertTextarea && insertTextarea.insertHasFocus) {
        editorElement = insertTextarea;
        Drupal.references_dialog_insert.insertAtCursor(insertTextarea, content);
      }
      // Direct tinyMCE support.
      else if (typeof(tinyMCE) != 'undefined' && tinyMCE.activeEditor) {
        editorElement = document.getElementById(tinyMCE.activeEditor.editorId);
        Drupal.references_dialog_insert.activateTabPane(editorElement);
        tinyMCE.activeEditor.execCommand('mceInsertContent', false, content);
      }
      // WYSIWYG support, should work in all editors if available.
      else if (Drupal.wysiwyg && Drupal.wysiwyg.activeId) {
        editorElement = document.getElementById(Drupal.wysiwyg.activeId);
        Drupal.references_dialog_insert.activateTabPane(editorElement);
        Drupal.wysiwyg.instances[Drupal.wysiwyg.activeId].insert(content)
      }
      // FCKeditor module support.
      else if (typeof(FCKeditorAPI) != 'undefined' && typeof(fckActiveId) != 'undefined') {
        editorElement = document.getElementById(fckActiveId);
        Drupal.references_dialog_insert.activateTabPane(editorElement);
        FCKeditorAPI.Instances[fckActiveId].InsertHtml(content);
      }
      // Direct FCKeditor support (only body field supported).
      else if (typeof(FCKeditorAPI) != 'undefined') {
        // Try inserting into the body.
        if (FCKeditorAPI.Instances[insertTextarea.id]) {
          editorElement = insertTextarea;
          Drupal.references_dialog_insert.activateTabPane(editorElement);
          FCKeditorAPI.Instances[insertTextarea.id].InsertHtml(content);
        }
        // Try inserting into the first instance we find (may occur with very
        // old versions of FCKeditor).
        else {
          for (var n in FCKeditorAPI.Instances) {
            editorElement = document.getElementById(n);
            Drupal.references_dialog_insert.activateTabPane(editorElement);
            FCKeditorAPI.Instances[n].InsertHtml(content);
            break;
          }
        }
      }
      // CKeditor module support.
      else if (typeof(CKEDITOR) != 'undefined' && typeof(Drupal.ckeditorActiveId) != 'undefined') {
        editorElement = document.getElementById(Drupal.ckeditorActiveId);
        Drupal.references_dialog_insert.activateTabPane(editorElement);
        CKEDITOR.instances[Drupal.ckeditorActiveId].insertHtml(content);
      }
      // Direct CKeditor support (only body field supported).
      else if (typeof(CKEDITOR) != 'undefined' && CKEDITOR.instances[insertTextarea.id]) {
        editorElement = insertTextarea;
        Drupal.references_dialog_insert.activateTabPane(editorElement);
        CKEDITOR.instances[insertTextarea.id].insertHtml(content);
      }
      else if (insertTextarea) {
        editorElement = insertTextarea;
        Drupal.references_dialog_insert.activateTabPane(editorElement);
        Drupal.references_dialog_insert.insertAtCursor(insertTextarea, content);
      }

      if (editorElement) {
        Drupal.references_dialog_insert.contentWarning(editorElement, content);
      }

      return false;
    },

    /**
     * Check for vertical tabs and activate the pane containing the editor.
     *
     * @param editor
     *   The DOM object of the editor that will be checked.
     */
    activateTabPane: function(editor) {
      var $pane = $(editor).parents('.vertical-tabs-pane:first');
      var $panes = $pane.parent('.vertical-tabs-panes');
      var $tabs = $panes.parents('.vertical-tabs:first').find('ul.vertical-tabs-list:first li a');
      if ($pane.size() && $pane.is(':hidden') && $panes.size() && $tabs.size()) {
        var index = $panes.children().index($pane);
        $tabs.eq(index).click();
      }
    },

    /**
     * Warn users when attempting to insert an image into an unsupported field.
     *
     * This function is only a 90% use-case, as it doesn't support when the filter
     * tip are hidden, themed, or when only one format is available. However it
     * should fail silently in these situations.
     */
    contentWarning: function(editorElement, content) {
      if (!content.match(/<img /)) return;

      var $wrapper = $(editorElement).parents('div.text-format-wrapper:first');
      if (!$wrapper.length) return;

      $wrapper.find('.filter-guidelines-item:visible li').each(function(index, element) {
        var expression = new RegExp(Drupal.t('Allowed HTML tags'));
        if (expression.exec(element.textContent) && !element.textContent.match(/<img>/)) {
          alert(Drupal.t("The selected text format will not allow it to display images. The text format will need to be changed for this image to display properly when saved."));
        }
      });
    },

    /**
     * Insert content into a textarea at the current cursor position.
     *
     * @param editor
     *   The DOM object of the textarea that will receive the text.
     * @param content
     *   The string to be inserted.
     */
    insertAtCursor: function(editor, content) {
      // Record the current scroll position.
      var scroll = editor.scrollTop;

      // IE support.
      if (document.selection) {
        editor.focus();
        sel = document.selection.createRange();
        sel.text = content;
      }

      // Mozilla/Firefox/Netscape 7+ support.
      else if (editor.selectionStart || editor.selectionStart == '0') {
        var startPos = editor.selectionStart;
        var endPos = editor.selectionEnd;
        editor.value = editor.value.substring(0, startPos) + content + editor.value.substring(endPos, editor.value.length);
      }

      // Fallback, just add to the end of the content.
      else {
        editor.value += content;
      }

      // Ensure the textarea does not unexpectedly scroll.
      editor.scrollTop = scroll;
    }
  };

})(jQuery);
