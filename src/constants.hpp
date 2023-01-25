#ifndef __PARAMETERS_HPP__
#define __PARAMETERS_HPP__


namespace PARAMETER{
/*
SYSTEM PARAMETERS
*/

    const int MAX_INTENSITY_VALUE=13;
    const int MIN_INTENSITY_VALUE=1;

    const int LEFT_GATE_PIN = 3;
    const int CENTER_GATE_PIN = 4;
    const int RIGHT_GATE_PIN = A0;

    const int SERVO_INITIAL_POSITION = 0;

/*
EXPERIMENT PARAMETERS
*/

    const long int INTERVAL_BETWEEN_TRIALS=4000;
    const long int INTERVAL_BETWEEN_RODENTS=6000;
    const int INTERVAL_BEFORE_ATTEMPT=6;
    const int NUMBER_OF_STAGES_TRIALS=7;
    const int NUMBER_OF_STAGES_REPEATS=5;

}
namespace CONSTANTS {

    const int buzzer = 2;

    const int Figure_X = 0;
    const int Figure_Y = 1;
    const int Figure_Z = 2;

    const int X_sound = 0;
    const int Y_sound = 1;
    const int Z_sound = 2;

    const int leftGate = 1;
    const int centerGate = 2;
    const int rightGate = 3;

    const int gates_array[] = {leftGate, centerGate, rightGate};

    const int ALL_GATES = 4;

}
#endif