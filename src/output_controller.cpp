#include <LedControl.h>
#include <Arduino.h>
#include "tasks.hpp"
#include "experiment_configuration.hpp"
#include "output_controller.hpp"
#include "constants.hpp"

//lc1 = left arm, lc2 = central arm, lc3 = right arm
LedControl lc1 = LedControl(7, 5, 6, 1); // define matrix DIN, CLK, CS pins and the number of devices, respectively
LedControl lc2 = LedControl(10, 8, 9, 1);
LedControl lc3 = LedControl(13, 11, 12, 1);

const int buzzer = A0;

void controllers_setup () {

  lc1.clearDisplay(0); lc2.clearDisplay(0); lc3.clearDisplay(0);
  lc1.shutdown(0, false); lc2.shutdown(0, false); lc3.shutdown(0, false);
  lc1.setIntensity(0, 1); lc2.setIntensity(0, 1); lc3.setIntensity(0, 1);

  pinMode(buzzer, OUTPUT); //set buzzer pin as output
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

void shutdown_all_displays (){
  lc1.shutdown (0,true);
  lc2.shutdown (0,true);
  lc3.shutdown (0,true);
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
  byte o[8] = {B00111100, B01111110, B11100111, B11000011, 
               B11000011, B11100111, B01111110, B00111100};
  lc.setIntensity(0,intensity);

  lc.setRow(0, 0, o[0]);
  lc.setRow(0, 1, o[1]);
  lc.setRow(0, 2, o[2]);
  lc.setRow(0, 3, o[3]);
  lc.setRow(0, 4, o[4]);
  lc.setRow(0, 5, o[5]);
  lc.setRow(0, 6, o[6]);
  lc.setRow(0, 7, o[7]);
}
void draw_plus(LedControl lc,  int intensity = PARAMETER::MIN_INTENSITY_VALUE) {
  byte draw_plus[8] = {B00011000, B00011000, B00011000, B11111111, 
                      B11111111, B00011000, B00011000, B00011000};
  lc.setIntensity(0, intensity);

  lc.setRow(0, 0, draw_plus[0]);
  lc.setRow(0, 1, draw_plus[1]);
  lc.setRow(0, 2, draw_plus[2]);
  lc.setRow(0, 3, draw_plus[3]);
  lc.setRow(0, 4, draw_plus[4]);
  lc.setRow(0, 5, draw_plus[5]);
  lc.setRow(0, 6, draw_plus[6]);
  lc.setRow(0, 7, draw_plus[7]);
}

// Routines for diferent buzzer frequencies
void Low_Frequency(){
  tone(buzzer, 100); // Send first sound signal...
  delay(1000);          // ...for 1 sec
  noTone(buzzer);       // Stop sound...          
}

void Medium_Frequency(){ 
  tone(buzzer, 750); // Send second sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
}

void High_Frequency(){
  tone(buzzer, 2000); // Send third sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
}
