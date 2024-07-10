#include "history.hpp"

void History::setup()
{
    clear();
    refresh();
    drawFrame();
    drawBanner();
    debugPrint("HISTORY");
    buttons.clear();
    buttons.emplace_back(Button("Cofnij", 38, 4, MAIN_MENU));
    if (!buttons.empty())
    {
        starCursor = buttons.begin();
    }
    drawButtons(buttons, starCursor);
}

void History::loop()
{
    refresh();
    while (currentScreen == HISTORY)
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

void History::setCurrentScreen()
{
}