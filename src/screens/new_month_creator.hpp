#include <ncurses.h>
#include <iostream>

#pragma once

#include "screens/screen.hpp"
#include "../definitions.hpp"
#include "../decorations.hpp"
#include "../button.hpp"
#include "../inputLabel.hpp"
#include "../purchase.hpp"

class NewMonthCreator : public Screen
{
public:
    void setup() override;
    void loop() override;
    void setCurrentScreen() override;

    int inputChar;
    std::string monthName = "";
    std::string inputWord = "";
    std::vector<Purchase> purchases;
    std::vector<InterfaceElement> interfaceElements;
    std::vector<InterfaceElement>::iterator starCursorOnInterfaceElement;
};