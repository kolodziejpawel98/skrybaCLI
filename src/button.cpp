#include <ncurses.h>
#include <string>
#include <vector>

#include "definitions.hpp"
#include "button.hpp"

Button::Button(std::string labelText,
               uint16_t row,
               uint16_t column,
               int nextScreen) : labelText(labelText),
                                 row(row),
                                 column(column),
                                 nextScreen(nextScreen) {}

Button::Button(std::vector<Button> subButtons) : subButtons(subButtons)
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

void Button::draw(bool isCursorOnMe)
{
    std::string buttonAndText;

    if (!hasSubButtons())
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
    else if (hasSubButtons())
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
            buttonAndText = starCursorOnSubbutton->getLabelText();
            row = starCursorOnSubbutton->row;
            column = starCursorOnSubbutton->column;

            attron(A_BOLD | COLOR_PAIR(textColor::red_black));
            buttonAndText = "[*]  " + buttonAndText;
            mvprintw(row, column, buttonAndText.c_str());
        }
        attroff(A_BOLD | COLOR_PAIR(textColor::red_black));
    }
}

void goToLowerButton()
{
    starCursor->getStarCursorOnSubbutton() = starCursor->getSubButtons().begin();
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
}

void goToUpperButton()
{
    starCursor->getStarCursorOnSubbutton() = starCursor->getSubButtons().begin();
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
}

void goToLeftButton()
{
    if (starCursor->hasSubButtons())
    {
        if (starCursor->getSubButtons().size() > 0)
        {
            if (starCursor->getStarCursorOnSubbutton() == starCursor->getSubButtons().begin())
            {
                starCursor->getStarCursorOnSubbutton() = starCursor->getSubButtons().end() - 1;
            }
            else
            {
                --(starCursor->getStarCursorOnSubbutton());
            }
        }
    }
}

void goToRightButton()
{
    if (starCursor->hasSubButtons())
    {
        if (starCursor->getSubButtons().size() > 0)
        {
            if (starCursor->getStarCursorOnSubbutton() == starCursor->getSubButtons().end() - 1)
            {
                starCursor->getStarCursorOnSubbutton() = starCursor->getSubButtons().begin();
            }
            else
            {
                ++(starCursor->getStarCursorOnSubbutton());
            }
        }
    }
}