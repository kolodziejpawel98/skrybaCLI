#include <ncurses.h>
#include <cstring>
#include <iostream>

enum textColor
{
    red_black = 1,
};

namespace cursor
{
    unsigned short row, col;
};

void printTextInColor(std::string text, unsigned short x, unsigned short y)
{
    mvprintw(x, y, text.c_str());
    getyx(stdscr, cursor::row, cursor::col);
    mvchgat(cursor::row, 0, text.length(), A_BOLD, textColor::red_black, NULL);
}

int main()
{
    int ch;

    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    echo();
    start_color();
    init_pair(textColor::red_black, COLOR_RED, COLOR_BLACK);

    mvprintw(0, 0, "Type 'q' to quit\n");
    char quit_string[10];

    while (true)
    {
        getstr(quit_string);
        if (!strcmp(quit_string, "quit"))
        {
            getyx(stdscr, cursor::row, cursor::col);
            printTextInColor("Made by PK", cursor::row + 1, 0);
            printTextInColor("bye...", cursor::row + 1, 0);
            refresh();
            napms(600);
            break;
        }
        else
        {
            printw("%s was pressed! Try again.\n", quit_string);
        }
        refresh();
    }

    endwin();

    return 0;
}
