#include <Arduino.h>
#include "output_controller.hpp"
#include "experiment_configuration.hpp"
#include "tasks.hpp"

void start_light_stimulus(String received_figures){
    if (received_figures == "Figure_X"){
        draw_xis();
    }
    else if (received_figures == "Figure_O"){
        draw_ball(); 
    }
    else if (received_figures == "Figure_+"){
        draw_plus();
    }
}

void start_all_lights_basal_mode (){
    draw_basal_ball();
    draw_basal_plus();
    draw_basal_X ();
}

void start_basal_light_stimulus_1 (String basal_figure_1){
    if (basal_figure_1 == "Figure_X"){
        draw_basal_X ();
    }
    else if (basal_figure_1 == "Figure_O"){
        draw_basal_ball ();
    }
    else if (basal_figure_1 == "Figure_+"){
        draw_basal_plus ();
    }
}

void start_basal_light_stimulus_2 (String basal_figure_2){
    if (basal_figure_2 == "Figure_X"){
        draw_basal_X ();
    }
    else if (basal_figure_2 == "Figure_O"){
        draw_basal_ball ();
    }
    else if (basal_figure_2 == "Figure_+"){
        draw_basal_plus ();
    }
}

void start_sound_stimulus(String randomized_sound){
    if (randomized_sound == "100 Hz"){
        Low_Frequency();
    }
    else if (randomized_sound == "750 Hz"){
        Medium_Frequency();
    }
    else if (randomized_sound == "2000Hz"){
        High_Frequency();
    }
}

void open_target_gate(String randomized_gate){
    if (randomized_gate == "Left Gate"){
        open_left_gate ();
    }
       else if (randomized_gate == "CenterGate"){
        open_center_gate();
    }
        else if (randomized_gate == "Right Gate"){
        open_right_gate();
    }
}

void close_target_gate(String randomized_gate){
    if (randomized_gate == "Left Gate"){
        close_left_gate ();
    }
       else if (randomized_gate == "CenterGate"){
        close_center_gate();
    }
        else if (randomized_gate == "Right Gate"){
        close_right_gate();
    }
}

void open_all_gates(){
    open_all_gates();
}

void shutdown_all_displays (){
    shutdown_all_displays();
}

void execute_paired_stimuli(){
    start_all_lights_basal_mode ();
    start_light_stimulus(ExperimentConfiguration::get_light_symbol());
    start_sound_stimulus(ExperimentConfiguration::get_sound());
    start_basal_light_stimulus_1(ExperimentConfiguration::get_current_basal_figure_1());
    start_basal_light_stimulus_2(ExperimentConfiguration::get_current_basal_figure_2());

    delay(5);
}

void execute_separated_stimuli(){
    start_all_lights_basal_mode();
    for (int a = 0; a < 6; a++){
        start_sound_stimulus(ExperimentConfiguration::get_sound());
        delay (10);
    }
    open_all_gates();  
    delay(5);
}
