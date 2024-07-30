#include <ncurses.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <memory>

#include "screens/main_menu.hpp"
#include "screens/new_month_intro.hpp"
#include "screens/new_month_creator.hpp"
#include "screens/purchases_list_edit.hpp"
#include "screens/history.hpp"

int main()
{

    std::unique_ptr<MainMenu> mainmenu = std::make_unique<MainMenu>();
    std::unique_ptr<NewMonthIntro> newMonthIntro = std::make_unique<NewMonthIntro>();
    std::unique_ptr<NewMonthCreator> newMonthCreator = std::make_unique<NewMonthCreator>();
    std::unique_ptr<PurchasesListEdit> purchasesListEdit = std::make_unique<PurchasesListEdit>();
    std::unique_ptr<History> history = std::make_unique<History>();

    setup();
    refresh();
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
            if (newMonthIntro->monthName != "")
            {
                newMonthCreator->monthName = newMonthIntro->monthName;
            }
            else
            {
                newMonthCreator->monthName = "empty";
            }

            newMonthCreator->setup();
            newMonthCreator->loop();
            break;
        case PURCHASES_LIST_EDIT:
            purchasesListEdit->setup();
            purchasesListEdit->loop();
            break;
        case HISTORY:
            history->setup();
            history->loop();
            break;
        case EXIT:
            exitText();
            return 0;
        default:
            return 0;
            break;
        }
    }
    endwin();
    return 0;
}
