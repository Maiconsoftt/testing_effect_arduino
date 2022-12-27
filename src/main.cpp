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
  Serial.begin(9600); 
  setup_random();
  ExperimentConfiguration::set_current_pair(0);
  Gates::setup_gates();
  controllers_setup();
  commands ();
}

void loop() {

  if (Serial.available()) { 

    String received_input_serial = Serial.readString();

    if (received_input_serial == "commands\r\n") {
      commands ();
    }

    else if (received_input_serial == "mouseID\r\n") {
      print_mouse_message();
      while (Serial.available () == 0) {}
      received_input_serial = Serial.readString();
      ExperimentConfiguration::set_mouse_id(received_input_serial);
      ExperimentConfiguration::set_current_pair(0);
      mouse_conditions_creation();
    }

    else if (received_input_serial == "manual\r\n"){
      manual_configuration();  
      delay (1000);
    }

    else if (received_input_serial == "stage0\r\n") {
      print_repertory_training_counting();
      repertory_trainning ();
    }

    else if (received_input_serial == "repeat\r\n") {
      print_close_gate();
      Repeat_Repertory_trainning ();
      repertory_trainning ();
    }

    else if (received_input_serial == "end\r\n") {
      print_close_gate();
      End_Repertory_trainning ();
    }

    else if (received_input_serial == "EndStage"){
      finalize_stage();
    }

    else if (received_input_serial == "stage1\r\n"){
      ExperimentConfiguration::set_current_pair(0);
      ExperimentConfiguration::set_current_basal_figure_1(ExperimentConfiguration::pair_y_figure);
      ExperimentConfiguration::set_current_basal_figure_2(ExperimentConfiguration::pair_z_figure);
      execute_paired_stages();
    }

    else if (received_input_serial == "stage2\r\n"){
      ExperimentConfiguration::set_current_pair (0);
      execute_working_sound_stages();
    }

    else if (received_input_serial == "stage3\r\n"){
      ExperimentConfiguration::set_current_pair(1);
      
      for (int trial = 0; trial < 8; trial ++){
        Randomize_gates_for_stages ();
        execute_paired_stages();

        shutdown_all_displays();
        delay(PARAMETER::INTERVAL_BETWEEN_TRIALS);
      }
    }

    else if (received_input_serial == "stage4\r\n"){
      ExperimentConfiguration::set_current_pair (1);

      for (int trial = 0; trial < 8; trial ++){
        Randomize_gates_for_stages ();
        execute_working_sound_stages();

        shutdown_all_displays();
        delay (PARAMETER::INTERVAL_BETWEEN_TRIALS);
      }
    }
    else {
      Serial.println ("Wrong command\n");
      commands();
    }
  }
}

