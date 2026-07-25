#pragma once
#include <Arduino.h>
#include <AccelStepper.h>

class c_stepper
{
private:
    int current_angle;
    int targer_angle;

    void _set_trapezoidal();
    void _microstep();

    uint8_t _in1;
    uint8_t _in2;
    uint8_t _in3;
    uint8_t _in4;

    int _speed;
    bool _hold;

public:
    c_stepper(uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4);
    void init();
    void home();
    void move_to(int angle);
    void set_speed(int speed);
    void hold();
    void release();
};