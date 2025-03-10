#include <Arduino.h>
#include <HTTPClient.h>
#include <M5Stack.h>
#include <WiFi.h>
#include <WiFiMulti.h>

WiFiMulti wifiMulti;
HTTPClient http;

void setup() {
  M5.begin();
  Serial.begin(9600);
  M5.Lcd.setTextSize(3);
  M5.Power.begin();
  wifiMulti.addAP(
    "799",
    "1234567890");
  M5.Lcd.print("\nConnecting Wifi...\n");
}

void loop() {
  M5.update();
  if ((wifiMulti.run() == WL_CONNECTED)) {
    if (M5.BtnA.wasPressed()) {
      getData("161.200.192.243");
    } else if (M5.BtnB.wasPressed()) {
      getData("202.47.249.7");
    } else if (M5.BtnC.wasPressed()) {
      getData("203.131.212.198");
    }
  } else {
    M5.Lcd.clear();
    M5.Lcd.setCursor(0, 0);
    M5.Lcd.print("connect failed");
  }
}

void getData(char address[]) {
  char full[45] = "http://ip-api.com/json/";
  sprintf(full + strlen(full), "%s", address);
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.print("[HTTP] begin...\n");
  http.begin(full);
  M5.Lcd.print("[HTTP] GET...\n");
  int httpCode = http.GET();
  if (httpCode > 0) {
    M5.Lcd.printf("[HTTP] code: %d\n", httpCode);
    if (httpCode == HTTP_CODE_OK) {
      String payload = http.getString();
      Serial.println(payload);
      M5.Lcd.println(address);
    }
  } else {
    M5.Lcd.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }
  http.end();
}
