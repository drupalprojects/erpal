jQuery(function ($) {
    $(document).ready(function () {
        $('a[href="' + Drupal.settings.basePath + 'commander/prompt/show' + '"]').click(function () {
            $('#commander-prompt-form').show();
            return false;
        });

        $.ajax({
            url:Drupal.settings.basePath + 'commander/prompt',
            success:function (html) {
                $('body').append(html);

                $('#commander-prompt-form').hide();

                Drupal.attachBehaviors('#commander-prompt-form');
                $('#commander-prompt-form').ajaxForm();

                $('.commander-prompt-close').click(function () {
                    $('#commander-prompt-form').hide();
                });
            }
        });
    });
});