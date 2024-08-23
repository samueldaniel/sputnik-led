#include "Arduino.h"
#include <FastLED.h>

#include <color_palette.hpp>
#include <pacifica.hpp>
#include <utils.hpp>

#define NUM_LEDS 200
#define NUM_ANTENNAE 4
#define ONE_MIN_IN_MILLIS 60000
#define CHOICES 9
#define PATTERN_CYCLE_TIME (ONE_MIN_IN_MILLIS * 1)

CRGB strip_2[NUM_LEDS];
CRGB strip_3[NUM_LEDS];
CRGB strip_4[NUM_LEDS];
CRGB strip_5[NUM_LEDS];
CRGB *antennae[NUM_ANTENNAE];

unsigned long last_millis;
void (*current_loop)(CRGB **, uint8_t, uint8_t);
int current_choice;

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

  // init a pattern for the first five mins
  color_palette_palette = RainbowColors_p;
  color_palette_blending = LINEARBLEND;
  current_loop = color_palette_loop;
  current_choice = 0;
}
void loop() {
  unsigned long now = millis();
  if (now - last_millis >= PATTERN_CYCLE_TIME) {
    // int choice = random(0, CHOICES + 1);
    int choice = current_choice;
    if (0 == choice) {
      color_palette_palette = RainbowColors_p;
      color_palette_blending = LINEARBLEND;
      current_loop = color_palette_loop;
    }
    if (1 == choice) {
      color_palette_palette = RainbowStripeColors_p;
      color_palette_blending = LINEARBLEND;
      current_loop = color_palette_loop;
    }
    if (2 == choice) {
      color_palette_setup_random();
      color_palette_blending = LINEARBLEND;
      current_loop = color_palette_loop;
    }
    if (3 == choice) {
      color_palette_palette = CloudColors_p;
      color_palette_blending = LINEARBLEND;
      current_loop = color_palette_loop;
    }
    if (4 == choice) {
      color_palette_palette = PartyColors_p;
      color_palette_blending = LINEARBLEND;
      current_loop = color_palette_loop;
    }
    if (5 == choice) {
      current_loop = cylon_loop;
    }
    if (6 == choice) {
      current_loop = rainbow_cylon_loop;
    }
    if (7 == choice) {
      current_loop = pacifica_loop;
    }
    if (8 == choice) {
      current_loop = sinc_loop;
    }
    current_choice = (current_choice + 1) % CHOICES;
  }
  current_loop(antennae, NUM_ANTENNAE, NUM_LEDS);
  last_millis = now;
}
