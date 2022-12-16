#include <Arduino.h>
#include <Servo.h>
#include "constants.hpp"
#include "gate_controller.hpp"


Servo leftGate = Servo(); //gate 1 = left arm and gate
Servo centerGate = Servo(); //gate 2 = central arm and gate
Servo rightGate = Servo(); //gate 3 = right arm and gate


void Gates::setup_gates(){

    leftGate.attach(PARAMETER::LEFT_GATE_PIN); 
    leftGate.write(PARAMETER::SERVO_INITIAL_POSITION); //servo 1 to digital output pin 2 - gate 1 = left arm and gate
    centerGate.attach(PARAMETER::CENTER_GATE_PIN); 
    centerGate.write(PARAMETER::SERVO_INITIAL_POSITION); // servo 2 to digital output pin 3 - gate 2 = central arm and gate
    rightGate.attach(PARAMETER::CENTER_GATE_PIN); 
    rightGate.write(PARAMETER::SERVO_INITIAL_POSITION); // servo 3 to digital output pin 4 - gate 3 = right arm and gate
}

void Gates::open_all_gates() {
  for (int angulo = 0; angulo <= 180; angulo += 1) { // Comando que muda a posição do servo de 0 para 180°
    rightGate.write(angulo); // Comando para angulo específico
    centerGate.write(angulo);
    leftGate.write(angulo);
    delay(8);
  }
}

void Gates::close_all_gates() {
  for (int angulo = 180; angulo >= 1; angulo -= 1) { // Comando que muda a posição do servo de 180 para 0°
    rightGate.write(angulo); // Comando para angulo específico
    centerGate.write(angulo);
    leftGate.write(angulo);
    delay(8);
  }
}

void Gates::open_gate_by_name(String gate_name){
    if (gate_name == CONSTANTS::gates_array[0]) {
        for (int angulo; angulo <= 150; angulo += 1) { // Comando que muda a posição do servo de 0 para 180°
        leftGate.write(angulo); // Comando para angulo específico
        delay(8);
        }  
    }
    else if (gate_name == CONSTANTS::gates_array [1]) {
        for (int angulo; angulo <= 150; angulo += 1) { // Comando que muda a posição do servo de 0 para 180°
        centerGate.write(angulo); // Comando para angulo específico
        delay(8);
        }
    }
    else if (gate_name == CONSTANTS::gates_array [2]) {
        for (int angulo; angulo <= 150; angulo += 1) { // Comando que muda a posição do servo de 0 para 180°
        rightGate.write(angulo); // Comando para angulo específico
        delay(8);
        }
    }
}

void Gates::close_gate_by_name(String gate_name){
    if (gate_name == CONSTANTS::gates_array[0]) {
        for (int angulo = 150; angulo >= 1; angulo -= 1) { // Comando que muda a posição do servo de 180 para 0°
        leftGate.write(angulo); // Comando para angulo específico
        delay(8);
        }
    }
    else if (gate_name == CONSTANTS::gates_array[1]) {
        for (int angulo = 150; angulo >= 1; angulo -= 1) { // Comando que muda a posição do servo de 180 para 0°
        centerGate.write(angulo); // Comando para angulo específico
        delay(8);
        }
    }
    else if (gate_name == CONSTANTS::gates_array[2]) {
        for (int angulo = 150; angulo >= 1; angulo -= 1) { // Comando que muda a posição do servo de 180 para 0°
        rightGate.write(angulo); // Comando para angulo específico
        delay(8);
        }
    }
}