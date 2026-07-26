#include "StepperDriverSimple.h"

c_stepper::c_stepper(uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4)
{
    _pins[0] = in1;
    _pins[1] = in2;
    _pins[2] = in3;
    _pins[3] = in4;

    _motor = AccelStepper(AccelStepper::FULL4WIRE, _pins[0], _pins[2], _pins[1], _pins[3]);
}

void c_stepper::init()
{
    for (int i = 0; i < 4; i++)
    {
        pinMode(_pins[i], OUTPUT);
    }
}

void c_stepper::home()
{
    if (_get_homing_ver())
    {
        _motor.setCurrentPosition(0);
    }
}

void c_stepper::set_max_speed(double speed)
{
    _motor.setMaxSpeed(speed);
}

void c_stepper::set_accel(double accel)
{
    _motor.setAcceleration(accel);
}

void c_stepper::release()
{
    _motor.disableOutputs();
    for (int i = 0; i < 4; i++)
    {
        digitalWrite(_pins[i], LOW);
    }
}

bool c_stepper::_get_homing_ver()
{
    return true;
}

void c_stepper::move_to(int steps)
{
    _motor.moveTo(steps);
}

bool c_stepper::run()
{
    bool is_moving = _motor.run();

    if (!is_moving && _motor.distanceToGo() == 0)
    {
        release();
    }

    return is_moving;
}