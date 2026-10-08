#include <Servo.h>

Servo myservo;
int servopin = 7;
int angle;
int redpin = 8;
int greenpin = 12; 
int echopin = 4;
int trigpin = 2;
int pingtraveltime;
void setup() {
  Serial.begin(9600);
  myservo.attach(servopin);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin ,INPUT);
  pinMode(redpin,OUTPUT);
  pinMode(greenpin,OUTPUT);

}

void loop() {
  // Sweep from 0 to 180 degrees
digitalWrite(redpin,HIGH);

  for (angle = 0; angle <= 180; angle++) {
  
    myservo.write(angle);
      digitalWrite(trigpin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  pingtraveltime = pulseIn(echopin,HIGH);
  Serial.println(pingtraveltime);
  delay(100);
    if (pingtraveltime > 0 && pingtraveltime < 750){
      digitalWrite(redpin,LOW);
      digitalWrite(greenpin,HIGH);
    }
    else {
      digitalWrite(redpin,HIGH);
      digitalWrite(greenpin,LOW);
    }
    
  }

  // Sweep from 180 back to 0 degrees
  for (angle = 180; angle >= 0; angle--) {
   
    myservo.write(angle);
      digitalWrite(trigpin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  pingtraveltime = pulseIn(echopin,HIGH);
  Serial.println(pingtraveltime);
  delay(100);
  if (pingtraveltime > 0 && pingtraveltime < 750){
      digitalWrite(redpin,LOW);
      digitalWrite(greenpin,HIGH);
    }
    else {
      digitalWrite(redpin,HIGH);
      digitalWrite(greenpin,LOW);
    }
  }  
}