#include <ncurses.h>
#include <string>
#include <vector>

#include "definitions.hpp"
#include "button.hpp"

Button::Button(std::string labelText, uint16_t row, uint16_t column) : labelText(labelText),
                                                                       row(row),
                                                                       column(column) {}

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

std::vector<Button> buttons = {
    Button("option 1", 15, 4),
    Button("option 2", 16, 4),
    Button("option 3", 17, 4),
    Button("option 4", 18, 4)};

std::vector<Button>::iterator starCursor = buttons.begin();

void lowerButton()
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

void upperButton()
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

void drawButtons()
{
    for (auto &button : buttons)
        button.draw();
    starCursor->draw(true);
    attroff(A_BOLD | COLOR_PAIR(textColor::red_black));
}
