#include <Adafruit_Fingerprint.h>
#include <Servo.h>

int servoPin = 9;
Servo myServo;
SoftwareSerial mySerial(2, 3);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void setup()
{
//  Serial.begin(9600);
  finger.begin(57600);
  delay(5);
  
//  myServo.attach(servoPin);
//  myServo.write(0);
  delay(3000);
//  Serial.println(startTime);
}

void loop()                     // run over and over again
{
  getFingerprintIDez();
  delay(200); 
}

// returns -1 if failed, otherwise returns ID #
void getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return;

  // found a match!
  myServo.attach(servoPin);
  myServo.write(170);
  delay(3000);
  myServo.write(0);
  delay(100);
  myServo.detach();
}
