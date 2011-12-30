<map version="0.9.0">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1323621720092" ID="ID_1225563429" MODIFIED="1323623109398" TEXT="bs_funambol">
<node CREATED="1323621888435" HGAP="-95" ID="ID_355473706" MODIFIED="1323622809430" POSITION="left" TEXT="Adminsettings" VSHIFT="-128">
<node CREATED="1323621896245" ID="ID_1440481595" MODIFIED="1323622076347" TEXT="Funambolserver"/>
<node CREATED="1323622128223" ID="ID_445649539" MODIFIED="1323623022344" TEXT="Inhaltstypen">
<node CREATED="1323623024253" ID="ID_122078127" MODIFIED="1323623027375" TEXT="Kontakte">
<node CREATED="1323623058473" ID="ID_286581390" MODIFIED="1323623166883" TEXT="Button &quot;Sync Now&quot;">
<arrowlink DESTINATION="ID_1650899958" ENDARROW="Default" ENDINCLINATION="661;0;" ID="Arrow_ID_796668502" STARTARROW="None" STARTINCLINATION="661;0;"/>
</node>
<node CREATED="1323623064828" ID="ID_97457496" MODIFIED="1323623087380" TEXT="Anzeige Datum Last Sync"/>
</node>
<node CREATED="1323623027583" ID="ID_1934143532" MODIFIED="1323623030440" TEXT="Termine">
<node CREATED="1323623045203" ID="ID_893453367" MODIFIED="1323623174051" TEXT="Button &quot;Sync Now&quot;">
<arrowlink DESTINATION="ID_1650899958" ENDARROW="Default" ENDINCLINATION="634;0;" ID="Arrow_ID_1199368964" STARTARROW="None" STARTINCLINATION="634;0;"/>
</node>
<node CREATED="1323623071185" ID="ID_625360582" MODIFIED="1323623082903" TEXT="Anzeige Datum Last Sync"/>
</node>
</node>
<node CREATED="1323622306301" ID="ID_1137999910" MODIFIED="1325241234856" TEXT="View Auswahl f&#xfc;r jeden Inhaltstyp">
<arrowlink DESTINATION="ID_1239881646" ENDARROW="Default" ENDINCLINATION="787;0;" ID="Arrow_ID_1637386957" STARTARROW="None" STARTINCLINATION="787;0;"/>
</node>
<node CREATED="1323622693785" ID="ID_1634749191" MODIFIED="1323622708763" TEXT="Liste VCard Felder pro Typ">
<node CREATED="1323622714010" ID="ID_1571951466" MODIFIED="1325241079730" TEXT="Auswahl CCK Felder pro VCard Feld">
<node CREATED="1325241353697" ID="ID_1689205978" MODIFIED="1325241372090" TEXT="Zuordnung Attribut:Typ f&#xfc;r jedes Feld n&#xf6;tig"/>
<node CREATED="1325241571037" ID="ID_1385706114" MODIFIED="1325241666930" TEXT="EINDEUTIGES mapping von Feldinhalt mit Attribut auf VCard Typ (Entity muss attribut haben)"/>
</node>
<node CREATED="1323622727075" FOLDED="true" ID="ID_1481893726" MODIFIED="1325241679644" TEXT="Mehrere CCK Felder pro VCard Feld ">
<font NAME="SansSerif" SIZE="12"/>
<icon BUILTIN="button_cancel"/>
<node CREATED="1323622912611" ID="ID_901180347" MODIFIED="1323622921084" TEXT="Button &quot;weiteres Feld&quot;"/>
<node CREATED="1323622921542" ID="ID_440685839" MODIFIED="1323622935849" TEXT="Reihenfolge &#xfc;ber Draggeble Fields"/>
<node CREATED="1323622936120" ID="ID_280140461" MODIFIED="1323622949523" TEXT="Freitextfelder einf&#xfc;gbar"/>
<node CREATED="1323622949700" ID="ID_400197293" MODIFIED="1323622968219" TEXT="ALTERNATIV: VCard-Feldbelegung &#xfc;ber Tokens wenn sinnvoller"/>
</node>
</node>
<node CREATED="1325241707708" ID="ID_61177458" MODIFIED="1325243989734" TEXT="Useraccounts">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Funamboluser: Da ja jeder seinen eigenen Satz daten w&#228;hlen kann, die er syncen will, braucht auch jeder einen eigenen useraccount.
    </p>
    <p>
      Was passiert, wenn ein user einen Datensatz, der schonmal auf gesyncht war, aus der Auswahlliste herausnimmt, wird dieser an funambol als &quot;delete&quot; geschickt oder bleibt er einfach vorhanden? (meiner Meinung nach m&#252;sste er gel&#246;scht werden)
    </p>
  </body>
</html>
</richcontent>
<node CREATED="1325241741732" ID="ID_1642972124" MODIFIED="1325241749438" TEXT="Useraccounts Funambol"/>
<node CREATED="1325241753463" ID="ID_477007532" MODIFIED="1325241764461" TEXT="Zuordnung Funamboluser-&gt;Drupaluser"/>
</node>
</node>
<node CREATED="1323621914846" HGAP="46" ID="ID_1620692200" MODIFIED="1325243976805" POSITION="right" TEXT="Anzeige am Nodetype" VSHIFT="49">
<node CREATED="1323621922562" ID="ID_1810953053" MODIFIED="1323621932187" TEXT="Welche Felder auf welches VCard Feld gemapped"/>
<node CREATED="1323621932412" ID="ID_1826390760" MODIFIED="1323621955166" TEXT="Auswahl wie Syncen">
<node CREATED="1323621955166" ID="ID_1107622884" MODIFIED="1323621964823" TEXT="Bidirektional"/>
<node CREATED="1323621965031" ID="ID_1442166402" MODIFIED="1325243953529" TEXT="Unidirektional">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Synchronisation unidirektional: Von Seiten Erpals sollte das kein Problem sein, aber in dem aktuellen Funambol Client f&#252;r Android kann man nur &quot;bidirectional&quot; oder &quot;no sync&quot; ausw&#228;hlen.
    </p>
    <p>
      Das w&#228;re aber auch kein Problem, da man ja die &quot;incoming&quot; kontakte verwerfen und beim n&#228;chsten sync wieder &#252;berschreiben kann.
    </p>
    <p>
      
    </p>
  </body>
</html>
</richcontent>
<node CREATED="1323621969861" ID="ID_791829822" MODIFIED="1323621974510" TEXT="Nodes nur Lesen"/>
<node CREATED="1323621974703" ID="ID_1323405754" MODIFIED="1323621994377" TEXT="Nodes nur Schreiben"/>
</node>
</node>
</node>
<node CREATED="1323621995163" ID="ID_566687317" MODIFIED="1323622224626" POSITION="left" TEXT="Hooks">
<node CREATED="1323622227096" ID="ID_1924307471" MODIFIED="1323622242472" TEXT="F&#xfc;r jeden Eintrag">
<node CREATED="1323622242472" ID="ID_1219346063" MODIFIED="1323622255467" TEXT="Wie hook_nodeapi">
<node CREATED="1323622259602" ID="ID_1854884781" MODIFIED="1323622267342" TEXT="Param Node"/>
<node CREATED="1323622267581" ID="ID_1957532872" MODIFIED="1323622274369" TEXT="Param OP"/>
<node CREATED="1323622274641" ID="ID_143891747" MODIFIED="1323622278714" TEXT="Param...."/>
</node>
</node>
</node>
<node CREATED="1323622109488" ID="ID_932604778" MODIFIED="1325244836184" POSITION="right" TEXT="Zu Syncende Nodes ausw&#xe4;hlen">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Ich kann mir nicht vorstellen, das ein user einzelne Kontakte explizit synchen will.
    </p>
    <p>
      ich sehe das&#160;eher als eine Admineinstellung, welche View zum w&#228;hlen der kontakte zur synch benutzt werden soll.
    </p>
    <p>
      
    </p>
    <p>
      Der user ben&#246;tigt dann nat&#252;rlich noch eine eigene View, in der er seine kontakte markieren kann (falls die &quot;geflaggt&quot; variante benutzt wird).
    </p>
  </body>
</html>
</richcontent>
<icon BUILTIN="messagebox_warning"/>
<node CREATED="1323622121151" ID="ID_1239881646" MODIFIED="1325241234856" TEXT="Auswahl eines Views">
<node CREATED="1323622325731" ID="ID_1506658149" MODIFIED="1323622364057" TEXT="M&#xf6;glich nur geflaggte Kontakte von User"/>
<node CREATED="1323622350670" ID="ID_6427796" MODIFIED="1323623274423" TEXT="M&#xf6;glich nur Termine von User"/>
<node CREATED="1323623274600" ID="ID_250980846" MODIFIED="1323623278986" TEXT="M&#xf6;glich..."/>
</node>
</node>
<node CREATED="1323623113226" FOLDED="true" ID="ID_1650899958" MODIFIED="1325243886599" POSITION="right" TEXT="Sync Prozess starten">
<node CREATED="1323623148802" ID="ID_1382851198" MODIFIED="1323623154825" TEXT="Als Batch Operation"/>
<node CREATED="1323623155050" ID="ID_1482142176" MODIFIED="1323623221094" TEXT="Alternativ als Shellscript"/>
<node CREATED="1323623221303" ID="ID_657276068" MODIFIED="1323623227342" TEXT="Fortschrittsanzeige"/>
</node>
</node>
</map>
