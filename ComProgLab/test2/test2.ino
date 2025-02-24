#include <M5Stack.h>
int count = 5;
void setup() {
  M5.begin();
  M5.Speaker.setVolume(4);
  M5.Lcd.setTextSize(10);
  M5.Lcd.setTextColor(GREEN);
  display(count);
}

void loop() {
  M5.update();
  if (M5.BtnA.wasPressed()) {
    while (count != 0) {
      delay(500);
      count--;
      display(count);
    }
    M5.Speaker.beep();
  } else if (M5.BtnB.wasPressed()) {
    count = 5;
    display(count);
  } else if (M5.BtnC.wasPressed()) {
    if (count < 10) {
      count++;
      display(count);
    } else {
      M5.Speaker.beep();
    }
  }
}

void display(int c) {
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.print(c);
}