# BLE52 Mouse and Keyboard library

This library provides an Arduino Mouse.h and Keyboard.h compatible API for using BLE connections on an nRF52840.

Copy all files to your "Arduino/libraries". See the "examples" folder for sample sketches.

This module simulates the standard Arduino "Mouse.h" API and Arduino "Keyboard.h" API for use with the BLE HID connections on the nRF52840. Instead of doing

    #include <HID.h>
    #include <Mouse.h>
    #include <Keyboard.h>

Simply do

    #include <TinyUSB_Mouse_and_Keyboard.h>
	 
In addition to the methods available in the standard Arduino Mouse.h and Keyboard.h you can also check to see if the Bluetooth connection has been established using…

    bool Mouse.isConnected()

or

    bool Keyboard.isConnected(void)

Also be sure to check out the companion library "[TinyUSB_Mouse_and_Keyboard](https://github.com/cyborg5/TinyUSB_Mouse_and_Keyboard)" which provides a similar interface for using TinyUSB connections.

