#include "experiment_configuration.hpp"
#include "manual_settings.hpp"
#include "serial_prints.hpp"

#include <Arduino.h>

char pair_id [4];

void manual_configuration(){

    while (!Serial.available()){}
    String received_input_serial = Serial.readString();
    ExperimentConfiguration::set_mouse_id(atoi(received_input_serial.c_str()));
    Serial.println(received_input_serial);

    print_set_figures_and_sounds("Pair_X");
    while (!Serial.available()){}
    received_input_serial = Serial.readString();
    extracting_char_from_serial(received_input_serial);
    ExperimentConfiguration::set_pair_x_figure(converting_char_to_int(pair_id[0]));
    ExperimentConfiguration::set_pair_x_sound(converting_char_to_int(pair_id[1]));

    print_set_figures_and_sounds ("Pair_Y");
    while (!Serial.available()){}
    received_input_serial = Serial.readString();
    extracting_char_from_serial(received_input_serial);
    ExperimentConfiguration::set_pair_y_figure(converting_char_to_int(pair_id[0]));
    ExperimentConfiguration::set_pair_y_sound(converting_char_to_int(pair_id[1]));

    print_set_figures_and_sounds ("Pair_Z");
    while (!Serial.available()){}
    received_input_serial = Serial.readString();
    extracting_char_from_serial(received_input_serial);
    ExperimentConfiguration::set_pair_z_figure(converting_char_to_int(pair_id[0]));
    ExperimentConfiguration::set_pair_z_sound(converting_char_to_int(pair_id[1]));

    converting_all_int_pairs_figures_to_string();
    converting_all_int_pairs_sounds_to_string();
    print_all_configurations();
}

int converting_char_to_int(char character){
    int number;
    //number = atoi(&character);
    sscanf(&character, "%d", &number);
    return number;
}

void extracting_char_from_serial(String serial_input){
    for (unsigned int character = 0; character < serial_input.length(); character++){
        char extracted_char = serial_input[character];
        pair_id[character] = extracted_char;
    }
}