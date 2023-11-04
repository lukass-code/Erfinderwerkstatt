/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-neopixel-led-strip
 */

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>  // Required for 16 MHz Adafruit Trinket
#endif

#define PIN_NEO_PIXEL 27  // Arduino pin that connects to NeoPixel
#define NUM_PIXELS 8    // The number of LEDs (pixels) on NeoPixel

#define DELAY_INTERVAL 250  // 250ms pause between each pixel

Adafruit_NeoPixel NeoPixel(NUM_PIXELS, PIN_NEO_PIXEL, NEO_GRB + NEO_KHZ800);

void setup() {
  NeoPixel.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  NeoPixel.clear();  // set all pixel colors to 'off'. It only takes effect if pixels.show() is called

  // turn pixels to green one by one with delay between each pixel
  for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
    NeoPixel.setPixelColor(pixel, NeoPixel.Color(30/4, 100/4, 200/4));  // it only takes effect if pixels.show() is called
    NeoPixel.show();                                           // send the updated pixel colors to the NeoPixel hardware.

    delay(DELAY_INTERVAL);  // pause between each pixel
  }

 // turn pixels to green one by one with delay between each pixel
  for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
    NeoPixel.setPixelColor(pixel, NeoPixel.Color(1/4, 255/4, 1/4));  // it only takes effect if pixels.show() is called
    NeoPixel.show();                                           // send the updated pixel colors to the NeoPixel hardware.

    delay(DELAY_INTERVAL);  // pause between each pixel
  }
 // turn pixels to green one by one with delay between each pixel
  for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
    NeoPixel.setPixelColor(pixel, NeoPixel.Color(255/4, 0, 0));  // it only takes effect if pixels.show() is called
    NeoPixel.show();                                           // send the updated pixel colors to the NeoPixel hardware.

    delay(DELAY_INTERVAL);  // pause between each pixel
  }

 // turn pixels to green one by one with delay between each pixel
  for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
    NeoPixel.setPixelColor(pixel, NeoPixel.Color(100/4, 100/4,0));  // it only takes effect if pixels.show() is called
    NeoPixel.show();                                           // send the updated pixel colors to the NeoPixel hardware.

    delay(DELAY_INTERVAL);  // pause between each pixel
  }


//  // turn off all pixels for two seconds
//  NeoPixel.clear();
//  NeoPixel.show();  // send the updated pixel colors to the NeoPixel hardware.
//  delay(100);      // off time
//  // turn on all pixels to red at the same time for two seconds
//  for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
//    NeoPixel.setPixelColor(pixel, NeoPixel.Color(255/4, 1/4, 1/4));  // it only takes effect if pixels.show() is called
//  }
//  NeoPixel.show();  // send the updated pixel colors to the NeoPixel hardware.
//  delay(240);      // on time
//
//  // turn off all pixels for one seconds
//  NeoPixel.clear();
//  NeoPixel.show();  // send the updated pixel colors to the NeoPixel hardware.
//  delay(40);      // off time
}
