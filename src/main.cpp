#include <ncurses.h>
#include <cstring>
#include <iostream>
#include <vector>

#include "button.hpp"
#include "definitions.hpp"
#include "decorations.hpp"

void setup()
{
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    start_color();
    initColors();
    drawFrame();
    drawButtons();
    curs_set(0);

    mvprintw(1, LEFT_MARGIN, "*S K R Y B A* CLI FINANCIAL REPORT GENERATOR");
    mvprintw(3, LEFT_MARGIN, "Type 'q' to quit\n");
}

int main()
{
    int inputChar;
    std::string chosenOption;
    setup();
    while (true)
    {
        inputChar = getch();
        switch (inputChar)
        {
        case 'q':
            printTextInColor("Made by PK", 7, LEFT_MARGIN);
            printTextInColor("bye...", 8, LEFT_MARGIN);
            refresh();
            napms(300);
            endwin();
            return 0;
        case KEY_UP:
            upperButton();
            drawButtons();
            break;
        case KEY_DOWN:
            lowerButton();
            drawButtons();
            break;
        case '\n':
            mvprintw(5, LEFT_MARGIN, "You chose: ");
            mvprintw(6, LEFT_MARGIN, starCursor->getLabelText().c_str());
            break;
        default:
            mvprintw(5, LEFT_MARGIN, "%c was pressed! Try again.", inputChar);
            break;
        }
    }
    endwin();
}