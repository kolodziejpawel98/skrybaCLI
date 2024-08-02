#include "main_menu.hpp"

void MainMenu::setup()
{
    refreshScreenWithoutButtons();
    buttons.clear();
    buttons.emplace_back(Button("Create new report", FIRST_BUTTON_ROW, FIRST_BUTTON_COL, NEW_MONTH_INTRO));
    buttons.emplace_back(Button("Previous reports", FIRST_BUTTON_ROW + buttons.size(), FIRST_BUTTON_COL, HISTORY));
    buttons.emplace_back(Button("Quit", FIRST_BUTTON_ROW + buttons.size(), FIRST_BUTTON_COL, EXIT));
    if (!buttons.empty())
    {
        starCursor = buttons.begin();
    }
    drawButtons();
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

void MainMenu::setCurrentScreen()
{
}