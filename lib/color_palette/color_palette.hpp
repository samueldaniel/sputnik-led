#include <FastLED.h>

void color_palette_loop(CRGB **leds, int num_strips, uint8_t num_leds,
                        CRGBPalette16 palette, TBlendType blending);
void color_palette_fill(uint8_t colorIndex, CRGB **leds, int num_strips,
                        uint8_t num_leds, CRGBPalette16 palette,
                        TBlendType blending);
void color_palette_setup_random(CRGBPalette16 palette);
