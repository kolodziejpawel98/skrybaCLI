#include <ncurses.h>
#include <cstring>

int main()
{
    int ch;

    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    echo();

    mvprintw(10, 0, "Type 'q' to quit\n");
    char quit_string[10];
    while (true)
    {
        getstr(quit_string);
        if (!strcmp(quit_string, "quit"))
        {
            printw("\nbye...");
            refresh();
            napms(400);
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