#include <Servo.h>

Servo my_servo;
void setup() {
  // put your setup code here, to run once
  my_servo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  my_servo.write(130);
}