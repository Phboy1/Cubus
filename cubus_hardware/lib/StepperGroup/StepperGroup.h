#pragma once
#include <Arduino.h>
#include "StepperDriver.h"
#include <AccelStepper.h>
#include <MultiStepper.h>

class c_step_group
{
private:
    MultiStepper mgroup;

    void _set_trapozoidal();
    void _microstep();

    c_stepper _m1;
    c_stepper _m2;

    bool _hold;

public:
    c_step_group(c_stepper m1, c_stepper m2);

    void init();
    void home();

    void set_group_max_speed(double speed);
    void set_group_accel(double speed);

    void set_own_max_speed(bool first, double speed);
    void set_own_accel(bool first, double accel);

    void move_to_together(int angle);
    void move_to(bool first, int angle);

    void hold_both();
    void hold(bool first);

    void release_both();
    void release(bool first);
};