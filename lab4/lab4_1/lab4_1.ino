#include <M5Stack.h>
#define C 262 * 2
#define D 294 * 2
#define E 330 * 2
#define F 349 * 2
#define G 392 * 2
#define A 440 * 2
#define B 494 * 2
#define Cs 277 * 2
#define Ds 311 * 2
#define Fs 370 * 2
#define Gs 415 * 2
#define As 466 * 2
const int melody[] = {Gs,A,Gs,G,Gs,Cs*2,E*2,Ds*2,Cs*2,Ds*2,Cs*2,C*2,Cs*2,E*2,Gs*2,Gs,A,Gs,G,Gs,Cs*2,E*2,Ds*2,Cs*2,Ds*2,Cs*2,C*2,Cs*2,E*2,Gs*2,A,Cs*2,Ds*2,Fs*2,A*2,Cs*4,Ds*4,B*4,A*4,Gs*4,Fs*4,E*4,Ds*4,Fs*4,Cs*4,C*4,Ds*4,A*2,Gs*2,Fs*2,A*2,E*2,Ds*2,Fs*2,Cs*2,C*2,Ds*2,A,Gs,B,A,Gs,A,Gs,G,Gs,Cs*2,E*2,Ds*2,Cs*2,Ds*2,Cs*2,C*2,Cs*2,E*2,Gs*2,Gs,A,Gs,G,Gs,Cs*2,E*2,Ds*2,Cs*2,Ds*2,Cs*2,C*2,Cs*2,E*2,Gs*2,0,Ds*2,E*2,Ds*2,D*2,Ds*2,B*2,As*2,Gs*2,G*2,E*4,Ds*4,Cs*4,B*2,As*2,Gs*2,G*2};
const int factors[] = { 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,  };
const int base_delay = 1000;  // 1 second
int total_notes = sizeof(melody) / sizeof(melody[0]);
void setup() {
  M5.begin();
  M5.Speaker.setVolume(8);  // 0-11 (loudest)
}
void loop() {
  M5.update();
  if (M5.BtnA.wasPressed()) {
    for (int i = 0; i < total_notes; i++) {
      int wait = 1000 / 8;  //factors[i];
      M5.Speaker.tone(melody[i]);
      delay(wait);
      M5.Speaker.mute();
      delay(10);
    }
  }
  // pause for 2 second
}