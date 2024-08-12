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

    std::ofstream outFile("../example.json");

    // json j;
    json j = purchases.at(0);

    outFile << j.dump(4);
    outFile.close();

    // std::ifstream f("../example.json");
    // if (!f)
    // {
    //     std::ofstream newFile("../example.json");
    //     // json emptyData = json::object();

    //     // f.open("../example.json");
    // }
    // json j = purchases.at(0);

    // f.close();
    // json data = json::parse(f);

    // create a person
    // ns::person p{"Ned Flanders", "744 Evergreen Terrace", 60};

    // conversion: person -> json

    // std::cout << j << std::endl;
    // // {"address":"744 Evergreen Terrace","age":60,"name":"Ned Flanders"}

    // // conversion: json -> person
    // auto p2 = j.template get<ns::person>();

    // // that's it
    // assert(p == p2);
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

void to_json(json &j, const Purchase &purchase)
{
    j = json{{"category", purchase.category}, {"cost", purchase.cost}, {"shopName", purchase.shopName}};
}

void from_json(const json &j, Purchase &purchase)
{
    j.at("category").get_to(purchase.category);
    j.at("cost").get_to(purchase.cost);
    j.at("shopName").get_to(purchase.shopName);
}

void SaveList::setCurrentScreen()
{
}