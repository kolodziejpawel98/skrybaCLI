#include "purchases_list_edit.hpp"

void PurchasesListEdit::setup()
{
    refreshScreenWithoutButtons();
    // debugPrint("PURCHASE LIST EDIT");
    buttons.clear();
    savePurchasesAsButtons();
    buttons.emplace_back(Button("Save", FIRST_BUTTON_ROW, FIRST_BUTTON_COL, NEW_MONTH_CREATOR));
    buttons.emplace_back(Button("Back without saving", FIRST_BUTTON_ROW + 1, FIRST_BUTTON_COL, NEW_MONTH_CREATOR));
    if (!buttons.empty())
    {
        starCursor = buttons.end() - 2;
    }

    drawButtons();
}

void PurchasesListEdit::loop()
{
    drawLabelDescription();
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
        case KEY_LEFT:
            goToLeftButton();
            drawButtons();
            break;
        case KEY_RIGHT:
            goToRightButton();
            drawButtons();
            break;
        case '\n':
            if (starCursor == buttons.end() - 1)
            {
                currentScreen = starCursor->getPointingToScreen();
            }
            else if (starCursor == buttons.end() - 2)
            {
                // in main.cpp new purchases are passed to previous screen
                currentScreen = starCursor->getPointingToScreen();
            }
            break;
        case KEY_BACKSPACE:
            if (starCursor->getStarCursorOnSubbutton()->getLabelText().size() > 0)
            {
                starCursor->getStarCursorOnSubbutton()->getLabelText().erase(starCursor->getStarCursorOnSubbutton()->getLabelText().length() - 1, 1);
                refreshScreen();
                // drawEnteredPurchases();
                drawLabelDescription();
            }
            break;
        default:
            if (starCursor->hasSubButtons())
            {
                starCursor->getStarCursorOnSubbutton()->addCharToLabelText(inputChar);
            }
            refreshScreen();
            drawLabelDescription();
            break;
        }
    }
}

void PurchasesListEdit::drawLabelDescription()
{
    printTextInColor("Category: ", 9, FIRST_BUTTON_COL, textColor::green_black);
    printTextInColor("Cost: ", 9, FIRST_BUTTON_COL + 40, textColor::green_black);
    printTextInColor("Shop name: ", 9, FIRST_BUTTON_COL + 80, textColor::green_black);
}

void PurchasesListEdit::savePurchasesAsButtons()
{
    int rowIterator = 0;
    for (auto purchase : purchases)
    {
        buttons.emplace_back(Button({Button(purchase.category, 10 + rowIterator, LEFT_MARGIN, 1),
                                     Button(purchase.cost, 10 + rowIterator, LEFT_MARGIN + 40, 1),
                                     Button(purchase.shopName, 10 + rowIterator, LEFT_MARGIN + 80, 1)}));
        rowIterator++;
    }
}

std::vector<Purchase> PurchasesListEdit::getUpdatedPurchasesList()
{
    std::vector<Purchase> newPurchases = {};
    for (auto button = buttons.begin(); button < buttons.end() - 2; button++)
    {
        if (button->getSubButtons().at(0).getLabelText() != "" or
            button->getSubButtons().at(1).getLabelText() != "" or
            button->getSubButtons().at(2).getLabelText() != "")
        {
            newPurchases.emplace_back(Purchase(button->getSubButtons().at(0).getLabelText(),
                                               button->getSubButtons().at(1).getLabelText(),
                                               button->getSubButtons().at(2).getLabelText()));
        }
    }
    return newPurchases;
}

void PurchasesListEdit::setCurrentScreen()
{
}