#include <ncurses.h>
#include <cstring>
#include <iostream>
#include <vector>

#pragma once

enum textColor
{
    red_black = 1,
    white_black
};

namespace cursor
{
    extern unsigned short row;
    extern unsigned short col;
}

void initColors();

const uint8_t LEFT_MARGIN = 4;