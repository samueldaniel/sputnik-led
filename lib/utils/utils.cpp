#include "utils.hpp"

int sinc_to_int8(double d) { return min(255, (int)(d * (double)256)); }
double deg_to_rad(double deg) { return deg * DEG_TO_RAD; }
double sinc(double rad) { return sin(rad) / rad; }
double sinc_brightness(double deg) {
  return abs(sinc_to_int8(sinc(deg_to_rad(deg)))) * 10;
}
void fade(CRGB *leds, int num_leds) {
  for (int i = 0; i < num_leds; i++) {
    leds[i].nscale8(250);
  }
}
void rainbow_cylon(CRGB **leds, int num_strips, int num_leds) {
  static uint8_t hue = 0;
  // First slide the led in one direction
  for (int i = 0; i < num_leds; i++) {
    // Set the i'th led to red
    for (int s = 0; s < num_strips; s++) {
      leds[s][i] = CHSV(hue++, 255, 255);
    }
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    for (int s = 0; s < num_strips; s++) {
      fade(leds[s], num_leds);
    }
    // Wait a little bit before we loop around and do it again
    delay(10);
  }

  // Now go in the other direction.
  for (int i = (num_leds)-1; i >= 0; i--) {
    for (int s = 0; s < num_strips; s++) {
      // Set the i'th led to red
      leds[s][i] = CHSV(hue++, 255, 255);
    }
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    for (int s = 0; s < num_strips; s++) {
      fade(leds[s], num_leds);
    }
    // Wait a little bit before we loop around and do it again
    delay(10);
  }
}
void cylon(CRGB **leds, int num_strips, int num_leds) {
  for (int i = 0; i < num_leds; i++) {
    // First slide the led in one direction
    for (int s = 0; s < num_strips; s++) {
      // Set the i'th led to red
      leds[s][i] = CRGB::Red;
    }
    // Show the leds
    FastLED.show();
    for (int s = 0; s < num_strips; s++) {
      // now that we've shown the leds, reset the i'th led to black
      // leds[i] = CRGB::Black;
      fade(leds[s], num_leds);
    }
    // Wait a little bit before we loop around and do it again
    delay(10);
  }
  // Now go in the other direction.
  for (int i = (num_leds)-1; i >= 0; i--) {
    for (int s = 0; s < num_strips; s++) {
      // Set the i'th led to red
      leds[s][i] = CRGB::Red;
    }
    // Show the leds
    FastLED.show();
    for (int s = 0; s < num_strips; s++) {
      // now that we've shown the leds, reset the i'th led to black
      // leds[i] = CRGB::Black;
      fade(leds[s], num_leds);
    }
    // Wait a little bit before we loop around and do it again
    delay(10);
  }
}
void black_out(CRGB *leds, int num_leds) {
  for (int i = 0; i < num_leds; ++i) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
}
