#include <ncurses.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <memory>

#include "screens/main_menu.hpp"
#include "screens/new_month_intro.hpp"
#include "screens/new_month_creator.hpp"
#include "screens/history.hpp"

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
    std::unique_ptr<NewMonthIntro> newMonthIntro = std::make_unique<NewMonthIntro>();
    std::unique_ptr<NewMonthCreator> newMonthCreator = std::make_unique<NewMonthCreator>();
    std::unique_ptr<History> history = std::make_unique<History>();

    setup();
    while (true)
    {

        switch (currentScreen)
        {
        case MAIN_MENU:
            mainmenu->setup();
            mainmenu->loop();
            break;
        case NEW_MONTH_INTRO:
            newMonthIntro->setup();
            newMonthIntro->loop();
            break;
        case NEW_MONTH_CREATOR:
            newMonthCreator->setup();
            newMonthCreator->loop();
            break;
        case HISTORY:
            history->setup();
            history->loop();
            break;
        case EXIT:
            return 0;
            break;
        default:
            return 0;
            break;
        }
    }

    endwin();
    return 0;
}
