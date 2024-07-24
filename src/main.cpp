#include <FastLED.h>
#define NUM_LEDS 200
#define LEDS_PER_RING 1
#define NUM_RINGS (NUM_LEDS / LEDS_PER_RING)
CRGB antennae[200];

class Ring {
public:
  Ring(const struct CRGB *antennae, int pixels_per_antennae, int offset,
       int pixels_per_ring){

  };
};
CLEDController *controllers[200];
void setup() {
  // FastLED.addLeds<WS2811, 13>(antennae, NUM_LEDS);
  for (int i = 0; i < 200; i++) {
    controllers[i] = &FastLED.addLeds<WS2811, 13>(antennae, i, 1);
  }
}
void loop() {
  for (int i = 0; i < 200; i++) {
    controllers[i]->showColor(CRGB(CRGB::Black));
    controllers[i]->showLeds(255);
  }
  for (int i = 0; i < 200; i++) {
    controllers[i]->showColor(CRGB(CRGB::DarkRed));
    controllers[i]->showLeds(255);
    controllers[i]->leds()->nscale8(250);
    delay(10);
  }
  for (int i = 200 - 1; i >= 0; i--) {
    controllers[i]->showColor(CRGB(CRGB::DarkRed));
    controllers[i]->showLeds(255);
    controllers[i]->leds()->nscale8(250);
    delay(10);
  }
  // for (int i = 0; i < NUM_LEDS; i++) {
  //   antennae[i] = CRGB::Black;
  //   FastLED.show();
  // }
  // for (int i = 0; i < NUM_RINGS; i++) {
  //   CRGB *leds = controllers[i]->leds();
  //   *leds = CRGB::Black;
  //   controllers[i]->showLeds();
  // }
  // for (int i = 0; i < NUM_RINGS; i++) {
  //   CRGB *leds = controllers[i]->leds();
  //   *leds = CRGB::DarkRed;
  //   controllers[i]->showLeds();
  //   leds->nscale8(250);
  //   delay(10);
  // }
  // for (int i = NUM_RINGS - 1; i >= 0; i--) {
  //   CRGB *leds = controllers[i]->leds();
  //   *leds = CRGB::DarkRed;
  //   controllers[i]->showLeds();
  //   leds->nscale8(250);
  //   delay(10);
  // }
  //  for (int i = 0; i < NUM_LEDS; ++i) {
  //    leds[i] = CRGB::DarkRed;
  //  }
  //  FastLED.show();
  //  delay(1000);
  //  for (int i = 0; i < NUM_LEDS; ++i) {
  //    leds[i] = CRGB::DarkGreen;
  //  }
  //  FastLED.show();
  //  delay(1000);
  //  for (int i = 0; i < NUM_LEDS; ++i) {
  //    leds[i] = CRGB::DarkBlue;
  //  }
  //  FastLED.show();
  //  delay(1000);
}
