#include "Arduino.h"
#include <FastLED.h>
#include <color_palette.hpp>
#define NUM_LEDS 200
CRGB strip_2[NUM_LEDS];
CRGB strip_3[NUM_LEDS];
CRGB strip_4[NUM_LEDS];
CRGB strip_5[NUM_LEDS];
CRGB strip_6[NUM_LEDS];
CRGB strip_7[NUM_LEDS];
CRGB strip_8[NUM_LEDS];
CRGB strip_9[NUM_LEDS];

int sinc_to_int8(double d) { return min(255, (int)(d * (double)256)); }
double deg_to_rad(double deg) { return deg * DEG_TO_RAD; }
double sinc(double rad) { return sin(rad) / rad; }
double sinc_brightness(double deg) {
  return abs(sinc_to_int8(sinc(deg_to_rad(deg)))) * 10;
}

void fadeall() {
  for (int i = 0; i < NUM_LEDS; i++) {
    strip_2[i].nscale8(250);
  }
}
void rainbow_cylon() {
  static uint8_t hue = 0;
  // First slide the led in one direction
  for (int i = 0; i < NUM_LEDS; i++) {
    // Set the i'th led to red
    strip_2[i] = CHSV(hue++, 255, 255);
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    fadeall();
    // Wait a little bit before we loop around and do it again
    delay(10);
  }

  // Now go in the other direction.
  for (int i = (NUM_LEDS)-1; i >= 0; i--) {
    // Set the i'th led to red
    strip_2[i] = CHSV(hue++, 255, 255);
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    fadeall();
    // Wait a little bit before we loop around and do it again
    delay(10);
  }
}

void setup() {
  delay(3000); // power-up safety delay
  color_palette_setup(strip_2, NUM_LEDS);
  // FastLED.addLeds<WS2811, 2>(strip_2, NUM_LEDS);
  // FastLED.addLeds<WS2811, 3>(strip_3, NUM_LEDS);
  // FastLED.addLeds<WS2811, 4>(strip_4, NUM_LEDS);
  // FastLED.addLeds<WS2811, 5>(strip_5, NUM_LEDS);
  // FastLED.addLeds<WS2811, 6>(strip_6, NUM_LEDS);
  // FastLED.addLeds<WS2811, 7>(strip_7, NUM_LEDS);
  // FastLED.addLeds<WS2811, 8>(strip_8, NUM_LEDS);
  // FastLED.addLeds<WS2811, 9>(strip_9, NUM_LEDS);
}
// void loop() { rainbow_cylon(); }
void loop() { color_palette_loop(strip_2, NUM_LEDS); }
