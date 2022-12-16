#ifndef _GATE_CONTROLLER_HPP_
#define _GATE_CONTROLLER_HPP_

#include <Arduino.h>

namespace Gates {

    void setup_gates();
    void open_left_gate();
    void close_left_gate();
    void open_center_gate();
    void close_center_gate();
    void open_right_gate();
    void close_right_gate();
    void open_all_gates();
    void close_all_gates();
    void open_gate_by_name(String gate_name);
    void close_gate_by_name(String gate_name);
}

#endif