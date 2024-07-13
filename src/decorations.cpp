#include "decorations.hpp"
#include "definitions.hpp"

void drawFrame()
{
    uint8_t frameHeigh = 42;
    mvprintw(0, 0, "############################################################################################################################");
    for (unsigned short i = 1; i < frameHeigh; ++i)
        mvprintw(i, 0, "#");
    mvprintw(frameHeigh, 0, "############################################################################################################################");
}

void drawBanner()
{
    mvprintw(1, LEFT_MARGIN, "   _____   _  __  _____   __     __  ____                  _____   _        _____ ");
    mvprintw(2, LEFT_MARGIN, "  / ____| | |/ / |  __ \\  \\ \\   / / |  _ \\      /\\        / ____| | |      |_   _|");
    mvprintw(3, LEFT_MARGIN, " | (___   | ' /  | |__) |  \\ \\_/ /  | |_) |    /  \\      | |      | |        | |  ");
    mvprintw(4, LEFT_MARGIN, "  \\___ \\  |  <   |  _  /    \\   /   |  _ <    / /| \\     | |      | |        | |  ");
    mvprintw(5, LEFT_MARGIN, "  ____) | | . \\  | | \\ \\     | |    | |_) |  / ____ \\    | |____  | |____   _| |_ ");
    mvprintw(6, LEFT_MARGIN, " |_____/  |_ \\_\\ |_|  \\_\\    |_|    |____/  /_/    \\_\\    \\_____| |______| |_____|");
    mvprintw(7, LEFT_MARGIN, "                                                                              ");
}

void printTextInColor(std::string text, unsigned short row, unsigned short col, int textColor)
{
    mvprintw(row, col, text.c_str());
    mvchgat(row, col, text.length(), A_BOLD, textColor, NULL);
}

void debugPrint(std::string text, int row, int col)
{
    int oldRow, oldCol;
    getyx(stdscr, oldRow, oldCol);
    mvprintw(row, col, text.c_str());
    move(oldRow, oldCol);
}
