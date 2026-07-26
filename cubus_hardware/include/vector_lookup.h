#include <Arduino.h>

typedef struct
{
    int x;
    int y;
    int z;
} vector3;

typedef struct
{
    vector3 i;
    vector3 j;
    vector3 k;
} matrix;

const vector3 up{0, 1, 0};

const vector3 down{0, -1, 0};

const vector3 right{1, 0, 0};

const vector3 left{-1, 0, 0};

const vector3 front{0, 0, 1};

const vector3 back{0, 0, -1};

matrix x_rot_ccw{
    {1, 0, 0},
    {0, 0, 1},
    {0, -1, 0}};

matrix x_rot_cw{
    {1, 0, 0},
    {0, 0, -1},
    {0, 1, 0}};

matrix z_rot_ccw{
    {0, 1, 0},
    {-1, 0, 0},
    {0, 0, 1}};

matrix z_rot_cw{
    {0, -1, 0},
    {1, 0, 0},
    {0, 0, 1}};

matrix init{
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1}};

enum rot_typ
{
    x,
    z
};

struct command_map
{
    char command_side;
    vector3 vector;
};

constexpr command_map command_parser[]{
    {'U', up},
    {'D', down},
    {'F', front},
    {'B', back},
    {'L', left},
    {'R', right},
};