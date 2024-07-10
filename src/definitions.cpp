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
    buttons.clear();
    buttons.emplace_back(Button("Create new report", 25, 4, NEW_MONTH_INTRO));
    buttons.emplace_back(Button("Previous reports", 26, 4, HISTORY));
    buttons.emplace_back(Button("Exit", 27, 4, EXIT));
    drawButtons();
    curs_set(0);
    drawBanner();
    mvprintw(13, LEFT_MARGIN, "Type 'q' to quit\n");
}

void exitText()
{
    printTextInColor("Made by PK", 27, LEFT_MARGIN + 40);
    printTextInColor("bye...", 28, LEFT_MARGIN + 40);
    refresh();
    napms(500);
    endwin();
}
