#include "new_month_creator.hpp"

void NewMonthCreator::setup()
{
    clear();
    refresh();
    drawFrame();
    drawBanner();
    buttons.clear();
    buttons.emplace_back(Button({Button("", 38, 4, 1),
                                 Button("", 38, 23, 1),
                                 Button("", 38, 44, 1)}));
    buttons.emplace_back(Button("Edit list", 39, 4, PURCHASES_LIST_EDIT));
    buttons.emplace_back(Button("Back", 40, 4, NEW_MONTH_INTRO));
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
        case '\n':                                                                                 // ENTER
            if (starCursor->getLabelText() == "Back" or starCursor->getLabelText() == "Edit list") // TODO CHANGE!!!!!!!!!!
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
        default:
            if (starCursor->hasSubButtons())
            {
                starCursor->getStarCursorOnSubbutton()->addCharToLabelText(inputChar);
                refreshScreen();
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
