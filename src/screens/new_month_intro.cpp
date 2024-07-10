#include "new_month_intro.hpp"

void NewMonthIntro::setup()
{
    clear();
    refresh();
    drawFrame();
    drawBanner();
    debugPrint("NEW MONTH INTRO");
    buttons.emplace_back(Button("Dalej", 25, 4, NEW_MONTH_INTRO));
    buttons.emplace_back(Button("Cofnij", 26, 4, MAIN_MENU));
    if (!buttons.empty())
    {
        starCursor = buttons.begin();
    }
    drawButtons(buttons, starCursor);
}

void NewMonthIntro::loop()
{
    refresh();
    while (currentScreen == NEW_MONTH_INTRO)
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

void NewMonthIntro::setCurrentScreen()
{
}