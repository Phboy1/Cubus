#pragma once
#include <Arduino.h>
#include <AccelStepper.h>
#include "config.h"

class c_stepper
{
private:
    AccelStepper _motor;

    int _current_step = 0;
    int _target_step = 0;

    double _max_speed = 0.0;
    double _current_speed = 0;
    double _accel = 0;

    long _n = 0;
    unsigned long _last_step_us = 0;
    unsigned long _step_interval_us = 0;

    void _microstep(int dir);
    void _hold();
    bool _get_homing_ver();

    uint8_t _pins[4];

    bool _holding;

    int _current_microindex = 0;

public:
    c_stepper(uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4);
    void init();
    void home();
    void move_to(int microsteps);
    bool run();
    void set_max_speed(double speed);
    void set_accel(double accel);
    void release();
    int get_current_step();
};