#include <Arduino.h>
#include "experiment_configuration.hpp"


String ExperimentConfiguration::current_pair = "";
String ExperimentConfiguration::current_gate = "";
String ExperimentConfiguration::current_repertory_gate = "";
String ExperimentConfiguration::pair_x_sound = "";
String ExperimentConfiguration::pair_x_figure = "";
String ExperimentConfiguration::pair_y_sound = "";
String ExperimentConfiguration::pair_y_figure = "";
String ExperimentConfiguration::pair_z_sound = "";
String ExperimentConfiguration::pair_z_figure = "";
String ExperimentConfiguration::current_basal_gate_1 = "";
String ExperimentConfiguration::current_basal_gate_2 = "";
String ExperimentConfiguration::current_basal_figure_1 = "";
String ExperimentConfiguration::current_basal_figure_2 = "";


void ExperimentConfiguration::set_current_pair(String current_pair){
        ExperimentConfiguration::current_pair = current_pair;
}

void ExperimentConfiguration::set_current_gate(String current_gate){
        ExperimentConfiguration::current_gate = current_gate;
}

void ExperimentConfiguration::set_current_repertory_gate(String current_repertory_gate){
        ExperimentConfiguration::current_repertory_gate = current_repertory_gate;
}

void ExperimentConfiguration::set_current_basal_gate_1(String basal_gate_1){
        ExperimentConfiguration::current_basal_gate_1 = basal_gate_1;
}

void ExperimentConfiguration::set_current_basal_gate_2(String basal_gate_2){
		ExperimentConfiguration::current_basal_gate_2 = basal_gate_2;
}

void ExperimentConfiguration::set_current_basal_figure_1(String basal_figure_1){
		ExperimentConfiguration::current_basal_figure_1 = basal_figure_1;
}

void ExperimentConfiguration::set_current_basal_figure_2(String basal_figure_2){
		ExperimentConfiguration::current_basal_figure_2 = basal_figure_2;
}

String ExperimentConfiguration::get_light_symbol(){
	if (ExperimentConfiguration::current_pair == "0"){
		return ExperimentConfiguration::pair_x_figure;
	}
	else if (ExperimentConfiguration::current_pair == "1"){
	    return ExperimentConfiguration::pair_y_figure;
	}
	else if (ExperimentConfiguration::current_pair == "2"){
		return ExperimentConfiguration::pair_z_figure;
	}
	else{
		return "";
	}
}

String ExperimentConfiguration::get_sound(){
        if (ExperimentConfiguration::current_pair == "0"){
            return ExperimentConfiguration::pair_x_sound;
    }
    else if (ExperimentConfiguration::current_pair == "1"){
            return ExperimentConfiguration::pair_y_sound;
    }
    else if (ExperimentConfiguration::current_pair == "2"){
            return ExperimentConfiguration::pair_z_sound;
    }
	else{
		return "";
	}
}

String ExperimentConfiguration::get_current_gate(){
	return ExperimentConfiguration::current_gate;
}

String ExperimentConfiguration::get_current_repertory_gate(){
	return ExperimentConfiguration::current_repertory_gate;
}

String ExperimentConfiguration::get_current_basal_gate_1(){
	return ExperimentConfiguration::current_basal_gate_1;
}

String ExperimentConfiguration::get_current_basal_gate_2(){
	return ExperimentConfiguration::current_basal_gate_2;
}

String ExperimentConfiguration::get_current_basal_figure_1(){
	return ExperimentConfiguration::current_basal_figure_1;
}

String ExperimentConfiguration::get_current_basal_figure_2(){
	return ExperimentConfiguration::current_basal_figure_2;
}

void ExperimentConfiguration::set_pair_x_figure(String new_figure){
	ExperimentConfiguration::pair_x_figure = new_figure;
}

void ExperimentConfiguration::set_pair_y_figure(String new_figure){
	ExperimentConfiguration::pair_y_figure = new_figure;
}

void ExperimentConfiguration::set_pair_z_figure(String new_figure){
	ExperimentConfiguration::pair_z_figure = new_figure;
}

void ExperimentConfiguration::set_pair_x_sound(String new_sound){
	ExperimentConfiguration::pair_x_sound = new_sound;
}

void ExperimentConfiguration::set_pair_y_sound(String new_sound){
	ExperimentConfiguration::pair_y_sound = new_sound;
}

void ExperimentConfiguration::set_pair_z_sound(String new_sound){
	ExperimentConfiguration::pair_z_sound = new_sound;
}
