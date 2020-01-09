// arduino UNO
#include <Wire.h>

int randNumber;
// char* lector_int = randNumber;
char cadena[3];

void setup() {
  Wire.begin(8);  //0x08=8, adreça 
//  Wire.onReceive(receiveEvent);
  Wire.onRequest(sendEvent);
  Serial.begin(9600);

  randomSeed(analogRead(1)); // per generar nombres random
}

void loop() {
 // sendEvent(2);
 // delay(1000);
}


void sendEvent(int howmany){
  randNumber = random(40, 200); Serial.print("generat: "); Serial.println(randNumber);
  
  cadena[2] = (randNumber - (randNumber/10)*10) + 48; 
  cadena[1] = (randNumber/10 - (randNumber/100)*10) + 48; 
  cadena[0] = (randNumber / 100) + 48; 
  Serial.println(cadena);

  if (randNumber >= 100){
    Wire.write(cadena); Serial.println("major de 100");
  }
 // Wire.write(cadena); // 3 bytes
}


/*
void receiveEvent(int howMany){
  String recibido;
  while (0 < Wire.available()) {
    char c = Wire.read();
    recibido += c;
  }
  Serial.print(recibido);
}
*/
