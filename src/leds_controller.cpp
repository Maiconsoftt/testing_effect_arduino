#include <LedControl.h>
#include <Arduino.h>
#include "tasks.hpp"
#include "experiment_configuration.hpp"
#include "leds_controller.hpp"
#include "constants.hpp"

//lc1 = left arm, lc2 = central arm, lc3 = right arm
LedControl lc1 = LedControl(7, 5, 6, 1); // define matrix DIN, CLK, CS pins and the number of devices, respectively
LedControl lc2 = LedControl(10, 8, 9, 1);
LedControl lc3 = LedControl(13, 11, 12, 1);

void led_and_controllers_setup () {

  lc1.clearDisplay(0); lc2.clearDisplay(0); lc3.clearDisplay(0);
  lc1.shutdown(0, false); lc2.shutdown(0, false); lc3.shutdown(0, false);
  lc1.setIntensity(0, 1); lc2.setIntensity(0, 1); lc3.setIntensity(0, 1);

  pinMode(A0, OUTPUT); //set buzzer pin as output
  pinMode(4, OUTPUT);
}

LedControl get_led_array_by_gate_name(int gate_name){
  if (gate_name == 1){
   return lc1;
  }  
  else if (gate_name == 2){
    return lc2;
  }  
  else{
   return lc3;
  }
}

void no_lights_on_all_displays(){
  lc1.clearDisplay(0);
  lc2.clearDisplay(0);
  lc3.clearDisplay(0);
}

// routine for all figures basal lights
void draw_X (LedControl lc,  int intensity = PARAMETER::MIN_INTENSITY_VALUE){
  byte x[8] = {B11000011, B11100111, B01111110, B00111100, 
               B00111100, B01111110, B11100111, B11000011};

  lc.setIntensity(0, intensity);
  
  lc.setRow(0, 0, x[0]);
  lc.setRow(0, 1, x[1]);
  lc.setRow(0, 2, x[2]);
  lc.setRow(0, 3, x[3]);
  lc.setRow(0, 4, x[4]);
  lc.setRow(0, 5, x[5]);
  lc.setRow(0, 6, x[6]);
  lc.setRow(0, 7, x[7]);

}

void draw_ball(LedControl lc,  int intensity = PARAMETER::MIN_INTENSITY_VALUE) {
  byte ball[8] = {B00111100, B01111110, B11100111, B11000011, 
               B11000011, B11100111, B01111110, B00111100};
  lc.setIntensity(0,intensity);

  lc.setRow(0, 0, ball[0]);
  lc.setRow(0, 1, ball[1]);
  lc.setRow(0, 2, ball[2]);
  lc.setRow(0, 3, ball[3]);
  lc.setRow(0, 4, ball[4]);
  lc.setRow(0, 5, ball[5]);
  lc.setRow(0, 6, ball[6]);
  lc.setRow(0, 7, ball[7]);
}

void draw_plus(LedControl lc,  int intensity = PARAMETER::MIN_INTENSITY_VALUE) {
  byte plus[8] = {B00011000, B00011000, B00011000, B11111111, 
                      B11111111, B00011000, B00011000, B00011000};
  lc.setIntensity(0, intensity);

  lc.setRow(0, 0, plus[0]);
  lc.setRow(0, 1, plus[1]);
  lc.setRow(0, 2, plus[2]);
  lc.setRow(0, 3, plus[3]);
  lc.setRow(0, 4, plus[4]);
  lc.setRow(0, 5, plus[5]);
  lc.setRow(0, 6, plus[6]);
  lc.setRow(0, 7, plus[7]);
}


