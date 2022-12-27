#include "experiment_configuration.hpp"
#include "manual_settings.hpp"
#include "serial_prints.hpp"

#include <Arduino.h>

void manual_configuration(){

    String received_input_serial;

    print_mouse_message();
    while (Serial.available () == 0) {}
    received_input_serial = Serial.readString();
    ExperimentConfiguration::set_mouse_id(received_input_serial);
    print_received_serial_input(received_input_serial); 

    print_set_figures_and_sounds ("Pair_X figure");
    while (Serial.available() == 0){}
    received_input_serial = Serial.readString();
    ExperimentConfiguration::set_pair_x_figure(received_input_serial.toInt());
    print_received_serial_input(received_input_serial);

    print_set_figures_and_sounds ("Pair_Y figure");
    while (!Serial.available()){}
    received_input_serial = Serial.readString();
    ExperimentConfiguration::set_pair_y_figure(received_input_serial.toInt());
    print_received_serial_input(received_input_serial);

    print_set_figures_and_sounds ("Pair_Z figure");
    while (Serial.available() == 0){}
    received_input_serial = Serial.readString();
    ExperimentConfiguration::set_pair_z_figure(received_input_serial.toInt());
    print_received_serial_input(received_input_serial);

    print_set_figures_and_sounds ("Pair_X sound");
    while (Serial.available() == 0){}
    received_input_serial = Serial.readString();
    ExperimentConfiguration::set_pair_x_sound(received_input_serial.toInt());
    print_received_serial_input(received_input_serial);

    print_set_figures_and_sounds ("Pair_Y sound");
    while (Serial.available() == 0){}
    received_input_serial = Serial.readString();
    ExperimentConfiguration::set_pair_y_sound(received_input_serial.toInt());
    print_received_serial_input(received_input_serial);

    print_set_figures_and_sounds ("Pair_Z sound");
    while (Serial.available() == 0){}
    received_input_serial = Serial.readString();
    ExperimentConfiguration::set_pair_z_sound(received_input_serial.toInt());
    print_received_serial_input(received_input_serial);

    converting_all_int_pairs_figures_to_string();
    converting_all_int_pairs_sounds_to_string();
    print_all_configurations();
}