#include <ncurses.h>
#include <cstring>
#include <iostream>
#include <vector>

#pragma once

enum CurrentScreen
{
    MAIN_MENU = 1,
    NEW_MONTH_INTRO,
    NEW_MONTH_CREATOR,
    HISTORY,
    EXIT
};

extern CurrentScreen currentScreen;

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