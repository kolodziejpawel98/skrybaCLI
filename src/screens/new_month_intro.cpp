#include "new_month_intro.hpp"

void NewMonthIntro::setup()
{
    refreshScreenWithoutButtons();
    buttons.clear();
    buttons.emplace_back(Button("Next", 38, 4, NEW_MONTH_CREATOR));
    buttons.emplace_back(Button("Back", 39, 4, MAIN_MENU));
    if (!buttons.empty())
    {
        starCursor = buttons.begin();
    }
    drawButtons();
    printTextInColor("Month name: ", 36, LEFT_MARGIN, textColor::white_black);
}

std::string NewMonthIntro::checkAutofill(std::string wordPrefix)
{
    for (const auto &word : autofillDictionary)
    {
        if (word.compare(0, wordPrefix.length(), wordPrefix) == 0)
        {
            return word;
        }
    }
    return "";
}

void NewMonthIntro::loop()
{

    while (currentScreen == NEW_MONTH_INTRO)
    {
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
                printTextInColor("Month name: " + inputWord, 36, LEFT_MARGIN, textColor::white_black);
            }
            break;
        case '\t':
            refreshScreen();
            printTextInColor("Month name: ", 36, LEFT_MARGIN, textColor::white_black);
            if (inputWord.length() > 0)
            {
                inputWord = checkAutofill(inputWord);
            }
            printTextInColor(
                inputWord,
                37,
                LEFT_MARGIN,
                textColor::red_black);
            break;
        default:
            inputWord += inputChar;

            if (inputWord.length() > 0)
            {
                refreshScreen();
                printTextInColor("Month name: ", 36, LEFT_MARGIN, textColor::white_black);

                printTextInColor(
                    checkAutofill(inputWord),
                    37,
                    LEFT_MARGIN,
                    textColor::white_black, false);
                printTextInColor(
                    inputWord,
                    37,
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
