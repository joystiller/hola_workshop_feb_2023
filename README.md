# hola_workshop_feb_2023

Kopiera länken till koden (tryck på gröna knappen "code", kopiera https koden). Det går också att ladda ner filen som zip, packa upp den och lägga den där du vill ha den. Annars: 

Öppna terminalen eller kommandotolken

Används commando "cd" för att navigera till en lämplig folder. Mer om det [här](https://help.ubuntu.com/community/UsingTheTerminal).

Skriv 
```
git clone https://github.com/kaffeocigg/hola_workshop_feb_2023.git
```


Gå in i mappen genom att skriva cd hola_workshop_feb_2023

Mappen innehåller flera olika filer för olika projekt. För att använda arduino-koderna behöver du ladda ner "Arduino IDE". Därifrån kan du ladda upp koden på din Arduino. Ifall det högst upp i koden står till exempel

```
#include <CapacitiveSensor.h>
```
så betyder det att ett bibliotek används. Då kan du behöva installera biblioteket. Gå i så fall till sketch -> include library -> manage libraries. Sök sedan efter biblioteket, till exempel "CapacitiveSensor", och välj "install". 

För att använda .pd-sketcherna kan du också behöva installera olika bibliotek. Gå till help -> find externals, och installera följande bibliotek:

```
else
cyclone
iemlib
comport
```

För att kommunicera med Arduino behöver du först ansluta till den. Öppna en .pd patch från mappen "pd-patches", tryck sen på devices-knappen och kolla i Pd's konsoll vilka devices som finns tillgängliga. Lägg märke till siffran, för det är den du vill ansluta till. Ifall du är osäker på vilken som är din Arduino device kan du gå till Arduino IDE, tools -> port, och leta efter den som heter "arduino UNO" (om du nu har just en arduino Uno).  Tryck sen på "open-#", byt ut # mot siffran som överensstämmer med din Arduino device. 

Om kommunikationen mellan Arduino och Pd går trögt, dubbelkolla att inte Arduinos "serial monitor" fönster är öppet.

För att ladda upp en ny sketch till din Arduino måste du först stänga kommunikationen i Pd. 





I mappen ligger också ett program som laddar ner väderdata från SMHI och som skickar det vidare till Pd. Nedan följer instruktionerna för hur det funkar. Öppna terminalen eller kommandotolken och navigera till mappen "hola_workshop_feb_2023". 


Skriv 
```
npm install
```

Detta installerar externa bibliotek genom "node package manager". Ifall npm saknas, ladda ner node [här](https://nodejs.org/en/download/).

Öppna sketchen hola_smhi_api.pd.

Starta servern som laddar ner vädret, skriv
```
node index.js
```

Lägg märke till att vädret skrivs ut i terminalen i Pd. För att ändra vilken geografisk position, börja med att följa länken till SMHIs API [här](https://opendata.smhi.se/apidocs/metfcst/demo_point.html), välj sedan en plats på kartan och kopiera in siffrorna för latitude och longitude i index.js. Nästan högst upp i dokumentet finns två variabler, en för latitude och en för longitud. Ändra siffrorna och starta om programmet (för att avsluta programmet, tryck först ctrl+c, för att bläddra mellan senaste kommandon kan man använda piltangen upp tills man kommer tillbaka till "node index.js".

Servern skickar siffror till Pd som beskriver olika väderförhållanden. Längst ner på [denna sida](https://opendata.smhi.se/apidocs/metfcst/parameters.html) står vad siffrorna betyder.

För att trigga olika events i Pd, till exempel en ljudfil med [readsf~], kan man routa olika väder, alltså siffrorna som kommer från servern, med till exempel [route] objektet.

SMHIs API uppdaterar väderprognosen för dygnets alla 24 timmar varje hel timma, vidare läser koden av det nuvarande vädret när programmet startas, och uppdateras sen automatiskt en gång i timman. Objektet [change] används för att hindra Pd att skicka till exempel en bang ifall vädret uppdateras, men vädret är detsamma.


