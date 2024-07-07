#include <ncurses.h>
#include <iostream>

#pragma once

class Screen
{
public:
    virtual void setup() = 0;
    virtual void loop() = 0;
    virtual void setCurrentScreen() = 0;
};