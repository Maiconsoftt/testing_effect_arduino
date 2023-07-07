#ifndef TAREFAS_GERAIS
#define TAREFAS_GERAIS
#include <Arduino.h>

void print_repertory_gate();
void open_repertory_training_gate (); //select a random gate to open 
void Repeat_Repertory_training (); //reinitialize the randomization
void End_Repertory_training (); //finish the repertory trainning

void randomize_gates_for_stages_and_print();
void mouse_conditions_creation(int info);
void execute_pairs_stage_1 ();
void execute_working_sound_stages();
void setting_all_outputs_to_low();
void execute_paired_stages();
void finalize_stage_trial();
void finalize_stage_attempt();

void stages(String monitor_input);

#endif
