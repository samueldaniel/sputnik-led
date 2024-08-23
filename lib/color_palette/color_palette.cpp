#include "color_palette.hpp"
#include "colorutils.h"

#define UPDATES_PER_SECOND 100

// globals, must be declared as extern in main.cpp to use
// not a great pattern but i needed the *_loop() function signatures to match
CRGBPalette16 color_palette_palette;
TBlendType color_palette_blending;

void color_palette_loop(CRGB **leds, uint8_t num_strips, uint8_t num_leds) {
  static uint8_t startIndex = 0;
  startIndex = startIndex + 1; /* motion speed */

  color_palette_fill(startIndex, leds, num_strips, num_leds);

  FastLED.show();
  FastLED.delay(1000 / UPDATES_PER_SECOND);
}

void color_palette_fill(uint8_t colorIndex, CRGB **leds, uint8_t num_strips,
                        uint8_t num_leds) {
  uint8_t brightness = 255;

  for (int i = 0; i < num_leds; ++i) {
    for (int s = 0; s < num_strips; ++s) {
      leds[s][i] = ColorFromPalette(color_palette_palette, colorIndex,
                                    brightness, color_palette_blending);
    }
    colorIndex += 3;
  }
}

// This function fills the palette with totally random colors.
void color_palette_setup_random() {
  for (int i = 0; i < 16; ++i) {
    color_palette_palette[i] = CHSV(random8(), 255, random8());
  }
}
