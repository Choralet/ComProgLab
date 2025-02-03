#include <M5Stack.h>
#define C 262
#define D 294
#define E 330
#define F 349
#define G 392
#define A 440
#define B 494
const int melody[] = { GE, G, G, D, E, E, D, B, B, A, A, G };
const int factors[] = { 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 };
const int base_delay = 1000;  // 1 second
int total_notes = sizeof(melody) / sizeof(melody[0]);
void setup() {
  M5.begin();
  M5.Speaker.setVolume(1);  // 0-11 (loudest)
}
void loop() {
  for (int i = 0; i < total_notes; i++) {
    int wait = 1000 / factors[i];
    M5.Speaker.tone(melody[i]);
    delay(wait);
    M5.Speaker.mute();
    delay(50);
  }
  delay(2000);  // pause for 2 second
}