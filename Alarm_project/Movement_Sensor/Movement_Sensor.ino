#include "SR04.h"
#define TRIG_PIN A3
#define ECHO_PIN A2
#define Beep_boi 8 //ALARM 
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

void setup() {
   pinMode(Beep_boi, OUTPUT);
   Serial.begin(9600);
   delay(1000);
}

void loop() {
   a=sr04.Distance();
   Serial.print(a);
   Serial.println("cm");

   if (a < 30) {
    digitalWrite(Beep_boi, HIGH);}
    else {
      digitalWrite(Beep_boi, LOW);}
   delay(1000);
   }
