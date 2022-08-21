int button = 2;
int buttonState = HIGH;
int prev = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(button,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(button);
  if(buttonState==LOW&prev==0){
    prev = 1;
    Serial.println("on");
    }else if (buttonState == HIGH&prev==1){
      prev=0;
      Serial.println("off");
      }
}
