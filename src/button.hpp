#include <ncurses.h>
#include <string>
#include <vector>

#pragma once

class Button
{
public:
    Button(std::string, uint16_t, uint16_t, int);
    Button(std::string, uint16_t, uint16_t);
    Button(std::vector<Button>);
    void draw(bool isCursorOnMe = false);
    std::string &getLabelText() { return labelText; }
    void setLabelText(std::string newName) { labelText = newName; }
    void addCharToLabelText(char letter) { labelText += letter; }
    int getPointingToScreen() { return nextScreen; }
    std::vector<Button> &getSubButtons() { return subButtons; }
    uint16_t &getCol() { return column; }
    uint16_t &getRow() { return row; }
    std::vector<Button>::iterator &getStarCursorOnSubbutton() { return starCursorOnSubbutton; }
    bool hasSubButtons() const { return !subButtons.empty(); }

private:
    std::string labelText;
    uint16_t row, column; // change to std::optional in case creating button with subbutons, row and column is empty
    int nextScreen;
    std::vector<Button> subButtons;
    std::vector<Button>::iterator starCursorOnSubbutton;
};

void goToLowerButton();
void goToUpperButton();
void goToLeftButton();
void goToRightButton();
void drawButtons();