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
    printTextInColor(inputWord, 30, LEFT_MARGIN + 40);
}

void NewMonthIntro::loop()
{

    while (currentScreen == NEW_MONTH_INTRO)
    {
        printTextInColor("Month name: " + monthName, 10, LEFT_MARGIN + 40);
        refresh();
        inputChar = getch();
        if (std::isalpha(inputChar) ||
            inputChar == '\n' ||
            inputChar == KEY_UP ||
            inputChar == KEY_DOWN ||
            inputChar == KEY_BACKSPACE)
        {
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
                    printTextInColor(inputWord, 30, LEFT_MARGIN + 40);
                }
                break;
            default:
                inputWord.insert(inputWord.size() - 1, 1, inputChar);
                clear();
                refresh();
                drawFrame();
                drawBanner();
                drawButtons(buttons, starCursor);
                printTextInColor(inputWord, 30, LEFT_MARGIN + 40);
                break;
            }
        }
    }
}

void NewMonthIntro::setCurrentScreen()
{
}
