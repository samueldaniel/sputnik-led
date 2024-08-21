#include "color_palette.hpp"
#include "colorutils.h"

#define UPDATES_PER_SECOND 100

void color_palette_loop(CRGB **leds, int num_strips, uint8_t num_leds,
                        CRGBPalette16 palette, TBlendType blending) {
  static uint8_t startIndex = 0;
  startIndex = startIndex + 1; /* motion speed */

  color_palette_fill(startIndex, leds, num_strips, num_leds, palette, blending);

  FastLED.show();
  FastLED.delay(1000 / UPDATES_PER_SECOND);
}

void color_palette_fill(uint8_t colorIndex, CRGB **leds, int num_strips,
                        uint8_t num_leds, CRGBPalette16 palette,
                        TBlendType blending) {
  uint8_t brightness = 255;

  for (int i = 0; i < num_leds; ++i) {
    for (int s = 0; s < num_strips; ++s) {
      leds[s][i] = ColorFromPalette(palette, colorIndex, brightness, blending);
    }
    colorIndex += 3;
  }
}

// This function fills the palette with totally random colors.
void color_palette_setup_random(CRGBPalette16 palette) {
  for (int i = 0; i < 16; ++i) {
    palette[i] = CHSV(random8(), 255, random8());
  }
}
