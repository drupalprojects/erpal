jQuery(function ($) {
    $(document).ready(function () {
        $('a[href="' + Drupal.settings.basePath + 'command/prompt/show' + '"]').click(function () {
            $('#command-prompt-form').show();
            return false;
        });

        $.ajax({
            url:Drupal.settings.basePath + 'command/prompt',
            success:function (html) {
                $('body').append(html);

                $('#command-prompt-form').hide();

                Drupal.attachBehaviors('#command-prompt-form');
                $('#command-prompt-form').ajaxForm();

                $('.command-prompt-close').click(function () {
                    $('#command-prompt-form').hide();
                });
            }
        });


//        $(Drupal.settings.basePath + 'command/prompt/show').click(function() {
//            $('#command-prompt-form').show();
//            return false;
//        });

//        $.ajax({
//            url: Drupal.settings.basePath + 'command/prompt'
//        }).done(function (data) {
//                alert(data);
//                $(this).addClass("done");
//            });

//        $('#footer').load(Drupal.theme('commandbox'));

//        alert(Drupal.settings.basePath);
//        alert($('#command-prompt-form'));
//        Drupal.attachBehaviors('#command-prompt-form');
//

//        $('#footer').append(Drupal.theme('commandbox'));

//        $('#command-box-run').click(function () {
//            alert($('#command-box-input').val());
//        });
    });
});