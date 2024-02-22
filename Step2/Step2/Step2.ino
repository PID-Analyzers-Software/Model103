#include <EEPROM.h>

void saveSampleValuesToEEPROM() {
  // Timer Interval: 0
  int timerInterval = 30; // Sample value
  EEPROM.put(0, timerInterval);

  // Selected Gas Index: 4
  int selectedGasIndex = 2; // Sample value
  EEPROM.put(4, selectedGasIndex);

  // Gas Calibration Parameters
  double gas1Intercept = 1.1, gas1Slope = 2.2; // Sample values
  EEPROM.put(8, gas1Intercept);
  EEPROM.put(16, gas1Slope);

  double gas2Intercept = 3.3, gas2Slope = 4.4; // Sample values
  EEPROM.put(24, gas2Intercept);
  EEPROM.put(32, gas2Slope);

  double gas3Intercept = 5.5, gas3Slope = 6.6; // Sample values
  EEPROM.put(40, gas3Intercept);
  EEPROM.put(48, gas3Slope);

  double gas4Intercept = 7.7, gas4Slope = 8.8; // Sample values
  EEPROM.put(56, gas4Intercept);
  EEPROM.put(64, gas4Slope);

  // Range Setting: 72
  int rangeSetting = 100; // Sample value
  EEPROM.put(72, rangeSetting);

  // Alarm Setting: 76
  int alarmSetting = 200; // Sample value
  EEPROM.put(76, alarmSetting);

  // Calibration Value: 80
  int calibrationValue = 300; // Sample value
  EEPROM.put(80, calibrationValue);

  // Device ID: 84
  String deviceId = "Device1234"; // Sample value
  for (unsigned int i = 0; i < deviceId.length(); i++) {
    EEPROM.write(84 + i, deviceId[i]);
  }

  // Wi-Fi SSID: 148
  String wifiSSID = "MyWiFiNetwork"; // Sample value
  for (unsigned int i = 0; i < wifiSSID.length(); i++) {
    EEPROM.write(148 + i, wifiSSID[i]);
  }

  // Wi-Fi Password: 180
  String wifiPassword = "MyWiFiPassword"; // Sample value
  for (unsigned int i = 0; i < wifiPassword.length(); i++) {
    EEPROM.write(180 + i, wifiPassword[i]);
  }

  // Commit changes to EEPROM
  EEPROM.commit();
}

void setup() {
  // Initialize EEPROM
  if (!EEPROM.begin(512)) { // Assuming 512 bytes of EEPROM, adjust as necessary
    Serial.println("Failed to initialise EEPROM");
    delay(1000);
  }

  saveSampleValuesToEEPROM();

  Serial.begin(115200);
  Serial.println("Sample values saved to EEPROM.");
}

void loop() {
  // Your main code
}
