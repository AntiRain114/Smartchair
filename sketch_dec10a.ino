#include <SoftwareSerial.h>

SoftwareSerial espSerial(10, 11); // RX, TX

const int sensorPins[4] = {A0, A1, A2, A3};
const int touchSensorPin = 2; // 触摸传感器连接到数字引脚2
const int THRESHOLD = 75;

int seatFrontBackDiff;
int backLeftRightDiff;
bool isSleeping = false;
unsigned long sleepStartTime;

void setup() {
  Serial.begin(9600);
  espSerial.begin(9600);
  pinMode(touchSensorPin, INPUT);
}

void loop() {
  int sensorValue = digitalRead(touchSensorPin);
  if (sensorValue==1) { // 检测到触摸
    isSleeping = true;
    sleepStartTime = millis();
  }

  if (isSleeping) {
    if (millis() - sleepStartTime > 3600000) { // 1小时后唤醒
      isSleeping = false;
    } else {
      delay(1000); // 休眠期间每秒检查一次
      return;
    }
  }

  // 正常操作
  int sensorValues[4];
  for (int i = 0; i < 4; i++) {
    sensorValues[i] = analogRead(sensorPins[i]);
  }

  analyzePosture(sensorValues);
  String alert = giveFeedback();
  if (alert != "") {
    Serial.println("Data sent to ESP8266" );
    sendToESP8266(alert);
  }

  delay(1000); // 1秒延迟
}

bool isPostureChanged(int values[]) {
  static int lastValues[4] = {0, 0, 0, 0};
  bool changed = false;

  for (int i = 0; i < 4; i++) {
    if (abs(values[i] - lastValues[i]) > THRESHOLD) {
      changed = true;
    }
    lastValues[i] = values[i];
  }

  return changed;
}

void analyzePosture(int values[]) {
  seatFrontBackDiff = values[0] - values[1];
  backLeftRightDiff = values[2] - values[3];
}

String giveFeedback() {
  String alert = "";
  if (abs(seatFrontBackDiff) > THRESHOLD) {
    alert += "Adjust your sitting posture: Please sit back and keep your back close to the backrest.\n";
  }
  if (abs(backLeftRightDiff) > THRESHOLD) {
    alert += "Adjust your sitting posture: Please sit in the middle and avoid leaning to one side.\n";
  }
  return alert;
}

void sendToESP8266(String message) {
  espSerial.println(message);
}