#pragma once
#include <Arduino.h>

typedef struct
{
    uint8_t in1;
    uint8_t in2;
    uint8_t in3;
    uint8_t in4;
} stepperPins_t;

namespace Stepper
{
    namespace pins
    {
        constexpr stepperPins_t m1{0, 0, 0, 0};
        constexpr stepperPins_t m2{0, 0, 0, 0};
        constexpr stepperPins_t m3{0, 0, 0, 0};
        constexpr stepperPins_t m4{0, 0, 0, 0};
        constexpr stepperPins_t m5{0, 0, 0, 0};
        constexpr stepperPins_t m6{0, 0, 0, 0};
    }
    namespace turnConstants
    {
        constexpr static double turnMotorSpeed = 10;
        constexpr static double shiftMotorSpeed = 10;
        constexpr static uint8_t microstep_table[16][4] = {
            {255, 0, 0, 0},
            {236, 98, 0, 0},
            {180, 180, 0, 0},
            {98, 236, 0, 0},
            {0, 255, 0, 0},
            {0, 236, 98, 0},
            {0, 180, 180, 0},
            {0, 98, 236, 0},
            {0, 0, 255, 0},
            {0, 0, 236, 98},
            {0, 0, 180, 180},
            {0, 0, 98, 236},
            {0, 0, 0, 255},
            {98, 0, 0, 236},
            {180, 0, 0, 180},
            {236, 0, 0, 98}};

    }
}