#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include "wifi_config.h"
#include "wifi_setup.h"

#ifndef STASSID
#define STASSID "INNOVATION"
#define STAPSK  "035720369innova"
#endif
const char* ssid = STASSID;
const char* password = STAPSK;
void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Booting Sketch...");
  WiFi.mode(WIFI_AP_STA);
  WiFi.begin(ssid, password);

  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    WiFi.begin(ssid, password);
    Serial.println("WiFi failed, retrying.");
  }
  Serial.print("connected...yeey :)  IP address : ");
  Serial.println(WiFi.localIP());
  OTAsetup();
}

void loop() {
  OTAloop();

}
