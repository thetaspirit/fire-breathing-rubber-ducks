#include <Arduino.h>

#include <FastLED.h>
#include <stdint.h>

#define TEST_LED 6

#define LED_STRIPE_1   7
#define LED_STRIPE_2   8
#define LED_STRIPE_3   9
#define LED_STRIPE_4   10
#define LED_STRIPE_5   11
#define LED_STRIPE_6   12
#define LED_STRIPE_7   15


// #define NUM_LEDS    343
#define NUM_LEDS    60
#define BRIGHTNESS  50
#define LED_TYPE    WS2813
#define COLOR_ORDER GRB

typedef enum{
  Red=0xFF0000,                   ///< @htmlcolorblock{FF0000}
  Orange=0xFFA500,                ///< @htmlcolorblock{FFA500}
  Yellow=0xFFFF00,                ///< @htmlcolorblock{FFFF00}
  Green=0x008000,                 ///< @htmlcolorblock{008000}
  Cyan=0x00FFFF,                  ///< @htmlcolorblock{00FFFF}
  Blue=0x0000FF,                  ///< @htmlcolorblock{0000FF}
  Purple=0x800080,                ///< @htmlcolorblock{800080}
  Brown=0xA52A2A,                 ///< @htmlcolorblock{A52A2A}
  Black=0x000000
}Color;

// leds = the array of leds, stores the colour data for each of the leds
CRGB leds_1[NUM_LEDS];
CRGB leds_2[NUM_LEDS];
CRGB leds_3[NUM_LEDS];
CRGB leds_4[NUM_LEDS];
CRGB leds_5[NUM_LEDS];
CRGB leds_6[NUM_LEDS];
CRGB leds_7[NUM_LEDS];

// void wait_for_serial_connection() {
//   uint32_t timeout_end = millis() + 2000;
//   Serial.begin(115200);
//   while(!Serial && timeout_end > millis()) {}  //wait until the connection to the PC is established
// }

void setup() {
  // wait_for_serial_connection(); // Optional, but seems to help Teensy out a lot.
  FastLED.addLeds<LED_TYPE, LED_STRIPE_1, COLOR_ORDER>(leds_1, NUM_LEDS).setCorrection(TypicalLEDStrip); // "register" the leds
  FastLED.addLeds<LED_TYPE, LED_STRIPE_2, COLOR_ORDER>(leds_2, NUM_LEDS).setCorrection(TypicalLEDStrip); // "register" the leds
  FastLED.addLeds<LED_TYPE, LED_STRIPE_3, COLOR_ORDER>(leds_3, NUM_LEDS).setCorrection(TypicalLEDStrip); // "register" the leds
  FastLED.addLeds<LED_TYPE, LED_STRIPE_4, COLOR_ORDER>(leds_4, NUM_LEDS).setCorrection(TypicalLEDStrip); // "register" the leds
  FastLED.addLeds<LED_TYPE, LED_STRIPE_5, COLOR_ORDER>(leds_5, NUM_LEDS).setCorrection(TypicalLEDStrip); // "register" the leds
  FastLED.addLeds<LED_TYPE, LED_STRIPE_6, COLOR_ORDER>(leds_6, NUM_LEDS).setCorrection(TypicalLEDStrip); // "register" the leds
  FastLED.addLeds<LED_TYPE, LED_STRIPE_7, COLOR_ORDER>(leds_7, NUM_LEDS).setCorrection(TypicalLEDStrip); // "register" the leds

  FastLED.setBrightness(BRIGHTNESS); // 0-255
}

// Lights up every single LED, one at a time, in sequential order
void runSequentialTestPattern(Color color) {
  for (int light = 0; i < NUM_LEDS; i++) {
    leds_1[light] = color;
    FastLED.show();
    delay(100);
    leds_1[i] = Black;
  }

  for (int light = 0; i < NUM_LEDS; i++) {
    leds_2[light] = color;
    FastLED.show();
    delay(100);
    leds_2[i] = Black;
  }

  for (int light = 0; i < NUM_LEDS; i++) {
    leds_3[light] = color;
    FastLED.show();
    delay(100);
    leds_3[i] = Black;
  }

  for (int light = 0; i < NUM_LEDS; i++) {
    leds_4[light] = color;
    FastLED.show();
    delay(100);
    leds_4[i] = Black;
  }

  for (int light = 0; i < NUM_LEDS; i++) {
    leds_5[light] = color;
    FastLED.show();
    delay(100);
    leds_5[i] = Black;
  }

  for (int light = 0; i < NUM_LEDS; i++) {
    leds_6[light] = color;
    FastLED.show();
    delay(100);
    leds_6[i] = Black;
  }

  for (int light = 0; i < NUM_LEDS; i++) {
    leds_7[light] = color;
    FastLED.show();
    delay(100);
    leds_7[i] = Black;
  }
  FastLED.show();
}

// moving red along the strip
// void testPattern() {
//   for(int i = 0; i < NUM_LEDS; i++){
//     leds[i] = CRGB::Red;
//     FastLED.show();
//     delay(100);
//     leds[i] = CRGB::Black;
//   }
//   for(int i = NUM_LEDS - 1; i >= 0; i--){
//     leds[i] = CRGB::Red;
//     FastLED.show();
//     delay(100);
//     leds[i] = CRGB::Black;
//   }
// }

// void fillRGB(){
  // can also use fill gradient or fill rainbow instead
//   fill_solid(leds, NUM_LEDS,CRGB::Red);
//   FastLED.show();
//   delay(500);

//   fill_solid(leds, NUM_LEDS,CRGB::Green);
//   FastLED.show();
//   delay(500);

//   fill_solid(leds, NUM_LEDS,CRGB::Blue);
//   FastLED.show();
//   delay(500);
// }

// inclusive!
// void fillColor(int left, int right, int size, Color color, CRGB ledArray[]){
//   for (int i = left; i <= right; i += size){
//     ledArray[i] = color;
//   }
// }
// void fillAllColor(Color color, CRGB ledArray[]){
//   for (int i = 0; i <= NUM_LEDS; i += 1){
//     ledArray[i] = color;
//   }
// }

// void treePattern(){
//   fillColor(5, 6, 1, Green);
//   fillColor(24, 26, 1, Green);
//   fillColor(43, 47, 1, Green);
//   fillColor(62, 67, 1, Green);
//   fillColor(81, 88, 1, Green);
//   fillColor(100, 108, 1, Green);
//   fillColor(119, 129, 1, Green);
//   fillColor(138, 149, 1, Green);
//   fillColor(157, 170, 1, Green);
//   fillColor(176, 190, 1, Green);
//   fillColor(195, 208, 1, Green);
//   fillColor(214, 225, 1, Green);
//   fillColor(233, 243, 1, Green);
//   fillColor(252, 260, 1, Green);
//   fillColor(271, 278, 1, Green);
//   fillColor(290, 295, 1, Green);
//   fillColor(309, 313, 1, Green);
//   fillColor(328, 330, 1, Green);
//   fillColor(347, 348, 1, Green);

//   fillColor(153, 156, 1, Brown);
//   fillColor(172, 175, 1, Brown);
//   fillColor(191, 194, 1, Brown);

//   FastLED.show();
// }


void loop() {
  runSequentialTestPattern(Red);
  runSequentialTestPattern(Orange);
  runSequentialTestPattern(Yellow);
  runSequentialTestPattern(Green);
  runSequentialTestPattern(Cyan);
  runSequentialTestPattern(Blue);
  runSequentialTestPattern(Purple);
  runSequentialTestPattern(Brown);
}