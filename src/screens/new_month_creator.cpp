#include "new_month_creator.hpp"

void NewMonthCreator::setup()
{
    clear();
    refresh();
    drawFrame();
    drawBanner();
    buttons.clear();
    buttons.emplace_back(Button({Button("1", 38, 4, 1),
                                 Button("2", 38, 23, 1),
                                 Button("3", 38, 44, 1)}));
    buttons.emplace_back(Button("Back", 39, 4, NEW_MONTH_INTRO));
    if (!buttons.empty())
    {
        starCursor = buttons.begin();
    }
    drawButtons();
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
        case '\n': // ENTER
            // inputWord.substr(1, inputWord.size() - 2)
            if (starCursor->getLabelText() == "Back")
            {
                currentScreen = starCursor->getPointingToScreen();
            }
            //     else
            //     {
            //         std::string newPurchaseCellText = inputWord.substr(1, inputWord.size() - 2);
            //         starCursor->setLabelText(newPurchaseCellText);
            //         inputWord = "[]";
            //         clear();
            //         refresh();
            //         drawFrame();
            //         drawBanner();
            //         drawButtons();
            //         printTextInColor("[" + newPurchaseCellText + "]", starCursor->getRow(), LEFT_MARGIN, textColor::white_black);
            //     }
            break;
        // case KEY_BACKSPACE:
        //     if (inputWord.length() > 2)
        //     {
        //         inputWord.erase(inputWord.length() - 2, 1);
        //         clear();
        //         refresh();
        //         drawFrame();
        //         drawBanner();
        //         drawButtons();
        //         printTextInColor("Purchase: " + inputWord, 35, LEFT_MARGIN, textColor::white_black);
        //     }
        //     break;
        default:

            if (starCursor->hasSubButtons())
            {
                // refreshScreen();
                // debugPrint(starCursor->getStarCursorOnSubbutton()->getLabelText(), 20, 20);
                starCursor->getStarCursorOnSubbutton()->addCharToLabelText(inputChar);
                refreshScreen();
            }

            // inputWord += inputChar;
            //             refreshScreen();
            //             debugPrint(inputWord, 30, 40);
            //             break;

            break;
        }
    }
}

void NewMonthCreator::setCurrentScreen()
{
}
