# ECG_WiFi - Electrocardiògraf amb connectivitat Wi-Fi  

Repositori que allotja el codi per l'electrocardiògraf amb connectivitat Wi-Fi que hem desenvolupat per l'assignatura d'Aplicacions industrials dels microprocessadors.

També inclou la memòria del projecte, en format TeX, i el disseny de la placa de circuit imprès, fet en KiCAD.

## Resultats
La portada i l'abstract:
<p align="center">
<img src="https://github.com/LFanals/Plantilla_TFG/blob/master/PLANTILLA_TFG/captures/Portada_2.png" align="center" width="100%" height="100%">
</p>


## Hardware
* Arduino Nano - Realitza la lectura de la senyal de l'ECG, fa els càlculs necessaris i respon per I2C a l'ESP-01.
* ESP-01 - Emmagatzema dades, calcula la variància de les dades i mostra la web.
* AD8232 - Amplifica la diferència de tensió entre dos elèctrodes i la referencia respecte un tercer elèctrode.
* NeoPixel 16 LEDs - Anell de LEDs que indica de forma molt visual la freqüència cardíaca.
* Pila 1,2V 2800mAh
* Reguladors de tensió - Convertidor boost a 5V i regulador lineal de 5V a 3,3V.

<img src="https://drive.google.com/uc?export=view&id=1OwWSyZsfkwHrD8OPpXs3E0eJzi3jnsBT" width="600">

## Software
### Organigrama lògic de l'Arduino Nano
<img src="https://drive.google.com/uc?export=view&id=18ilxempdVNSotkTA9mkRWEK1KUC6rwiT" width="500">

### Organigrama lògic de l'ESP-01
<img src="https://drive.google.com/uc?export=view&id=1N8h_sPnpfsne39gnEx7M1gGLyZmYzbAA" width="300">


## Autors

* **Llorenç Fanals Batllori** - *Desenvolupament* - [LFanals](https://github.com/LFanals)
* **Pol Fernández Rejón** - *Desenvolupament*

## Llicència

El projecte està sota la llicència [LICENSE](LICENSE). Podeu baixar-vos i utilitzar aquest repositori de forma lliure.

## Agraïments

* [JLCPCB](https://jlcpcb.com/) per la seva gran qualitat al fabricar el PCB i la rapidesa a fer l'entrega.
* Everyone that posted questions and answers on forums.
