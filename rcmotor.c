// Arduino Obstacle Avoiding Robot 
// Code adapted from http://www.educ8s.tv 
#include <Servo.h>

#define TRIG_PIN A4
#define ECHO_PIN A5
#define MAX_DISTANCE 200
Servo myservo;
boolean goesForward = false;
int distance = 100;
int speedSet = 0;
const int motorPin1 = 11;
const int motorPin2 = 10;
//Motor B
const int motorPin3 = 6;
const int motorPin4 = 5;
void setup() {
  myservo.attach(9);
  myservo.write(115);
}
void loop() {
/*
  for (int i = 0; i < 10000; i++) {
     analogWrite(motorPin1, 180);
 analogWrite(motorPin2, 0);
 analogWrite(motorPin3, 180);
 analogWrite(motorPin4, 0);
  }
*/

  delay(1000);
  
  for (int i = 0; i < 10000; i++) {
    analogWrite(motorPin1, 0);
 analogWrite(motorPin2, 180);
 analogWrite(motorPin3, 0);
 analogWrite(motorPin4, 180); 
  }

  delay(1000);
}
