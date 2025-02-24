#include <M5Stack.h>
#include <DHT.h>

DHT dht(21, DHT22);
int cnt = 0;
float old_t = -100.0, old_h = -100.0;
int LCD_state = 0;
bool show_celsius = true;

void setup() {
  M5.begin();

  M5.Lcd.setTextSize(10);
  M5.Lcd.setTextColor(YELLOW);
  M5.Lcd.println("Lab 5");

  Serial.begin(115200);
  Serial.println("Lab 5");

  dht.begin();
}
void loop() {
  delay(2000);

  M5.update();

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  ++cnt;
  Serial.printf("%03d -> ", cnt);
  Serial.printf(" Humidity: %.2f%% Temperature: %.2f°C %.2f°F\n", h, t, f);

  if (M5.BtnA.wasPressed()) {
    Serial.printf("Button A is pressed\n");
    LCD_state = !LCD_state;
    M5.Lcd.setBrightness((LCD_state) ? 0 : 255);
  }
  if (M5.BtnB.wasPressed()) {
    Serial.printf("Button B is pressed\n");
    show_celsius = true;
  }
  if (M5.BtnC.wasPressed()) {
    Serial.printf("Button C is pressed\n");
    show_celsius = false;
  }
  if (t == old_t && h == old_h) {
    return;
  }

  old_t = t;
  old_h = h;

  update_LCD(cnt, h, t, f);
}
void update_LCD(int count, float humidity, float celsius, float fahrenheit) {
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.fillScreen(BLACK); 
  M5.Lcd.println(count);
  M5.Lcd.print((show_celsius)?celsius:fahrenheit);
  M5.Lcd.println((show_celsius)?"C":"F");
  M5.Lcd.print(humidity);
  M5.Lcd.println("%");
}