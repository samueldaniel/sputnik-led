#include "color_palette.hpp"

#define UPDATES_PER_SECOND 100

extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;

CRGBPalette16 currentPalette;
TBlendType currentBlending;

void color_palette_loop(CRGB *leds, uint8_t num_leds) {
  // color_palette_periodic_change();

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

  static uint8_t startIndex = 0;
  startIndex = startIndex + 1; /* motion speed */

  color_palette_fill(startIndex, leds, num_leds);

  FastLED.show();
  FastLED.delay(1000 / UPDATES_PER_SECOND);
}

void color_palette_fill(uint8_t colorIndex, CRGB *leds, uint8_t num_leds) {
  uint8_t brightness = 255;

  for (int i = 0; i < num_leds; ++i) {
    leds[i] = ColorFromPalette(currentPalette, colorIndex, brightness,
                               currentBlending);
    colorIndex += 3;
  }
}

// This function fills the palette with totally random colors.
void color_palette_setup_random() {
  for (int i = 0; i < 16; ++i) {
    currentPalette[i] = CHSV(random8(), 255, random8());
  }
}
