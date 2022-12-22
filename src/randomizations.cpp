#include <Arduino.h>
#include <SoftwareSerial.h>

#include "tasks.hpp"
#include "experiment_configuration.hpp"
#include "output_controller.hpp"
#include "stimuli_control.hpp"
#include "gate_controller.hpp"
#include "constants.hpp"
#include "serial_prints.hpp"

void randomize_gate_for_repertory_trainning(){
  int current_repertory_gate = random (0,3);
  ExperimentConfiguration::set_current_repertory_gate(current_repertory_gate);
}

void randomize_and_create_pairs (){

  Serial.println ("Recieved! Configuring pairs to Mouse " + ExperimentConfiguration::get_mouse_id());

  int x_figure = random (0,3); int x_sound = random (0,3);
  int y_figure = random (0,3); int y_sound = random (0,3); 
  int z_figure = random (0,3); int z_sound = random (0,3);

  if ((x_sound == y_sound) || (x_sound == z_sound) || (y_sound == z_sound)){
    randomSeed (analogRead(random(0,5)));
    randomize_and_create_pairs();
  }
  else if ((x_figure == y_figure) || (x_figure == z_figure) || (y_figure == z_figure)){
    randomSeed (analogRead(random(0,5)));
    randomize_and_create_pairs();
  }
  ExperimentConfiguration::set_pair_x_figure(x_figure), 
  ExperimentConfiguration::set_pair_y_figure(y_figure), 
  ExperimentConfiguration::set_pair_z_figure(z_figure);
  ExperimentConfiguration::set_pair_x_sound(x_sound), 
  ExperimentConfiguration::set_pair_y_sound(y_sound), 
  ExperimentConfiguration::set_pair_z_sound(z_sound);

  converting_int_pairs_figures_to_string();
  converting_int_pairs_sounds_to_string();
}

void Randomize_gates_for_stages () {
  int gates_array [3] = {1,2,3};
  int basal_gate_1; int basal_gate_2;
  int new_random_gate = gates_array[random (1, 4)]; //randomize a number from 1 to 3 that corresponds to the target gates'
  
  ExperimentConfiguration::set_current_gate(new_random_gate);
  int randomized_gate = ExperimentConfiguration::get_current_gate();

  randomSeed(analogRead(random(0, 6)));

  Serial.print ("Oppening ");
  Serial.println (ExperimentConfiguration::get_current_gate());
  delay (1000);

  //openning the target gate from randomization
  if (randomized_gate == gates_array[0]) {
    basal_gate_1 = gates_array [1];
    basal_gate_2 = gates_array [2];
    ExperimentConfiguration::set_current_basal_gate_1(basal_gate_1);
    ExperimentConfiguration::set_current_basal_gate_2(basal_gate_2);
    Gates::open_gate_by_name (randomized_gate);
  }
  else if (randomized_gate == gates_array [1]) {
    basal_gate_1 = gates_array [0];
    basal_gate_2 = gates_array [2];
    ExperimentConfiguration::set_current_basal_gate_1(basal_gate_1);
    ExperimentConfiguration::set_current_basal_gate_2(basal_gate_2);
    Gates::open_gate_by_name (randomized_gate);
  }
  else if (randomized_gate == gates_array [2]) {
    basal_gate_1 = gates_array [0];
    basal_gate_2 = gates_array [1];
    ExperimentConfiguration::set_current_basal_gate_1(basal_gate_1);
    ExperimentConfiguration::set_current_basal_gate_2(basal_gate_2);
    Gates::open_gate_by_name (randomized_gate);
  }
}
