#include "main_menu.hpp"

void MainMenu::setup()
{
}

void MainMenu::loop()
{
    while (currentScreen == MAIN_MENU)
    {
        inputChar = getch();
        switch (inputChar)
        {
        case 'q':
            printTextInColor("Made by PK", 17, LEFT_MARGIN);
            printTextInColor("bye...", 18, LEFT_MARGIN);
            refresh();
            napms(300);
            endwin();
            currentScreen = EXIT;
            break;
        case KEY_UP:
            upperButton();
            drawButtons();
            break;
        case KEY_DOWN:
            lowerButton();
            drawButtons();
            break;
        case '\n':
            // debugPrint("starCursor->getPointingToScreen() =  " + std::to_string(starCursor->getPointingToScreen()));
            // debugPrint("ENTER");

            // mvprintw(15, LEFT_MARGIN, "You chose: ");
            // mvprintw(16, LEFT_MARGIN, starCursor->getLabelText().c_str());
            currentScreen = starCursor->getPointingToScreen();
            break;
        default:
            mvprintw(15, LEFT_MARGIN, "%c was pressed! Try again.", inputChar);
            break;
        }
    }
}

void MainMenu::setCurrentScreen()
{
}