#include <M5Stack.h>
#define C 262
int led = 21;
int readByte;
void setup() {
  M5.begin();
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  M5.Speaker.setVolume(4);
}

void loop() {
  M5.update();
  if (Serial.available() > 0) {
    readByte = Serial.read();
    if (readByte > 96 && readByte < 123) {
      for (int i = 0; i < 3; i++) {
        digitalWrite(led, LOW);
        delay(500);
        digitalWrite(led, HIGH);
        delay(500);
      }
    } else {
      digitalWrite(led, HIGH);
      M5.Speaker.tone(C);
      delay(1000);
      M5.Speaker.mute();
      digitalWrite(led, LOW);
    }
  }
}
