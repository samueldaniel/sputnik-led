#include "Arduino.h"
#include <FastLED.h>
#include <color_palette.hpp>
extern CRGBPalette16 currentPalette;
extern TBlendType currentBlending;

#define NUM_LEDS 200

CRGB strip_2[NUM_LEDS];
CRGB strip_3[NUM_LEDS];
CRGB strip_4[NUM_LEDS];
CRGB strip_5[NUM_LEDS];

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

void black_out(CRGB *leds, int num_leds) {
  for (int i = 0; i < num_leds; ++i) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
}

void setup() {
  delay(3000); // power-up safety delay
  FastLED.addLeds<WS2811, 2, RGB>(strip_2, NUM_LEDS);
  FastLED.addLeds<WS2811, 3, RGB>(strip_3, NUM_LEDS);
  FastLED.addLeds<WS2811, 4, RGB>(strip_4, NUM_LEDS);
  FastLED.addLeds<WS2811, 5, RGB>(strip_5, NUM_LEDS);
  black_out(strip_2, NUM_LEDS);
  black_out(strip_3, NUM_LEDS);
  black_out(strip_4, NUM_LEDS);
  black_out(strip_5, NUM_LEDS);
}
void loop() {
  color_palette_loop(strip_2, NUM_LEDS);
  color_palette_loop(strip_3, NUM_LEDS);
  color_palette_loop(strip_4, NUM_LEDS);
  color_palette_loop(strip_5, NUM_LEDS);
}
