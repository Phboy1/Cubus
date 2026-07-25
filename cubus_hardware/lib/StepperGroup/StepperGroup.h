#pragma once
#include <Arduino.h>
#include <AccelStepper.h>
#include "StepperDriver.h"

class c_step_group
{
private:
    void _set_trapozoidal();
    void _microstep();

    c_stepper _m1;
    c_stepper _m2;

    bool _hold;
    int _speed;

public:
    c_step_group(c_stepper m1, c_stepper m2);

    void init();
    void home();

    void set_group_speed(int speed);

    void set_own_speed(bool first, int speed);

    void move_to_together(int angle);
    void move_to(bool first, int angle);

    void hold_both();
    void hold(bool first);

    void release_both();
    void release(bool first);
};