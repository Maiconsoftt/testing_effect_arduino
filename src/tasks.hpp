#ifndef TAREFAS_GERAIS
#define TAREFAS_GERAIS
#include <Arduino.h>
#include <Servo.h>

extern char figures [3][9];
extern char sounds  [3][7];
extern char gates_array  [3][11];

// creating servos' objects
extern Servo leftGate; //gate 1 = left arm and gate
extern Servo centerGate; //gate 2 = central arm and gate
extern Servo rightGate; //gate 3 = right arm and gate

void commands (); //remainder about the list of commands accepted by the serial monitor and their functions
void randomize_pairs_sounds_and_figures(); //create X, Y and Z pairs to the mouse at the maze
void repertory_trainning (); //select a random gate to open 
void Repeat_Repertory_trainning (); //reinitialize the randomization
void End_Repertory_trainning (); //finish the repertory trainning
void Randomize_gates_for_stages ();

void execute_pairs_stage_1 ();
void execute_working_sound_stage_2();

// routines that open or close servos'/gates 
void open_left_gate();
void close_left_gate();
void open_center_gate();
void close_center_gate();
void open_right_gate();
void close_right_gate();

#endif
