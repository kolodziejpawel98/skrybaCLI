#include "new_month_intro.hpp"

void NewMonthIntro::setup()
{
    refreshScreenWithoutButtons();
    buttons.clear();
    buttons.emplace_back(Button("Next", FIRST_BUTTON_ROW, FIRST_BUTTON_COL, NEW_MONTH_CREATOR));
    buttons.emplace_back(Button("Back", FIRST_BUTTON_ROW + buttons.size(), 4, MAIN_MENU));
    if (!buttons.empty())
    {
        starCursor = buttons.begin();
    }
    drawButtons();
    printTextInColor("Month name: ", FIRST_BUTTON_ROW - 3, LEFT_MARGIN, textColor::white_black);
}

void NewMonthIntro::loop()
{

    while (currentScreen == NEW_MONTH_INTRO)
    {
        printTextInColor("Month name: ", FIRST_BUTTON_ROW - 3, LEFT_MARGIN, textColor::white_black);
        printTextInColor("---------------------------------------",
                         FIRST_BUTTON_ROW - 1,
                         LEFT_MARGIN,
                         textColor::white_black);
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
        case '\n':
            monthName = inputWord;
            inputWord = "";
            currentScreen = starCursor->getPointingToScreen();
            break;
        case KEY_BACKSPACE:
            if (inputWord.length() > 0)
            {
                inputWord.erase(inputWord.length() - 1, 1);
                refreshScreen();
                printTextInColor(
                    inputWord,
                    FIRST_BUTTON_ROW - 2,
                    LEFT_MARGIN,
                    textColor::red_black);
            }
            break;
        case '\t':
            refreshScreen();
            if (inputWord.length() > 0)
            {
                inputWord = checkAutofill(inputWord);
            }
            printTextInColor(
                inputWord,
                FIRST_BUTTON_ROW - 2,
                LEFT_MARGIN,
                textColor::red_black);
            break;
        default:
            inputWord += inputChar;

            if (inputWord.length() > 0)
            {
                refreshScreen();

                printTextInColor(
                    checkAutofill(inputWord),
                    FIRST_BUTTON_ROW - 2,
                    LEFT_MARGIN,
                    textColor::white_black, false);
                printTextInColor(
                    inputWord,
                    FIRST_BUTTON_ROW - 2,
                    LEFT_MARGIN,
                    textColor::red_black);
            }
            break;
        }
    }
}

void NewMonthIntro::setCurrentScreen()
{
}
