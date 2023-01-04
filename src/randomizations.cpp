#include <Arduino.h>
#include <SoftwareSerial.h>

#include "experiment_configuration.hpp"
#include "constants.hpp"

int _rand_range(int n)
{
    int r, ul;
    ul = RAND_MAX - RAND_MAX % n;
    while ((r = random(RAND_MAX)) >= ul);
    return r % n;
}

void _shuffle_swap(int index_a, int index_b, int *array, int size)
{
    char *x, *y, tmp[size];

    if (index_a == index_b) return;

    x = (char*)array + index_a * size;
    y = (char*)array + index_b * size;

    memcpy(tmp, x, size);
    memcpy(x, y, size);
    memcpy(y, tmp, size);
}

void _shuffle(int *array, size_t nmemb)
{
  size_t  size = sizeof(int);

  int r;
    
  while (nmemb > 1) {                                                                      
      r = _rand_range(nmemb--);                                                              
      _shuffle_swap(nmemb, r, array, size);
  }
}

void setup_random(){
  randomSeed(analogRead(0));
}

void randomize_gate_for_repertory_training(){
  int current_repertory_gate = CONSTANTS::gates_array[random (0,3)];
  ExperimentConfiguration::set_current_repertory_gate(current_repertory_gate);
  randomSeed(analogRead(random(0,6)));
}

void randomize_and_create_pairs (){

  Serial.println ("Configuring pairs for Mouse " + ExperimentConfiguration::get_mouse_id()); delay (1000);

  int figure_options[] = {CONSTANTS::Figure_X, CONSTANTS::Figure_Y, CONSTANTS::Figure_Z};
  _shuffle(figure_options, sizeof(figure_options)/sizeof(int));
  int x_figure = figure_options[0];
  int y_figure = figure_options[1];
  int z_figure = figure_options[2];

  int sound_options[] = {CONSTANTS::X_sound, CONSTANTS::Y_sound, CONSTANTS::Z_sound};
  _shuffle(sound_options, sizeof(sound_options)/sizeof(int));
  int x_sound = sound_options[0];
  int y_sound = sound_options[1];
  int z_sound = sound_options[2];

  ExperimentConfiguration::set_pair_x_figure(x_figure), 
  ExperimentConfiguration::set_pair_y_figure(y_figure), 
  ExperimentConfiguration::set_pair_z_figure(z_figure);
  ExperimentConfiguration::set_pair_x_sound(x_sound), 
  ExperimentConfiguration::set_pair_y_sound(y_sound), 
  ExperimentConfiguration::set_pair_z_sound(z_sound);
}

void Randomize_gates_for_stages () {
  using namespace CONSTANTS;

  int basal_gate_1; int basal_gate_2;
  int current_stage_gate = gates_array[random (0,3)];
  randomSeed(analogRead(random(0,6)));
  
  ExperimentConfiguration::set_current_gate(current_stage_gate);
  int randomized_gate = ExperimentConfiguration::get_current_gate();

  if (randomized_gate == leftGate) {
    basal_gate_1 = centerGate;
    basal_gate_2 = rightGate;
    ExperimentConfiguration::set_current_basal_gate_1(basal_gate_1);
    ExperimentConfiguration::set_current_basal_gate_2(basal_gate_2);
  }
  else if (randomized_gate == centerGate) {
    basal_gate_1 = leftGate;
    basal_gate_2 = rightGate;
    ExperimentConfiguration::set_current_basal_gate_1(basal_gate_1);
    ExperimentConfiguration::set_current_basal_gate_2(basal_gate_2);
  }
  else if (randomized_gate == rightGate) {
    basal_gate_1 = leftGate;
    basal_gate_2 = centerGate;
    ExperimentConfiguration::set_current_basal_gate_1(basal_gate_1);
    ExperimentConfiguration::set_current_basal_gate_2(basal_gate_2);
  }
}

