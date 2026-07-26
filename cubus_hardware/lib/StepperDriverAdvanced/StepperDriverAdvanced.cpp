#include "StepperDriverAdvanced.h"
#include "config.h"

c_stepper::c_stepper(uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4)
{
    _pins[0] = in1;
    _pins[1] = in2;
    _pins[2] = in3;
    _pins[3] = in4;
};

void c_stepper::init()
{
    for (int i = 0; i < 4; i++)
    {
        pinMode(_pins[i], OUTPUT);
    }
    _motor = AccelStepper(_pins[0], _pins[1], _pins[2], _pins[3]);
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
    _max_speed = speed;
    _motor.setMaxSpeed(speed);
}
void c_stepper::set_accel(double accel)
{
    _accel = accel;
    _motor.setAcceleration(accel);
}

void c_stepper::_hold()
{
    if (_holding)
        return;

    for (int i = 0; i < 4; i++)
    {
        int base_val = stp::turnConstants::MICROSTEP_LOOKUP[_current_microindex][i];
        int hold_val = (int)(base_val * 0.3);
        analogWrite(_pins[i], hold_val);
    }
    _holding = true;
}
void c_stepper::release()
{
    for (int i = 0; i < 4; i++)
    {
        digitalWrite(_pins[i], LOW);
    }
}

bool c_stepper::_get_homing_ver()
{
    return true;
}

void c_stepper::_microstep(int dir)
{
    _current_microindex += dir;

    if (_current_microindex >= 16)
    {
        _current_microindex = 0;
    }
    else if (_current_microindex < 0)
    {
        _current_microindex = 15;
    }

    int microstep_val;
    for (int i = 0; i < 4; i++)
    {
        microstep_val = stp::turnConstants::MICROSTEP_LOOKUP[_current_microindex][i];
        analogWrite(_pins[i], microstep_val);
    }
}
void c_stepper::move_to(int microsteps)
{
    if (microsteps != _target_step)
    {
        _target_step = microsteps;
        if (_current_step == _target_step)
        {
            _n = 0;
            _current_speed = 0.;
        }
    }
}
bool c_stepper::run()
{
    long distance_to_go = _target_step - _current_step;

    if (distance_to_go == 0)
    {
        _current_speed = 0.0f;
        _n = 0;
        _hold();
        return false;
    }

    _holding = false;

    unsigned long now = micros();
    if (now - _last_step_us >= _step_interval_us)
    {

        int dir = (distance_to_go > 0) ? 1 : -1;
        long steps_remaining = abs(distance_to_go);

        long decel_steps = (long)((_current_speed * _current_speed) / (2.0f * _accel));

        if (steps_remaining <= decel_steps)
        {
            _n--;
            if (_n < 1)
                _n = 1;
        }
        else if (_current_speed < _max_speed)
        {
            _n++;
        }

        _current_speed = sqrtf(2.0f * _accel * (float)_n);
        if (_current_speed > _max_speed)
        {
            _current_speed = _max_speed;
        }

        _step_interval_us = (unsigned long)(1000000.0f / _current_speed);

        _microstep(dir);
        _current_step += dir;
        _last_step_us = now;
    }
    return true;
}

int c_stepper::get_current_step()
{
    return _current_step;
}