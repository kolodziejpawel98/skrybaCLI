#include "new_month_intro.hpp"

void NewMonthIntro::setup()
{
    clear();
    refresh();
    drawFrame();
    drawBanner();
    debugPrint("NEW MONTH INTRO");
    buttons.emplace_back(Button(inputWord, 38, 4, NEW_MONTH_CREATOR));
    buttons.emplace_back(Button("Cofnij", 39, 4, MAIN_MENU));
    if (!buttons.empty())
    {
        starCursor = buttons.begin();
    }
    drawButtons(buttons, starCursor);
    printTextInColor(inputWord, 30, LEFT_MARGIN + 40);

    inputWord = "[]";
}

void NewMonthIntro::loop()
{
    printTextInColor(monthName, 10, LEFT_MARGIN + 40);
    refresh();
    while (currentScreen == NEW_MONTH_INTRO)
    {
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
                monthName = inputWord;
                inputWord = "[]";
                currentScreen = starCursor->getPointingToScreen();
                break;
            case KEY_BACKSPACE:
                if (inputWord.length() > 2)
                {
                    debugPrint("USUWANA LITERA: " + std::string(1, inputWord.at(inputWord.length() - 2)), 10, 10);
                    inputWord.erase(inputWord.length() - 2, 1);
                    printTextInColor(inputWord, 38, LEFT_MARGIN + 5);
                }
                break;
            default:
                if (starCursor->getRow() == 38)
                {
                    inputWord.insert(inputWord.size() - 1, 1, inputChar);
                    printTextInColor(inputWord, 38, LEFT_MARGIN + 5);
                }
                break;
            }
        }
    }
}

void NewMonthIntro::setCurrentScreen()
{
}
