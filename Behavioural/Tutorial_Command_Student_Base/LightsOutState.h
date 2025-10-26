#pragma once

#include <raylib.h>

struct LightsOutState
{
    bool quit = false;
    int size = 7; //board size
    int level = 1;
    int num_steps = 1;
    bool game_over = false;
    Color off_light{64,64,64,255};
    Color lines{0,0,0,255};
    Color on_light{128,196,128,255};
};