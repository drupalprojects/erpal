<html>
<head>
    <!--    <script type="text/javascript" src="http://code.jquery.com/jquery-1.9.0.min.js"></script>-->

    <script type="text/javascript">
        var isReady = false;

        function isAlive() {
            var alive = false;

            try {
                alive = document.getElementById("fileHandlerApplet").isAlive();
            } catch (e) {
                // ignore
            }

            return alive;
        }

        function setConfiguration(downloadUrl, filename, uploadUrl, uploadFieldName) {
//            if (!isReady) {
//                isReady = isAlive();
//            }
            try {
                document.getElementById("fileHandlerApplet").setConfiguration(downloadUrl, filename, uploadUrl, uploadFieldName);
            } catch (e) {
                // ignore
            }

//            if (isReady) {
//                document.getElementById("fileHandlerApplet").setConfiguration(downloadUrl, filename, uploadUrl, uploadFieldName);
//            } else {
//                alert('Applet is not loaded yet. Please try again.');
//            }
        }

        function showMessage(message) {
            alert(message);
        }
    </script>
</head>

<body>
<applet code='de.brightsolutions.erpal.filehandler.applet.FileHandlerApplet.class'
        codebase='<?php echo $args['fileedit_codebase']; ?>'
        archive='FileHandler.jar' type='application/x-java-applet;version=1.6'
        width="100%" height="100%" id="fileHandlerApplet" name="File Handler" MAYSCRIPT>
</applet>
</body>
</html>