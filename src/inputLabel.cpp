#include <ncurses.h>
#include <string>
#include <vector>

#include "definitions.hpp"
#include "inputLabel.hpp"

InputLabel::InputLabel(std::string enteredContent,
                       uint16_t row,
                       uint16_t column) : enteredContent(enteredContent),
                                          row(row),
                                          column(column){};

void InputLabel::temporaryDraw(bool isCursorOnMe)
{
    if (!isCursorOnMe)
    {
        attroff(A_BOLD | COLOR_PAIR(textColor::red_black));
        mvprintw(row, column, enteredContent.c_str());
    }
    else
    {
        attron(A_BOLD | COLOR_PAIR(textColor::red_black));
        mvprintw(row, column, enteredContent.c_str());
    }
}

uint16_t InputLabel::getCol()
{
}

uint16_t InputLabel::getRow()
{
}