#include "SR04.h"

#include <Servo.h>

#define MAX_PWM 2150
#define MID_PWM 1500
#define MIN_PWM 850

Servo myservo;

#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
long a;

#define VCC2 5
#define VCC3 3
#define GND2 4

#define in1 6
#define in2 7
#define in3 9
#define in4 8

bool sense_ball = false;
bool sense_dog = true;
int motor_time = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(2, INPUT);

  pinMode(VCC2, OUTPUT);
  digitalWrite(VCC2, HIGH);
  pinMode(VCC3, OUTPUT);
  digitalWrite(VCC3, HIGH);
  pinMode(GND2, OUTPUT);
  digitalWrite(GND2, LOW);

  myservo.attach(10);

  //temporary
  pinMode(LED_BUILTIN, OUTPUT);
  delay(1000);
}

void loop() {
  /*
myservo.writeMicroseconds(1000);
delay(1000);
myservo.writeMicroseconds(1500);
delay(1000);
myservo.writeMicroseconds(2000);
delay(1000);
myservo.writeMicroseconds(1500);
delay(1000);
}
*/
  // put your main code here, to run repeatedly:
/*
  if(sense_ball == true and sense_dog == false){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in4, HIGH);
    digitalWrite(in3, LOW);
    myservo.writeMicroseconds(850);
    }else{
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in4, LOW);
    digitalWrite(in3, LOW);
    myservo.writeMicroseconds(1500);
  }
*/
/*
  if(sense_ball == true and sense_dog == false){
    while(sense_dog == false and motor_time != 30){
      a=sr04.Distance();
      if (a > 100){
       sense_dog = false;
       motor_time += 1;
      }else{
       sense_dog = true;
       motor_time = 1;
      }
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in4, HIGH);
      digitalWrite(in3, LOW);
      //myservo.writeMicroseconds(1850);
      myservo.write(50);
   delay(100);
      }}else{
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in4, LOW);
      digitalWrite(in3, LOW);
      if(sense_ball == true){
        //myservo.writeMicroseconds(1150);
        myservo.write(90);
        delay(100);
      }
      //myservo.writeMicroseconds(1500);
      if(motor_time != 1){
        myservo.write(130);
        delay(750);
        myservo.write(90);
        motor_time = 1;
      }
    }
  */

    if(sense_ball == true and sense_dog == false){
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in4, HIGH);
      digitalWrite(in3, LOW);
      //myservo.writeMicroseconds(1850);
      myservo.write(140);
      motor_time=2;
      }else{
      
      myservo.write(90);
      delay(2000);
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in4, LOW);
      digitalWrite(in3, LOW);
      if(motor_time != 1){
        myservo.write(50);
        delay(1000);
        myservo.write(90);
        motor_time = 1;
      }
    }
    
  int no_detect = digitalRead(2);

  if(no_detect == HIGH){
    //digitalWrite(LED_BUILTIN, LOW);
    sense_ball = false;
  }else{
    //digitalWrite(LED_BUILTIN, HIGH);
    sense_ball = true;
  }


   a=sr04.Distance();
   Serial.print(a);
   Serial.println("cm");
   if (a > 100){
    //digitalWrite(LED_BUILTIN, HIGH);
    sense_dog = false;
   }else{
    //digitalWrite(LED_BUILTIN, LOW);
    sense_dog = true;
   }
   delay(100);



}
