#include "purchases_list_edit.hpp"

void PurchasesListEdit::setup()
{
    clear();
    refresh();
    drawFrame();
    drawBanner();
    debugPrint("PURCHASE LIST EDIT");
    buttons.clear();
    buttons.emplace_back(Button("Back", 38, 4, NEW_MONTH_CREATOR));
    if (!buttons.empty())
    {
        starCursor = buttons.begin();
    }

    drawButtons();
}

void PurchasesListEdit::loop()
{
    refresh();
    while (currentScreen == PURCHASES_LIST_EDIT)
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

void PurchasesListEdit::setCurrentScreen()
{
}