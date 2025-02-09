
#define Beep_boi 8

void setup() {
  pinMode(Beep_boi, OUTPUT);
  // put your setup code here, to run once:
Serial.begin(9600);
digitalWrite(Beep_boi, LOW);
}

void loop() {
 int analogValue = analogRead(A0);

  Serial.print("Analog reading = ");
  Serial.print(analogValue);   // the raw analog reading

  // We'll have a few threshholds, qualitatively determined
  if (analogValue < 50) {
    Serial.println(" - Door has been opened"),digitalWrite(Beep_boi, HIGH);
  } else  {
    Serial.println(" - Door remains closed"),digitalWrite(Beep_boi, LOW);
 
  }
  delay(700);
}
