#include <FastLED.h>

int sinc_to_int8(double d);
double deg_to_rad(double deg);
double sinc(double rad);
int sinc_brightness(double deg);
void sinc_loop(CRGB **leds, int num_strips, int num_leds);
void fade(CRGB *leds, int num_leds);
void rainbow_cylon_loop(CRGB **leds, int num_strips, int num_leds);
void cylon_loop(CRGB **leds, int num_strips, int num_leds);
void black_out(CRGB *leds, int num_leds);
