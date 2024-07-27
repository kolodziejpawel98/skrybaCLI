#include "history.hpp"

void History::setup()
{
    clear();
    refresh();
    drawFrame();
    drawBanner();
    debugPrint("HISTORY");
    buttons.clear();
    buttons.emplace_back(Button("Cofnij", 40, 4, MAIN_MENU));
    if (!buttons.empty())
    {
        starCursor = buttons.begin();
    }
    starCursorStoredPlace = starCursor;

    drawButtons();
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