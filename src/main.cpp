#include "Arduino.h"
#include <FastLED.h>
#include <color_palette.hpp>
#include <pacifica.hpp>
#include <utils.hpp>

#define NUM_LEDS 200
#define NUM_ANTENNAE 4
#define ONE_MIN_IN_MILLIS 60000
#define CHOICES 8

CRGB strip_2[NUM_LEDS];
CRGB strip_3[NUM_LEDS];
CRGB strip_4[NUM_LEDS];
CRGB strip_5[NUM_LEDS];
CRGB *antennae[NUM_ANTENNAE];

unsigned long last_millis;
FUNCTION_POINTER current_pattern;

// from color_palette lib
extern CRGBPalette16 color_palette_palette;
extern TBlendType color_palette_blending;

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
  last_millis = millis();
}
void loop() {
  unsigned long now = millis();
  if (now - last_millis >= ONE_MIN_IN_MILLIS * 5) {
    int choice = random_int() % CHOICES;
    if (0 == choice) {
      color_palette_palette = RainbowColors_p;
      color_palette_blending = LINEARBLEND;
      current_pattern = color_palette_loop;
    }
    if (1 == choice) {
      color_palette_palette = RainbowStripeColors_p;
      color_palette_blending = LINEARBLEND;
      current_pattern = color_palette_loop;
    }
    if (2 == choice) {
      color_palette_setup_random();
      color_palette_blending = LINEARBLEND;
      current_pattern = color_palette_loop;
    }
    if (3 == choice) {
      color_palette_palette = CloudColors_p;
      color_palette_blending = LINEARBLEND;
      current_pattern = color_palette_loop;
    }
    if (4 == choice) {
      color_palette_palette = PartyColors_p;
      color_palette_blending = LINEARBLEND;
      current_pattern = color_palette_loop;
    }
    if (5 == choice) {
      current_pattern = cylon;
    }
    if (6 == choice) {
      current_pattern = rainbow_cylon;
    }
    if (7 == choice) {
      current_pattern = pacifica_loop;
    }
  }
  current_pattern(antennae, 4, NUM_LEDS);
  last_millis = now;
}
