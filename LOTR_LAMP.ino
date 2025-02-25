#include "ICommunication.h"
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 32
#define NEO_COUNT 60 // Number of neo pixels in strip
#define BT_ECHO true // Should the bluetooth data be echoed over serial for debugging
#define BLE_COMM true // Utilize Bluetooth Low Energy for communcating with microcontroller
#define SERIAL_BAUD_RATE 115200
#define BTSERIAL_DEVICE_NAME "LOTR-Lamp"

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.


