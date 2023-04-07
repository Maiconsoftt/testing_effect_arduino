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
String current_repertory_gate = "";
String current_gate = "";


String converting_int_pair_figure_to_string(int randomized_figure){
    String string_figure = "";
    switch (randomized_figure){
        case 0:
            string_figure = "X_figure(0)";
            break;
        case 1:
            string_figure = "O_figure(1)";
            break;
        case 2:
            string_figure = "+_figure(2)"; //27bytes
            break;       
    }
    return string_figure;

}

String converting_int_pair_sound_to_string(int randomized_sound){
    String string_sound;
    switch (randomized_sound){
        case 0:
            string_sound = "3335Hz(0)";
            break;
        case 1:
            string_sound = "6670Hz(1)";
            break;
        case 2:
            string_sound = "13340Hz(2)"; //22 bytes
            break;       
    }
    return string_sound;
}

String converting_int_gate_to_string(int randomized_gate){
    String string_gate;
    switch (randomized_gate){
        case 1:
            string_gate = "leftGate";
            break;
        case 2:
            string_gate = "centerGate";
            break;
        case 3:
            string_gate = "rightGate";
            break;       
    }
    return string_gate;
}

void commands () { 
    Serial.println ("Type 'mouseID' to set mouse identification and pairs");
    Serial.println ("Type 'manual' to configure mouse pairs");
    Serial.println ("Type 'stage + number' to initialize stages (eg: 'stage0')");   
    Serial.println ("Type 'repeatRT' to repeat Repertory Training");
    Serial.println ("Type 'endRT' to finish Repertory Training"); 
    Serial.println ("Type 'EndStTrial' to finalize stage trial");  
    Serial.println ("Type 'EndStAttempt' to finalize any stage");
    Serial.println ("Type 'commands' to see this list again\n");
}

void print_counting(int repertory_counting, String seconds){
    char buff [35];
    Serial.println ("Place the mouse at the central compartment"); delay (1000);
    Serial.println ("Initializing in " + seconds); delay (1000);
    for (int counting = 1; counting <= repertory_counting; counting ++) {
        sprintf (buff, "Counting: %ds ...", counting);
        Serial.println (buff);
        delay (1000);
    }
}

void converting_all_int_pairs_figures_to_string(){
    pair_x_figure = converting_int_pair_figure_to_string(ExperimentConfiguration::pair_x_figure);
    pair_y_figure = converting_int_pair_figure_to_string(ExperimentConfiguration::pair_y_figure);
    pair_z_figure = converting_int_pair_figure_to_string(ExperimentConfiguration::pair_z_figure);
}

void converting_all_int_pairs_sounds_to_string(){
    pair_x_sound = converting_int_pair_sound_to_string(ExperimentConfiguration::pair_x_sound);
    pair_y_sound = converting_int_pair_sound_to_string(ExperimentConfiguration::pair_y_sound);
    pair_z_sound = converting_int_pair_sound_to_string(ExperimentConfiguration::pair_z_sound);
}

void converting_all_int_gates_to_string(){
    current_repertory_gate = converting_int_gate_to_string (ExperimentConfiguration::get_current_repertory_gate());
    current_gate = converting_int_gate_to_string(ExperimentConfiguration::get_current_gate());
}

void print_current_pairs(){
    char message[32];
    if (ExperimentConfiguration::get_current_pair() == 0){
        sprintf(message, "PairX: %s & %s", pair_x_figure.c_str(), pair_x_sound.c_str());
    }
    else if (ExperimentConfiguration::get_current_pair() == 1){
        sprintf(message, "PairY: %s & %s", pair_y_figure.c_str(), pair_y_sound.c_str());
    }
    else if (ExperimentConfiguration::get_current_pair() == 2){
        sprintf(message, "PairZ: %s & %s", pair_z_figure.c_str(), pair_z_sound.c_str());
    }
    Serial.println(message);
}

void print_all_configurations(){
    char message[150];
    sprintf(
        message, 
        "Mouse %d: \nX= %s & %s\nY= %s & %s\nZ= %s & %s",
        ExperimentConfiguration::get_mouse_id(), 
        pair_x_figure.c_str(), 
        pair_x_sound.c_str(),
        pair_y_figure.c_str(), 
        pair_y_sound.c_str(),
        pair_z_figure.c_str(),  
        pair_z_sound.c_str()
    );
    Serial.println(message);
}

void print_set_figures_and_sounds (String number){
    char pair [30];
    sprintf(pair, "Type %s ID", number.c_str());
    Serial.println(pair);
}

void print_repertory_training(){
    Serial.println ("Opening: " + current_repertory_gate);
}

void print_close_gate(){
    Serial.println ("Closing gate");
}

void print_received_input(String input){
    if (input == "60s" || input == "40s" || input == "5s"){
        Serial.println ("Wait " + input);
    }
    else if (input == "mouseID\r\n" || input == "manual\r\n"){
        Serial.println("Type Mouse ID");
    }
    else if (input ==  converting_int_gate_to_string(ExperimentConfiguration::get_current_gate()) 
    || input == converting_int_gate_to_string(ExperimentConfiguration::get_current_repertory_gate())){
        Serial.println ("Target gate = " + input);
    }    
    else{
        Serial.println(input);
    }
    
}