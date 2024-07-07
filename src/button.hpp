#include <ncurses.h>
#include <string>
#include <vector>

#pragma once

class Button
{
public:
    Button(std::string, uint16_t, uint16_t);
    void draw(bool isCursorOnMe = false);
    std::string getLabelText();

private:
    std::string labelText;
    uint16_t row, column;
};

extern std::vector<Button> buttons;
extern std::vector<Button>::iterator starCursor;

void lowerButton();
void upperButton();
void drawButtons();
