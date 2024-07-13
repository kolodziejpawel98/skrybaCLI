#include "new_month_intro.hpp"

void NewMonthIntro::setup()
{
    clear();
    refresh();
    drawFrame();
    drawBanner();
    buttons.emplace_back(Button("Dalej", 38, 4, NEW_MONTH_CREATOR));
    buttons.emplace_back(Button("Cofnij", 39, 4, MAIN_MENU));
    if (!buttons.empty())
    {
        starCursor = buttons.begin();
    }
    drawButtons(buttons, starCursor);
    printTextInColor("Month name: " + inputWord, 37, LEFT_MARGIN, textColor::white_black);
}

void NewMonthIntro::loop()
{

    while (currentScreen == NEW_MONTH_INTRO)
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

void NewMonthIntro::setCurrentScreen()
{
}
