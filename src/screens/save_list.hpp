#include <ncurses.h>
#include <iostream>

#pragma once

#include "screens/screen.hpp"
#include "../definitions.hpp"
#include "../decorations.hpp"
#include "../button.hpp"
#include "../purchase.hpp"

#include "../include/json.hpp"
#include <fstream>

// for convenience
using json = nlohmann::json;

class SaveList : public Screen
{
public:
    void setup() override;
    void loop() override;
    void setCurrentScreen() override;
    int inputChar;
};