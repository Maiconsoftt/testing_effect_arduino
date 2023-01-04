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
      
      print_received_input(received_input_serial);
      while (Serial.available () == 0) {}
      received_input_serial = Serial.readString();
      ExperimentConfiguration::set_mouse_id(atoi(received_input_serial.c_str()));
      ExperimentConfiguration::set_current_pair(0);
      mouse_conditions_creation();
    }

    else if (received_input_serial == "manual\r\n"){
      print_received_input(received_input_serial);
      manual_configuration();  
      delay (1000);
    }

    else if (received_input_serial == "stage0\r\n") {
      print_counting(PARAMETER::INTERVAL_BEFORE_ATTEMPT, "60s");
      Serial.println ("Beginning Repertory Training. Randomizing gate ..."); delay (1000);
      repertory_training ();
    }

    else if (received_input_serial == "repeat\r\n") {
      print_close_gate();
      Repeat_Repertory_training ();
      repertory_training ();
    }

    else if (received_input_serial == "end\r\n") {
      print_close_gate();
      End_Repertory_training ();
    }

    else if (received_input_serial == "EndStTrial\r\n"){
      finalize_stage_trial();
    }

    else if (received_input_serial == "EndStAttempt\r\n"){
      finalize_stage_attempt();
    }

    else if (received_input_serial == "stage1\r\n"){
      ExperimentConfiguration::set_current_pair(0);
      ExperimentConfiguration::set_current_basal_figure_1(ExperimentConfiguration::pair_y_figure);
      ExperimentConfiguration::set_current_basal_figure_2(ExperimentConfiguration::pair_z_figure);
      print_counting(PARAMETER::INTERVAL_BEFORE_ATTEMPT, "60s");
      execute_paired_stages();
    }

    else if (received_input_serial == "stage2\r\n"){
      ExperimentConfiguration::set_current_pair (0);
      print_counting(PARAMETER::INTERVAL_BEFORE_ATTEMPT, "60s");
      execute_working_sound_stages();
    }

    else if (received_input_serial == "stage3\r\n"){
      ExperimentConfiguration::set_current_pair(1);
      ExperimentConfiguration::set_current_basal_figure_1(ExperimentConfiguration::pair_x_figure);
      ExperimentConfiguration::set_current_basal_figure_2(ExperimentConfiguration::pair_z_figure);
      print_counting(PARAMETER::INTERVAL_BEFORE_ATTEMPT, "60s");
      execute_paired_stages();
    }

    else if (received_input_serial == "stage4\r\n"){
      ExperimentConfiguration::set_current_pair (1);
      print_counting(PARAMETER::INTERVAL_BEFORE_ATTEMPT, "60s");
      execute_working_sound_stages();
    }

    else if (received_input_serial == "stage5\r\n"){
      ExperimentConfiguration::set_current_pair(2);
      ExperimentConfiguration::set_current_basal_figure_1(ExperimentConfiguration::pair_x_figure);
      ExperimentConfiguration::set_current_basal_figure_2(ExperimentConfiguration::pair_y_figure);
      print_counting(PARAMETER::INTERVAL_BEFORE_ATTEMPT, "60s");
      execute_paired_stages();
    }

    else if (received_input_serial == "stage6\r\n"){
      ExperimentConfiguration::set_current_pair (2);
      print_counting(PARAMETER::INTERVAL_BEFORE_ATTEMPT, "60s");
      execute_working_sound_stages();
    }
  }
}

