#pragma once
#include <Arduino.h>

typedef struct
{
    uint8_t in1;
    uint8_t in2;
    uint8_t in3;
    uint8_t in4;
} stepperPins_t;

typedef struct
{
    facing red;
    facing white;
} orientation_t;

enum facing
{
    u,
    d,
    l,
    r,
    f,
    b
};

enum move_t
{
    u,
    up,
    u2,
    d,
    dp,
    d2,
    r,
    rp,
    r2,
    l,
    lp,
    l2,
    f,
    fp,
    f2,
    b,
    bp,
    b2,
};

namespace stp
{
    namespace pins
    {
        constexpr stepperPins_t L{0, 0, 0, 0}; // left
        constexpr stepperPins_t R{0, 0, 0, 0}; // right
        constexpr stepperPins_t U{0, 0, 0, 0}; // up
        constexpr stepperPins_t D{0, 0, 0, 0}; // down
        constexpr stepperPins_t H{0, 0, 0, 0}; // horizontal shifting
        constexpr stepperPins_t V{0, 0, 0, 0}; // vertical shifting
    }
    namespace turnConstants
    {
        constexpr static double TURN_SP = 10;
        constexpr static double SHIFT_SP = 10;
        constexpr static uint8_t MICROSTEP_TABLE[16][4] = {
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