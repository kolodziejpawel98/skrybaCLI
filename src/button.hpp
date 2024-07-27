#include <ncurses.h>
#include <string>
#include <vector>

#include "interfaceElement.hpp"

#pragma once

enum ButtonType
{
    SIMPLE_BUTTON,
    SUB_BUTTONS_INSIDE,
    SUBBUTTON
};

class Button : public InterfaceElement
{
public:
    Button(std::string, uint16_t, uint16_t, int, ButtonType = SIMPLE_BUTTON);
    Button(std::vector<Button>, ButtonType = SUB_BUTTONS_INSIDE);
    void draw(bool isCursorOnMe = false);
    std::string getLabelText();
    std::string setLabelText(std::string newName);
    int getPointingToScreen();
    std::vector<Button> &getSubButtons();
    ButtonType getButtonType();
    uint16_t getCol() override;
    uint16_t getRow() override;
    bool hasSubButtons() const { return !subButtons.empty(); }

private:
    std::string labelText;
    uint16_t row, column; // change to std::optional in case creating button with subbutons, row and column is empty
    int pointingToScreen;
    std::vector<Button> subButtons;
    std::vector<Button>::iterator starCursorOnSubbutton;
    ButtonType buttonType;
};

void goToLowerButton();
void goToUpperButton();
void drawButtons();
void updateStarCursor();
