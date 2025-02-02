#include <M5Stack.h>
void setup() {
  M5.begin();
  M5.Lcd.setTextSize(3);
  M5.Lcd.println("Lab 3: Task 1");
  Serial.begin(115200);
  Serial.println(" ... ");
}
void loop() {
  M5.update();
  Serial.print("The button is ");
  if (M5.BtnA.wasPressed()) {
    Serial.println("*****Pressed*****");
  } else {
    Serial.println("Released");
  }
}