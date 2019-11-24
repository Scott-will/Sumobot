#include <Servo.h>

#define MIN_SIGNAL 80 //Reverse speed (0-89)
#define OFF_SIGNAL 90 //Off speed
#define MAX_SIGNAL 100 //forward speed (90-180)
#define MOTOR_PIN1 9 //pin for motor on arduino
#define MOTOR_PIN2 10
Servo motor1; //motor 1
Servo motor2;



class Ultrasonic{ //class for ultrasonic, defines vars and functions
      public:
        int echo;
        int trig;
        void set_pins(int, int);
        float get_distance();
  };

  class Light_sensor{ //class for light sensor, defines vars and functions
     public:
      int pin;
      void set_pin(const int);
      bool check_pin();
  };

  void Ultrasonic::set_pins(const int x, const int y){ //sets pins for us
    echo = x; //echo pin
    trig = y; //trig pin on arduino
    pinMode(echo, INPUT); //since they read must be input
    pinMode(trig, OUTPUT);
  }

  float Ultrasonic::get_distance(){ //gets distance, returns the distance
    digitalWrite(trig, LOW);
    delay(2);
    digitalWrite(trig, HIGH);
    delay(10);
    digitalWrite(trig, LOW);
    unsigned long duration = pulseIn(echo, HIGH);
    int distance = duration*.017;
    
    return distance;
  }

  void Light_sensor::set_pin(const int x){ 
    pin = x; //pin for light sensor on arduino
    pinMode(pin, INPUT); //since it reads must be input
  }
  
  bool Light_sensor::check_pin(){ //check if light is detected
    //Serial.println(analogRead(pin)*5/1023.0);
    float value = analogRead(pin)*5/1023.0;
    
    delay(100);
    if (value < 1.00){ //this value (1.00) might need to be changed to a higher value
      return true; //if light is detected returns true
    }

    else{
      return false;
    }
  }

   //creates instances of classes
  Ultrasonic Us2;
  Light_sensor Ls1;
  Light_sensor Ls2;
  int current_state = 0;


void setup() { //runs once
  Serial.begin(9600); //speed do not change
  motor1.attach(MOTOR_PIN1); //sets pin to motor
  motor2.attach(MOTOR_PIN2);
  delay(2000); //delay is important,
 
  Us2.set_pins(6, 7); //sets pin for us and ls
  Ls1.set_pin(A0);
  Ls2.set_pin(A2);  
}

void loop() {
  // put your main code here, to run repeatedly:
  while(/*(Ls1.check_pin() != true && Ls2.check_pin() != true) &&*/  Us2.get_distance() > 60.0){//check light sensors again w distance
    //if no ls and no us, spins
    if(current_state == 2){
      motor2.write(OFF_SIGNAL);
      motor1.write(OFF_SIGNAL);
      current_state = 0;
      delay(10);
      
    }
    motor1.write(MAX_SIGNAL); //spin
    motor2.write(MIN_SIGNAL);
  }
  /*if(Ls1.check_pin() || Ls2.check_pin()){
    //if light detected it will exit while loop above and go backwards    
      motor1.write(OFF_SIGNAL); //turns off bc it glitches if it doesnt
      motor2.write(OFF_SIGNAL);
      delay(5);
    motor2.write(MIN_SIGNAL); //goes backwards
    motor1.write(MIN_SIGNAL);
    current_state = 1;
    
  }*/
  while(Us2.get_distance() <= 60.0){ //the value of 60 might need to be changed, depends on size of ring
    if(current_state != 2){ //this makes the motors not glitch
      motor1.write(OFF_SIGNAL);
      motor2.write(OFF_SIGNAL);
      current_state = 2;
      delay(10);
    }
    motor1.write(MAX_SIGNAL); //goes forward
    motor2.write(MAX_SIGNAL);
    
  }
}
