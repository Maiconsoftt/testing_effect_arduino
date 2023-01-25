#include <Arduino.h>
#include <Servo.h>
#include "constants.hpp"
#include "gate_controller.hpp"

Servo leftGate = Servo(); //gate 1 = left arm and gate
Servo centerGate = Servo(); //gate 2 = central arm and gate
Servo rightGate = Servo(); //gate 3 = right arm and gate


void Gates::setup_gates(){
    
    using namespace PARAMETER;
    
    pinMode(RIGHT_GATE_PIN, OUTPUT);

    leftGate.attach(LEFT_GATE_PIN); 
    leftGate.write(SERVO_INITIAL_POSITION); //servo 1 to digital output pin 2 - gate 1 = left arm and gate
    centerGate.attach(CENTER_GATE_PIN); 
    centerGate.write(SERVO_INITIAL_POSITION); // servo 2 to digital output pin 3 - gate 2 = central arm and gate
    rightGate.attach(RIGHT_GATE_PIN); 
    rightGate.write(SERVO_INITIAL_POSITION); // servo 3 to digital output pin 4 - gate 3 = right arm and gate
}

void Gates::open_all_gates() {
    for (int angulo = 0; angulo <= 140; angulo += 1) { 
        rightGate.write(angulo); 
        centerGate.write(angulo);
        leftGate.write(angulo);
        delay(15);
  }
}

void Gates::open_gate_by_name(int gate_name){
    if (gate_name == CONSTANTS::leftGate) {
        for (int angulo = 0; angulo <= 150; angulo += 1) { 
        leftGate.write(angulo); 
        delay(10);
        }
        for (int angulo = 150; angulo >= 140; angulo -= 1){
        leftGate.write(angulo);
        delay(10);
        }
    }
    else if (gate_name == CONSTANTS::centerGate) {
        for (int angulo = 0; angulo <= 150; angulo += 1) {
        centerGate.write(angulo);
        delay(10);
        }
    }   
    else if (gate_name == CONSTANTS::rightGate) {
        for (int angulo = 0; angulo <= 150; angulo += 1) { 
        rightGate.write(angulo);
        delay(10);
        }
    }
}

void Gates::close_gate_by_name(int gate_name){
    if (gate_name == CONSTANTS::gates_array[0]) {
        for (int angulo = 140; angulo >= 1; angulo -= 1) { 
        leftGate.write(angulo); 
        delay(10);
        }
    }
    else if (gate_name == CONSTANTS::gates_array[1]) {
        for (int angulo = 140; angulo >= 1; angulo -= 1) { 
        centerGate.write(angulo); 
        delay(10);
        }
    }
    else if (gate_name == CONSTANTS::gates_array[2]) {
        for (int angulo = 140; angulo >= 1; angulo -= 1) { 
        rightGate.write(angulo); 
        delay(10);
        }
    }
    else if (gate_name == 4){
        for (int angulo = 140; angulo >= 1; angulo -= 1) { 
        leftGate.write(angulo);
        centerGate.write(angulo);
        rightGate.write(angulo); 
        delay(12);
        }
    }
}