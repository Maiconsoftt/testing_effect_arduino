#ifndef __PARAMETERS_HPP__
#define __PARAMETERS_HPP__
#include <Arduino.h>

namespace PARAMETER{
/*
SYSTEM PARAMETERS
*/

    const int MAX_INTENSITY_VALUE=13;
    const int MIN_INTENSITY_VALUE=1;

    const int LEFT_GATE_PIN = 2;
    const int CENTER_GATE_PIN = 3;
    const int RIGHT_GATE_PIN = 4;

    const int SERVO_INITIAL_POSITION = 0;

/*
EXPERIMENT PARAMETERS
*/

    const int INTERVAL_BETWEEN_TRIALS=40000;
    const int INTERVAL_BETWEEN_RODENTS=60000;
    const int NUMBER_OF_STAGES_TRIALS=7;
    const int NUMBER_OF_STAGES_REPEATS=5;

}
namespace CONSTANTS {

    const String Figure_X = "Figure_X";

    const char figures [3][9] = {"Figure_X", "Figure_O", "Figure_+"}; 
    const char sounds  [3][7] = {"100 Hz", "750 Hz", "2000Hz"};
    const char gates_array   [3][11] = {"Left Gate", "CenterGate", "Right Gate"};
}
#endif