#include <Arduino.h>
#include <SoftwareSerial.h>

#include "tasks.hpp"
#include "experiment_configuration.hpp"
#include "stimuli_control.hpp"
#include "serial_prints.hpp"
#include "leds_controller.hpp"
#include "gate_controller.hpp"
#include "randomizations.hpp"
#include "constants.hpp"
#include "manual_settings.hpp"

void setup() {
  Serial.begin(9600); Serial.setTimeout(1000); 
  setup_random();
  ExperimentConfiguration::set_current_pair(0);
  Gates::setup_gates();
  led_and_controllers_setup();
  commands ();
}

void loop() {

  if (Serial.available()) { 

    String received_input_serial = Serial.readString();

    if (received_input_serial == "commands\r\n") {
      commands ();
    }

    else if (received_input_serial == "mouseID\r\n") {
      
      print_received_input(received_input_serial);
      while (Serial.available () == 0) {}
      received_input_serial = Serial.readString();
      ExperimentConfiguration::set_mouse_id(atoi(received_input_serial.c_str()));
      ExperimentConfiguration::set_current_pair(0);
      mouse_conditions_creation(0);
    }

    else if (received_input_serial == "manual\r\n"){
      print_received_input(received_input_serial);
      manual_configuration();  
      delay (1000);
    }

    else if (received_input_serial == "reset\r\n"){
      setup();      
      Serial.println("reset");
    }

    else if (received_input_serial == "info\r\n"){
      mouse_conditions_creation(1);
    }

    else if (received_input_serial == "stage0\r\n") {
      print_repertory_gate();
      print_counting(PARAMETER::INTERVAL_BEFORE_ATTEMPT, "60s");
      Serial.println ("Beginning Repertory Training. Randomizing gate ..."); delay (1000);
      open_repertory_training_gate ();
    }

    else if (received_input_serial == "repeatRT\r\n") {
      print_close_gate();
      Repeat_Repertory_training ();
      print_repertory_gate();
      open_repertory_training_gate ();
    }

    else if (received_input_serial == "endRT\r\n") {
      print_close_gate();
      End_Repertory_training ();
    }

    else if (received_input_serial == "EndStTrial\r\n"){
      finalize_stage_trial();
    }

    else if (received_input_serial == "EndStAttempt\r\n"){
      finalize_stage_attempt();
    }
    
    else {
      stages(received_input_serial);
    }
  }
}

