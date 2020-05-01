/*
 * Sample program demonstrating BLE52_Mouse_and_Keyboard.h module which
 * simulates the standard Arduino Mouse.h API and Arduino Keyboard.h API 
 * for use with Bluetooth connections with the nRF52840.
 * This program simply tries to connect your nRF52840to a PC or other
 * device using Bluetooth and it will report success when completed.
 */

#include <BLE52_Mouse_and_Keyboard.h>

void setup() {
  Serial.begin(115200);
  while ( !Serial ) delay(10);   // for nrf52840 with native usb
  Serial.println("Bluefruit52 Bluetooth Pairing Test");
  Serial.println("Go to your phone's Bluetooth settings to pair your device");
  Serial.println("then open an application that accepts mouse or keyboard input");

  Mouse.begin();      //This could be mouse or keyboard just for this test
                      //It attempts to initiate the Bluetooth connection
  Serial.print("Attempting to connect");
  uint8_t i=0;
  while(! Mouse.isConnected()) { 
    Serial.print("."); delay(100);
    if((++i)>50) {
      i=0; Serial.println();
    }
  };
  delay(1000);//just in case
  Serial.println("\nConnection successful");
};
void loop() {
}
