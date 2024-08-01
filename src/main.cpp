#include <FastLED.h>
#define NUM_LEDS 200
CRGB leds[NUM_LEDS];

void setup() { FastLED.addLeds<WS2811, 13>(leds, NUM_LEDS); }
void loop() {
  for (int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = CRGB::DarkRed;
  }
  FastLED.show();
  delay(1000);
  for (int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = CRGB::DarkGreen;
  }
  FastLED.show();
  delay(1000);
  for (int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = CRGB::DarkBlue;
  }
  FastLED.show();
  delay(1000);
}
