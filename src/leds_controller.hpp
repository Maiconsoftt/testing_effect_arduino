#ifndef OUTPUT_CONTROLLER_TEST_EFFECT_XP_H_
#define OUTPUT_CONTROLLER_TEST_EFFECT_XP_H_
#include <Servo.h>
#include <LedControl.h>
#include <Arduino.h>

void draw_X(LedControl lc,  int intensity);
void draw_ball(LedControl lc,  int intensity);
void draw_plus(LedControl lc,  int intensity);

void controllers_setup();
void defining_leds_to_show_figures ();
void shutdown_all_displays ();

LedControl get_led_array_by_gate_name(int gate_name);


#endif
