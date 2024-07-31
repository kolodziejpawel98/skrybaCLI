#include "purchases_list_edit.hpp"

void PurchasesListEdit::setup()
{
    clear();
    refresh();
    drawFrame();
    drawBanner();
    debugPrint("PURCHASE LIST EDIT");
    buttons.clear();
    savePurchasesAsButtons();
    buttons.emplace_back(Button("Back", 38, 4, NEW_MONTH_CREATOR));
    if (!buttons.empty())
    {
        starCursor = buttons.end() - 1;
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
            // drawEnteredPurchases();
            break;
        case KEY_DOWN:
            goToLowerButton();
            drawButtons();
            // drawEnteredPurchases();
            break;
        case KEY_LEFT:
            goToLeftButton();
            drawButtons();
            // drawEnteredPurchases();
            break;
        case KEY_RIGHT:
            goToRightButton();
            drawButtons();
            // drawEnteredPurchases();
            break;
        // case '\n':                                                                                 // ENTER
        //     if (starCursor->getLabelText() == "Back" or starCursor->getLabelText() == "Edit list") // TODO CHANGE!!!!!!!!!!
        //     {
        //         currentScreen = starCursor->getPointingToScreen();
        //     }
        //     else
        //     {
        //         if (starCursor->getStarCursorOnSubbutton() != starCursor->getSubButtons().end() - 1)
        //         {
        //             starCursor->getStarCursorOnSubbutton()++;
        //             refreshScreen();
        //             drawEnteredPurchases();
        //         }
        //         else
        //         {
        //             std::string categoryTmp;
        //             std::string costTmp;
        //             std::string shopNameTmp;

        //             categoryTmp = starCursor->getSubButtons().at(0).getLabelText();
        //             costTmp = starCursor->getSubButtons().at(1).getLabelText();
        //             shopNameTmp = starCursor->getSubButtons().at(2).getLabelText();

        //             purchases.push_back(Purchase(starCursor->getSubButtons().at(0).getLabelText(),
        //                                          starCursor->getSubButtons().at(1).getLabelText(),
        //                                          starCursor->getSubButtons().at(2).getLabelText()));

        //             starCursor->getSubButtons().at(0).setLabelText("");
        //             starCursor->getSubButtons().at(1).setLabelText("");
        //             starCursor->getSubButtons().at(2).setLabelText("");
        //             starCursor->getStarCursorOnSubbutton() = starCursor->getSubButtons().begin();
        //             refreshScreen();
        //             drawEnteredPurchases();
        //         }
        //     }

        //     break;
        // case KEY_BACKSPACE:
        //     if (starCursor->getStarCursorOnSubbutton()->getLabelText().size() > 0)
        //     {
        //         starCursor->getStarCursorOnSubbutton()->getLabelText().erase(starCursor->getStarCursorOnSubbutton()->getLabelText().length() - 1, 1);
        //         refreshScreen();
        //         drawEnteredPurchases();
        //     }
        //     break;
        case '\n': // ENTER
            currentScreen = starCursor->getPointingToScreen();
            break;
        }
    }
}

void PurchasesListEdit::savePurchasesAsButtons()
{
    int rowIterator = 0;
    for (auto purchase : purchases)
    {
        // buttons.emplace_back(Button(purchase.category + purchase.cost + purchase.shopName, 10 + rowIterator, 4, NEW_MONTH_CREATOR));
        buttons.emplace_back(Button({Button(purchase.category, 10 + rowIterator, 4, 1),
                                     Button(purchase.cost, 10 + rowIterator, 23, 1),
                                     Button(purchase.shopName, 10 + rowIterator, 44, 1)}));
        rowIterator += 2;
    }
}

void PurchasesListEdit::setCurrentScreen()
{
}