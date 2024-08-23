#include <FastLED.h>

uint8_t sinc_to_int8(double d);
double deg_to_rad(double deg);
double sinc(double rad);
uint8_t sinc_brightness(double deg);
void fade(CRGB *leds, uint8_t num_leds);
void black_out(CRGB *leds, uint8_t num_leds);

void rainbow_cylon_loop(CRGB **leds, uint8_t num_strips, uint8_t num_leds);
void cylon_loop(CRGB **leds, uint8_t num_strips, uint8_t num_leds);
void sinc_loop(CRGB **leds, uint8_t num_strips, uint8_t num_leds);
