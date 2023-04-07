#ifndef TAREFAS_GERAIS
#define TAREFAS_GERAIS


void repertory_training (); //select a random gate to open 
void Repeat_Repertory_training (); //reinitialize the randomization
void End_Repertory_training (); //finish the repertory trainning

void mouse_conditions_creation(int info);
void execute_pairs_stage_1 ();
void execute_working_sound_stages();
void setting_all_outputs_to_low();
void execute_paired_stages();
void finalize_stage_trial();
void finalize_stage_attempt();

#endif
