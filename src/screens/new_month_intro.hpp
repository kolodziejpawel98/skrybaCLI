#include <ncurses.h>
#include <iostream>

#pragma once

#include "screens/screen.hpp"
#include "../definitions.hpp"
#include "../decorations.hpp"
#include "../button.hpp"

class NewMonthIntro : public Screen
{
public:
    void setup() override;
    void loop() override;
    void setCurrentScreen() override;
    std::string checkAutofill(std::string);

    int inputChar;
    std::string inputWord = "[]";
    std::string monthName = "";
};