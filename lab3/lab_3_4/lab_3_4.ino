#include <M5Stack.h>
int ledR = 21;
int ledG = 22;
int ledB = 19;
int readByte;

void setup() {
  M5.begin();
  Serial.begin(9600);
  M5.Lcd.setTextSize(3);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  turnLed(LOW,LOW,LOW);
}
// 82 r 114
// 71 g 103
// 66 b 98
void loop() {
  M5.update();
  if (Serial.available() > 0) {
    readByte = Serial.read();
    switch (readByte) {
      case 82:
        turnLed2('r');
        break;
      case 114:
        turnLed2('r');
        break;
      case 71:
        turnLed2('g');
        break;
      case 103:
        turnLed2('g');
        break;
      case 66:
        turnLed2('b');
        break;
      case 98:
        turnLed2('b');
        break;
      default:
        turnLed2('0');
        break;
    } 
  }
}
void turnLed2(char ledC) {
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);
  switch (ledC) {
    case 'r':
      turnLed(HIGH, LOW, LOW);
      display("RED");
      break;
    case 'g':
      turnLed(LOW, HIGH, LOW);
      display("GREEN");
      break;
    case 'b':
      turnLed(LOW, LOW, HIGH);
      display("BLUE");
      break;
    default:
      turnLed(LOW, LOW, LOW);
      display("OFF");
      break;
  }
}
void turnLed(int r, int g, int b) {
  digitalWrite(ledR, r);
  digitalWrite(ledG, g);
  digitalWrite(ledB, b);
}
void display(char dis[]){
  M5.Lcd.print(dis);
  Serial.println(dis);
}