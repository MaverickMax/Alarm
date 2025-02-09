int BLU = 3;
int GRN = 2;
int RED = 4;
int Beep_boi = 8; //ALARM 
int STAGE_ON = 5;
int STAGE_DUAL = 6;
int STAGE_OFF = 7;


#include "SR04.h"
#define TRIG_PIN A3
#define ECHO_PIN A2
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

void setup() {
pinMode(RED, OUTPUT);
pinMode(GRN, OUTPUT);
pinMode(BLU, OUTPUT);
pinMode(Beep_boi, OUTPUT);
pinMode(STAGE_ON, INPUT_PULLUP);
pinMode(STAGE_DUAL, INPUT_PULLUP);
pinMode(STAGE_OFF, INPUT_PULLUP);



  
  

Serial.begin(9600);
digitalWrite(Beep_boi, LOW);
}
int redValue;
int greenValue;
int blueValue;

void loop() {
  #define delayTime 10



 if(digitalRead(STAGE_ON) == LOW)
 {
  digitalWrite(RED,LOW), digitalWrite(GRN, HIGH), digitalWrite(BLU, LOW);
   loop(); {
  int lightDetector = analogRead(A0);
  
  Serial.print("Analog reading = ");
  Serial.print(lightDetector);   // the raw analog reading

  // We'll have a few threshholds, qualitatively determined
  if (lightDetector < 50) {
    Serial.println(" - Door has been opened"),digitalWrite(Beep_boi, HIGH);
  } else  {
    Serial.println(" - Door remains closed"),digitalWrite(Beep_boi, LOW);
 
  }
   delay(700);
 }
 }
    if(digitalRead(STAGE_DUAL) == LOW)
 {
  digitalWrite(RED,LOW), digitalWrite(GRN, LOW), digitalWrite(BLU, HIGH);
loop(); {
   a=sr04.Distance();
   Serial.print(a);
   Serial.println("cm");

    int lightDetector = analogRead(A0);

  Serial.print("Analog reading = ");
  Serial.print(lightDetector);   // the raw analog reading

  // We'll have a few threshholds, qualitatively determined
  if (lightDetector < 150 and a < 30) {
    Serial.println(" - Door has been opened"),digitalWrite(Beep_boi, HIGH);
  } else  {
    Serial.println(" - Door remains closed"),digitalWrite(Beep_boi, LOW);
 
  }

 }
 }
 
 
 if(digitalRead(STAGE_OFF) == LOW)
 {
  digitalWrite(RED,HIGH), digitalWrite(GRN, LOW), digitalWrite(BLU, LOW);
  digitalWrite(Beep_boi, LOW);
 }

redValue = 255; // choose a value between 1 and 255 to change the color.
greenValue = 255;
blueValue = 255;
}
