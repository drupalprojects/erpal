jQuery(function ($) {
    $(document).ready(function () {
        $('a.fileedit-link').click(function (e) {
            var n = window.fileEditWin == undefined;

            if (n) {
                // http://www.pageresource.com/jscript/jwinopen.htm
                window.fileEditWin = window.open(Drupal.settings.fileedit.appletUrl, 'FileEdit', "status=no,resizable=no,width=415,height=315");
            } else {
                window.fileEditWin.focus();
            }

            var fid = $(this).attr('fid');
            var filename = $(this).attr('filename');
            var downloadUrl = Drupal.settings.fileedit.downloadUrl.replace("%25", fid).replace('%25', Drupal.settings.fileedit.sid);
            var uploadUrl = Drupal.settings.fileedit.uploadUrl.replace("%25", fid).replace('%25', Drupal.settings.fileedit.sid);

            if (n) {
                window.fileEditWin.onload = function () {
                    window.fileEditWin.setConfiguration(downloadUrl, filename, uploadUrl, Drupal.settings.fileedit.uploadFieldName);
                };
            } else {
                window.fileEditWin.setConfiguration(downloadUrl, filename, uploadUrl, Drupal.settings.fileedit.uploadFieldName);
            }

            return false;
        });
    });
});