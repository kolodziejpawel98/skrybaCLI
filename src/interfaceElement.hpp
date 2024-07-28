#include <ncurses.h>
#include <string>
#include <vector>

#pragma once

class InterfaceElement
{
public:
    virtual uint16_t &getCol() = 0;
    virtual uint16_t &getRow() = 0;
    uint16_t row, column;
};
