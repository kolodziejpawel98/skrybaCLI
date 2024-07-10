#include "main_menu.hpp"

void MainMenu::setup()
{
    debugPrint("MAIN MENU");
    refresh();
    buttons.clear();
    buttons.emplace_back(Button("Create new report", 25, 4, NEW_MONTH_INTRO));
    buttons.emplace_back(Button("Previous reports", 26, 4, HISTORY));
    buttons.emplace_back(Button("Cofnij", 27, 4, EXIT));
}

void MainMenu::loop()
{
    while (currentScreen == MAIN_MENU)
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

void MainMenu::setCurrentScreen()
{
}