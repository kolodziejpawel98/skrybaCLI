#include <ncurses.h>
#include <string>
#include <vector>

#include "interfaceElement.hpp"

#pragma once

class InputLabel : public InterfaceElement
{
public:
    InputLabel(std::string, uint16_t, uint16_t);
    void temporaryDraw(bool isCursorOnMe = false) override;
    uint16_t getCol() override;
    uint16_t getRow() override;
    uint16_t row, column;
    std::string enteredContent;
};
