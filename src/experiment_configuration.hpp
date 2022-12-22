#ifndef EXPERIMENT_CONFIGURATION_HPP__
#define EXPERIMENT_CONFIGURATION_HPP__
#include <Arduino.h>


class ExperimentConfiguration{
    public: 
        
        static int current_pair;
        static int current_gate;
        static int current_repertory_gate;
        static int pair_x_sound;
        static int pair_x_figure;
        static int pair_y_sound;
        static int pair_y_figure;
        static int pair_z_sound;
        static int pair_z_figure;
        static int randomized_gate;
        static int random_repertory_gate;
        static int current_basal_gate_1;
        static int current_basal_gate_2;
        static int current_basal_figure_1;
        static int current_basal_figure_2;

        static void set_current_pair(int current_pair);
        static void set_pair_x_sound(int x_sound);
        static void set_pair_y_sound(int y_sound);
        static void set_pair_z_sound(int z_sound);
        static void set_pair_x_figure(int x_figure);
        static void set_pair_y_figure(int y_figure);
        static void set_pair_z_figure(int z_figure);
        static void set_current_gate(int current_gate);
        static void set_current_repertory_gate(int current_repertory_gate);
        static void set_current_basal_gate_1(int basal_gate_1);
        static void set_current_basal_gate_2(int basal_gate_2);
        static void set_current_basal_figure_1(int basal_figure_2);
        static void set_current_basal_figure_2(int basal_figure_2);
        
        
        static int get_light_symbol();
        static int get_sound();
        static int get_current_pair();
        static int get_current_gate();
        static int get_pair_x_figure();
        static int get_pair_y_figure();
        static int get_pair_z_figure();
        static int get_pair_x_sound();
        static int get_pair_y_sound();
        static int get_pair_z_sound();
        static int get_current_repertory_gate();
        static int get_current_basal_gate_1();
        static int get_current_basal_gate_2();
        static int get_current_basal_figure_1();
        static int get_current_basal_figure_2();
};

#endif
