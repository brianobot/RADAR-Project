#include <Servo.h>

#define echoPin 2
#define trigPin 3

//create a variable to hold the duration and distance data
unsigned long duration;
int distance;

int start_angle=0;
int end_angle=180;

//create an object for controlling the Servomotor
Servo myServo;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  myServo.attach(12);
  Serial.println("UltraSonic Sensor Test");
  Serial.println("With Arduino Uno R3");
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=start_angle;i<end_angle;i++){
    myServo.write(i);
    delay(30);
    distance = calculateDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
  for(int i=end_angle;i>start_angle;i--){
    myServo.write(i);
    delay(30);
    distance = calculateDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}

int calculateDistance(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  while ((duration = pulseIn(echoPin, HIGH)) == 0){
    Serial.println("Waiting for update...");
    };
//  Serial.print(duration);
  distance = duration * 0.034 / 2 ;
//  Serial.print("Distance: ");
//  Serial.print(distance);
//  Serial.print(" cm");
//  Serial.println("");
  return distance;
}
