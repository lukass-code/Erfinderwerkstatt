#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>  // Required for 16 MHz Adafruit Trinket
#endif

#define PIN_NEO_PIXEL 27  // Arduino pin that connects to NeoPixel
#define NUM_PIXELS 8    // The number of LEDs (pixels) on NeoPixel

#define DELAY_INTERVAL 60  // 250ms pause between each pixel

Adafruit_NeoPixel NeoPixel(NUM_PIXELS, PIN_NEO_PIXEL, NEO_GRB + NEO_KHZ800);

void setup() {
  NeoPixel.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop(){
for (int pixel =0; pixel < NUM_PIXELS; pixel++) { // for each pixel
  int colors_hsv = pixel * (65535 / (NUM_PIXELS));
  NeoPixel.setPixelColor(pixel, NeoPixel.ColorHSV(colors_hsv, 255, 100));
  NeoPixel.show();
  delay(DELAY_INTERVAL);
}
for (int pixel =0; pixel < NUM_PIXELS; pixel++) { // for each pixel
  int colors_hsv = pixel * (65535 / (NUM_PIXELS));
  NeoPixel.setPixelColor(pixel, NeoPixel.Color(0,0,0));
  NeoPixel.show();
  delay(DELAY_INTERVAL);
}
}
