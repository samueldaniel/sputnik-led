#include "Arduino.h"
#include <FastLED.h>
#include <color_palette.hpp>
#include <utils.hpp>

extern CRGBPalette16 currentPalette;
extern TBlendType currentBlending;

#define NUM_LEDS 200

CRGB strip_2[NUM_LEDS];
CRGB strip_3[NUM_LEDS];
CRGB strip_4[NUM_LEDS];
CRGB strip_5[NUM_LEDS];
CRGB *strips[4];

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
  strips[0] = strip_2;
  strips[1] = strip_3;
  strips[2] = strip_4;
  strips[3] = strip_5;
}
void loop() {
  // color_palette_loop(strip_2, NUM_LEDS);
  // color_palette_loop(strip_3, NUM_LEDS);
  // color_palette_loop(strip_4, NUM_LEDS);
  // color_palette_loop(strip_5, NUM_LEDS);
  cylon(strips, 4, NUM_LEDS);
}
