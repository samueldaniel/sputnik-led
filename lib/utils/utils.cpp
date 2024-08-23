#include "utils.hpp"

int sinc_to_int8(double d) { return min(255, (int)(d * (double)256)); }
double deg_to_rad(double deg) { return deg * DEG_TO_RAD; }
double sinc(double rad) { return sin(rad) / rad; }
int sinc_brightness(double deg) {
  return round_to_int(abs(sinc_to_int8(sinc(deg_to_rad(deg)))) * 10);
}
void sinc_loop(CRGB **leds, int num_strips, int num_leds) {
  CHSV random_color = CHSV(random8(), 255, random8());
  for (int i = 0; i < num_leds; i++) {
    for (int s = 0; s < num_strips; s++) {
      leds[s][i] = random_color;
    }
  }
  for (int degs = 1; degs < 361; degs++) {
    int brightness = sinc_brightness(degs);
    FastLED.show(brightness);
    delay(50);
  }
}

void fade(CRGB *leds, int num_leds) {
  for (int i = 0; i < num_leds; i++) {
    leds[i].nscale8(250);
  }
}
void rainbow_cylon_loop(CRGB **leds, int num_strips, int num_leds) {
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
void cylon_loop(CRGB **leds, int num_strips, int num_leds) {
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
