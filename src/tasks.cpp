#include "tasks.hpp"
#include "experiment_configuration.hpp"
#include "output_controller.hpp"
#include "stimuli_control.hpp"
#include "gate_controller.hpp"
#include "constants.hpp"
#include <SoftwareSerial.h>

void commands () {
  Serial.println ("List of Commands:"); 
  Serial.println ("Type 'mouseID' to set mouse indentification and pairs");
  Serial.println ("Type 'stage0' to initialize Repertory Trainning");
  Serial.println ("Type 'repeat' after every successufull Repertory Trainning attempt");
  Serial.println ("Type 'end' to finish Repertory Tranning"); 
  Serial.println ("Type 'commands' to see this list again");
}

// repertory training routine
void repertory_trainning () {

  Serial.println ("Initializing Repertoy Training"); 
  delay (500); //print this to csv file with timestamp!
  Serial.println ("Randomizing arm to open the gate"); 
  delay (500);

  String random_repertory_gate = CONSTANTS::gates_array[random (0, 3)]; //randomize a number from 1 to 3 that corresponds to the target gates'
  ExperimentConfiguration::set_current_repertory_gate(random_repertory_gate);
  String randomized_repertory_gate = ExperimentConfiguration::get_current_repertory_gate();

  Serial.print ("Oppening ");
  Serial.println (ExperimentConfiguration::get_current_repertory_gate());
  delay (1000);

  //openning the target gate from randomization

  Gates::open_gate_by_name(randomized_repertory_gate);
}

void Repeat_Repertory_trainning () {
  Serial.println ("Closing the Gate");
  String current_gate = ExperimentConfiguration::get_current_repertory_gate();
  Gates::close_gate_by_name(current_gate);
  Serial.println ("The gate was closed! Wait 5 seconds");
  delay (5000);
  randomSeed(analogRead(random(0, 6)));
}

void End_Repertory_trainning () { //bonsai needs to calculate the time!
  // bonsai needs to work here !! so it can finish the first trial and randomize again

  Serial.print("Closing the gate");
  String current_gate = ExperimentConfiguration::get_current_repertory_gate();
  Gates::close_gate_by_name(current_gate);
  Serial.println ("The gate was closed!");
}

void execute_pairs_stage_1 (){
  execute_paired_stimuli();

}

void execute_working_sound_stage_2(){
  execute_separated_stimuli ();
}
