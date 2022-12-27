#include <Arduino.h>
#include "experiment_configuration.hpp"


int ExperimentConfiguration::current_pair;
int ExperimentConfiguration::current_gate;
int ExperimentConfiguration::current_repertory_gate;
int ExperimentConfiguration::pair_x_sound;
int ExperimentConfiguration::pair_x_figure;
int ExperimentConfiguration::pair_y_sound;
int ExperimentConfiguration::pair_y_figure;
int ExperimentConfiguration::pair_z_sound;
int ExperimentConfiguration::pair_z_figure;
int ExperimentConfiguration::current_basal_gate_1;
int ExperimentConfiguration::current_basal_gate_2;
int ExperimentConfiguration::current_basal_figure_1;
int ExperimentConfiguration::current_basal_figure_2;

String ExperimentConfiguration::mouse_id = "";


void ExperimentConfiguration::set_mouse_id(String mouse_id){
        ExperimentConfiguration::mouse_id = mouse_id;
}

void ExperimentConfiguration::set_current_pair(int current_pair){
        ExperimentConfiguration::current_pair = current_pair;
}

void ExperimentConfiguration::set_current_gate(int current_gate){
        ExperimentConfiguration::current_gate = current_gate;
}

void ExperimentConfiguration::set_current_repertory_gate(int current_repertory_gate){
        ExperimentConfiguration::current_repertory_gate = current_repertory_gate;
}

void ExperimentConfiguration::set_current_basal_gate_1(int basal_gate_1){
        ExperimentConfiguration::current_basal_gate_1 = basal_gate_1;
}

void ExperimentConfiguration::set_current_basal_gate_2(int basal_gate_2){
		ExperimentConfiguration::current_basal_gate_2 = basal_gate_2;
}

void ExperimentConfiguration::set_current_basal_figure_1(int basal_figure_1){
		ExperimentConfiguration::current_basal_figure_1 = basal_figure_1;
}

void ExperimentConfiguration::set_current_basal_figure_2(int basal_figure_2){
		ExperimentConfiguration::current_basal_figure_2 = basal_figure_2;
}

int ExperimentConfiguration::get_light_symbol(){
	if (ExperimentConfiguration::current_pair == 0){
		return ExperimentConfiguration::pair_x_figure;
	}
	else if (ExperimentConfiguration::current_pair == 1){
	    return ExperimentConfiguration::pair_y_figure;
	}
	else if (ExperimentConfiguration::current_pair == 2){
		return ExperimentConfiguration::pair_z_figure;
	}
	else{
		return 4;
	}
}

int ExperimentConfiguration::get_sound(){
        if (ExperimentConfiguration::current_pair == 0){
            return ExperimentConfiguration::pair_x_sound;
    }
    else if (ExperimentConfiguration::current_pair == 1){
            return ExperimentConfiguration::pair_y_sound;
    }
    else if (ExperimentConfiguration::current_pair == 3){
            return ExperimentConfiguration::pair_z_sound;
    }
	else{
		return 4;
	}
}

String ExperimentConfiguration::get_mouse_id(){
	return ExperimentConfiguration::mouse_id;
}

int ExperimentConfiguration::get_current_gate(){
	return ExperimentConfiguration::current_gate;
}

int ExperimentConfiguration::get_current_pair(){
	return ExperimentConfiguration::current_pair;
}

int ExperimentConfiguration::get_pair_x_figure(){
	return ExperimentConfiguration::pair_x_figure;
}

int ExperimentConfiguration::get_pair_y_figure(){
	return ExperimentConfiguration::pair_y_figure;
}

int ExperimentConfiguration::get_pair_z_figure(){
	return ExperimentConfiguration::pair_z_figure;
}

int ExperimentConfiguration::get_pair_x_sound(){
	return ExperimentConfiguration::pair_x_sound;
}

int ExperimentConfiguration::get_pair_y_sound(){
	return ExperimentConfiguration::pair_y_sound;
}

int ExperimentConfiguration::get_pair_z_sound(){
	return ExperimentConfiguration::pair_z_sound;
}

int ExperimentConfiguration::get_current_repertory_gate(){
	return ExperimentConfiguration::current_repertory_gate;
}

int ExperimentConfiguration::get_current_basal_gate_1(){
	return ExperimentConfiguration::current_basal_gate_1;
}

int ExperimentConfiguration::get_current_basal_gate_2(){
	return ExperimentConfiguration::current_basal_gate_2;
}

int ExperimentConfiguration::get_current_basal_figure_1(){
	return ExperimentConfiguration::current_basal_figure_1;
}

int ExperimentConfiguration::get_current_basal_figure_2(){
	return ExperimentConfiguration::current_basal_figure_2;
}

void ExperimentConfiguration::set_pair_x_figure(int x_figure){
	ExperimentConfiguration::pair_x_figure = x_figure;
}

void ExperimentConfiguration::set_pair_y_figure(int y_figure){
	ExperimentConfiguration::pair_y_figure = y_figure;
}

void ExperimentConfiguration::set_pair_z_figure(int z_figure){
	ExperimentConfiguration::pair_z_figure = z_figure;
}

void ExperimentConfiguration::set_pair_x_sound(int x_sound){
	ExperimentConfiguration::pair_x_sound = x_sound;
}

void ExperimentConfiguration::set_pair_y_sound(int y_sound){
	ExperimentConfiguration::pair_y_sound = y_sound;
}

void ExperimentConfiguration::set_pair_z_sound(int z_sound){
	ExperimentConfiguration::pair_z_sound = z_sound;
}
