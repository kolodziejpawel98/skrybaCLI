#include <ncurses.h>
#include <cstring>
#include <iostream>
#include <vector>

enum textColor
{
    red_black = 1,
};

namespace cursor
{
    unsigned short row, col;
};

std::vector<uint8_t> buttons = {1, 2, 3};

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
    for (unsigned short i = 1; i <= buttons.size(); ++i)
        mvprintw(i + 15, 4, "[ ]");
}

void drawStarCursor(uint8_t buttonFromTop)
{
    for (unsigned short i = 1; i <= buttons.size(); ++i)
        mvprintw(i + 15, 4, "[ ]");
    mvprintw(buttonFromTop + 15, 4, "[*]");
}

int main()
{
    int ch;

    initscr();
    // cbreak();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    start_color();
    init_pair(textColor::red_black, COLOR_RED, COLOR_BLACK);
    drawFrame();
    drawButtons();
    drawStarCursor(1);
    curs_set(0);
    mvprintw(1, 10, "Type 'q' to quit\n");
    char quit_string[10];

    while (true)
    {
        getyx(stdscr, cursor::row, cursor::col);
        move(cursor::row, cursor::col + 10);
        // getstr(quit_string);
        ch = getch();

        switch (ch)
        {
        case 'q':
            getyx(stdscr, cursor::row, cursor::col);
            printTextInColor("Made by PK", cursor::row + 1, 10);
            printTextInColor("bye...", cursor::row + 1, 10);
            refresh();
            napms(500);
            endwin();
            return 0;
        case KEY_UP:
            drawStarCursor(1);
            // getyx(stdscr, cursor::row, cursor::col);
            // mvprintw(cursor::row, cursor::col + 1, "KEY_UP was pressed! Try again.\n");
            break;
        case KEY_DOWN:
            drawStarCursor(2);
            // getyx(stdscr, cursor::row, cursor::col);
            // mvprintw(cursor::row, cursor::col + 1, "KEY_DOWN was pressed! Try again.\n");
            break;
        case '\n':
            getyx(stdscr, cursor::row, cursor::col);
            mvprintw(cursor::row, cursor::col + 10, "ENTER was pressed! Try again.\n");
            break;
        default:
            getyx(stdscr, cursor::row, cursor::col);
            mvprintw(cursor::row, cursor::col + 1, "%s was pressed! Try again.\n", quit_string);
            break;
        }
    }
    endwin();

    //     if (ch == KEY_UP)
    //     {
    // getyx(stdscr, cursor::row, cursor::col);
    // printTextInColor("Made by PK", cursor::row + 1, 10);
    // printTextInColor("bye...", cursor::row + 1, 10);
    // refresh();
    // napms(500);
    // break;
    //     }
    //     else
    //     {
    //         getyx(stdscr, cursor::row, cursor::col);
    //         mvprintw(cursor::row, cursor::col + 10, "%s was pressed! Try again.\n", quit_string);
    //     }
    //     refresh();
    // }

    // endwin();
}
