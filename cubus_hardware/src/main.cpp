#include <Arduino.h>
#include "config.h"
#include "StepperDriverAdvanced.h"
#include "vector_lookup.h"

static matrix transform = init;
move_t move;
static bool idle = true;

String get_input();

matrix add_transform(matrix m);
void update_transform(enum rot_typ rot, int dir, int num);
move_t apply_transform(String input);

void rot_x(int dir, int num);
void rot_y(int dir, int num);

void rot_u(int dir, int num);
void rot_d(int dir, int num);
void rot_l(int dir, int num);
void rot_r(int dir, int num);
void rot_f(int dir, int num);
void rot_b(int dir, int num);

void setup()
{
    Serial.begin(115200);
}

void loop()
{

    if (free)
    {
        move = apply_transform(get_input());

        idle = false;
        switch (move)
        {

        case u:
            rot_u(true, 1);
            break;
        case upr:
            rot_u(false, 1);
            break;
        case u2:
            rot_u(true, 2);
            break;
        case d:
            rot_d(true, 1);
            break;
        case dpr:
            rot_d(false, 1);
            break;
        case d2:
            rot_d(true, 2);
            break;
        case r:
            rot_r(true, 1);
            break;
        case rpr:
            rot_r(false, 1);
            break;
        case r2:
            rot_r(true, 2);
            break;
        case l:
            rot_l(true, 1);
            break;
        case lpr:
            rot_l(false, 1);
            break;
        case l2:
            rot_l(true, 2);
            break;
        case f:
            rot_f(true, 1);
            break;
        case fpr:
            rot_f(false, 1);
            break;
        case f2:
            rot_f(true, 2);
            break;
        case b:
            rot_b(true, 1);
            break;
        case bpr:
            rot_b(false, 1);
            break;
        case b2:
            rot_b(true, 1);
            break;

        default:
            idle = true;
            Serial.println("Invalid move recieved");
        }
    }
}

void update_orient(enum rot_typ rot, int dir, int num)
{
    for (int i = 0; i < num; i++)
    {
        if (rot == rot_typ::x && dir == 1)
        {
            add_transform(x_rot_ccw);
        }
        if (rot == rot_typ::x && dir == -1)
        {
            add_transform(x_rot_ccw);
        }
        if (rot == rot_typ::z && dir == 1)
        {
            add_transform(z_rot_ccw);
        }
        if (rot == rot_typ::z && dir == -1)
        {
            add_transform(z_rot_ccw);
        }
    }
}
void add_trasform(matrix m)
{
    matrix result;

    result.i.x = (transform.i.x * m.i.x) + (transform.j.x * m.i.y) + (transform.k.x * m.i.z);
    result.i.y = (transform.i.y * m.i.x) + (transform.j.y * m.i.y) + (transform.k.y * m.i.z);
    result.i.z = (transform.i.z * m.i.x) + (transform.j.z * m.i.y) + (transform.k.z * m.i.z);

    result.j.x = (transform.i.x * m.j.x) + (transform.j.x * m.j.y) + (transform.k.x * m.j.z);
    result.j.y = (transform.i.y * m.j.x) + (transform.j.y * m.j.y) + (transform.k.y * m.j.z);
    result.j.z = (transform.i.z * m.j.x) + (transform.j.z * m.j.y) + (transform.k.z * m.j.z);

    result.k.x = (transform.i.x * m.k.x) + (transform.j.x * m.k.y) + (transform.k.x * m.k.z);
    result.k.y = (transform.i.y * m.k.x) + (transform.j.y * m.k.y) + (transform.k.y * m.k.z);
    result.k.z = (transform.i.z * m.k.x) + (transform.j.z * m.k.y) + (transform.k.z * m.k.z);

    transform = result;
}
move_t apply_transform(String input)
{
    vector3 move_side_v;

    if (input.length() == 1)
    {
        input += '0';
    }

    for (int i = 1; 6; i++)
    {
        if (input[0] == command_parser->command_side)
        {
            move_side_v = command_parser[i].vector;
        }
    }
    vector3 new_side_v;

    new_side_v.x = (transform.i.x * move_side_v.x) + (transform.j.x * move_side_v.y) + (transform.k.x * move_side_v.z);
    new_side_v.y = (transform.i.y * move_side_v.x) + (transform.j.y * move_side_v.y) + (transform.k.y * move_side_v.z);
    new_side_v.z = (transform.i.z * move_side_v.x) + (transform.j.z * move_side_v.y) + (transform.k.z * move_side_v.z);

    char move_side_c;
    for (int i = 1; 6; i++)
    {
        if (new_side_v.x == command_parser->vector.x && new_side_v.y == command_parser->vector.y && new_side_v.z == command_parser->vector.z)
        {
            move_side_c = command_parser[i].command_side;
        }
    }

    if (move_side_c == 'U' && input[1] == '0')
    {
        return move_t::u;
    }
    else if (move_side_c == 'U' && input[1] == 'P')
    {
        return move_t::upr;
    }
    else if (move_side_c == 'U' && input[1] == '2')
    {
        return move_t::u2;
    }
    else if (move_side_c == 'D' && input[1] == '0')
    {
        return move_t::d;
    }
    else if (move_side_c == 'D' && input[1] == 'P')
    {
        return move_t::dpr;
    }
    else if (move_side_c == 'D' && input[1] == '2')
    {
        return move_t::d2;
    }
    else if (move_side_c == 'B' && input[1] == '0')
    {
        return move_t::b;
    }
    else if (move_side_c == 'B' && input[1] == 'P')
    {
        return move_t::bpr;
    }
    else if (move_side_c == 'B' && input[1] == '2')
    {
        return move_t::b2;
    }
    else if (move_side_c == 'F' && input[1] == '0')
    {
        return move_t::f;
    }
    else if (move_side_c == 'F' && input[1] == 'P')
    {
        return move_t::fpr;
    }
    else if (move_side_c == 'F' && input[1] == '2')
    {
        return move_t::f2;
    }
    else if (move_side_c == 'L' && input[1] == '0')
    {
        return move_t::l;
    }
    else if (move_side_c == 'L' && input[1] == 'P')
    {
        return move_t::lpr;
    }
    else if (move_side_c == 'L' && input[1] == '2')
    {
        return move_t::l2;
    }
    else if (move_side_c == 'R' && input[1] == '0')
    {
        return move_t::r;
    }
    else if (move_side_c == 'R' && input[1] == 'P')
    {
        return move_t::rpr;
    }
    else if (move_side_c == 'R' && input[1] == '2')
    {
        return move_t::r2;
    }
}

void rot_x(int dir, int num)
{
    update_orient(rot_typ::x, dir, num);
}
void rot_y(int dir, int num)
{
    update_orient(rot_typ::z, dir, num);
}

void rot_u(int dir, int num) {}
void rot_d(int dir, int num) {}
void rot_l(int dir, int num) {}
void rot_r(int dir, int num) {}
void rot_f(int dir, int num) {}
void rot_b(int dir, int num) {}
String get_input() {}