jQuery(function ($) {
    $(document).ready(function () {
        window.fileEditConfigurations = new Array();

        function runConfiguration(downloadUrl, filename, uploadUrl, uploadFieldName) {
            var configuration = {
                downloadUrl:downloadUrl,
                filename:filename,
                uploadUrl:uploadUrl,
                uploadFieldName:uploadFieldName,

            };

            window.fileEditConfigurations.push(configuration);

            if (!window.fileEditWin.isAlive || !window.fileEditWin.isAlive()) {
                if (window.fileEditWin.showMessage) {
                    window.fileEditWin.showMessage('Please make sure that you have activated and trusted the applet to Edit the file ' + filename + '. Your request was added to the queue and will be handled as soon as applet is loaded.');
//                    alert('Please make sure that you have activated and trusted the applet to Edit the file ' + filename + '. Your request was added to the queue and will be handled as soon as applet is loaded.');
                }
            }
        }

        window.setInterval(function () {
            if (window.fileEditConfigurations.length && window.fileEditWin.isAlive && window.fileEditWin.isAlive()) {
                var configuration = window.fileEditConfigurations.shift();
                window.fileEditWin.setConfiguration(configuration.downloadUrl, configuration.filename, configuration.uploadUrl, configuration.uploadFieldName);
            }
        }, 250);

        $('a.fileedit-link').click(function (e) {
            var fid = $(this).attr('fid');
            var filename = $(this).attr('filename');
            var downloadUrl = Drupal.settings.fileedit.downloadUrl.replace("%25", fid).replace('%25', Drupal.settings.fileedit.sid);
            var uploadUrl = Drupal.settings.fileedit.uploadUrl.replace("%25", fid).replace('%25', Drupal.settings.fileedit.sid);

            if (window.fileEditWin == undefined || window.fileEditWin.closed) {
                // http://www.pageresource.com/jscript/jwinopen.htm
                window.fileEditWin = window.open(Drupal.settings.fileedit.appletUrl, 'FileEdit', "status=no,resizable=no,width=415,height=315");
                window.fileEditWin.onload = function (e) {
                    setTimeout(function () {
                        runConfiguration(downloadUrl, filename, uploadUrl, Drupal.settings.fileedit.uploadFieldName);
                    }, 1000);
                }
            } else {
                window.fileEditWin.focus();
                runConfiguration(downloadUrl, filename, uploadUrl, Drupal.settings.fileedit.uploadFieldName);
            }

            return false;
        });
    });
});