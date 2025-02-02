#include <M5Stack.h>
int led = 21;
int ledState = LOW;
int readByte;

void setup() {
  M5.begin();
  Serial.begin(9600);
  M5.Lcd.setTextSize(3);
  pinMode(led, OUTPUT);
  digitalWrite(led, ledState);
}
void loop() {
  M5.update();
  if (Serial.available() > 0) {
    readByte = Serial.read();
    if ((readByte > 47 && readByte < 58)) {
      ledState = !ledState;
      digitalWrite(led, ledState);
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);
      if (ledState == LOW) {
        M5.Lcd.print("OFF");
        Serial.println("OFF");
      } else {
        M5.Lcd.print("ON");
        Serial.println("ON");
      }
    }
  }
}