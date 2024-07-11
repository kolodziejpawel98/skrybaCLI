#include "new_month_intro.hpp"

void NewMonthIntro::setup()
{
    clear();
    refresh();
    drawFrame();
    drawBanner();
    debugPrint("NEW MONTH INTRO");
    buttons.emplace_back(Button("Dalej", 38, 4, NEW_MONTH_CREATOR));
    buttons.emplace_back(Button("Cofnij", 39, 4, MAIN_MENU));
    if (!buttons.empty())
    {
        starCursor = buttons.begin();
    }
    drawButtons(buttons, starCursor);
    printTextInColor(inputWord, 30, LEFT_MARGIN + 40);
}

void NewMonthIntro::loop()
{
    printTextInColor(monthName, 10, LEFT_MARGIN + 40);
    refresh();
    while (currentScreen == NEW_MONTH_INTRO)
    {
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
            monthName = inputWord;
            inputWord = "[]";
            currentScreen = starCursor->getPointingToScreen();
            break;
        default:
            inputWord.insert(inputWord.size() - 1, 1, inputChar);
            printTextInColor(inputWord, 30, LEFT_MARGIN + 40);
            break;
        }
    }
}

void NewMonthIntro::setCurrentScreen()
{
}