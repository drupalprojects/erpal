<?php
/**
 * @file
 * erpal_wysiwyg.features.ckeditor_profile.inc
 */

/**
 * Implements hook_ckeditor_profile_defaults().
 */
function erpal_wysiwyg_ckeditor_profile_defaults() {
  $data = array(
    'ERPAL' => array(
      'name' => 'ERPAL',
      'settings' => array(
        'ss' => '2',
        'default' => 't',
        'show_toggle' => 't',
        'uicolor' => 'default',
        'uicolor_user' => 'default',
        'toolbar' => '[
    [\'Undo\',\'Redo\',\'Source\',\'Styles\',\'Format\',\'Font\',\'FontSize\',\'NewPage\',\'Cut\',\'Copy\',\'Paste\',\'PasteText\',\'PasteFromWord\',\'SpellChecker\',\'Scayt\',\'RemoveFormat\'],
    \'/\',
    [\'Bold\',\'Italic\',\'Underline\',\'Strike\',\'Subscript\',\'Superscript\',\'NumberedList\',\'BulletedList\',\'Outdent\',\'Indent\',\'Blockquote\',\'CreateDiv\',\'JustifyLeft\',\'JustifyCenter\',\'JustifyRight\',\'JustifyBlock\',\'BidiLtr\',\'BidiRtl\',\'Link\',\'Unlink\',\'Anchor\',\'Table\',\'HorizontalRule\',\'SpecialChar\',\'PageBreak\']
]',
        'expand' => 't',
        'width' => '100%',
        'lang' => 'en',
        'auto_lang' => 't',
        'language_direction' => 'default',
        'enter_mode' => 'p',
        'shift_enter_mode' => 'br',
        'font_format' => 'p;div;pre;address;h1;h2;h3;h4;h5;h6',
        'custom_formatting' => 'f',
        'formatting' => array(
          'custom_formatting_options' => array(
            'indent' => 'indent',
            'breakBeforeOpen' => 'breakBeforeOpen',
            'breakAfterOpen' => 'breakAfterOpen',
            'breakAfterClose' => 'breakAfterClose',
            'breakBeforeClose' => 0,
            'pre_indent' => 0,
          ),
        ),
        'css_mode' => 'theme',
        'css_path' => '',
        'css_style' => 'theme',
        'styles_path' => '',
        'filebrowser' => 'none',
        'filebrowser_image' => '',
        'filebrowser_flash' => '',
        'forcePasteAsPlainText' => 'f',
        'html_entities' => 'f',
        'scayt_autoStartup' => 'f',
        'theme_config_js' => 'f',
        'js_conf' => '',
        'loadPlugins' => array(
          'drupalbreaks' => array(
            'name' => 'drupalbreaks',
            'desc' => 'Plugin for inserting Drupal teaser and page breaks.',
            'path' => '%plugin_dir%drupalbreaks/',
            'buttons' => array(
              'DrupalBreak' => array(
                'label' => 'DrupalBreak',
                'icon' => 'images/drupalbreak.png',
              ),
            ),
            'default' => 't',
          ),
          'mediaembed' => array(
            'name' => 'mediaembed',
            'desc' => 'Plugin for inserting Drupal embeded media',
            'path' => '%plugin_dir%mediaembed/',
            'buttons' => array(
              'MediaEmbed' => array(
                'label' => 'MediaEmbed',
                'icon' => 'images/icon.png',
              ),
            ),
            'default' => 'f',
          ),
        ),
      ),
      'input_formats' => array(
        'plain_text' => 'Plain text',
      ),
    ),
  );
  return $data;
}
