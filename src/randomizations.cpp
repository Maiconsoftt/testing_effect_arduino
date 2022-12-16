#include <Arduino.h>
#include <SoftwareSerial.h>

#include "tasks.hpp"
#include "experiment_configuration.hpp"
#include "output_controller.hpp"
#include "stimuli_control.hpp"
#include "gate_controller.hpp"
#include "constants.hpp"

using namespace CONSTANTS;

void randomize_gate_for_repertory_trainning(){
    String random_repertory_gate = CONSTANTS::gates_array[random (0, 3)]; //randomize a number from 1 to 3 that corresponds to the target gates'
    ExperimentConfiguration::set_current_repertory_gate(random_repertory_gate);
}
  
void randomize_pairs_sounds_and_figures() {
  Serial.print ("Recived! Configuring and creating conditions to Mouse "); //print to csv
  delay (500);

  String pair_x_figure, pair_y_figure, pair_z_figure;
  String pair_x_sound, pair_y_sound, pair_z_sound;

  pair_x_sound = sounds[random(0, 3)];
  pair_x_figure = figures[random(0, 3)];

  if (pair_x_sound == sounds[0]) {

    pair_y_sound = sounds [random(1, 3)]; //choose between 2 or 3 because 1 was already chosen
    pair_z_sound = sounds [random(1, 3)];
    while (pair_z_sound == pair_y_sound) {
      pair_z_sound = sounds [random(1, 3)];
    }
  }

  if (pair_x_sound == sounds[1]) {
    pair_y_sound = sounds [random(0, 3)]; //choose between 2 or 3 because 1 was already chosen
    while (pair_y_sound == sounds[1]) {
      pair_y_sound = sounds [random(0, 3)];
    }
    pair_z_sound = sounds [random(0, 3)];
    while (pair_z_sound == pair_y_sound || pair_z_sound == pair_x_sound) {
      pair_z_sound = sounds [random(0, 3)];
    }
  }

  if (pair_x_sound == sounds[2]) {
    pair_y_sound = sounds [random(0, 2)]; //choose between 2 or 3 because 1 was already chosen
    pair_z_sound = sounds [random(0, 2)];
    while (pair_z_sound == pair_y_sound) {
      pair_z_sound = sounds [random(0, 2)];
    }
  }

  if (pair_x_figure == figures[0]) {
    pair_y_figure = figures[random(1, 3)]; //choose between 5 or 6 because 4 was already chosen
    pair_z_figure = figures[random(1, 3)];
    while (pair_z_figure == pair_y_figure) {
      pair_z_figure = figures[random(1, 3)];
    }
  }

  if (pair_x_figure == figures[1]) {
    pair_y_figure = figures [random(0, 3)]; //choose between 2 or 3 because 1 was already chosen
    while (pair_y_figure == figures[1]) {
      pair_y_figure = figures [random(0, 3)];
    }
    pair_z_figure = figures [random(0, 3)];
    while (pair_z_figure == pair_x_figure || pair_z_figure == pair_y_figure) {
      pair_z_figure = figures [random(0, 3)];
    }
  }

  if (pair_x_figure == figures[2]) {
    pair_y_figure = figures[random(0, 2)]; //choose between 5 or 6 because 4 was already chosen
    pair_z_figure = figures[random(0, 2)];
    while (pair_z_figure == pair_y_figure) {
      pair_z_figure = figures[random(0, 2)];
    }
  }

  ExperimentConfiguration::set_pair_x_figure(pair_x_figure), 
  ExperimentConfiguration::set_pair_y_figure(pair_y_figure), 
  ExperimentConfiguration::set_pair_z_figure(pair_z_figure);
  ExperimentConfiguration::set_pair_x_sound(pair_x_sound), 
  ExperimentConfiguration::set_pair_y_sound(pair_y_sound), 
  ExperimentConfiguration::set_pair_z_sound(pair_z_sound);

  Serial.println ("Pairs:");
  Serial.print ("X = "); Serial.print (pair_x_sound); Serial.print (" and ");
  Serial.println (pair_x_figure);
  delay (200);
  Serial.print ("Y = "); Serial.print (pair_y_sound); Serial.print (" and ");
  Serial.println (pair_y_figure);
  delay (200);
  Serial.print ("Z = "); Serial.print (pair_z_sound); Serial.print (" and ");
  Serial.println (pair_z_figure);
}

void Randomize_gates_for_stages () {

  String basal_gate_1;
  String basal_gate_2;
  String new_random_gate = gates_array [random (0, 3)]; //randomize a number from 1 to 3 that corresponds to the target gates'
  ExperimentConfiguration::set_current_gate(new_random_gate);
  String randomized_gate = ExperimentConfiguration::get_current_gate();


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

void random_seed_repeat (){
    randomSeed(analogRead(random(0, 6)));
}