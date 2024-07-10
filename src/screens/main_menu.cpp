#include "main_menu.hpp"

void MainMenu::setup()
{
    clear();
    refresh();
    drawFrame();
    drawBanner();
    debugPrint("MAIN MENU");
    buttons.clear();
    buttons.emplace_back(Button("Create new report", 38, 4, NEW_MONTH_INTRO));
    buttons.emplace_back(Button("Previous reports", 39, 4, HISTORY));
    buttons.emplace_back(Button("Cofnij", 40, 4, EXIT));
    if (!buttons.empty())
    {
        starCursor = buttons.begin();
    }
    drawButtons(buttons, starCursor);
}

void MainMenu::loop()
{
    refresh();
    while (currentScreen == MAIN_MENU)
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

void MainMenu::setCurrentScreen()
{
}