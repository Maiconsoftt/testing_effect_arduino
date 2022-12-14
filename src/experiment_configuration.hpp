#ifndef EXPERIMENT_CONFIGURATION_HPP__
#define EXPERIMENT_CONFIGURATION_HPP__
#include <Arduino.h>


class ExperimentConfiguration{
    public: 
        
        static String current_pair;
        static String current_gate;
        static String current_repertory_gate;
        static String pair_x_sound;
        static String pair_x_figure;
        static String pair_y_sound;
        static String pair_y_figure;
        static String pair_z_sound;
        static String pair_z_figure;
        static String randomized_gate;
        static String random_repertory_gate;
        static String current_basal_gate_1;
        static String current_basal_gate_2;
        static String current_basal_figure_1;
        static String current_basal_figure_2;

        static void set_current_pair(String current_pair);
        static void set_pair_x_sound(String new_pair);
        static void set_pair_y_sound(String new_pair);
        static void set_pair_z_sound(String new_pair);
        static void set_pair_x_figure(String new_pair);
        static void set_pair_y_figure(String new_pair);
        static void set_pair_z_figure(String new_pair);
        static void set_current_gate(String gate);
        static void set_current_repertory_gate(String repertory_gate);
        static void set_current_basal_gate_1(String basal_gate_1);
        static void set_current_basal_gate_2(String basal_gate_2);
        static void set_current_basal_figure_1(String basal_figure_2);
        static void set_current_basal_figure_2(String basal_figure_2);
        
        
        static String get_light_symbol();
        static String get_sound();
        static String get_current_gate();
        static String get_current_repertory_gate();
        static String get_current_basal_gate_1();
        static String get_current_basal_gate_2();
        static String get_current_basal_figure_1();
        static String get_current_basal_figure_2();
};

#endif
