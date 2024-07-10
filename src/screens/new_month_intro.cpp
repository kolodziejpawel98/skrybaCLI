#include "new_month_intro.hpp"

void NewMonthIntro::setup()
{
    debugPrint("NEW MONTH INTRO");
    refresh();
    buttons.clear();
    buttons.emplace_back(Button("Create new report", 25, 4, NEW_MONTH_INTRO));
    buttons.emplace_back(Button("Previous reports", 26, 4, HISTORY));
    buttons.emplace_back(Button("Cofnij", 27, 4, MAIN_MENU));
}

void NewMonthIntro::loop()
{
    while (currentScreen == NEW_MONTH_INTRO)
    {
        inputChar = getch();
        switch (inputChar)
        {
        case KEY_UP:
            debugPrint("KEY UP");
            refresh();
            goToUpperButton();
            drawButtons();
            break;
        case KEY_DOWN:
            debugPrint("LEY DOWN");
            refresh();
            goToLowerButton();
            drawButtons();
            break;
        case '\n': // ENTER
            currentScreen = starCursor->getPointingToScreen();
            break;
        }
    }
}

void NewMonthIntro::setCurrentScreen()
{
}