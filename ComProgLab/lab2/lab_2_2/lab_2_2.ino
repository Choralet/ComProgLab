#include <M5Stack.h>
int ledPin = 21;
int ledPin1 = 22;
int ledPin2 = 23;
int ledState = HIGH;
void setup() {
  M5.begin();
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  digitalWrite(ledPin, ledState);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
}
void loop() {
  M5.update();  // read the press state of the key
  if (M5.BtnA.wasPressed() || M5.BtnB.wasPressed() || M5.BtnC.wasPressed()) {
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
  }
}