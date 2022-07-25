# RadioFM_With_Arduino
Come realizzare una radio FM con Arduino e TEA5767

Nell’articolo di oggi vedremo come realizzare una vera e propria radio su cui ascoltare le varie stazioni radio utilizzando una board Arduino Nano, un TEA5767, due bottoni, un display e delle casse.

Prima di cominciare con il progetto vero e proprio vediamo come funziona il modulo TEA5767.

Con questo modulo abbiamo modo di costruire un ricevitore radio. Inoltre è dotato di un amplificatore audio ( basato sull’integrato TDA1308 ) in grado di pilotare qualsiasi cuffia stereo o un amplificatore BF esterno. La comunicazione con i vari microcontrollori avviene attraverso il BUS I2C.

Con questa breve panoramica sul modulo TEA5767 vediamo quali sono le componenti da utilizzare per questo progetto:

Arduino (va bene qualsiasi)
* 2x bottoni
* Modulo FM Radio TEA5767
* Display LCD 16×02
* Vari jumper

# Video

https://www.youtube.com/watch?v=V43uGZiU8Ho

# Diagramma di collegamento

![alt text](https://i0.wp.com/www.moreware.org/wp/wp-content/uploads/2022/02/TEA5767-FM-Radio.jpg?w=645&ssl=1)

![alt text](https://i0.wp.com/www.moreware.org/wp/wp-content/uploads/2022/07/radioarduino.png?resize=1024%2C847&ssl=1)

# [Codice](https://github.com/SimoneMoreWare/RadioFM_With_Arduino/blob/main/radio.ino)

Potete ora caricare il codice sul vostro microcontrollore, premendo un tasto avrete modo di accendere la radio e con l’altro di cambiare le stazioni radio. Se modificate la riga contenente le frequenze sarete in grado di selezionare stazioni radio diverse e magari inserirci le vostre stazioni preferite.

Questo progetto è possibile realizzarlo con qualsiasi altra scheda e microcontrollore, basta che modificate i pin che definiscono il display e bottoni e tutto funzionerà normalmente.

Collegando le casse potete poi ben vedere che si tratta di una vera e propria radio con una qualità del segnale ottima (tradotto che si ha modo di avere un ascolto “pulito)
