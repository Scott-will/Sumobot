class Ultrasonic{
      int echo;
      int trig;
      public:
        void set_pins(int, int);
        float get_distance();
  };

  class Light_sensor{
     int pin;
     public:
      void set_pin(const int);
      bool check_pin();
  };

  class Motor{
     int pin;
     public:
      void go_forward();
      void reverse();
      void change_direction();
  };
  void Ultrasonic::set_pins(int x, int y){
    echo = y;
    trig = x;
  }

  float Ultrasonic::get_distance(){
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    unsigned long duration = pulseIn(echo, HIGH);
    float distance = duration/29/0/2.0;
    Serial.println(distance);
    return distance;
  }

  void Light_sensor::set_pin(const int x){
    pin = x;
  }
  
  bool Light_sensor::check_pin(){
    if (analogRead(pin) < 1.00){
      return true;
    }

    else{
      return false;
    }
  }

  bool sensor1; //values to check if on edge
  bool sensor2;
  float d1;   //values to check how far bot is
  float d2;

  Ultrasonic Us1; //creates instances of classes
  Ultrasonic Us2;
  Light_sensor Ls1;
  Light_sensor Ls2;


void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  Us1.set_pins(8, 9);
  Us2.set_pins(10, 11);
  Ls1.set_pin(A0);
  Ls2.set_pin(A1);  
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor1 = Ls1.check_pin();
  sensor2 = Ls2.check_pin();

  if (sensor2 == true || sensor1 == true){
    Serial.println("Go back");
    //make motors reverse
  }
  d1 = Us1.get_distance();
  d2 = Us2.get_distance();

  if (d1 < 70.0 || d2 < 70.0){
    Serial.println("go forward");
    //stop spinning and go forward
  }
  
 
}
