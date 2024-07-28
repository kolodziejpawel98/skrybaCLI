#include <ncurses.h>
#include <string>
#include <vector>

#include "definitions.hpp"
#include "inputLabel.hpp"

InputLabel::InputLabel(std::string enteredContent,
                       uint16_t row,
                       uint16_t column) : enteredContent(enteredContent),
                                          row(row),
                                          column(column) {};

uint16_t &InputLabel::getCol()
{
}

uint16_t &InputLabel::getRow()
{
}