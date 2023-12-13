#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

// WiFi配置
#include "arduino_secrets.h"   //import password file


const char* ssid     = SECRET_SSID; // Set the WiFi SSID from the arduino_secrets.h file
const char* password = SECRET_PASS; // Set the WiFi password from the arduino_secrets.h file

const char* serverUrl = "http://43.157.46.171:3000/sendToDiscord"; // 替换为您的Node.js服务器URL

WiFiClient wifiClient;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n');
    sendDataToServer(data);
  }
}

void sendDataToServer(String data) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(wifiClient, serverUrl); // 使用WiFiClient对象和URL初始化HTTPClient

    http.addHeader("Content-Type", "application/json");
    
    DynamicJsonDocument doc(1024);
    doc["message"] = data;
    String requestBody;
    serializeJson(doc, requestBody);

    int httpResponseCode = http.POST(requestBody);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println("Data sent to server: " + response);
    } else {
      Serial.println("Error sending data: " + httpResponseCode);
    }

    http.end();
  }
}