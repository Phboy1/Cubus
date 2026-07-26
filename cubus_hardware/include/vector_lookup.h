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
    vector3 k;
    vector3 j;
} matrix;

vector3 up{0, 1, 0};

vector3 down{0, -1, 0};

vector3 right{1, 0, 0};

vector3 left{-1, 0, 0};

vector3 front{0, 0, 1};

vector3 back{0, 0, -1};

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