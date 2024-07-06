#include <ncurses.h>

int main()
{
    int ch;

    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    echo();

    printw("Type 'q' to quit or press Ctrl+C to exit\n");
    while (true)
    {
        ch = getch();
        if (ch == 'q')
        {
            printw("\nbye...");
            refresh();
            napms(600);
            break;
        }
        else
        {
            printw(" was pressed! Try again.\n");
        }
        refresh();
    }

    endwin();

    return 0;
}
