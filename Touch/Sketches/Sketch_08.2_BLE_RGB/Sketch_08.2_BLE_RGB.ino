/*
* @ File:   Sketch_08.2_BLE_RGB.ino
* @ Author: [Zhentao Lin]
* @ Date:   [2025-06-14]
*/

#include "BLEDevice.h"
#include "BLEServer.h"
#include "BLEUtils.h"
#include "BLE2902.h"
#include "String.h"
#include "Freenove_WS2812_Lib_for_ESP32.h"

BLECharacteristic *pCharacteristic;
bool deviceConnected = false;
uint8_t txValue = 0;
long lastMsg = 0;
String rxload = "Test\n";

#define SERVICE_UUID "6E400001-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_TX "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"

#define KEY_PIN 0
#define LEDS_COUNT 1
#define LEDS_PIN   42
#define CHANNEL    0

Freenove_ESP32_WS2812 strip = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN, CHANNEL, TYPE_GRB);

uint8_t m_color[5][3] = { { 255, 0, 0 }, { 0, 255, 0 }, { 0, 0, 255 }, { 255, 255, 255 }, { 0, 0, 0 } };

void stripInit(void){
  strip.begin();
  strip.setBrightness(10);
}

void switchRGB(int value) {
  int colorIndex = value % 4;
  switch (colorIndex) {
    case 1:
      strip.setLedColorData(0, m_color[0][0], m_color[0][1], m_color[0][2]);
      strip.show();
      break;
    case 2:
      strip.setLedColorData(0, m_color[1][0], m_color[1][1], m_color[1][2]);
      strip.show();
      break;
    case 3:
      strip.setLedColorData(0, m_color[2][0], m_color[2][1], m_color[2][2]);
      strip.show();
      break;
    default:
      strip.setLedColorData(0, m_color[4][0], m_color[4][1], m_color[4][2]);
      strip.show();
      break;
  }
}

class MyServerCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer *pServer) {
    deviceConnected = true;
  };
  void onDisconnect(BLEServer *pServer) {
    deviceConnected = false;
  }
};

class MyCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
    String rxValue = pCharacteristic->getValue();
    if (rxValue.length() > 0) {
      rxload = "";
      for (int i = 0; i < rxValue.length(); i++) {
        rxload += (char)rxValue[i];
      }
    }
  }
};

void setupBLE(String BLEName) {
  const char *ble_name = BLEName.c_str();
  BLEDevice::init(ble_name);
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());
  BLEService *pService = pServer->createService(SERVICE_UUID);
  pCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID_TX, BLECharacteristic::PROPERTY_NOTIFY);
  pCharacteristic->addDescriptor(new BLE2902());
  BLECharacteristic *pCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID_RX, BLECharacteristic::PROPERTY_WRITE);
  pCharacteristic->setCallbacks(new MyCallbacks());
  pService->start();
  pServer->getAdvertising()->start();
  Serial.println("Waiting a client connection to notify...");
}

void setup() {
  Serial.begin(115200);
  stripInit();
  switchRGB(0);
  setupBLE("ESP32S3_BLE");
}

void loop() {
  long now = millis();
  if (now - lastMsg > 100) {
    if (deviceConnected && rxload.length() > 0) {
      Serial.println(rxload);
      if (strncmp(rxload.c_str(), "red_on", 6) == 0) {
        switchRGB(1);
      } else if (strncmp(rxload.c_str(), "red_off", 7) == 0) {
        switchRGB(0);
      } else if (strncmp(rxload.c_str(), "green_on", 8) == 0) {
        switchRGB(2);
      } else if (strncmp(rxload.c_str(), "green_off", 9) == 0) {
        switchRGB(0);
      } else if (strncmp(rxload.c_str(), "blue_on", 7) == 0) {
        switchRGB(3);
      } else if (strncmp(rxload.c_str(), "blue_off", 8) == 0) {
        switchRGB(0);
      }
      rxload = "";
    }
    if (Serial.available() > 0) {
      String str = Serial.readString();
      const char *newValue = str.c_str();
      pCharacteristic->setValue(newValue);
      pCharacteristic->notify();
    }
    lastMsg = now;
  }
}