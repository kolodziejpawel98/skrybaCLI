#include "history.hpp"

void History::setup()
{
    debugPrint("HISTORY");
    refresh();
    buttons.clear();
    buttons.emplace_back(Button("Create new report", 25, 4, NEW_MONTH_INTRO));
    buttons.emplace_back(Button("Previous reports", 26, 4, HISTORY));
    buttons.emplace_back(Button("Cofnij", 27, 4, MAIN_MENU));
}

void History::loop()
{
    while (currentScreen == HISTORY)
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
        case '\n': // ENTER
            currentScreen = starCursor->getPointingToScreen();
            break;
        }
    }
}

void History::setCurrentScreen()
{
}