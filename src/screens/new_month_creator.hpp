#include <ncurses.h>
#include <iostream>

#pragma once

#include "screens/screen.hpp"
#include "../definitions.hpp"
#include "../decorations.hpp"
#include "../button.hpp"
#include "../purchase.hpp"

class NewMonthCreator : public Screen
{
public:
    void setup() override;
    void loop() override;
    void setCurrentScreen() override;

    int inputChar;
    int help = 0;
    std::string monthName = "";
    std::string inputWord = "";
    std::vector<Purchase> purchases;
    std::vector<Button>::iterator starCursorOnInterfaceElement;
    void drawEnteredPurchases();
};