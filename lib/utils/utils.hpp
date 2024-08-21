#include <FastLED.h>

int sinc_to_int8(double d);
double deg_to_rad(double deg);
double sinc(double rad);
double sinc_brightness(double deg);
void fade(CRGB *leds, int num_leds);
void rainbow_cylon(CRGB *leds, int num_leds);
void cylon(CRGB **leds, int num_strips, int num_leds);
void black_out(CRGB *leds, int num_leds);
