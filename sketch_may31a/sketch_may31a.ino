#include <Servo.h>
Servo myServo;
int const potPin=A0;
int potVal;
int angle;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal=analogRead(potPin);
  Serial.print("potVal: ");
  Serial.println(potVal);
  
  //angle=168;
  angle=map(potVal, 0, 1023, 0, 160);
  Serial.print("angle: ");
  Serial.println(angle);
  Serial.println();
  
  myServo.write(angle);
  delay(15);
}
