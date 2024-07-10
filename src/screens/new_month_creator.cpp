#include "new_month_creator.hpp"

void NewMonthCreator::setup()
{
    clear();
    refresh();
    drawFrame();
    drawBanner();
    debugPrint("NEW MONTH SETUP");
    buttons.clear();
    buttons.emplace_back(Button("Cofnij", 27, 4, NEW_MONTH_INTRO));
    if (!buttons.empty())
    {
        starCursor = buttons.begin();
    }
    drawButtons(buttons, starCursor);
}

void NewMonthCreator::loop()
{
    refresh();
    while (currentScreen == NEW_MONTH_CREATOR)
    {
        inputChar = getch();
        switch (inputChar)
        {
        case KEY_UP:
            goToUpperButton(buttons, starCursor);
            drawButtons(buttons, starCursor);
            break;
        case KEY_DOWN:
            goToLowerButton(buttons, starCursor);
            drawButtons(buttons, starCursor);
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