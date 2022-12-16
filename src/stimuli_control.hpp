#ifndef STIMULI_CONTROL_HPP__
#define STIMULI_CONTROL_HPP__
#include <Arduino.h>


void start_light_stimulus(String gate_name, String received_figure);
void start_sound_stimulus(String som_randomizado);
void start_basal_light_stimulus(String gate_name, String basal_light_1);
void start_all_lights_basal_mode ();

void open_target_gate(String randomized_gate);
void close_target_gate(String randomized_gate);
void open_all_gates();

void execute_paired_stimuli();
void execute_separated_stimuli();
void shutdown_all_displays();

#endif