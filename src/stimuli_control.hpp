#ifndef STIMULI_CONTROL_HPP__
#define STIMULI_CONTROL_HPP__
#include <Arduino.h>


void start_light_stimulus(int gate_name, int received_figure);
void start_sound_stimulus(int som_randomizado);
void start_basal_light_stimulus(int gate_name, int figure);

void start_target_light_basal_mode (int gate_name_1, int figure_1);

void open_target_gate(int randomized_gate);
void close_target_gate(int randomized_gate);
void open_all_gates();

void execute_paired_stimuli();
void execute_separated_stimuli();
void shutdown_all_displays();



#endif