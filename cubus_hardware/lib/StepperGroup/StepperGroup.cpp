#include <AccelStepper.h>
#include "StepperDriver.h"
#include "StepperGroup.h"

c_step_group::c_step_group(c_stepper m1, c_stepper m2)
    : _m1(m1), _m2(m2) {}

void c_step_group::init()
{
    _m1.init();
    _m2.init();
}
void c_step_group::home()
{
    _m1.home();
    _m2.home();
}

void c_step_group::set_group_max_speed(double speed)
{
    _m1.set_max_speed(speed);
    _m2.set_max_speed(speed);
}

void c_step_group::set_own_max_speed(bool first, double speed)
{
    if (first)
    {
        _m1.set_max_speed(speed);
    }
    else
    {
        _m2.set_max_speed(speed);
    }
}

void c_step_group::set_group_accel(double accel)
{
    _m1.set_accel(accel);
    _m2.set_accel(accel);
}

void c_step_group::set_own_accel(bool first, double accel)
{
    if (first)
    {
        _m1.set_accel(accel);
    }
    else
    {
        _m2.set_accel(accel);
    }
}

void c_step_group::move_to_together(int angle) {}
void c_step_group::move_to(bool first, int angle)
{
    if (first)
    {
        _m1.move_to(angle);
    }
    else
    {
        _m2.move_to(angle);
    }
}

void c_step_group::hold_both() {}
void c_step_group::hold(bool first)
{
    if (first)
    {
        _m1.hold();
    }
    else
    {
        _m2.hold();
    }
}

void c_step_group::release_both() {}
void c_step_group::release(bool first)
{
    if (first)
    {
        _m1.release();
    }
    else
    {
        _m2.release();
    }
}

bool _get_homing_verification() {}

void _microstep() {}