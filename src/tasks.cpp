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
void repertory_trainning (){
  randomize_gate_for_repertory_trainning();
  converting_all_int_gates_to_string ();
  print_repertory_trainning ();
  delay (1000);
  //openning the target gate from randomization
  Gates::open_gate_by_name(ExperimentConfiguration::get_current_repertory_gate());
}

void Repeat_Repertory_trainning () {
  Gates::close_gate_by_name(ExperimentConfiguration::get_current_repertory_gate());
  print_end_close_gate (); print_wait ("5 seconds");
  delay (5000);
}

void End_Repertory_trainning () { //bonsai needs to calculate the time!
  // bonsai needs to work here !! so it can finish the first trial and randomize again
  Gates::close_gate_by_name(ExperimentConfiguration::get_current_repertory_gate());
  print_end_close_gate ();
}

void mouse_conditions_creation(){
    randomize_and_create_pairs();
    converting_all_int_pairs_figures_to_string();
    converting_all_int_pairs_sounds_to_string();
    print_all_configurations();
}

void execute_paired_stages(){
  Randomize_gates_for_stages ();
  print_current_gate();
  execute_paired_stimuli();
  Gates::open_gate_by_name(ExperimentConfiguration::get_current_gate());
}

void execute_working_sound_stages(){
  Randomize_gates_for_stages();
  print_current_gate();
  execute_separated_stimuli ();
}

void finalize_stage(){
  shutdown_all_displays();
  print_wait ("40 seconds");
  delay(PARAMETER::INTERVAL_BETWEEN_TRIALS);
}