#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>  // Required for 16 MHz Adafruit Trinket
#endif

#define PIN_NEO_PIXEL 27  // Arduino pin that connects to NeoPixel
#define NUM_PIXELS 8    // The number of LEDs (pixels) on NeoPixel
#define NUM_LEDS 8

#define DELAY_INTERVAL 50  // 250ms pause between each pixel

Adafruit_NeoPixel NeoPixel(NUM_PIXELS, PIN_NEO_PIXEL, NEO_GRB + NEO_KHZ800);

int program_nummber = 0;
long firstPixelHue = 0;

void setup() {
  NeoPixel.begin();
  // put your setup code here, to run once:

  pinMode(25, INPUT_PULLUP);
  Serial.begin(9600);
}

void setPixel(int Pixel, byte red, byte green, byte blue) {
  NeoPixel.setPixelColor(Pixel, NeoPixel.Color(red, green, blue));
}

void Fire(int Cooling, int Sparking, int SpeedDelay) {
  static byte heat[NUM_LEDS];
  int cooldown;

  // Step 1.  Cool down every cell a little
  for ( int i = 0; i < NUM_LEDS; i++) {
    cooldown = random(0, ((Cooling * 10) / NUM_LEDS) + 2);

    if (cooldown > heat[i]) {
      heat[i] = 0;
    } else {
      heat[i] = heat[i] - cooldown;
    }
  }

  // Step 2.  Heat from each cell drifts 'up' and diffuses a little
  for ( int k = NUM_LEDS - 1; k >= 2; k--) {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
  }

  // Step 3.  Randomly ignite new 'sparks' near the bottom
  if ( random(255) < Sparking ) {
    int y = random(7);
    heat[y] = heat[y] + random(160, 255);
    //heat[y] = random(160,255);
  }

  // Step 4.  Convert heat to LED colors
  for ( int j = 0; j < NUM_LEDS; j++) {
    setPixelHeatColor(j, heat[j] );
  }

  NeoPixel.show();
  delay(SpeedDelay);
}

void setPixelHeatColor (int Pixel, byte temperature) {
  // Scale 'heat' down from 0-255 to 0-191
  byte t192 = round((temperature / 255.0) * 191);

  // calculate ramp up from
  byte heatramp = t192 & 0x3F; // 0..63
  heatramp <<= 2; // scale up to 0..252

  // figure out which third of the spectrum we're in:
  if ( t192 > 0x80) {                    // hottest
    setPixel(Pixel, 255, 255, heatramp);
  } else if ( t192 > 0x40 ) {            // middle
    setPixel(Pixel, 255, heatramp, 0);
  } else {                               // coolest
    setPixel(Pixel, heatramp, 0, 0);
  }
}

void rainbow(int wait) {
  for (int i = 0; i < NeoPixel.numPixels(); i++) {
    int pixelHue = firstPixelHue + (i * 65536L / NeoPixel.numPixels());
    NeoPixel.setPixelColor(i, NeoPixel.gamma32(NeoPixel.ColorHSV(pixelHue)));
  }
  NeoPixel.show();
  delay(wait);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(25));
  if (!digitalRead(25)) {
    program_nummber++;
  }
  Serial.println(program_nummber);

  if (program_nummber == 0) {
    for (int i = 0; i < 80; i++) {
      Serial.println(i);
      Fire(55, 120, 15);
    }
  }
  if (program_nummber == 1) {
    NeoPixel.clear();  // set all pixel colors to 'off'. It only takes effect if pixels.show() is called

    // turn pixels to green one by one with delay between each pixel
    for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
      NeoPixel.setPixelColor(pixel, NeoPixel.Color(255, 0, 0));  // it only takes effect if pixels.show() is called
      NeoPixel.show();                                           // send the updated pixel colors to the NeoPixel hardware.

      delay(DELAY_INTERVAL);  // pause between each pixel
    }

    // turn off all pixels for two seconds
    NeoPixel.clear();
    NeoPixel.show();  // send the updated pixel colors to the NeoPixel hardware.
    delay(50);      // off time
    for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
      NeoPixel.setPixelColor(pixel, NeoPixel.Color(0, 255, 0));  // it only takes effect if pixels.show() is called
      NeoPixel.show();                                           // send the updated pixel colors to the NeoPixel hardware.

      delay(DELAY_INTERVAL);  // pause between each pixel
    }

    // turn off all pixels for two seconds
    NeoPixel.clear();
    NeoPixel.show();  // send the updated pixel colors to the NeoPixel hardware.
    delay(50);      // off time
    for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
      NeoPixel.setPixelColor(pixel, NeoPixel.Color(0, 0, 255));  // it only takes effect if pixels.show() is called
      NeoPixel.show();                                           // send the updated pixel colors to the NeoPixel hardware.

      delay(DELAY_INTERVAL);  // pause between each pixel
    }

    // turn off all pixels for two seconds
    NeoPixel.clear();
    NeoPixel.show();  // send the updated pixel colors to the NeoPixel hardware.
    delay(50);      // off time

    for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
      NeoPixel.setPixelColor(pixel, NeoPixel.Color(255, 255, 255)); // it only takes effect if pixels.show() is called
      NeoPixel.show();                                           // send the updated pixel colors to the NeoPixel hardware.
      delay(50);
    }

    // turn off all pixels for two seconds
    NeoPixel.clear();
    NeoPixel.show();  // send the updated pixel colors to the NeoPixel hardware.
    delay(50);      // off time
    for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
      NeoPixel.setPixelColor(pixel, NeoPixel.Color(0, 255, 255));  // it only takes effect if pixels.show() is called
      NeoPixel.show();                                           // send the updated pixel colors to the NeoPixel hardware.
      delay(50);

    }

    // turn off all pixels for two seconds
    NeoPixel.clear();
    NeoPixel.show();  // send the updated pixel colors to the NeoPixel hardware.
    delay(50);      // off time

    for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
      NeoPixel.setPixelColor(pixel, NeoPixel.Color(255, 255, 0));  // it only takes effect if pixels.show() is called
      NeoPixel.show();                                           // send the updated pixel colors to the NeoPixel hardware.
      delay(50);
    }
    //flash light
    // turn off all pixels for two seconds
    NeoPixel.clear();
    NeoPixel.show();  // send the updated pixel colors to the NeoPixel hardware.
    delay(50);      // off time
    // turn on all pixels to red at the same time for two seconds
    for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
      NeoPixel.setPixelColor(pixel, NeoPixel.Color(255, 255, 255)); // it only takes effect if pixels.show() is called
    }
    NeoPixel.show(); //
    delay(50);

    //flash light
    // turn off all pixels for two seconds
    NeoPixel.clear();
    NeoPixel.show();  // send the updated pixel colors to the NeoPixel hardware.
    delay(50);      // off time
    // turn on all pixels to red at the same time for two seconds
    for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
      NeoPixel.setPixelColor(pixel, NeoPixel.Color(255, 255, 255)); // it only takes effect if pixels.show() is called
    }
    NeoPixel.show(); //
    delay(50);

    //flash light
    // turn off all pixels for two seconds
    NeoPixel.clear();
    NeoPixel.show();  // send the updated pixel colors to the NeoPixel hardware.
    delay(50);      // off time
    // turn on all pixels to red at the same time for two seconds
    for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
      NeoPixel.setPixelColor(pixel, NeoPixel.Color(255, 255, 255)); // it only takes effect if pixels.show() is called
    }
    NeoPixel.show(); //
    delay(50);

    //flash light
    // turn off all pixels for two seconds
    NeoPixel.clear();
    NeoPixel.show();  // send the updated pixel colors to the NeoPixel hardware.
    delay(50);      // off time
    // turn on all pixels to red at the same time for two seconds
    for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
      NeoPixel.setPixelColor(pixel, NeoPixel.Color(255, 255, 255)); // it only takes effect if pixels.show() is called
    }
    NeoPixel.show(); //
    delay(50);
    //flash light
    // turn off all pixels for two seconds
    NeoPixel.clear();
    NeoPixel.show();  // send the updated pixel colors to the NeoPixel hardware.
    delay(50);      // off time
    // turn on all pixels to red at the same time for two seconds
    for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
      NeoPixel.setPixelColor(pixel, NeoPixel.Color(255, 255, 255)); // it only takes effect if pixels.show() is called
    }
    NeoPixel.show(); //
    delay(50);

    //flash light
    // turn off all pixels for two seconds
    NeoPixel.clear();
    NeoPixel.show();  // send the updated pixel colors to the NeoPixel hardware.
    delay(50);      // off time
    // turn on all pixels to red at the same time for two seconds
    for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
      NeoPixel.setPixelColor(pixel, NeoPixel.Color(255, 255, 255)); // it only takes effect if pixels.show() is called
    }
    NeoPixel.show(); //
    delay(50);

    //flash light
    // turn off all pixels for two seconds
    NeoPixel.clear();
    NeoPixel.show();  // send the updated pixel colors to the NeoPixel hardware.
    delay(50);      // off time
    // turn on all pixels to red at the same time for two seconds
    for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
      NeoPixel.setPixelColor(pixel, NeoPixel.Color(255, 255, 255)); // it only takes effect if pixels.show() is called
    }
    NeoPixel.show(); //
    delay(50);

    //flash light
    // turn off all pixels for two seconds
    NeoPixel.clear();
    NeoPixel.show();  // send the updated pixel colors to the NeoPixel hardware.
    delay(50);      // off time
    // turn on all pixels to red at the same time for two seconds
    for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
      NeoPixel.setPixelColor(pixel, NeoPixel.Color(255, 255, 255)); // it only takes effect if pixels.show() is called
    }
    NeoPixel.show(); //
    delay(50);
    //flash light
    // turn off all pixels for two seconds
    NeoPixel.clear();
    NeoPixel.show();  // send the updated pixel colors to the NeoPixel hardware.
    delay(50);      // off time
    // turn on all pixels to red at the same time for two seconds
    for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
      NeoPixel.setPixelColor(pixel, NeoPixel.Color(255, 255, 255)); // it only takes effect if pixels.show() is called
    }
    NeoPixel.show(); //
    delay(50);

    //flash light
    // turn off all pixels for two seconds
    NeoPixel.clear();
    NeoPixel.show();  // send the updated pixel colors to the NeoPixel hardware.
    delay(50);      // off time
    // turn on all pixels to red at the same time for two seconds
    for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
      NeoPixel.setPixelColor(pixel, NeoPixel.Color(255, 255, 255)); // it only takes effect if pixels.show() is called
    }
    NeoPixel.show(); //
    delay(50);

    //flash light
    // turn off all pixels for two seconds
    NeoPixel.clear();
    NeoPixel.show();  // send the updated pixel colors to the NeoPixel hardware.
    delay(50);      // off time
    // turn on all pixels to red at the same time for two seconds
    for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
      NeoPixel.setPixelColor(pixel, NeoPixel.Color(255, 255, 255)); // it only takes effect if pixels.show() is called
    }
    NeoPixel.show(); //
    delay(50);

    //flash light
    // turn off all pixels for two seconds
    NeoPixel.clear();
    NeoPixel.show();  // send the updated pixel colors to the NeoPixel hardware.
    delay(50);      // off time
    // turn on all pixels to red at the same time for two seconds
    for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
      NeoPixel.setPixelColor(pixel, NeoPixel.Color(255, 255, 255)); // it only takes effect if pixels.show() is called
    }
    NeoPixel.show(); //
    delay(50);
    //flash light
    // turn off all pixels for two seconds
    NeoPixel.clear();
    NeoPixel.show();  // send the updated pixel colors to the NeoPixel hardware.
    delay(50);      // off time
    // turn on all pixels to red at the same time for two seconds
    for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
      NeoPixel.setPixelColor(pixel, NeoPixel.Color(255, 255, 255)); // it only takes effect if pixels.show() is called
    }
    NeoPixel.show(); //
    delay(50);

    //flash light
    // turn off all pixels for two seconds
    NeoPixel.clear();
    NeoPixel.show();  // send the updated pixel colors to the NeoPixel hardware.
    delay(50);      // off time
    // turn on all pixels to red at the same time for two seconds
    for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
      NeoPixel.setPixelColor(pixel, NeoPixel.Color(255, 255, 255)); // it only takes effect if pixels.show() is called
    }
    NeoPixel.show(); //
    delay(50);

    //flash light
    // turn off all pixels for two seconds
    NeoPixel.clear();
    NeoPixel.show();  // send the updated pixel colors to the NeoPixel hardware.
    delay(50);      // off time
    // turn on all pixels to red at the same time for two seconds
    for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
      NeoPixel.setPixelColor(pixel, NeoPixel.Color(255, 255, 255)); // it only takes effect if pixels.show() is called
    }
    NeoPixel.show(); //
    delay(50);

    //flash light
    // turn off all pixels for two seconds
    NeoPixel.clear();
    NeoPixel.show();  // send the updated pixel colors to the NeoPixel hardware.
    delay(50);      // off time
    // turn on all pixels to red at the same time for two seconds
    for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
      NeoPixel.setPixelColor(pixel, NeoPixel.Color(255, 255, 255)); // it only takes effect if pixels.show() is called
    }
    NeoPixel.show(); //
    delay(50);

  }

  if (program_nummber == 2) {
    for (int i = 0; i < 100; i++) {
      if (firstPixelHue < 5 * 65536) {
        rainbow(10);
        firstPixelHue += 256;
      } else {
        firstPixelHue = 0;
      }
    }

  }
  if (program_nummber == 3) {
    program_nummber = -1;
  }
}
