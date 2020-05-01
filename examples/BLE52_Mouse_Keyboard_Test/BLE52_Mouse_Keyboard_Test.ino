/*
 * Sample program demonstrating BLE52_Mouse_and_Keyboard.h module which
 * simulates the standard Arduino Mouse.h API and Arduino Keyboard.h API 
 * for use with Bluetooth connections with the nRF52840.
 * This program tests the mouse and keyboard portions together.
 */

#include <BLE52_Mouse_and_Keyboard.h>

void setup() {
  Serial.begin(115200);
  while ( !Serial ) delay(10);   // for nrf52840 with native usb
  Serial.println("Bluefruit52 HID Mouse Example");
  Serial.println("Go to your phone's Bluetooth settings to pair your device");
  Serial.println("then open an application that accepts mouse and keyboard input");

  /*
   * Unlike Arduino Mouse.h and Keyboard.h you MUST call a begin method to ensure
   * that initialization of the device and Bluetooth connection.
   * Because this library defines the mouse and keyboard as a single Bluetooth
   * device, you really only need to call either Mouse.begin() or Keyboard.begin()
   * It doesn't hurt to call them both just in case you would later decide to remove one
   * you would be sure at least one of them got called. Similarly you can check either
   * Mouse.isConnected() or Keyboard.isConnected() because it doesn't matter. Your
   * device sees it as a single Bluetooth device with both mouse and keyboard capabilities.
   */
  Mouse.begin();
  Keyboard.begin();
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
  
  Serial.println("USB mouse and keyboard test");
  Keyboard.println("The first line of text");   //write some text
  Keyboard.println("The second line of text");
  Serial.println("Wrote some text.");
  delay(2000);
  Mouse.click();
  Keyboard.press(KEY_LEFT_SHIFT);   //hold the shift key
  Mouse.move(100,0);                //move the mouse
  Mouse.click();                    //click again
  Keyboard.releaseAll();            //release the shift
  Serial.println("Highlighted the first line.");
  delay(2000);
  Keyboard.press(KEY_LEFT_CTRL);    //do a control-x
  Keyboard.write('x');              //press and release 'x' key
  Keyboard.releaseAll();            //release the control
  Serial.println("Cut the text");
  delay(2000);
  Mouse.move(0, 20);                //move the mouse down a bit
  Mouse.click();
  delay(2000);
  Keyboard.press(KEY_LEFT_CTRL);    //do a control-v
  Keyboard.write('v');              //press and release 'v' key
  Keyboard.releaseAll();            //release the control
  Serial.println("Pasted the text");
  Serial.println("Test completed.");
};
void loop() {
}

/*
 * Click just after the "*" on the on the next line before uploading
 * 
 * 
 * 
 *  
 *  
 * 
 *  
 *  
 *  
 *  
 *  
 *  
 */
