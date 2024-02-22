#include <EEPROM.h>

void setup() {
  // Initialize serial communication at 9600 bits per second:
  Serial.begin(115200);

  // Calculate the size of the EEPROM. On many Arduino boards, it's 512 or 1024 bytes.
  // EEPROM.length() provides the actual EEPROM size for the board.
  int eepromSize = EEPROM.length();

  Serial.println("Clearing EEPROM...");

  for (int i = 0; i < eepromSize; i++) {
    EEPROM.write(i, 0xFF); // Write 0xFF to each byte
  }

  Serial.println("EEPROM cleared!");

  // It's a good practice to call EEPROM.commit() after writing,
  // especially on ESP8266/ESP32 boards to ensure data is written to flash.
  // Uncomment the line below if you're using ESP8266/ESP32.
  // EEPROM.commit();

  // No need to loop endlessly, since the EEPROM clearing is a one-time operation.
  while (true) {}
}

void loop() {
  // Empty loop since we don't need to perform any operation repeatedly.
}
