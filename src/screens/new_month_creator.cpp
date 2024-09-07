#include "new_month_creator.hpp"

void NewMonthCreator::setup()
{
    refreshScreenWithoutButtons();
    buttons.clear();
    buttons.emplace_back(Button({Button("", FIRST_BUTTON_ROW - 1, FIRST_BUTTON_COL),
                                 Button("", FIRST_BUTTON_ROW - 1, FIRST_BUTTON_COL + 40),
                                 Button("", FIRST_BUTTON_ROW - 1, FIRST_BUTTON_COL + 80)}));
    buttons.emplace_back(Button("Edit list", FIRST_BUTTON_ROW + buttons.size(), FIRST_BUTTON_COL, PURCHASES_LIST_EDIT));
    buttons.emplace_back(Button("Save list to JSON", FIRST_BUTTON_ROW + buttons.size(), FIRST_BUTTON_COL, SAVE_LIST));
    buttons.emplace_back(Button("Back", FIRST_BUTTON_ROW + buttons.size(), FIRST_BUTTON_COL, MAIN_MENU));
    if (!buttons.empty())
    {
        starCursor = buttons.begin();
    }
    drawButtons();
    drawEnteredPurchases();
}

void NewMonthCreator::loop()
{
    while (currentScreen == NEW_MONTH_CREATOR)
    {
        printTextInColor("Month: " + monthName, 8, LEFT_MARGIN, textColor::white_black);
        printTextInColor("Category: ", FIRST_BUTTON_ROW - 2, FIRST_BUTTON_COL, textColor::white_black);
        printTextInColor("Cost: ", FIRST_BUTTON_ROW - 2, FIRST_BUTTON_COL + 40, textColor::white_black);
        printTextInColor("Shop name: ", FIRST_BUTTON_ROW - 2, FIRST_BUTTON_COL + 80, textColor::white_black);
        printTextInColor("------------------------------------------------------------------------------------------------------",
                         FIRST_BUTTON_ROW,
                         LEFT_MARGIN,
                         textColor::white_black);
        inputChar = getch();
        switch (inputChar)
        {
        case KEY_UP:
            goToUpperButton();
            drawButtons();
            drawEnteredPurchases();
            break;
        case KEY_DOWN:
            goToLowerButton();
            drawButtons();
            drawEnteredPurchases();
            break;
        case KEY_LEFT:
            goToLeftButton();
            drawButtons();
            drawEnteredPurchases();
            break;
        case KEY_RIGHT:
            goToRightButton();
            drawButtons();
            drawEnteredPurchases();
            break;
        case '\n':
            if (starCursor == buttons.end() - 1 or starCursor == buttons.end() - 2 or starCursor == buttons.end() - 3)
            {
                currentScreen = starCursor->getPointingToScreen();
            }
            else
            {
                if (starCursor->getStarCursorOnSubbutton() != starCursor->getSubButtons().end() - 1)
                {
                    starCursor->getStarCursorOnSubbutton()++;
                    refreshScreen();
                    drawEnteredPurchases();
                }
                else
                {
                    std::string categoryTmp;
                    std::string costTmp;
                    std::string shopNameTmp;

                    categoryTmp = starCursor->getSubButtons().at(0).getLabelText();
                    costTmp = starCursor->getSubButtons().at(1).getLabelText();
                    shopNameTmp = starCursor->getSubButtons().at(2).getLabelText();

                    purchases.push_back(Purchase(starCursor->getSubButtons().at(0).getLabelText(),
                                                 starCursor->getSubButtons().at(1).getLabelText(),
                                                 starCursor->getSubButtons().at(2).getLabelText()));

                    starCursor->getSubButtons().at(0).setLabelText("");
                    starCursor->getSubButtons().at(1).setLabelText("");
                    starCursor->getSubButtons().at(2).setLabelText("");
                    starCursor->getStarCursorOnSubbutton() = starCursor->getSubButtons().begin();
                    refreshScreen();
                    drawEnteredPurchases();
                }
            }

            break;
        case KEY_BACKSPACE:
            if (starCursor->getStarCursorOnSubbutton()->getLabelText().size() > 0)
            {
                starCursor->getStarCursorOnSubbutton()->getLabelText().erase(starCursor->getStarCursorOnSubbutton()->getLabelText().length() - 1, 1);
                refreshScreen();
                drawEnteredPurchases();
            }
            break;
        case '\t':
            refreshScreen();
            if (starCursor->getStarCursorOnSubbutton()->getLabelText().size() > 0)
            {
                if (starCursor->getStarCursorOnSubbutton() == starCursor->getSubButtons().begin())
                {
                    starCursor->getStarCursorOnSubbutton()->setLabelText(checkAutofill(starCursor->getStarCursorOnSubbutton()->getLabelText(), autofillDictionaryCategory));
                }
                else
                {
                    starCursor->getStarCursorOnSubbutton()->setLabelText(checkAutofill(starCursor->getStarCursorOnSubbutton()->getLabelText(), autofillDictionaryShopName));
                }
            }
            printTextInColor(
                starCursor->getStarCursorOnSubbutton()->getLabelText(),
                starCursor->getStarCursorOnSubbutton()->getRow(),
                starCursor->getStarCursorOnSubbutton()->getCol() + 5,
                textColor::red_black);
            break;
        default:
            if (starCursor->hasSubButtons())
            {
                starCursor->getStarCursorOnSubbutton()->addCharToLabelText(inputChar);
                if (starCursor->getStarCursorOnSubbutton()->getLabelText().size() > 0)
                {
                    refreshScreen();
                    if (starCursor->getStarCursorOnSubbutton() == starCursor->getSubButtons().begin())
                    {
                        printTextInColor(
                            checkAutofill(starCursor->getStarCursorOnSubbutton()->getLabelText(), autofillDictionaryCategory),
                            starCursor->getStarCursorOnSubbutton()->getRow(),
                            starCursor->getStarCursorOnSubbutton()->getCol() + 5,
                            textColor::white_black, false);
                    }
                    else
                    {
                        printTextInColor(
                            checkAutofill(starCursor->getStarCursorOnSubbutton()->getLabelText(), autofillDictionaryShopName),
                            starCursor->getStarCursorOnSubbutton()->getRow(),
                            starCursor->getStarCursorOnSubbutton()->getCol() + 5,
                            textColor::white_black, false);
                    }

                    printTextInColor(
                        starCursor->getStarCursorOnSubbutton()->getLabelText(),
                        starCursor->getStarCursorOnSubbutton()->getRow(),
                        starCursor->getStarCursorOnSubbutton()->getCol() + 5,
                        textColor::red_black);
                }

                drawEnteredPurchases();
            }
            break;
        }
    }
}

void NewMonthCreator::drawEnteredPurchases()
{
    int rowIterator = 0;
    if (purchases.size() <= 10)
    {
        for (auto &purchase : purchases)
        {
            attron(A_BOLD | COLOR_PAIR(textColor::green_black));
            mvprintw(10 + rowIterator, 4, purchase.category.c_str());
            mvprintw(10 + rowIterator, 4 + purchase.category.size() + 1, purchase.cost.c_str());
            mvprintw(10 + rowIterator, 4 + purchase.category.size() + 1 + purchase.cost.size() + 1, purchase.shopName.c_str());
            rowIterator += 2;
            attroff(A_BOLD | COLOR_PAIR(textColor::green_black));
        }
    }
    else
    {
        refreshScreen();
        int help = purchases.size() - 10;
        rowIterator = 0;
        for (int i = help; i < 10 + help; i++)
        {
            attron(A_BOLD | COLOR_PAIR(textColor::green_black));
            mvprintw(10 + rowIterator, 4, purchases.at(i).category.c_str());
            mvprintw(10 + rowIterator, 4 + purchases.at(i).category.size() + 1, purchases.at(i).cost.c_str());
            mvprintw(10 + rowIterator, 4 + purchases.at(i).category.size() + 1 + purchases.at(i).cost.size() + 1, purchases.at(i).shopName.c_str());
            rowIterator += 2;
            attroff(A_BOLD | COLOR_PAIR(textColor::green_black));
        }
    }
}

void NewMonthCreator::setCurrentScreen()
{
}
