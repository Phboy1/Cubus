#include <Arduino.h>
#include "config.h"
#include "stepperDriver.h"

static orientation_t orient;
move_t move;
static bool free = true;

c_stepper ml = c_stepper(stp::pins::L.in1, stp::pins::L.in2, stp::pins::L.in3, stp::pins::L.in4);
c_stepper mr = c_stepper(stp::pins::R.in1, stp::pins::R.in2, stp::pins::R.in3, stp::pins::R.in4);
c_stepper mu = c_stepper(stp::pins::U.in1, stp::pins::U.in2, stp::pins::U.in3, stp::pins::U.in4);
c_stepper md = c_stepper(stp::pins::D.in1, stp::pins::D.in2, stp::pins::D.in3, stp::pins::D.in4);
c_stepper mh = c_stepper(stp::pins::H.in1, stp::pins::H.in2, stp::pins::H.in3, stp::pins::H.in4);
c_stepper mv = c_stepper(stp::pins::V.in1, stp::pins::V.in2, stp::pins::V.in3, stp::pins::V.in4);

move_t get_input();

void update_orient(void (*func)(bool, int), bool dir, int num);

void rot_x(bool dir, int num);
void rot_y(bool dir, int num);

void rot_u(bool dir, int num);
void rot_d(bool dir, int num);
void rot_l(bool dir, int num);
void rot_r(bool dir, int num);
void rot_f(bool dir, int num);
void rot_b(bool dir, int num);

void setup()
{
    Serial.begin(115200);
    ml.init();
    mr.init();
    mu.init();
    md.init();
    mh.init();
    mv.init();

    ml.set_speed(stp::turnConstants::TURN_SP);
    mr.set_speed(stp::turnConstants::TURN_SP);
    mu.set_speed(stp::turnConstants::TURN_SP);
    md.set_speed(stp::turnConstants::TURN_SP);
    mh.set_speed(stp::turnConstants::SHIFT_SP);
    mv.set_speed(stp::turnConstants::SHIFT_SP);
}

void loop()
{

    if (free) // this need to be switched to false in the functions themselves and back when they
    {
        move = get_input();

        free = false;
        switch (move)
        {

        case u:
            rot_u(true, 1);
            break;
        case up:
            rot_u(false, 1);
            break;
        case u2:
            rot_u(true, 2);
            break;
        case d:
            rot_d(true, 1);
            break;
        case dp:
            rot_d(false, 1);
            break;
        case d2:
            rot_d(true, 2);
            break;
        case r:
            rot_r(true, 1);
            break;
        case rp:
            rot_r(false, 1);
            break;
        case r2:
            rot_r(true, 2);
            break;
        case l:
            rot_l(true, 1);
            break;
        case lp:
            rot_l(false, 1);
            break;
        case l2:
            rot_l(true, 2);
            break;
        case f:
            rot_f(true, 1);
            break;
        case fp:
            rot_f(false, 1);
            break;
        case f2:
            rot_f(true, 2);
            break;
        case b:
            rot_b(true, 1);
            break;
        case bp:
            rot_b(false, 1);
            break;
        case b2:
            rot_b(true, 1);
            break;

        default:
            free = true;
            Serial.println("Invalid move recieved");
        }
    }
}

void update_orient(void (*func)(bool, int), bool dir, int num) {}

void rot_x(bool dir, int num) {}
void rot_y(bool dir, int num) {}

void rot_u(bool dir, int num) {}
void rot_d(bool dir, int num) {}
void rot_l(bool dir, int num) {}
void rot_r(bool dir, int num) {}
void rot_f(bool dir, int num) {}
void rot_b(bool dir, int num) {}
