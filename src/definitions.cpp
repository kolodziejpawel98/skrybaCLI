#include "definitions.hpp"

namespace cursor
{
    unsigned short row = 0;
    unsigned short col = 0;
}

int currentScreen = MAIN_MENU;

void initColors()
{
    init_pair(textColor::red_black, COLOR_RED, COLOR_BLACK);
    init_pair(textColor::white_black, COLOR_WHITE, COLOR_BLACK);
    init_pair(textColor::blue_black, COLOR_BLUE, COLOR_BLACK);
    init_pair(textColor::green_black, COLOR_GREEN, COLOR_BLACK);
}
void setup()
{
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    start_color();
    initColors();
    drawFrame();
    curs_set(0);
    drawBanner();
    refresh();
}

void exitText()
{
    printTextInColor("Made by PK", 27, LEFT_MARGIN + 40, textColor::red_black);
    printTextInColor("bye...", 28, LEFT_MARGIN + 40, textColor::red_black);
    refresh();
    napms(500);
    endwin();
}

void refreshScreenWithoutButtons()
{
    clear();
    refresh();
    drawFrame();
    drawBanner();
}

void refreshScreen()
{
    clear();
    refresh();
    drawFrame();
    drawBanner();
    drawButtons();
}

// std::vector<std::string> categories = {
//     "spozywka",
//     "rzeczy",
//     "oplaty stale",
//     "transport (bez jakdojade)",
//     "transport (jakdojade)",
//     "jedzenie na miescie",
//     "jedzenie zamawiane"};

std::vector<Button> buttons = {};
std::vector<Button>::iterator starCursor = buttons.begin();

std::vector<std::string> autofillDictionary = {
    "styczen",
    "luty",
    "marzec",
    "kwiecien",
    "maj",
    "czerwiec",
    "lipiec",
    "sierpien",
    "wrzesien",
    "pazdziernik",
    "listopad",
    "grudzien",
    // ##########
    "spozywka",
    "rzeczy",
    "oplaty stale",
    "transport (bez jakdojade)",
    "transport (jakdojade)",
    "jedzenie na miescie",
    "jedzenie zamawiane",
    // ##########
    "lidl",
    "biedronka",
    "zabka"};

std::string checkAutofill(std::string wordPrefix)
{
    for (const auto &word : autofillDictionary)
    {
        if (word.compare(0, wordPrefix.length(), wordPrefix) == 0)
        {
            return word;
        }
    }
    return wordPrefix;
}