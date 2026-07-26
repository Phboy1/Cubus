#pragma once
#include <Arduino.h>

typedef struct
{
    uint8_t in1;
    uint8_t in2;
    uint8_t in3;
    uint8_t in4;
} stepperPins_t;

enum move_t
{
    u,
    upr,
    u2,
    d,
    dpr,
    d2,
    r,
    rpr,
    r2,
    l,
    lpr,
    l2,
    f,
    fpr,
    f2,
    b,
    bpr,
    b2,
};

namespace stp
{
    namespace pins
    {
        constexpr stepperPins_t L{3, 4, 5, 6}; // left
        constexpr stepperPins_t R{0, 0, 0, 0}; // right
        constexpr stepperPins_t U{0, 0, 0, 0}; // up
        constexpr stepperPins_t D{0, 0, 0, 0}; // down
        constexpr stepperPins_t H{0, 0, 0, 0}; // horizontal shifting
        constexpr stepperPins_t V{0, 0, 0, 0}; // vertical shifting
    }
    namespace turnConstants
    {
        constexpr static double TURN_MAX_SP = 2000.0;
        constexpr static double TURN_ACC = 5000.0;
        constexpr static double SHIFT_MAX_SP = 10;
        constexpr static double SHIFT_ACC = 10;

        constexpr static uint8_t MICROSTEP_LOOKUP[16][4] = {
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

namespace servoConstants
{
    namespace pins
    {
        constexpr uint8_t mw = A0;
        constexpr uint8_t ma = A1;
        constexpr uint8_t ms = A2;
        constexpr uint8_t md = A3;
    }
}
namespace shifterConstants
{
    namespace pins
    {
        constexpr uint8_t h1 = 3;
        constexpr uint8_t h2 = 4;
        constexpr uint8_t v1 = 5;
        constexpr uint8_t v2 = 6;
    }
}