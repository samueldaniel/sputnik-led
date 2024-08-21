#include <FastLED.h>

void pacifica_loop(CRGB **leds, int num_strips, int num_leds);
void pacifica_one_layer(CRGB **leds, int num_strips, int num_leds,
                        const CRGBPalette16 &p, uint16_t cistart,
                        uint16_t wavescale, uint8_t bri, uint16_t ioff);
void pacifica_add_whitecaps(CRGB **leds, int num_strips, int num_leds);
void pacifica_deepen_colors(CRGB **leds, int num_strips, int num_leds);
