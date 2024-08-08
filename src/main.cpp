#include "Arduino.h"
#include <FastLED.h>
#define NUM_LEDS 200
CRGB strip_2[NUM_LEDS];
CRGB strip_3[NUM_LEDS];
CRGB strip_4[NUM_LEDS];
CRGB strip_5[NUM_LEDS];
CRGB strip_6[NUM_LEDS];
CRGB strip_7[NUM_LEDS];
CRGB strip_8[NUM_LEDS];
CRGB strip_9[NUM_LEDS];

int sinc_to_int8(double d) { return min(255, (int)(d * (double)256)); }
double deg_to_rad(double deg) { return deg * DEG_TO_RAD; }
double sinc(double rad) { return sin(rad) / rad; }

void setup() {
  FastLED.addLeds<WS2811, 2>(strip_2, NUM_LEDS);
  FastLED.addLeds<WS2811, 3>(strip_3, NUM_LEDS);
  FastLED.addLeds<WS2811, 4>(strip_4, NUM_LEDS);
  FastLED.addLeds<WS2811, 5>(strip_5, NUM_LEDS);
  FastLED.addLeds<WS2811, 6>(strip_6, NUM_LEDS);
  FastLED.addLeds<WS2811, 7>(strip_7, NUM_LEDS);
  FastLED.addLeds<WS2811, 8>(strip_8, NUM_LEDS);
  FastLED.addLeds<WS2811, 9>(strip_9, NUM_LEDS);
}
void loop() {
  for (int i = 0; i < 360; ++i) {
    for (int j = 0; j < NUM_LEDS; ++j) {
      strip_2[j] = CRGB::DarkRed;
      strip_3[j] = CRGB::DarkRed;
      strip_4[j] = CRGB::DarkRed;
      strip_5[j] = CRGB::DarkRed;
      strip_6[j] = CRGB::DarkRed;
      strip_7[j] = CRGB::DarkRed;
      strip_8[j] = CRGB::DarkRed;
      strip_9[j] = CRGB::DarkRed;
    }
    int brightness = abs(sinc_to_int8(sinc(deg_to_rad(i)))) * 10;
    FastLED.show(brightness);
    delay(50);
  }
  // for (int i = 0; i < NUM_LEDS; ++i) {
  //   strip_2[i] = CRGB::DarkRed;
  //   strip_3[i] = CRGB::DarkRed;
  //   strip_4[i] = CRGB::DarkRed;
  //   strip_5[i] = CRGB::DarkRed;
  //   strip_6[i] = CRGB::DarkRed;
  //   strip_7[i] = CRGB::DarkRed;
  //   strip_8[i] = CRGB::DarkRed;
  //   strip_9[i] = CRGB::DarkRed;
  // }

  // FastLED.show();
  // delay(1000);
  // for (int i = 0; i < NUM_LEDS; ++i) {
  //   strip_2[i] = CRGB::DarkGreen;
  //   strip_3[i] = CRGB::DarkGreen;
  //   strip_4[i] = CRGB::DarkGreen;
  //   strip_5[i] = CRGB::DarkGreen;
  //   strip_6[i] = CRGB::DarkGreen;
  //   strip_7[i] = CRGB::DarkGreen;
  //   strip_8[i] = CRGB::DarkGreen;
  //   strip_9[i] = CRGB::DarkGreen;
  // }
  // FastLED.show();
  // delay(1000);
  // for (int i = 0; i < NUM_LEDS; ++i) {
  //   strip_2[i] = CRGB::DarkBlue;
  //   strip_3[i] = CRGB::DarkBlue;
  //   strip_4[i] = CRGB::DarkBlue;
  //   strip_5[i] = CRGB::DarkBlue;
  //   strip_6[i] = CRGB::DarkBlue;
  //   strip_7[i] = CRGB::DarkBlue;
  //   strip_8[i] = CRGB::DarkBlue;
  //   strip_9[i] = CRGB::DarkBlue;
  // }
  // FastLED.show();
  // delay(1000);
  // for (int i = 0; i < NUM_LEDS; ++i) {
  //   strip_2[i] = CRGB::White;
  //   strip_3[i] = CRGB::White;
  //   strip_4[i] = CRGB::White;
  //   strip_5[i] = CRGB::White;
  //   strip_6[i] = CRGB::White;
  //   strip_7[i] = CRGB::White;
  //   strip_8[i] = CRGB::White;
  //   strip_9[i] = CRGB::White;
  // }
  // FastLED.show();
  // delay(1000);
}
