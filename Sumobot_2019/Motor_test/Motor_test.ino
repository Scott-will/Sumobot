#include <Servo.h>

#define MIN_SIGNAL 0
#define OFF_SIGNAL 90
#define MAX_SIGNAL 180
#define MOTOR_PIN 9
Servo motor;

void setup(){
  Serial.begin(9600);
  delay(2000);
  motor.attach(MOTOR_PIN);
  
  motor.write(MAX_SIGNAL);
  delay(2000);
  
  motor.write(OFF_SIGNAL);
  delay(1000);
  motor.write(MIN_SIGNAL);
  delay(1000);
  
}

void loop(){
  /*motor.write(MAX_SIGNAL);
  delay(500);
  motor.write(OFF_SIGNAL);
  delay(500);
  motor.write(MIN_SIGNAL);
  delay(500);
  motor.write(OFF_SIGNAL);
  delay(500);
  /*motor.writeMicroseconds(OFF_SIGNAL);
  delay(500);
  motor.writeMicroseconds(MIN_SIGNAL);
  delay(500);
  motor.writeMicroseconds(OFF_SIGNAL);
  delay(500);*/
  /*analogWrite(motA, 0);
  motA.writeMicroseconds(MAX_PULSE_LENGTH);
  delayMicroseconds(1000);*/  
}
/*const int motor1PinClock = 5;
const int Motor1counter = 6;
const int Motor2Pin = 2;
const int Motor2PinCount = 3;
const int LightSensor = A0;
const int TrigPin = 9;
const int EchoPin = 10;

const int on = 255;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1PinClock, OUTPUT);
  pinMode(Motor1counter, OUTPUT);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
      analogWrite(5,255);
      analogWrite(Motor2Pin,255);
      delay(1000);
      analogWrite(Motor2Pin,0);
      analogWrite(motor1PinClock,0);
      delay(10);
      analogWrite(Motor2PinCount,255);
      analogWrite(6,255);
      delay(1000);
      analogWrite(Motor2PinCount,0);
      analogWrite(6,0);
      delay(10);
}*/
