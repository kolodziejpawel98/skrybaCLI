#include "save_list.hpp"

void SaveList::setup()
{
    debugPrint("SAVE!!!");

    refreshScreenWithoutButtons();
    buttons.clear();
    buttons.emplace_back(Button("Back", FIRST_BUTTON_ROW, FIRST_BUTTON_COL, NEW_MONTH_CREATOR));
    if (!buttons.empty())
    {
        starCursor = buttons.end() - 1;
    }

    drawButtons();
}

void SaveList::loop()
{
    refresh();
    while (currentScreen == SAVE_LIST)
    {
        inputChar = getch();
        switch (inputChar)
        {
        case KEY_UP:
            goToUpperButton();
            drawButtons();
            break;
        case KEY_DOWN:
            goToLowerButton();
            drawButtons();
            break;
        case '\n':
            currentScreen = starCursor->getPointingToScreen();
            break;
        }
    }
}

void SaveList::setCurrentScreen()
{
}