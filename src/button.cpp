#include <ncurses.h>
#include <string>
#include <vector>

#include "button.hpp"
#include "definitions.hpp"

Button::Button(std::string labelText,
               uint16_t row,
               uint16_t column,
               int nextScreen) : labelText(labelText),
                                 row(row),
                                 column(column),
                                 nextScreen(nextScreen) {}

Button::Button(std::string labelText,
               uint16_t row,
               uint16_t column) : labelText(labelText),
                                  row(row),
                                  column(column),
                                  nextScreen(EMPTY) {}

Button::Button(std::vector<Button> subButtons) : subButtons(subButtons)
{
    this->starCursorOnSubbutton = this->subButtons.begin();
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
        buttonAndText = this->labelText;
        if (isCursorOnMe)
        {
            attron(A_BOLD | COLOR_PAIR(textColor::red_black));
            buttonAndText = "[*]  " + buttonAndText;
            mvprintw(this->row, this->column, buttonAndText.c_str());
        }
        else
        {
            attroff(A_BOLD | COLOR_PAIR(textColor::red_black));
            buttonAndText = "[ ]  " + buttonAndText;
            mvprintw(this->row, this->column, buttonAndText.c_str());
        }
        attroff(A_BOLD | COLOR_PAIR(textColor::red_black));
    }
    else if (hasSubButtons())
    {
        for (auto &subButton : this->subButtons)
        {
            buttonAndText = subButton.getLabelText();

            attroff(A_BOLD | COLOR_PAIR(textColor::red_black));
            buttonAndText = "[ ]  " + buttonAndText;
            mvprintw(subButton.getRow(), subButton.getCol(), buttonAndText.c_str());
        }

        if (isCursorOnMe)
        {
            buttonAndText = starCursorOnSubbutton->getLabelText();

            attron(A_BOLD | COLOR_PAIR(textColor::red_black));
            buttonAndText = "[*]  " + buttonAndText;
            mvprintw(this->starCursorOnSubbutton->row, this->starCursorOnSubbutton->column, buttonAndText.c_str());
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