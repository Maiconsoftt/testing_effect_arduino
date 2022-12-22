#include <Arduino.h>
#include "tasks.hpp"
#include "experiment_configuration.hpp"
#include "stimuli_control.hpp"
#include "serial_prints.hpp"
#include "output_controller.hpp"
#include "gate_controller.hpp"
#include "randomizations.hpp"
#include "constants.hpp"
#include "parameters.hpp"

char buff[35];

void setup() {

  Serial.begin(9600); // boudrate of serialport communication

  ExperimentConfiguration::set_current_pair(0);
  Gates::setup_gates();
  controllers_setup();
  randomSeed(analogRead(5)); //read random noise from analog pin 5 and generate random seeds

  for (int a = 5; a <= 13; a++){
    pinMode (a, OUTPUT);
    digitalWrite (a, LOW);
    delay (10);
  } 
  commands ();
}

void loop() {

  if (Serial.available()) { //if serial receives more than 0 bytes, than there is someting to read

    String recieved_input_serial = Serial.readString();

    if (recieved_input_serial == "commands\r\n") {
      commands ();
    }

    else if (recieved_input_serial == "pairs\r\n"){
      ExperimentConfiguration::set_current_pair(5);
      randomize_and_create_pairs ();
      print_pairs ();
    }

    else if (recieved_input_serial == "mouseID\r\n") {

      Serial.println("Type Mouse Identification Number");

      while (Serial.available () == 0) {}
      recieved_input_serial = Serial.readString();
      ExperimentConfiguration::set_mouse_id(recieved_input_serial);
      ExperimentConfiguration::set_current_pair(0);

      randomize_and_create_pairs ();
      
      print_pairs ();

      Serial.println (String(ExperimentConfiguration::get_pair_x_figure()));
      Serial.println (String(ExperimentConfiguration::get_pair_x_sound()));
      delay (100);
    }

    //stage_0 - repertory training
    else if (recieved_input_serial == "stage0\r\n") {
      Serial.println ("Put the mouse at the central compartment");
      Serial.println ("Initializing Repertory Trainning in 60 seconds");
      for (int i = 0; i <= 60; i ++) {
        sprintf (buff, "Counting: %ds ...", i);
        Serial.println (buff);
        delay (1000);
      }
      repertory_trainning ();
    }

    else if (recieved_input_serial == "repeat\r\n") {
      delay (100);
      Repeat_Repertory_trainning ();
      repertory_trainning ();
    }

    else if (recieved_input_serial == "end\r\n") {
      delay (100);
      End_Repertory_trainning ();
    }

    else if (recieved_input_serial == "Stage1\r\n"){
      ExperimentConfiguration::set_current_pair(0);
    
      ExperimentConfiguration::set_current_basal_figure_1(ExperimentConfiguration::pair_y_figure);
      ExperimentConfiguration::set_current_basal_figure_2(ExperimentConfiguration::pair_z_figure);
      
      for (int trial = 0; trial < 8; trial ++){
        Randomize_gates_for_stages ();
        execute_pairs_stage_1 ();

        shutdown_all_displays();
        delay(PARAMETER::INTERVAL_BETWEEN_TRIALS);
      }
    }

    else if (recieved_input_serial == "Stage2\r\n"){
      ExperimentConfiguration::set_current_pair (0);

      for (int trial = 0; trial < 8; trial ++){
        Randomize_gates_for_stages ();
        execute_working_sound_stage_2();

        shutdown_all_displays();
        delay (PARAMETER::INTERVAL_BETWEEN_TRIALS);
      }
    }

    else if (recieved_input_serial == "Stage3\r\n"){
      ExperimentConfiguration::set_current_pair(1);
      
      for (int trial = 0; trial < 8; trial ++){
        Randomize_gates_for_stages ();
        execute_pairs_stage_1 ();

        shutdown_all_displays();
        delay(PARAMETER::INTERVAL_BETWEEN_TRIALS);
      }
    }

    else if (recieved_input_serial == "Stage4\r\n"){
      ExperimentConfiguration::set_current_pair (1);

      for (int trial = 0; trial < 8; trial ++){
        Randomize_gates_for_stages ();
        execute_working_sound_stage_2();

        shutdown_all_displays();
        delay (PARAMETER::INTERVAL_BETWEEN_TRIALS);
      }
    }
  }
}

