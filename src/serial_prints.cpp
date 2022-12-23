#include <Arduino.h>
#include <SoftwareSerial.h>

#include "serial_prints.hpp"
#include "experiment_configuration.hpp"


String pair_x_figure = "";
String pair_y_figure = "";
String pair_z_figure = "";
String pair_x_sound = "";
String pair_y_sound = "";
String pair_z_sound = "";


String converting_int_pair_figure_to_string(int id){
    String string_figure = "";
    switch (id){
        case 0:
            string_figure = "X_figure";
            break;
        case 1:
            string_figure = "O_figure";
            break;
        case 2:
            string_figure = "+_figure";
            break;       
    }
    return string_figure;

}

void converting_all_int_pairs_figures_to_string(){
    pair_x_figure = converting_int_pair_figure_to_string(ExperimentConfiguration::pair_x_figure);
    pair_y_figure = converting_int_pair_figure_to_string(ExperimentConfiguration::pair_y_figure);
    pair_z_figure = converting_int_pair_figure_to_string(ExperimentConfiguration::pair_z_figure);
}


String converting_int_pair_sound_to_string(int id){
    String string_sound;
    switch (id){
        case 0:
            string_sound = "100 Hz";
            break;
        case 1:
            string_sound = "750 Hz";
            break;
        case 2:
            string_sound = "2000 Hz";
            break;       
    }
    return string_sound;
}

void converting_all_int_pairs_sounds_to_string(){
    pair_x_sound = converting_int_pair_sound_to_string(ExperimentConfiguration::pair_x_sound);
    pair_y_sound = converting_int_pair_sound_to_string(ExperimentConfiguration::pair_y_sound);
    pair_z_sound = converting_int_pair_sound_to_string(ExperimentConfiguration::pair_z_sound);
}

void print_current_pairs (){
    char message[32];
    if (ExperimentConfiguration::get_current_pair() == 0){
        sprintf(message, "Figure: %s\nSound: %s", pair_x_figure.c_str(), pair_x_sound.c_str());
    }
    else if (ExperimentConfiguration::get_current_pair() == 1){
        sprintf(message, "Figure: %s\nSound: %s", pair_y_figure.c_str(), pair_y_sound.c_str());
    }
    else if (ExperimentConfiguration::get_current_pair() == 2){
        sprintf(message, "Figure: %s\nSound: %s", pair_z_figure.c_str(), pair_z_sound.c_str());
    }
    Serial.println(message);
}


void print_all_configurations(){
    char message[256];
    sprintf(
        message, 
        "FigureX: %s\tSoundX: %s\nFigureY: %s\tSoundY: %s\nFigureZ: %s\tSoundZ: %s", 
        pair_x_figure.c_str(), 
        pair_x_sound.c_str(),
        pair_y_figure.c_str(), 
        pair_y_sound.c_str(),
        pair_z_figure.c_str(),  
        pair_z_sound.c_str()
    );
    Serial.println(message);
}