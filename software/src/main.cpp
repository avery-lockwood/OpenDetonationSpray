#include <Arduino.h>
//pins
const int skrewPin = 10;
const int sparkPin = 3;
const int viobratorPin = 4;
const int ButtonPin = 22;
//other constants
int skrewFeedTime = 100;
int skrewSpeed = 100;
int sparkDelay = 10;

void setup() {
  pinMode(skrewPin, OUTPUT);
  pinMode(sparkPin, OUTPUT);
  pinMode(viobratorPin, OUTPUT);
  pinMode(ButtonPin,INPUT);
  pinMode(6,OUTPUT);
  Serial.begin(9600);
  digitalWrite(6,HIGH);
}

void loop() {
  
  if(digitalRead(ButtonPin) == 1){
    Serial.print("button pressed");

    analogWrite(skrewPin, skrewSpeed);

    digitalWrite(viobratorPin, HIGH);

    delay(skrewFeedTime);

    analogWrite(skrewPin, 0);

    delay(sparkDelay);

    digitalWrite(viobratorPin,LOW);

    analogWrite(sparkPin, 50); // tune spark power

    delay(100); // tune to change spark on time

    analogWrite(sparkPin, 0);
  }

}
 

