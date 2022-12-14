#include <Arduino.h>
#include "output_controller.hpp"
#include "experiment_configuration.hpp"
#include "gate_controller.hpp"
#include "parameters.hpp"


void start_light_stimulus(String gate_name, String received_figures){
    LedControl led_matrix_controller = get_led_array_by_gate_name(gate_name);

    if (received_figures == CONSTANT::Figure_X){
        draw_X(led_matrix_controller, PARAMETER::MAX_INTENSITY_VALUE);
    }
    else if (received_figures == "Figure_O"){
        draw_ball(led_matrix_controller, PARAMETER::MAX_INTENSITY_VALUE); 
    }
    else if (received_figures == "Figure_+"){
        draw_plus(led_matrix_controller, PARAMETER::MAX_INTENSITY_VALUE);
    }
}

void start_all_lights_basal_mode (){
    LedControl led_matrix_controller = get_led_array_by_gate_name("CenterGate");
    
    draw_ball(led_matrix_controller, PARAMETER::MAX_INTENSITY_VALUE); 
    draw_plus(led_matrix_controller, PARAMETER::MAX_INTENSITY_VALUE);
    draw_X (led_matrix_controller, PARAMETER::MAX_INTENSITY_VALUE);
}

void start_basal_light_stimulus(String gate_name, String figure){
    LedControl led_matrix_controller = get_led_array_by_gate_name(gate_name);
    
    if (figure == "Figure_X"){  
        draw_X (led_matrix_controller, PARAMETER::MIN_INTENSITY_VALUE);
    }
    else if (figure == "Figure_O"){
        draw_ball (led_matrix_controller, PARAMETER::MIN_INTENSITY_VALUE);
    }
    else if (figure == "Figure_+"){
        draw_plus (led_matrix_controller, PARAMETER::MIN_INTENSITY_VALUE);
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
        Gates::open_left_gate ();
    }
       else if (randomized_gate == "CenterGate"){
        Gates::open_center_gate();
    }
        else if (randomized_gate == "Right Gate"){
        Gates::open_right_gate();
    }
}

void close_target_gate(String randomized_gate){
    if (randomized_gate == "Left Gate"){
        Gates::close_left_gate ();
    }
       else if (randomized_gate == "CenterGate"){
        Gates::close_center_gate();
    }
        else if (randomized_gate == "Right Gate"){
        Gates::close_right_gate();
    }
}


void execute_paired_stimuli(){
    start_all_lights_basal_mode ();

    for (int a = 0; a < 5; a++){
        start_basal_light_stimulus(
            ExperimentConfiguration::get_current_basal_figure_1(), 
            ExperimentConfiguration::get_current_basal_figure_1()
        );
        start_basal_light_stimulus(
            ExperimentConfiguration::get_current_basal_figure_2(), 
            ExperimentConfiguration::get_current_basal_figure_2()
        );
        start_light_stimulus(
            ExperimentConfiguration::get_current_gate(), 
            ExperimentConfiguration::get_light_symbol()
        );
        start_sound_stimulus(ExperimentConfiguration::get_sound());
    }
    delay(5);
}

void execute_separated_stimuli(){
    start_all_lights_basal_mode();
    for (int a = 0; a < 6; a++){
        start_sound_stimulus(ExperimentConfiguration::get_sound());
        delay (10);
    }
    Gates::open_all_gates();  
    delay(5);
}
