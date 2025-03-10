#include <M5Stack.h>
#define C 262
#define D 294
#define E 330
#define F 349
#define G 392
#define A 440
#define B 494
const int melody[] = { G, G, G, D, E, E, D, B, B, A, A, G };
// const int factors[] = { 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 2 };
// const int base_delay = 1000;  // 1 second
int total_notes = sizeof(melody) / sizeof(melody[0]);
int x = 0;
void setup() {
  M5.begin();

  M5.Speaker.setVolume(2);  // 0-11 (loudest)
}
void loop() {
  M5.update();
  if ((x + 1) > total_notes) { x = 0; }
  if (M5.BtnA.wasPressed()) {
    M5.Speaker.tone(melody[x]);
    
  } else if (M5.BtnA.wasReleased()) {
   
    M5.Speaker.mute();
    x++;
  }
}