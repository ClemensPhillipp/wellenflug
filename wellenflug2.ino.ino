#include <Servo.h>
int GSM1 = 3;
int GSM2 = 5;

#define In1 12
#define In2 13

#define In3 2
#define In4 4

Servo myservo;
int pos = 150;

void setup() {
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  pinMode(GSM1, OUTPUT);
  pinMode(GSM2, OUTPUT);

  myservo.attach(6);
  myservo.write(pos);

  Serial.begin(9600);
}

void loop() {
  for (pos; pos >= 120; pos -= 1) {
    myservo.write(pos);
    delay(15);
  }
  startSpin();

  delay(5000);
  for (pos; pos >= 0; pos -= 1) {
    myservo.write(pos);
    if (pos == 50) {
      shake();
    }
    delay(15);
  }

  delay(15000);
  for (pos = 0; pos <= 150; pos += 1) {
    myservo.write(pos);
    if (pos == 50) {
      shakeOff();
    }else if(pos == 120){
      stopSpin();
    }
    delay(15);
  }

  
  delay(15000);
}

void startSpin() {
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  for (int i = 0; i <= 255; i += 5) {
    analogWrite(GSM1, i);
    delay(250);
  }
}

void stopSpin() {
  for (int i = 255; i >= 0; i -= 5) {
    analogWrite(GSM1, i);
    delay(250);
  }
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
}

void shake() {
  analogWrite(GSM2, 50);

  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
}

void shakeOff() {
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
}
