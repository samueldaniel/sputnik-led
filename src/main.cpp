#include "Arduino.h"
#include <FastLED.h>
#include <color_palette.hpp>
#include <pacifica.hpp>
#include <utils.hpp>

extern CRGBPalette16 currentPalette;
extern TBlendType currentBlending;

#define NUM_LEDS 200
#define NUM_ANTENNAE 4

CRGB strip_2[NUM_LEDS];
CRGB strip_3[NUM_LEDS];
CRGB strip_4[NUM_LEDS];
CRGB strip_5[NUM_LEDS];
CRGB *antennae[NUM_ANTENNAE];

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
  antennae[0] = strip_2;
  antennae[1] = strip_3;
  antennae[2] = strip_4;
  antennae[3] = strip_5;
}
void loop() {
  // color_palette_periodic_change();

  CRGBPalette16 currentPalette;
  TBlendType currentBlending;

  currentPalette = RainbowColors_p;
  currentBlending = LINEARBLEND;

  // currentPalette = RainbowStripeColors_p;
  // currentBlending = NOBLEND;

  // currentPalette = RainbowStripeColors_p;
  // currentBlending = LINEARBLEND;

  // color_palette_setup_random();
  // currentBlending = LINEARBLEND;

  // currentPalette = CloudColors_p;
  // currentBlending = LINEARBLEND;

  // currentPalette = PartyColors_p;
  // currentBlending = LINEARBLEND;

  color_palette_loop(antennae, NUM_ANTENNAE, NUM_LEDS, currentPalette,
                     currentBlending);
  // cylon(antennae, 4, NUM_LEDS);
  // pacifica_loop(antennae, NUM_ANTENNAE, NUM_LEDS);
}
