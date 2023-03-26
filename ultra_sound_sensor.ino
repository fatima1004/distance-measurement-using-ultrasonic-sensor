#include "Arduino.h"

int Echo = A4;
int Trig = A5;
int distance = 0;
int buzzerPin = 5;                              

int Distance_test(){
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  //delayMicroseconds(1000);
  float Fdistance = pulseIn(Echo, HIGH);
  Fdistance = Fdistance /58;
  Serial.print(distance);
  Serial.println(" cms");
  return (int)Fdistance;
}

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);                       // configuring pin 7 as Input
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, HIGH);
  Serial.begin(9600);
  Serial.println();
  }

void loop()
{
 distance = Distance_test();
 Serial.print(distance);
 if(distance <= 50){
 Serial.println("Distance is less than 200 cm");
 digitalWrite(LED_BUILTIN, HIGH);                   
 digitalWrite(buzzerPin, LOW);                        //Sound buzzer

}
else{
 Serial.println("Distance is greater than 200 cm");
 digitalWrite(LED_BUILTIN, LOW);
 digitalWrite(buzzerPin, HIGH); 
}
delay(500);
}
