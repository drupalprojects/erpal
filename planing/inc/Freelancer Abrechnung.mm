<map version="0.9.0">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node COLOR="#990000" CREATED="1334758786959" ID="ID_1314994798" LINK="../ERPAL.mm" MODIFIED="1334760509304" TEXT="Freelancer Abrechnung">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      - Wenn der user ein freelancer ist und ein g&#252;ltiger Stundensatz ermittelt werden konnte (g&#252;ltig ab, projekt Tag [Taxonomy]) und auf einen Task Zeit bucht contractor des billables ist dann der contact der im profil des users verlinkt ist und der Kunde ist die eigene Firma subject ist der task
    </p>
    <p>
      - Wenn ein Task auf completed gesetzt wird und
    </p>
  </body>
</html>
</richcontent>
<font NAME="SansSerif" SIZE="14"/>
<node CREATED="1334758890639" ID="ID_934603784" MODIFIED="1334758893102" POSITION="right" TEXT="profile">
<node CREATED="1334758853902" ID="ID_1881439016" MODIFIED="1334758916301" TEXT="contact_ref">
<node CREATED="1334760938190" ID="ID_500408048" MODIFIED="1334760945750" TEXT="refernziert einen erpal_contact"/>
<node CREATED="1334760945953" ID="ID_1875921895" MODIFIED="1334760953721" TEXT="nur mit bestimmtem Recht &#xe4;nderbar"/>
</node>
<node CREATED="1334758917973" ID="ID_1564469349" MODIFIED="1334758970186" TEXT="field_collection contract_data">
<node CREATED="1334758970187" ID="ID_1725902349" MODIFIED="1334758978868" TEXT="g&#xfc;ltig ab datum"/>
<node CREATED="1334758979427" ID="ID_42598740" MODIFIED="1334759072917" TEXT="typ">
<node CREATED="1334758993789" ID="ID_1792567017" MODIFIED="1334758996435" TEXT="freelancer"/>
<node CREATED="1334758996865" ID="ID_1112386068" MODIFIED="1334759006198" TEXT="angestellt"/>
</node>
<node CREATED="1334759007034" ID="ID_1868242467" MODIFIED="1334759035661" TEXT="f&#xfc;r angestellte">
<node CREATED="1334759035662" ID="ID_1071925707" MODIFIED="1334759334005" TEXT="urlaub pro Jahr"/>
<node CREATED="1334759038706" ID="ID_808440721" MODIFIED="1334759071165" TEXT="std pro Woche"/>
</node>
<node CREATED="1334759503042" ID="ID_1774150527" MODIFIED="1334759591232" TEXT="f&#xfc;r Freelancer">
<node CREATED="1334759523283" ID="ID_302188801" MODIFIED="1334759525760" TEXT="vat"/>
<node CREATED="1334759525979" ID="ID_1450977096" MODIFIED="1334759530357" TEXT="currency"/>
<node CREATED="1334759530558" ID="ID_773071658" MODIFIED="1334759552870" TEXT="zahlungsziel (credit period)"/>
</node>
<node CREATED="1334759091736" FOLDED="true" ID="ID_666379478" MODIFIED="1334759169065" TEXT="Anwesenheit pro Woche regelm&#xe4;&#xdf;ig / plan">
<node CREATED="1334759101725" ID="ID_1742649343" MODIFIED="1334759158392" TEXT="checkbox tage + eingabe Stunden (ohne genaue Uhrzeit)"/>
</node>
<node CREATED="1334759175913" FOLDED="true" ID="ID_582890564" MODIFIED="1334759633055" TEXT="kosten netto">
<node CREATED="1334759204693" ID="ID_1197783475" MODIFIED="1334759230637" TEXT="inkl. lohnnebenkosten"/>
<node CREATED="1334759230863" ID="ID_1249283329" MODIFIED="1334759248909" TEXT="inkl soz abgaben bei festen ma"/>
<node CREATED="1334759253839" ID="ID_694251459" MODIFIED="1334759259113" TEXT="ohne vat bei freelancern"/>
</node>
<node CREATED="1334759633922" FOLDED="true" ID="ID_1919033062" MODIFIED="1334760959875" TEXT="G&#xfc;ltig f&#xfc;r Project Tag">
<node CREATED="1334759651945" ID="ID_1966134731" MODIFIED="1334759666068" TEXT="es kann nur eine Setting im gleichen Zeitraum f&#xfc;r gleiches Tag geben"/>
</node>
<node CREATED="1334760960672" ID="ID_1424126357" MODIFIED="1334760975792" TEXT="nur mit bestimmtem recht ansehbar"/>
<node CREATED="1334760976000" ID="ID_1642316729" MODIFIED="1334760981737" TEXT="nur mit bestimmtem recht &#xe4;nderbar"/>
</node>
</node>
<node CREATED="1334758866212" ID="ID_1644802832" MODIFIED="1334758873357" POSITION="right" TEXT="task / projekt">
<node CREATED="1334759381307" ID="ID_1369948232" MODIFIED="1334759388920" TEXT="VK priceing">
<node CREATED="1334759388921" ID="ID_1493158607" MODIFIED="1334759393162" TEXT="bereits vorhanden"/>
</node>
<node CREATED="1334759393991" ID="ID_402116699" MODIFIED="1334761041848" TEXT="EK pricing (Einkauf, freelancer etc)">
<node CREATED="1334759404469" ID="ID_659110207" MODIFIED="1334759467551" TEXT="checkbox fixed price EK checked">
<node CREATED="1334759467553" ID="ID_453256327" MODIFIED="1334759470768" TEXT="vat"/>
<node CREATED="1334759470995" ID="ID_1815230655" MODIFIED="1334759477212" TEXT="currency"/>
<node CREATED="1334759477422" ID="ID_201350481" MODIFIED="1334759487751" TEXT="contact"/>
<node CREATED="1334759487961" ID="ID_1894271226" MODIFIED="1334759502090" TEXT="ek price"/>
<node CREATED="1334759510192" ID="ID_660438498" MODIFIED="1334759520972" TEXT="credit period"/>
<node CREATED="1334759567212" ID="ID_680568294" MODIFIED="1334759591232" TEXT="daten aus defaults per ajax nach contact select">
<arrowlink DESTINATION="ID_1774150527" ENDARROW="Default" ENDINCLINATION="531;0;" ID="Arrow_ID_339834645" STARTARROW="None" STARTINCLINATION="531;0;"/>
</node>
</node>
</node>
<node CREATED="1334759677307" ID="ID_1491433250" MODIFIED="1334759691678" TEXT="Project Tag">
<arrowlink DESTINATION="ID_1919033062" ENDARROW="Default" ENDINCLINATION="219;0;" ID="Arrow_ID_246606652" STARTARROW="None" STARTINCLINATION="219;0;"/>
</node>
</node>
<node CREATED="1334758873570" ID="ID_1309184907" MODIFIED="1334758879881" POSITION="right" TEXT="billable">
<node CREATED="1334759776411" ID="ID_1808358446" MODIFIED="1334760716497" TEXT="Erstellt wenn: siehe body">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Ein user, der einen g&#252;ltigen Stundenpreis im Profil hintelegt hat, freelancer ist und Zeit auf einen Task verbucht hat. Der Kunde ist dann die eigene Firma, der Contractor der COntact der zum Profil des USers referenziert ist.
    </p>
    <p>
      Wenn ein Task mit vollst&#228;ndigen EK Pricing informationen auf Completed gesetzt wird. der Kunde ist dann die eigene Firma, der contractor der contact der zu den Pricing informationen hinterlegt ist.
    </p>
  </body>
</html>
</richcontent>
</node>
<node CREATED="1334760824258" ID="ID_420839048" MODIFIED="1334760870533" TEXT="behandeln wie f&#xfc;r forderungen">
<node CREATED="1334760833242" ID="ID_1647696882" MODIFIED="1334760842746" TEXT="l&#xf6;schen, anpassen etc."/>
</node>
<node CREATED="1334760848073" ID="ID_1217035326" MODIFIED="1334761151459" TEXT="neues Feld contractor">
<node CREATED="1334760862433" ID="ID_725374080" MODIFIED="1334760870504" TEXT="wie customer nur f&#xfc;r lieferant"/>
<node CREATED="1334761140357" ID="ID_1339650622" MODIFIED="1334761146627" TEXT="referenziert erpal_contact"/>
</node>
</node>
<node CREATED="1334758880113" ID="ID_1639483521" MODIFIED="1334758886083" POSITION="right" TEXT="invoice">
<node CREATED="1334761126275" ID="ID_192387088" MODIFIED="1334761151459" TEXT="field contractor">
<arrowlink DESTINATION="ID_1217035326" ENDARROW="Default" ENDINCLINATION="53;0;" ID="Arrow_ID_517463090" STARTARROW="None" STARTINCLINATION="53;0;"/>
</node>
<node CREATED="1334761157982" ID="ID_57765662" MODIFIED="1334761192089" TEXT="gescannte Rechnung hintelegen">
<node CREATED="1334761192090" ID="ID_589448888" MODIFIED="1334761207448" TEXT="pdf generieren nicht m&#xf6;glich, wenn contractor != eigene Firma"/>
<node CREATED="1334761215939" ID="ID_1895080158" MODIFIED="1334761227541" TEXT="wenn gel&#xf6;scht, billables unbiled setzen wie bei Forderungen"/>
</node>
</node>
<node CREATED="1334759265682" ID="ID_898064015" MODIFIED="1334760812360" POSITION="right" TEXT="F&#xe4;lle">
<node CREATED="1334759269037" FOLDED="true" ID="ID_1284384552" MODIFIED="1334759699518" TEXT="Reisekosten">
<node CREATED="1334759273102" ID="ID_840010210" MODIFIED="1334759286626" TEXT="task mit ek festpreis, completed"/>
</node>
<node CREATED="1334759700410" ID="ID_414499945" MODIFIED="1334759709803" TEXT="Subunternehmer festpreis">
<node CREATED="1334759709804" ID="ID_1881076185" MODIFIED="1334759730069" TEXT="entsprechend Reisekosten"/>
</node>
</node>
<node CREATED="1334760813158" ID="ID_817473202" MODIFIED="1334760817233" POSITION="right" TEXT="Modulaufbau">
<node CREATED="1334761264974" ID="ID_824259290" MODIFIED="1334761281528" TEXT="packen wir mit in ERPAL_projects"/>
<node CREATED="1334761286182" ID="ID_801199975" MODIFIED="1334761295856" TEXT="erpal_invoice anpassen"/>
</node>
</node>
</map>
