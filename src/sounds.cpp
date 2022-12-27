#include <Arduino.h>
#include "constants.hpp"

// Routines for diferent buzzer frequencies
void execute_sound (int frequency){
  tone(CONSTANTS::buzzer, frequency); // Send first sound signal...
}
void stop_sound_excution (){
    noTone(CONSTANTS::buzzer);  
}         
