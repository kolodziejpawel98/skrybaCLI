#include <ncurses.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <memory>

#include "screens/screen_main_menu.hpp"

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

    drawBanner();
    mvprintw(13, LEFT_MARGIN, "Type 'q' to quit\n");
}

int main()
{
    std::unique_ptr<MainMenu> mainmenu = std::make_unique<MainMenu>();
    setup();
    while (true)
    {
        switch (currentScreen)
        {
        case MAIN_MENU:
            mainmenu->loop();
            break;
        case NEW_MONTH_PRE_INPUT:

            break;
        case NEW_MONTH_CREATOR:

            break;
        case HISTORY:

            break;
        case EXIT:
            return 0;
            break;
        }
    }

    endwin();
    return 0;
}
