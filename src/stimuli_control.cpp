#include <Arduino.h>
#include "leds_controller.hpp"
#include "experiment_configuration.hpp"
#include "gate_controller.hpp"
#include "constants.hpp"
#include "sounds.hpp"


void start_light_stimulus(int gate_number, int received_figures){
    LedControl led_matrix_controller = get_led_array_by_gate_name(gate_number);

    if (received_figures == 0){
        draw_X(led_matrix_controller, PARAMETER::MAX_INTENSITY_VALUE);
    }
    else if (received_figures == 1){
        draw_ball(led_matrix_controller, PARAMETER::MAX_INTENSITY_VALUE); 
    }
    else if (received_figures == 2){
        draw_plus(led_matrix_controller, PARAMETER::MAX_INTENSITY_VALUE);
    }
}

void start_basal_light_stimulus(int gate_number, int figure){
    LedControl led_matrix_controller = get_led_array_by_gate_name(gate_number);
    
    if (figure == 0){  
        draw_X (led_matrix_controller, PARAMETER::MIN_INTENSITY_VALUE);
    }
    else if (figure == 1){
        draw_ball (led_matrix_controller, PARAMETER::MIN_INTENSITY_VALUE);
    }
    else if (figure == 2){
        draw_plus (led_matrix_controller, PARAMETER::MIN_INTENSITY_VALUE);
    }
}

void start_light_1_basal_mode (int first_gate_number, int first_figure){
    start_basal_light_stimulus (first_gate_number, first_figure); 
}
void start_light_2_basal_mode (int second_gate_number, int second_figure){
    start_basal_light_stimulus (second_gate_number, second_figure); 
}
void start_light_3_basal_mode (int third_gate_number, int third_figure){
    start_basal_light_stimulus (third_gate_number, third_figure); 
}


void start_sound_stimulus(int randomized_sound){
    if (randomized_sound == 0){
        execute_sound(3335);
    }
    else if (randomized_sound == 1){
        execute_sound(6670);
    }
    else if (randomized_sound == 2){
        execute_sound(13340);
    }
}

void open_target_gate(int randomized_gate){
    if (randomized_gate == 1){
        Gates::open_gate_by_name (randomized_gate);
    }
       else if (randomized_gate == 2){
        Gates::open_gate_by_name (randomized_gate);
    }
        else if (randomized_gate == 3){
        Gates::open_gate_by_name (randomized_gate);
    }
}

void close_target_gate(int randomized_gate){
    if (randomized_gate == 1){
        Gates::close_gate_by_name (randomized_gate);
    }
       else if (randomized_gate == 2){
        Gates::close_gate_by_name (randomized_gate);
    }
        else if (randomized_gate == 3){
        Gates::close_gate_by_name (randomized_gate);
    }
}

void execute_paired_stimuli(){
    
    start_basal_light_stimulus(
        ExperimentConfiguration::get_current_gate(), 
        ExperimentConfiguration::get_light_symbol()
    );
    start_basal_light_stimulus(
        ExperimentConfiguration::get_current_basal_gate_1(), 
        ExperimentConfiguration::get_current_basal_figure_1()
    );
    start_basal_light_stimulus(
        ExperimentConfiguration::get_current_basal_gate_2(), 
        ExperimentConfiguration::get_current_basal_figure_2()
    );

    delay (2000);

    for (int a = 1; a <= 5; a++){
        start_light_stimulus(
            ExperimentConfiguration::get_current_gate(), 
            ExperimentConfiguration::get_light_symbol()
        );

        start_sound_stimulus(ExperimentConfiguration::get_sound());

        delay (1000);

        start_basal_light_stimulus (
            ExperimentConfiguration::get_current_gate(), 
            ExperimentConfiguration::get_light_symbol()
        );

        stop_sound_execution();

        delay (1000);
    }
    delay(5);
}

void execute_separated_stimuli(){

    start_basal_light_stimulus (
        ExperimentConfiguration::get_current_basal_gate_1(), 
        ExperimentConfiguration::get_current_basal_figure_1()
    );
    start_basal_light_stimulus (
        ExperimentConfiguration::get_current_basal_gate_2(), 
        ExperimentConfiguration::get_current_basal_figure_2()
    );
    start_basal_light_stimulus (
        ExperimentConfiguration::get_current_gate(), 
        ExperimentConfiguration::get_light_symbol()
    );

    delay (2000);

    for (int a = 1; a <= 5; a++){
        start_sound_stimulus(ExperimentConfiguration::get_sound());
        delay (1000);
        stop_sound_execution();
        delay (1000);
    }
    delay (5);
}
