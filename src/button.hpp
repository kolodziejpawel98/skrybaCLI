#include <ncurses.h>
#include <string>
#include <vector>

#include "interfaceElement.hpp"

#pragma once

class Button : public InterfaceElement
{
public:
    Button(std::string, uint16_t, uint16_t, int);
    void draw(bool isCursorOnMe = false);
    void temporaryDraw(bool isCursorOnMe = false) override;
    std::string getLabelText();
    std::string setLabelText(std::string newName);
    int getPointingToScreen();
    uint16_t getCol() override;
    uint16_t getRow() override;

private:
    std::string labelText;
    uint16_t row, column;
    int pointingToScreen;
};

void goToLowerButton(std::vector<Button> &buttons, std::vector<Button>::iterator &starCursor);
void goToUpperButton(std::vector<Button> &buttons, std::vector<Button>::iterator &starCursor);
void drawButtons(std::vector<Button> &buttons, std::vector<Button>::iterator &starCursor);
