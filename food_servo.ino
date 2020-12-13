#include <Servo.h>

#define MAX_PWM 2150
#define MID_PWM 1500
#define MIN_PWM 850

Servo myservo;




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9);

  //myservo.writeMicroseconds(1500);
  //delay(2000);


}

void loop() {
  // put your main code here, to run repeatedly:

 
  //1
  myservo.write(90);
  delay(30000);
  myservo.write(87);
  delay(1395);

  
  //2
  myservo.write(90);
  delay(30000);
  myservo.write(87);
  delay(1380);

 
  //3
  myservo.write(90);
  delay(30000);
  myservo.write(87);
  delay(1300);

  
  //4
  myservo.write(90);
  delay(30000);
  myservo.write(87);
  delay(1275);
  //5

  
  myservo.write(90);
  delay(30000);
  myservo.write(87);
  delay(1280);
  
  
  //6
  myservo.write(90);
  delay(30000);
  myservo.write(87);
  delay(1300);
 
}
