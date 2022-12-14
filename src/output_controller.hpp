#ifndef OUTPUT_CONTROLLER_TEST_EFFECT_XP_H_
#define OUTPUT_CONTROLLER_TEST_EFFECT_XP_H_
#include <Servo.h>
#include <LedControl.h>
#include <Arduino.h>

void draw_xis();
void draw_ball();
void draw_plus();

void draw_basal_X ();
void draw_basal_ball();
void draw_basal_plus();

void Low_Frequency();
void Medium_Frequency();
void High_Frequency();

void defining_leds_to_show_figures ();
void shutdown_all_displays ();

#endif
