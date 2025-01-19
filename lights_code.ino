// Lights control code

#include <FastLED.h>
#include <Servo.h>
#include <Arduino.h>



// Properties
#define NUM_STRIPS 14
#define NUM_TWOSTRIPS 7
#define NUM_ANGLES 12
#define NUM_LEDS_ONESTRIP 30
#define NUM_LEDS_TWOSTRIP 60
#define BRIGHTNESS  25
#define LED_TYPE    WS2813
#define COLOR_ORDER GRB



// LEDS //

// wiring order:
// where 0 is innermost radius; connections from left to right start at 2ndouter
// pin0: 12 up, 10 down
// pin1: 8 up, 6 down
// pin2: 4 up, 2 down
// pin3: 0 up, 1 down
// pin4: 3 up, 5 down
// pin5: 7 up, 9 down
// pin6: 11 up, 13 down
// stored as below:
int wiring_matrix[NUM_TWOSTRIPS][2] = {
  {12, 10},
  {8, 6},
  {4, 2},
  {0, 1},
  {3, 5},
  {7, 9},
  {11, 13}
}

//TODO: populate with gpio according to above convention
// maps fastled led strips to gpio pins
int gpio_matrix[NUM_TWOSTRIPS] = {};


// Address conversion matrix: used to convert from pin polar coords to actual data
// addr_matrix[radial_posn] = {gpio_pin, is_second_strip} 
// (s.t. pin address on strip = abs(is_second_strip*59-z_value))
// TODO fill out according to wiring
int addr_matrix[NUM_STRIPS][2] = 

// Vals matrix: stores RGB values for polar coords
// 1st index is radius, 2nd index is z value, 3rd index is angle
CRGB vals_matrix[NUM_STRIPS][NUM_LEDS_ONESTRIP][NUM_ANGLES] = {0};

// LEDS matrix: actual led matrix used by FastLED library to write
CRGB leds[NUM_TWOSTRIPS][NUM_LEDS_TWOSTRIP];



// SPEED/FREQUENCY //
int curr_angle = 0;
int curr_frequency = 0;
int is_hall_efft = 0;



void setup() {
  // initialise all LED strips
  for (int i = 0; i < NUM_TWOSTRIPS; i++){
    FastLED.addLeds<LED_TYPE, gpio_matrix[i], COLOR_ORDER>(leds[i], NUM_LEDS_TWOSTRIP).setCorrection(TypicalLEDStrip);
  }

  // fill out vals_matrix from image 
}


void loop() {
  // update frequency from hall effect sensor
  if (is_hall_efft){
    //update angle
    curr_angle = 0;
    //update frequency
  }

  // update angle based on timestamp
  curr_angle += (1/curr_frequency)*360* //(1/change in time from last is_hall_efft);

  // update vals_matrix depending on image being shown - only if want some button for changing image

  // update leds matrix from vals_matrix based on current angle 
  for 

  // write to LED strips
  //FastLED.show();
  
}
