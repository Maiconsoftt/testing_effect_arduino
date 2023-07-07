#include "tasks.hpp"
#include "experiment_configuration.hpp"
#include "leds_controller.hpp"
#include "stimuli_control.hpp"
#include "gate_controller.hpp"
#include "constants.hpp"
#include "randomizations.hpp"
#include "serial_prints.hpp"
#include <SoftwareSerial.h>

// repertory training routine
void print_repertory_gate(){
  randomize_gate_for_repertory_training();
  converting_all_int_gates_to_string (0);
  print_received_input("repertory_gate");
  delay (1000);
}

void open_repertory_training_gate (){
  //opening the target gate from randomization
  Gates::open_gate_by_name(ExperimentConfiguration::get_current_repertory_gate());
}

void Repeat_Repertory_training () {
  Gates::close_gate_by_name(ExperimentConfiguration::get_current_repertory_gate());
  print_received_input("5s");
  delay (5000);
}

void End_Repertory_training () { //bonsai needs to calculate the time!
  // bonsai needs to work here !! so it can finish the first trial and randomize again
  Gates::close_gate_by_name(ExperimentConfiguration::get_current_repertory_gate());
}

void mouse_conditions_creation(int info){
  if (info == 0){
    randomize_and_create_pairs();
    converting_all_int_pairs_figures_to_string();
    converting_all_int_pairs_sounds_to_string();
    print_all_configurations();
  }
  else if (info == 1){
    converting_all_int_pairs_figures_to_string();
    converting_all_int_pairs_sounds_to_string();
    print_all_configurations();
  }
}
void randomize_gates_for_stages_and_print () {
  Randomize_gates_for_stages ();
  converting_all_int_gates_to_string (1);
  print_received_input("current_gate");
}

void stages (String monitor_input){
  if (monitor_input == "stage1\r\n"){
    ExperimentConfiguration::set_current_pair(0);
    ExperimentConfiguration::set_current_basal_figure_1(ExperimentConfiguration::pair_y_figure);
    ExperimentConfiguration::set_current_basal_figure_2(ExperimentConfiguration::pair_z_figure);
    randomize_gates_for_stages_and_print ();
    print_counting(PARAMETER::INTERVAL_BEFORE_ATTEMPT, "40s");
    execute_paired_stages();
  }
  else if (monitor_input == "stage2\r\n"){
    ExperimentConfiguration::set_current_pair (0);
    ExperimentConfiguration::set_current_basal_figure_1(ExperimentConfiguration::pair_y_figure);
    ExperimentConfiguration::set_current_basal_figure_2(ExperimentConfiguration::pair_z_figure);
    randomize_gates_for_stages_and_print ();
    print_counting(PARAMETER::INTERVAL_BEFORE_ATTEMPT, "40s");
    execute_working_sound_stages();
  }
  else if (monitor_input == "stage3\r\n"){
    ExperimentConfiguration::set_current_pair(1);
    ExperimentConfiguration::set_current_basal_figure_1(ExperimentConfiguration::pair_x_figure);
    ExperimentConfiguration::set_current_basal_figure_2(ExperimentConfiguration::pair_z_figure);
    randomize_gates_for_stages_and_print ();
    print_counting(PARAMETER::INTERVAL_BEFORE_ATTEMPT, "40s");
    execute_paired_stages();
  }
  else if (monitor_input == "stage4\r\n"){
    ExperimentConfiguration::set_current_pair(1);
    ExperimentConfiguration::set_current_basal_figure_1(ExperimentConfiguration::pair_x_figure);
    ExperimentConfiguration::set_current_basal_figure_2(ExperimentConfiguration::pair_z_figure);
    randomize_gates_for_stages_and_print ();
    print_counting(PARAMETER::INTERVAL_BEFORE_ATTEMPT, "40s");
    execute_working_sound_stages();
  }
  else if (monitor_input == "stage5\r\n"){
    ExperimentConfiguration::set_current_pair(2);
    ExperimentConfiguration::set_current_basal_figure_1(ExperimentConfiguration::pair_x_figure);
    ExperimentConfiguration::set_current_basal_figure_2(ExperimentConfiguration::pair_y_figure);
    randomize_gates_for_stages_and_print ();
    print_counting(PARAMETER::INTERVAL_BEFORE_ATTEMPT, "40s");
    execute_paired_stages();
  }
  else if (monitor_input == "stage6\r\n"){
    ExperimentConfiguration::set_current_pair (2);
    ExperimentConfiguration::set_current_basal_figure_1(ExperimentConfiguration::pair_x_figure);
    ExperimentConfiguration::set_current_basal_figure_2(ExperimentConfiguration::pair_y_figure);
    randomize_gates_for_stages_and_print ();
    print_counting(PARAMETER::INTERVAL_BEFORE_ATTEMPT, "40s");
    execute_working_sound_stages();
  }
  else {
    Serial.println("Wrong command: " + monitor_input);
  }
}
void execute_paired_stages(){
  execute_paired_stimuli();
  Gates::open_gate_by_name(ExperimentConfiguration::get_current_gate());
}

void execute_working_sound_stages(){
  execute_separated_stimuli ();
  Gates::open_all_gates();
  ExperimentConfiguration::set_current_gate(4); 
}

void finalize_stage_trial(){
  no_lights_on_all_displays();
  Gates::close_gate_by_name(ExperimentConfiguration::get_current_gate());
}

void finalize_stage_attempt(){
  no_lights_on_all_displays();
  Gates::close_gate_by_name(ExperimentConfiguration::get_current_gate());
  print_received_input("60s");
  delay(PARAMETER::INTERVAL_BETWEEN_RODENTS);
}