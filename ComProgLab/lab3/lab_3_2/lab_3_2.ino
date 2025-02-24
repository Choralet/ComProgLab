#include <M5Stack.h>
int count = 0;
void setup() {
  M5.begin();
  Serial.begin(9600);
}
void loop() {
  M5.update();
  if (M5.BtnA.wasPressed()) {
    Serial.print("Clicked");
    Serial.println(count);
    ++count;
  }
}