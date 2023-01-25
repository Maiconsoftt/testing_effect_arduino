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
void repertory_training (){
  randomize_gate_for_repertory_training();
  converting_all_int_gates_to_string ();
  print_repertory_training ();
  delay (1000);
  //openning the target gate from randomization
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

void execute_paired_stages(){
  Randomize_gates_for_stages ();
  print_received_input(String(ExperimentConfiguration::get_current_gate()));
  execute_paired_stimuli();
  Gates::open_gate_by_name(ExperimentConfiguration::get_current_gate());
}

void execute_working_sound_stages(){
  Randomize_gates_for_stages();
  print_received_input(String(ExperimentConfiguration::get_current_gate()));
  execute_separated_stimuli ();
  Gates::open_all_gates();
  ExperimentConfiguration::set_current_gate(4); 
}

void finalize_stage_trial(){
  no_lights_on_all_displays();
  Gates::close_gate_by_name(ExperimentConfiguration::get_current_gate());
  print_received_input("40s");
  delay(PARAMETER::INTERVAL_BETWEEN_TRIALS);
}

void finalize_stage_attempt(){
  no_lights_on_all_displays();
  Gates::close_gate_by_name(ExperimentConfiguration::get_current_gate());
  print_received_input("60s");
  delay(PARAMETER::INTERVAL_BETWEEN_RODENTS);
}