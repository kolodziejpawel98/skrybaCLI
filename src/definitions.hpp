#include <ncurses.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <memory>
#include "decorations.hpp"
#include "button.hpp"
#include "purchase.hpp"
#pragma once

enum CurrentScreen
{
    MAIN_MENU = 1,
    NEW_MONTH_INTRO,
    NEW_MONTH_CREATOR,
    HISTORY,
    PURCHASES_LIST_EDIT,
    SAVE_LIST,
    EMPTY,
    EXIT
};

extern int currentScreen;

enum textColor
{
    red_black = 1,
    white_black,
    blue_black,
    green_black
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
const uint8_t FIRST_BUTTON_ROW = 38;
const uint8_t FIRST_BUTTON_COL = LEFT_MARGIN;
extern std::vector<std::string> categories;

extern std::vector<Button> buttons;
extern std::vector<Button>::iterator starCursor;
extern std::vector<std::string> autofillDictionary;
extern std::vector<Purchase> purchases;
extern std::string checkAutofill(std::string wordPrefix, std::vector<std::string> autofillDictionary);
