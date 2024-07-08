#include "definitions.hpp"

namespace cursor
{
    unsigned short row = 0;
    unsigned short col = 0;
}

int currentScreen = MAIN_MENU;

void initColors()
{
    init_pair(textColor::red_black, COLOR_RED, COLOR_BLACK);
    init_pair(textColor::white_black, COLOR_WHITE, COLOR_BLACK);
}