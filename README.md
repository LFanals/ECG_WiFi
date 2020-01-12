# ECG_WiFi - Electrocardiògraf amb connectivitat Wi-Fi  

Repositori que allotja el codi per l'electrocardiògraf amb connectivitat Wi-Fi que hem desenvolupat per l'assignatura d'Aplicacions industrials dels microprocessadors.

També inclou la memòria del projecte, en format TeX, i el disseny de la placa de circuit imprès, fet en KiCAD.

## Resultats
La portada i l'abstract:
<p align="center">
<img src="https://github.com/LFanals/Plantilla_TFG/blob/master/PLANTILLA_TFG/captures/Portada_2.png" align="center" width="100%" height="100%">
</p>


## Software
<p align="center">
<img src="  https://drive.google.com/uc?export=view&id=1OwWSyZsfkwHrD8OPpXs3E0eJzi3jnsBT" align="center" width="100%" height="100%">
</p>


### Arduino Nano
Encarregada de mostrejar la senyal analògica que provés de l'AD8232. En segon pla s'encarrega de controlar l'anell de LEDs i de respondre a l'ESP8266 en cas de què s'hagi donat un nou pols.

### ESP8266
Hem fet servir una placa de desenvolupament que conté aquest integrat i té un total de 8 pins, se sol anomenar ESP-01.
Els pins d'I2C són el GPIO0 (data) i el GPIO2 (clock).  
S'encarrega de sol·licitar dades de freqüència cardíaca, connectar-se a una xarxa Wi-Fi i donar servei als client que se li connectin. Calcula la variància de les dades, que a la web s'anomena variabilitat.


## Autors

* **Llorenç Fanals Batllori** - *Desenvolupament* - [LFanals](https://github.com/LFanals)
* **Pol Fernández Rejón** - *Desenvolupament*

## Llicència

El projecte està sota la llicència [LICENSE](LICENSE). Podeu baixar-vos i utilitzar aquest repositori de forma lliure.

## Agraïments

* [JLCPCB](https://jlcpcb.com/) per la seva gran qualitat al fabricar el PCB i la rapidesa a fer l'entrega.
* Everyone that posted questions and answers on forums.
