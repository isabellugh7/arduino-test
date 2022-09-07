#include <Servo.h>

int cacti; // goes with pin 3, yellow
int birds; // goes with pin 4, green
int cacti2; //goes with pin 5, blue
const int yellow = 3;
const int green = 4;
const int blue = 5;

Servo cactiServo;
Servo birdServo;


void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
  cactiServo.attach(A4);
  birdServo.attach(A3);

}

void loop() {

  cacti = analogRead(A0);
  birds = analogRead(A1);
  cacti2 = analogRead(A2);
  
  if (cacti < 560) {
    if (cacti < 560 and cacti2 < 560) {
      cactiServo.write(15);
      digitalWrite(blue, HIGH);
      delay(100);    // at some point this will be able to detect different kind of cacti clusters and jump accordingly
    } else {
      digitalWrite(yellow, HIGH);
      cactiServo.write(15); 
      delay(100);
      cactiServo.write(0);
    }
  } else if (birds < 560) {
    digitalWrite(green, HIGH);
    birdServo.write(50);
    delay(100);
    birdServo.write(0);
    
  } else {
    cactiServo.write(0);
    birdServo.write(0);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    
  }

} 
