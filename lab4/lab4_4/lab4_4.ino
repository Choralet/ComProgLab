#include <M5Stack.h>
#define C 262
#define D 294
#define E 330
#define F 349
#define G 392
#define A 440
#define B 494
const int melody[] = { G, G, G, D, E, E, D, B, B, A, A, G };
const int factors[] = { 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 2 };
const float speeds[] = { 0.5, 0.75, 1.0, 1.5, 2.0 };
int cs = 3;
const int base_delay = 1000;  // 1 second

int total_notes = sizeof(melody) / sizeof(melody[0]);
int total_speed = sizeof(speeds) / sizeof(speeds[0]);
void setup() {
  M5.begin();
  Serial.begin(9600);
  M5.Speaker.setVolume(4);  // 0-11 (loudest)
}
void loop() {
  M5.update();


  for (int i = 0; i < total_notes; i++) {
    M5.update();
    if (M5.BtnC.isPressed() && cs >1) {
      cs--;
    }
    if (M5.BtnA.isPressed() && cs < total_speed) {
      cs++;
    }
    if (M5.BtnB.isPressed()) {
      cs = 3;
    }
    Serial.println(cs);
    int wait = speeds[cs - 1] * (1000 / factors[i]);
    M5.Speaker.tone(melody[i]);
    delay(wait);
    M5.Speaker.mute();
    delay(50);
  }
  delay(2000);  // pause for 2 second
}