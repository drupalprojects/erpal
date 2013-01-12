jQuery(function ($) {
    $(document).ready(function () {
        $('a[href="' + Drupal.settings.basePath + 'commander/prompt/show' + '"]').click(function () {
            $('#commander-front-prompt-form').show();
            return false;
        });

        $.Shortcuts.add({
            type:'down',
            mask:'Ctrl+E',
            handler:function () {
                $('#commander-front-prompt-form').show();
                $('.commander-prompt-command.form-text').focus();

            }
        });

        $.Shortcuts.start();

//        $(document).bind('keypress', 'Ctrl+e', function () {
//            $('#commander-front-prompt-form').show();
//        });

        $.ajax({
            url:Drupal.settings.basePath + 'commander/prompt',
            data:"nid=" + Drupal.settings.commander.nid,
            success:function (html) {
                $('body').append(html);

                $('#commander-front-prompt-form').hide();

                Drupal.attachBehaviors('#commander-prompt-form');
                $('#commander-front-prompt-form').ajaxForm();

                $('.commander-prompt-close').click(function () {
                    $('#commander-front-prompt-form').hide();
                });
            }
        });
    });
});