#include "save_list.hpp"

void SaveList::setup()
{
    debugPrint("SAVE!!!");

    refreshScreenWithoutButtons();
    buttons.clear();
    buttons.emplace_back(Button("Back", FIRST_BUTTON_ROW, FIRST_BUTTON_COL, NEW_MONTH_CREATOR));
    if (!buttons.empty())
    {
        starCursor = buttons.end() - 1;
    }

    drawButtons();
    std::ifstream f("../example.json");
    if (!f)
    {
        std::ofstream newFile("../example.json");
        json emptyData = json::object();

        newFile.close();
        f.open("../example.json");
    }
    json data = json::parse(f);
}

void SaveList::loop()
{
    refresh();
    while (currentScreen == SAVE_LIST)
    {
        inputChar = getch();
        switch (inputChar)
        {
        case KEY_UP:
            goToUpperButton();
            drawButtons();
            break;
        case KEY_DOWN:
            goToLowerButton();
            drawButtons();
            break;
        case '\n':
            currentScreen = starCursor->getPointingToScreen();
            break;
        }
    }
}

void SaveList::setCurrentScreen()
{
}