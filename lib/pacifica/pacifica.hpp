#include <FastLED.h>

void pacifica_loop(CRGB **leds, uint8_t num_strips, uint8_t num_leds);
void pacifica_one_layer(CRGB **leds, uint8_t num_strips, uint8_t num_leds,
                        const CRGBPalette16 &p, uint16_t cistart,
                        uint16_t wavescale, uint8_t bri, uint16_t ioff);
void pacifica_add_whitecaps(CRGB **leds, uint8_t num_strips, uint8_t num_leds);
void pacifica_deepen_colors(CRGB **leds, uint8_t num_strips, uint8_t num_leds);
