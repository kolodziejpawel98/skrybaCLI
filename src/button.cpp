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
                                                                        buttonType(buttonType){};

void Button::draw(bool isCursorOnMe)
{
    std::string buttonAndText;
    if (!isCursorOnMe)
    {
        attroff(A_BOLD | COLOR_PAIR(textColor::red_black));
        buttonAndText = "[ ]  " + labelText;
        mvprintw(row, column, buttonAndText.c_str());
    }
    else
    {
        attron(A_BOLD | COLOR_PAIR(textColor::red_black));
        buttonAndText = "[*]  " + labelText;
        mvprintw(row, column, buttonAndText.c_str());
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
            debugPrint("ekolpaw 3", 20, 20);
            starCursor = starCursorStoredPlace;
            starCursor = buttons.end() - 1;
        }
    }
    starCursorStoredPlace = starCursor;
    updateStarCursor();
}

void nextButton()
{
    if (starCursor->hasSubButtons())
    {
    }
}

void previousButton()
{
}

void drawButtons()
{
    if (buttons.size() > 0)
    {
        for (auto &button : buttons)
        {
            if (button.getButtonType() == SIMPLE_BUTTON)
            {
                button.draw();
            }
            else
            {
                for (auto &subbutton : button.getSubButtons())
                {
                    subbutton.draw();
                }
            }
        }
        starCursor->draw(true);
        attroff(A_BOLD | COLOR_PAIR(textColor::red_black));
    }
}

std::vector<Button> &Button::getSubButtons()
{
    return subButtons;
}

ButtonType Button::getButtonType()
{
    return buttonType;
}

void updateStarCursor()
{
    if (starCursor->hasSubButtons())
    {
        starCursor = starCursor->getSubButtons().begin();
    }
}
