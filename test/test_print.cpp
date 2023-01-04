#include <Arduino.h>
#include "experiment_configuration.hpp"
#include "stimuli_control.hpp"
#include "serial_prints.hpp"
#include "output_controller.hpp"
#include "gate_controller.hpp"
#include "randomizations.hpp"
#include "constants.hpp"
#include "tasks.hpp"


void test_print() {
  randomize_and_create_pairs();
  converting_all_int_pairs_figures_to_string();
  converting_all_int_pairs_sounds_to_string();


  ExperimentConfiguration::set_current_pair(1);
  print_current_pairs();
  ExperimentConfiguration::set_current_pair(2);
  print_current_pairs(); 
  ExperimentConfiguration::set_current_pair(3);
  print_current_pairs();

  print_all_configurations();
}

void setup() {
  Serial.begin(9600); 
  for (int a = 5; a <= 13; a++){
    pinMode (a, OUTPUT);
    digitalWrite (a, LOW);
    delay (10);
  } 
}

void loop() {
    test_print();
    while(true);
}
