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

extern std::vector<Button> buttons;
extern std::vector<Button>::iterator starCursor;

void goToLowerButton();
void goToUpperButton();
void drawButtons();
