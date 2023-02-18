# hola_workshop_feb_2023

Kopiera länken till koden (tryck på gröna knappen "code", kopiera https koden)

Öppna terminalen eller kommandotolken

Används commando "cd" för att navigera till en lämplig folder. Mer om det [här](https://help.ubuntu.com/community/UsingTheTerminal).

Skriv 
```
git clone https://github.com/kaffeocigg/hola_workshop_feb_2023.git
```


Gå in i mappen genom att skriva cd hola_workshop_feb_2023


Skriv 
```
npm install
```

Detta installerar externa bibliotek genom "node package manager". Ifall npm saknas, ladda ner node [här](https://nodejs.org/en/download/).

Öppna sketchen hola_smhi_api.pd.

Kanske funkar inte [mrpeach/udpreceive] objektet? Gå i så fall till help -> externals och sök efter mrpeach eller udpreceive, och välj installera. Funkar inte det kan man prova att gå till pd -> preferences -> startup och lägga till "mrpeach". Man kan också prova att göra ett nytt objekt och skriva in "declare -lib mrpeach". 

Starta servern som laddar ner vädret, skriv
```
node index.js
```

Lägg märke till att vädret skrivs ut i terminalen i Pd. För att ändra vilken geografisk position, börja med att följa länken till SMHIs API [här](https://opendata.smhi.se/apidocs/metfcst/demo_point.html), välj sedan en plats på kartan och kopiera in siffrorna för latitude och longitude i index.js. Nästan högst upp i dokumentet finns två variabler, en för latitude och en för longitud. Ändra siffrorna och starta om programmet (för att avsluta programmet, tryck först ctrl+c, för att bläddra mellan senaste kommandon kan man använda piltangen upp tills man kommer tillbaka till "node index.js".

Servern skickar siffror till Pd som beskriver olika väderförhållanden. Längst ner på [denna sida](https://opendata.smhi.se/apidocs/metfcst/parameters.html) står vad siffrorna betyder.

För att trigga olika events i Pd, till exempel en ljudfil med [readsf~], kan man routa olika väder, alltså siffrorna som kommer från servern, med till exempel [route] objektet.

SMHIs API uppdaterar väderprognosen för dygnets alla 24 timmar varje hel timma, vidare läser koden av det nuvarande vädret när programmet startas, och uppdateras sen automatiskt en gång i timman. Objektet [change] används för att hindra Pd att skicka till exempel en bang ifall vädret uppdateras, men vädret är detsamma.


