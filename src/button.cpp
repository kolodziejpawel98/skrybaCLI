#include <ncurses.h>
#include <string>
#include <vector>

#include "definitions.hpp"
#include "button.hpp"

Button::Button(std::string labelText,
               uint16_t row,
               uint16_t column,
               int pointingToScreen,
               ButtonType buttonType) : labelText(labelText),
                                        row(row),
                                        column(column),
                                        pointingToScreen(pointingToScreen),
                                        buttonType(buttonType) {}

Button::Button(std::vector<Button> subButtons, ButtonType buttonType) : subButtons(subButtons),
                                                                        buttonType(buttonType)
{
    starCursorOnSubbutton = subButtons.begin();
};

void drawButtons()
{
    if (buttons.size() > 0)
    {
        for (auto &button : buttons)
        {
            button.draw();
        }
        starCursor->draw(true);
    }
}

void updateStarCursor()
{
    // if (starCursor->hasSubButtons())
    // {
    //     starCursor = starCursor->getSubButtons().begin();
    // }
}

void Button::draw(bool isCursorOnMe)
{
    std::string buttonAndText;

    if (buttonType == SIMPLE_BUTTON)
    {
        buttonAndText = labelText;
        if (isCursorOnMe)
        {
            attron(A_BOLD | COLOR_PAIR(textColor::red_black));
            buttonAndText = "[*]  " + buttonAndText;
            mvprintw(row, column, buttonAndText.c_str());
        }
        else
        {
            attroff(A_BOLD | COLOR_PAIR(textColor::red_black));
            buttonAndText = "[ ]  " + buttonAndText;
            mvprintw(row, column, buttonAndText.c_str());
        }
        attroff(A_BOLD | COLOR_PAIR(textColor::red_black));
    }
    else if (buttonType == SUB_BUTTONS_INSIDE)
    {
        for (auto &subButton : subButtons)
        {
            buttonAndText = subButton.getLabelText();
            row = subButton.getRow();
            column = subButton.getCol();

            attroff(A_BOLD | COLOR_PAIR(textColor::red_black));
            buttonAndText = "[ ]  " + buttonAndText;
            mvprintw(row, column, buttonAndText.c_str());
        }

        if (isCursorOnMe)
        {
            buttonAndText = subButtons.at(0).getLabelText();
            row = subButtons.at(0).row;
            column = subButtons.at(0).column;

            attron(A_BOLD | COLOR_PAIR(textColor::red_black));
            buttonAndText = "[*]  " + buttonAndText;
            mvprintw(row, column, buttonAndText.c_str());
        }
        attroff(A_BOLD | COLOR_PAIR(textColor::red_black));
    }
}

std::string Button::getLabelText()
{
    return labelText;
}

std::string Button::setLabelText(std::string newName)
{
    labelText = newName;
}

int Button::getPointingToScreen()
{
    return pointingToScreen;
}

uint16_t Button::getCol()
{
    return column;
}

uint16_t Button::getRow()
{
    return row;
}

void goToLowerButton()
{
    if (buttons.size() > 0)
    {
        if (starCursor != buttons.end() - 1)
        {
            starCursor = starCursorStoredPlace;
            ++starCursor;
        }
        else
        {
            starCursor = starCursorStoredPlace;
            starCursor = buttons.begin();
        }
    }
    starCursorStoredPlace = starCursor;
    updateStarCursor();
}

void goToUpperButton()
{
    if (buttons.size() > 0)
    {
        if (starCursor != buttons.begin())
        {
            starCursor = starCursorStoredPlace;
            --starCursor;
        }
        else
        {
            starCursor = starCursorStoredPlace;
            starCursor = buttons.end() - 1;
        }
    }
    starCursorStoredPlace = starCursor;
    updateStarCursor();
}

std::vector<Button> &Button::getSubButtons()
{
    return subButtons;
}

ButtonType Button::getButtonType()
{
    return buttonType;
}
