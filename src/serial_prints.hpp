#ifndef _SERIAL_PRINTS_HPP_
#define _SERIAL_PRINTS_HPP_
#include <Arduino.h>


void commands();

void print_repertory_training_counting();
void print_current_pairs ();

void converting_all_int_pairs_figures_to_string();
void converting_all_int_pairs_sounds_to_string();
void converting_all_int_gates_to_string();

void print_all_configurations();
void print_set_figures_and_sounds (String number);
void print_repertory_trainning ();
void print_close_gate();
void print_current_gate();
void print_wait (String time);
void print_end_close_gate ();
void print_mouse_message();
void print_received_serial_input(String input);

#endif