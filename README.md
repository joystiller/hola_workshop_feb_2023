# hola_workshop_feb_2023

Kopiera länken till koden (tryck på gröna knappen "code", kopiera https koden)

Öppna terminalen eller kommandotolken

Används commando "cd" för att navigera till en lämplig folder (https://help.ubuntu.com/community/UsingTheTerminal)

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

Lägg märke till att vädret skrivs ut i terminalen. För att ändra vilken geografisk position som används kan man ta read på latitude och longitude [här](https://opendata.smhi.se/apidocs/metfcst/demo_point.html). Välj en plats på kartan och kopiera in siffrorna för latitude och longitude i index.js. Nästan högst upp i dokumentet finns två variabler, en för latitude och en för longitud. Ändra siffrorna och starta om programmet (för att avsluta programmet, tryck ctrl+c). 

Längst ner på [denna sida](https://opendata.smhi.se/apidocs/metfcst/parameters.html) står vad siffrorna betyder. Det står också i en kommentar i pd-sketchen, om än något svårläst. 

Med till exempel [route] objektet kan man i Pd routa siffror till olika siffror, alltså väder, till olika events. 

Vädret uppdateras automatiskt en gång i timman. 
