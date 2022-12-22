#include <Arduino.h>
#include <SoftwareSerial.h>

#include "experiment_configuration.hpp"
#include "randomizations.hpp"

String pair_x_figure, pair_y_figure, pair_z_figure;
String pair_x_sound, pair_y_sound, pair_z_sound;

void converting_int_pairs_figures_to_string(){
    if (ExperimentConfiguration::get_pair_x_figure() == 0){
        pair_x_figure = "X_Figure ";
    }
    else if (ExperimentConfiguration::get_pair_y_figure() == 1){
        pair_x_figure = "O_Figure ";
    }
    else if (ExperimentConfiguration::get_pair_z_figure() == 2){
        pair_x_figure = "+_Figure ";
    }
}

void converting_int_pairs_sounds_to_string(){
    if (ExperimentConfiguration::get_pair_x_sound() == 0){
        pair_x_sound = "and 100 Hz";
    }
    else if (ExperimentConfiguration::get_pair_y_sound() == 1){
        pair_y_sound = "and 750 Hz";
    }
    else if (ExperimentConfiguration::get_pair_z_sound() == 2){
        pair_z_sound = "and 2000 Hz";
    }
}

void print_pairs (){
    if (ExperimentConfiguration::get_current_pair() == 0){
        Serial.print (pair_x_figure);
        Serial.println (pair_x_sound);
    }
    else if (ExperimentConfiguration::get_current_pair() == 1){
        Serial.print (pair_y_figure);
        Serial.println (pair_y_sound);
    }
    else if (ExperimentConfiguration::get_current_pair() == 2){
        Serial.print (pair_z_figure);
        Serial.println (pair_z_sound);
    }
}