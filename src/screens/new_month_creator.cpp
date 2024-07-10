#include "new_month_creator.hpp"

void NewMonthCreator::setup()
{
    debugPrint("NEW MONTH SETUP");
    refresh();
    buttons.clear();
    buttons.emplace_back(Button("Create new report", 25, 4, NEW_MONTH_INTRO));
    buttons.emplace_back(Button("Previous reports", 26, 4, HISTORY));
    buttons.emplace_back(Button("Cofnij", 27, 4, NEW_MONTH_INTRO));
}

void NewMonthCreator::loop()
{
    while (currentScreen == NEW_MONTH_CREATOR)
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

void NewMonthCreator::setCurrentScreen()
{
}