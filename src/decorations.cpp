#include "decorations.hpp"
#include "definitions.hpp"

void drawFrame()
{
    uint8_t frameHeigh = 20;
    mvprintw(0, 0, "##########################################\n");
    for (unsigned short i = 1; i < frameHeigh; ++i)
        mvprintw(i, 0, "#");
    mvprintw(frameHeigh, 0, "##########################################\n");
}

void printTextInColor(std::string text, unsigned short row, unsigned short col)
{
    mvprintw(row, col, text.c_str());
    mvchgat(row, col, text.length(), A_BOLD, textColor::red_black, NULL);
}

void debugPrint(std::string text)
{
    int oldRow, oldCol;
    getyx(stdscr, oldRow, oldCol);
    mvprintw(40, 15, text.c_str());
    move(oldRow, oldCol);
}
