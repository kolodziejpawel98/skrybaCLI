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
        debugPrint("SIMPLE BUTTON", 10, 50);

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
        debugPrint("SUBBUTONZ", 10, 50);
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
    starCursor->starCursorOnSubbutton = starCursor->subButtons.begin();
    if (buttons.size() > 0)
    {
        if (starCursor != buttons.end() - 1)
        {
            // starCursor = starCursorStoredPlace;
            ++starCursor;
        }
        else
        {
            // starCursor = starCursorStoredPlace;
            starCursor = buttons.begin();
        }
    }
    // starCursorStoredPlace = starCursor;
    // updateStarCursor();
}

void goToUpperButton()
{
    starCursor->starCursorOnSubbutton = starCursor->subButtons.begin();
    if (buttons.size() > 0)
    {
        if (starCursor != buttons.begin())
        {
            // starCursor = starCursorStoredPlace;
            --starCursor;
        }
        else
        {
            // starCursor = starCursorStoredPlace;
            starCursor = buttons.end() - 1;
        }
    }
    // starCursorStoredPlace = starCursor;
    // updateStarCursor();
}

void goToLeftButton(std::vector<Button>::iterator &parentButton)
{
    if (parentButton->getButtonType() == SUB_BUTTONS_INSIDE)
    {
        if (parentButton->getSubButtons().size() > 0)
        {
            if (parentButton->starCursorOnSubbutton->getLabelText() == parentButton->subButtons.begin()->getLabelText())
            {
                parentButton->starCursorOnSubbutton = parentButton->subButtons.end() - 1;
                debugPrint(parentButton->starCursorOnSubbutton->getLabelText(), 10, 40);
            }
            else
            {
                --parentButton->starCursorOnSubbutton;
                // debugPrint(parentButton->starCursorOnSubbutton->getLabelText(), 10, 40);
            }
        }
    }
}

void goToRightButton(std::vector<Button>::iterator &parentButton)
{
    if (parentButton->getButtonType() == SUB_BUTTONS_INSIDE)
    {
        if (parentButton->getSubButtons().size() > 0)
        {
            auto help = parentButton->subButtons.end() - 1;
            if (parentButton->starCursorOnSubbutton->getLabelText() == help->getLabelText())
            {
                parentButton->starCursorOnSubbutton = parentButton->subButtons.begin();
                debugPrint(parentButton->starCursorOnSubbutton->getLabelText(), 10, 40);
            }
            else
            {
                ++parentButton->starCursorOnSubbutton;
                // debugPrint(parentButton->starCursorOnSubbutton->getLabelText(), 10, 40);
            }
        }
    }
}

std::vector<Button> &Button::getSubButtons()
{
    return subButtons;
}

std::vector<Button>::iterator &Button::getStarCursorOnSubbutton()
{
    return starCursorOnSubbutton;
}

ButtonType Button::getButtonType()
{
    return buttonType;
}
