<jnlp spec="1.0+" href="<?php  echo $args['arguments']['fid']; ?>.jnlp">
    <information>
        <title>File Handler</title>
        <vendor>Bright Solutions GmbH</vendor>
    </information>
    <resources>
        <j2se version="1.6+" href="http://java.sun.com/products/autodl/j2se"/>
        <jar href="<?php  echo $args['filehandler_jar_url']; ?>" main="true" />
        <jar href="<?php  echo $args['commons_logging_jar_url']; ?>" download="eager" />
        <jar href="<?php  echo $args['httpclient_jar_url']; ?>" download="eager" />
        <jar href="<?php  echo $args['httpcore_jar_url']; ?>" download="eager" />
    </resources>
<security>
<all-permissions/>
</security>    
    <application-desc
         name="File Handler"
         main-class="de.brightsolutions.filehandler.FileHandler">
        <?php
          foreach ($args['arguments'] as $key=>$value) {
            echo "<argument>".$key."=".$value."</argument>";
          }
        ?>        
     </application-desc>
     <update check="background"/>
</jnlp>