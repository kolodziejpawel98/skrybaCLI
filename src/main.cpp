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
    mvchgat(cursor::row, 10, text.length(), A_BOLD, textColor::red_black, NULL);
}

void drawFrame()
{
    uint8_t frameHeigh = 20;
    mvprintw(0, 0, "##########################################\n");
    for (unsigned short i = 1; i < frameHeigh; ++i)
        mvprintw(i, 0, "#");
    mvprintw(frameHeigh, 0, "##########################################\n");
}

void drawButtons()
{
    for (unsigned short i = 1; i <= 3; ++i)
        mvprintw(i + 15, 4, "[ ]");
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
    drawFrame();
    drawButtons();
    mvprintw(1, 10, "Type 'q' to quit\n");
    char quit_string[10];

    while (true)
    {
        getyx(stdscr, cursor::row, cursor::col);
        move(cursor::row, cursor::col + 10);
        getstr(quit_string);
        if (!strcmp(quit_string, "quit"))
        {
            getyx(stdscr, cursor::row, cursor::col);
            printTextInColor("Made by PK", cursor::row + 1, 10);
            printTextInColor("bye...", cursor::row + 1, 10);
            refresh();
            napms(500);
            break;
        }
        else
        {
            getyx(stdscr, cursor::row, cursor::col);
            mvprintw(cursor::row, cursor::col + 10, "%s was pressed! Try again.\n", quit_string);
        }
        refresh();
    }

    endwin();

    return 0;
}
