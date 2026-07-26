#pragma once
#include <Arduino.h>
#include <AccelStepper.h>
#include "config.h"

class c_stepper
{
private:
    AccelStepper _motor;
    uint8_t _pins[4];

    bool _get_homing_ver();

public:
    c_stepper(uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4);

    void init();
    void home();
    void move_to(int steps);
    bool run();
    void set_max_speed(double speed);
    void set_accel(double accel);
    void release();
};