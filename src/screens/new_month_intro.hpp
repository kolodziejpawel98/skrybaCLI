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
    std::vector<Button> buttons;
    std::vector<Button>::iterator starCursor;
    std::vector<std::string> autofillDictionary = {"styczen",
                                                   "luty",
                                                   "marzec",
                                                   "kwiecien",
                                                   "maj",
                                                   "czerwiec",
                                                   "lipiec",
                                                   "sierpien",
                                                   "wrzesien",
                                                   "pazdziernik",
                                                   "listopad",
                                                   "grudzien"};
};