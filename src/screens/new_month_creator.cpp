#include "new_month_creator.hpp"

void NewMonthCreator::setup()
{
    clear();
    refresh();
    drawFrame();
    drawBanner();
    debugPrint("MONTH NAME: " + monthName);
    buttons.clear();
    buttons.emplace_back(Button("Cofnij", 38, 4, NEW_MONTH_INTRO));
    if (!buttons.empty())
    {
        starCursor = buttons.begin();
    }
    drawButtons(buttons, starCursor);
}

void NewMonthCreator::loop()
{

    while (currentScreen == NEW_MONTH_CREATOR)
    {
        // refresh();
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
            monthName = inputWord.substr(1, inputWord.size() - 2);
            inputWord = "[]";
            currentScreen = starCursor->getPointingToScreen();
            break;
        case KEY_BACKSPACE:
            if (inputWord.length() > 2)
            {
                inputWord.erase(inputWord.length() - 2, 1);
                clear();
                refresh();
                drawFrame();
                drawBanner();
                drawButtons(buttons, starCursor);
                printTextInColor("Month name: " + inputWord, 37, LEFT_MARGIN, textColor::white_black);
            }
            break;
        default:
            inputWord.insert(inputWord.size() - 1, 1, inputChar);
            clear();
            refresh();
            drawFrame();
            drawBanner();
            drawButtons(buttons, starCursor);
            printTextInColor("Month name: " + inputWord, 37, LEFT_MARGIN, textColor::white_black);
            break;
        }
    }
}

void NewMonthCreator::setCurrentScreen()
{
}
