#include <Adafruit_NeoPixel.h>

#define PIN 4

uint16_t i;

Adafruit_NeoPixel strip(18, PIN, NEO_GRB + NEO_KHZ800);


void setup() {

  Serial.begin(9600); // open the serial port at 9600 bps
  strip.begin();
  strip.setBrightness(200); // 0 To 255
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {


    five_led_snake();
    
      for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i,255,85,0);
      strip.show();
      delay(60);
      }

      for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i,0,0,0);
      strip.show();
      delay(60);
      }

      for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i,255,85,0);
      strip.show();
      delay(60);
      }
      
      for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i,0,0,0);
      strip.show();
      delay(60);
      }

      for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i,255,85,0);
      strip.show();
      delay(60);
      }
      
      delay(10000);


strip.clear();
      
}

void five_led_snake(){

    for(int i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(0+i,255,80,0);
      strip.setPixelColor(1+i,255,80,0);
      strip.setPixelColor(2+i,255,80,0);
      strip.setPixelColor(3+i,255,80,0);
      strip.setPixelColor(4+i,255,80,0);
      strip.show();
      delay(50);
      strip.setPixelColor(0+i,0,0,0);
      strip.setPixelColor(1+i,0,0,0);
      strip.setPixelColor(2+i,0,0,0);
      strip.setPixelColor(3+i,0,0,0);
      strip.setPixelColor(4+i,0,0,0);
      strip.show();
      if (i>55) {
      strip.setPixelColor(0,255,80,0);
      }
      if (i>56) {
      strip.setPixelColor(1,255,80,0);
      }
      if (i>57) {
      strip.setPixelColor(2,255,80,0);
      }
      if (i>58) {
      strip.setPixelColor(3,255,80,0);
      }
      if (i>59) {
      strip.setPixelColor(4,255,80,0);
      }
    }
  
}
