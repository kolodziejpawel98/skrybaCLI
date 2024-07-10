#include <ncurses.h>
#include <string>
#include <vector>

#include "definitions.hpp"
#include "button.hpp"

Button::Button(std::string labelText,
               uint16_t row,
               uint16_t column,
               int pointingToScreen) : labelText(labelText),
                                       row(row),
                                       column(column),
                                       pointingToScreen(pointingToScreen) {}

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

int Button::getPointingToScreen()
{
    return pointingToScreen;
}

std::vector<Button> buttons = {
    Button("Create new report", 25, 4, NEW_MONTH_INTRO),
    Button("Previous reports", 26, 4, HISTORY),
    Button("Exit", 27, 4, EXIT)};

std::vector<Button>::iterator starCursor = buttons.begin();

void goToLowerButton()
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
}

void goToUpperButton()
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
}

void drawButtons()
{
    if (buttons.size() > 0)
    {
        for (auto &button : buttons)
            button.draw();
        starCursor->draw(true);
        attroff(A_BOLD | COLOR_PAIR(textColor::red_black));
    }
}
