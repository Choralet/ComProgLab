#include <M5Stack.h>

void setup() {
  M5.begin();
  M5.Power.begin();
  // M5.Lcd.print("Hello World");

  M5.Lcd.setTextSize(5);
  M5.Lcd.setTextColor(CYAN);
  M5.Lcd.print("Arch\n");
  M5.Lcd.setTextColor(YELLOW);
  M5.Lcd.print("6738274921\n");
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.print("Siraphop\n");
  M5.Lcd.setTextColor(PINK);
  M5.Lcd.print("6738257221\n");

}

void loop() {
  // put your main code here, to run repeatedly:
}
