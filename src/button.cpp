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

void Button::temporaryDraw(bool isCursorOnMe)
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

void goToLowerButton(std::vector<Button> &buttons, std::vector<Button>::iterator &starCursor)
{
    if (buttons.size() > 0)
    {
        if (starCursor != buttons.end() - 1)
        {
            ++starCursor;
        }
        else
        {
            starCursor = buttons.begin();
        }
    }
    updateStarCursor(buttons, starCursor);
}

void goToUpperButton(std::vector<Button> &buttons, std::vector<Button>::iterator &starCursor)
{
    if (buttons.size() > 0)
    {
        if (starCursor != buttons.begin())
        {
            --starCursor;
        }
        else
        {
            starCursor = buttons.end() - 1;
        }
    }
    updateStarCursor(buttons, starCursor);
}

void drawButtons(std::vector<Button> &buttons, std::vector<Button>::iterator &starCursor)
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

void updateStarCursor(std::vector<Button> &buttons, std::vector<Button>::iterator &starCursor)
{
    if (starCursor->hasSubButtons())
    {
        starCursor = starCursor->getSubButtons().begin();
    }
}
