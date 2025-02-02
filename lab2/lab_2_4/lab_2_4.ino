#include <M5Stack.h>
int ledPin = 21;
int ledPin1 = 22;
int ledPin2 = 23;
int ledState = LOW;
int ledState1 = LOW;
void setup() {
  M5.begin();
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  digitalWrite(ledPin, ledState);
  digitalWrite(ledPin1, ledState1);
  digitalWrite(ledPin2, LOW);
}
void loop() {
  M5.update();  // read the press state of the key
  if (M5.BtnA.wasPressed()) {
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
  } else if (M5.BtnB.wasPressed()) {
    ledState1 = !ledState1;
    digitalWrite(ledPin1, ledState1);
  }
}