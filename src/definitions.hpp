#include <ncurses.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <memory>
#include "decorations.hpp"
#include "button.hpp"
#pragma once

enum CurrentScreen
{
    MAIN_MENU = 1,
    NEW_MONTH_INTRO,
    NEW_MONTH_CREATOR,
    HISTORY,
    EMPTY,
    EXIT
};

extern int currentScreen;

enum textColor
{
    red_black = 1,
    white_black,
    blue_black
};

namespace cursor
{
    extern unsigned short row;
    extern unsigned short col;
}

void setup();
void exitText();
void initColors();
void refreshScreen();
void refreshScreenWithoutButtons();

const uint8_t LEFT_MARGIN = 4;
extern std::vector<std::string> categories;

extern std::vector<Button> buttons;
extern std::vector<Button>::iterator starCursor;
extern std::vector<std::string> autofillDictionary;