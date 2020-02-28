# ECG_WiFi 

Repositori que allotja el codi per l'electrocardiògraf amb connectivitat Wi-Fi que hem desenvolupat per l'assignatura d'Aplicacions industrials dels microprocessadors.

Conté:

* Codi Arduino Nano.
* Codi ESP-01.
* Arxius de disseny del circuit imprès.
* Arxius de la caixa: STL i editable amb SolidWorks.
* Memòria del projecte en PDF i originals en TeX.


## Resultats

<img src="https://drive.google.com/uc?export=view&id=11FMWBnEfO2eM9R5VtW1JbiUtnjxs2st9" width=100%>
<img src="https://drive.google.com/uc?export=view&id=1hwH6YIEUzncWyd3L917bixS2f2-p1eiy" width=100%>

## Hardware
* Arduino Nano - Realitza la lectura de la senyal de l'ECG, fa els càlculs necessaris i respon per I2C a l'ESP-01.
* ESP-01 - Emmagatzema dades, calcula la variància de les dades i mostra la web.
* AD8232 - Amplifica la diferència de tensió entre dos elèctrodes i la referencia respecte un tercer elèctrode.
* NeoPixel 16 LEDs - Anell de LEDs que indica de forma molt visual la freqüència cardíaca.
* Pila 1,2V 2800mAh
* Reguladors de tensió - Convertidor boost a 5V i regulador lineal de 5V a 3,3V.

<img src="https://drive.google.com/uc?export=view&id=1OwWSyZsfkwHrD8OPpXs3E0eJzi3jnsBT" width="600">

La placa de circuit imprès dissenyada:

<img src="https://drive.google.com/uc?export=view&id=15edPhUFj0VzMyy1Zxvsf8PRmim2vZPJy" width="400">

## Software
### Arduino Nano
S'encarrega de fer les lectures de freqüència cardíaca, controlar els LEDs que s'han d'encendre i comunicar les dades per I2C a l'ESP-01.

<img src="https://drive.google.com/uc?export=view&id=18ilxempdVNSotkTA9mkRWEK1KUC6rwiT" width="500">

### ESP-01
Contínuament demana dades a l'Arduino Nano. Cada vegada que rep una dada l'emmagatzema en memòria. Calcula la variància de les dades. Conté la web programada en HTML, amb fragments de CSS i JavaScript. Cada vegada que es connecta un client li passa les dades més recents.

<img src="https://drive.google.com/uc?export=view&id=1N8h_sPnpfsne39gnEx7M1gGLyZmYzbAA" width="300">


## Autors

* **Llorenç Fanals Batllori** - *Desenvolupament* - [LFanals](https://github.com/LFanals)
* **Pol Fernández Rejón** - *Desenvolupament*

## Llicència

El projecte està sota la llicència [LICENSE](LICENSE). Podeu baixar-vos i utilitzar aquest repositori de forma lliure.

## Agraïments

* [JLCPCB](https://jlcpcb.com/) per la seva gran qualitat al fabricar el PCB i la rapidesa a fer l'entrega.
