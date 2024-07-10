#include <ncurses.h>
#include <string>
#include <vector>

#pragma once

class Button
{
public:
    Button(std::string, uint16_t, uint16_t, int);
    void draw(bool isCursorOnMe = false);
    std::string getLabelText();
    int getPointingToScreen();

private:
    std::string labelText;
    uint16_t row, column;
    int pointingToScreen;
};
void goToLowerButton(std::vector<Button> &buttons, std::vector<Button>::iterator &starCursor);
void goToUpperButton(std::vector<Button> &buttons, std::vector<Button>::iterator &starCursor);
void drawButtons(std::vector<Button> &buttons, std::vector<Button>::iterator &starCursor);
