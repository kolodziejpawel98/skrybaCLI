#include <ncurses.h>
#include <cstring>
#include <iostream>
#include <vector>

enum textColor
{
    red_black = 1,
    white_black
};

namespace cursor
{
    unsigned short row, col;
};

void debugPrint(std::string text)
{
    int oldRow, oldCol;
    getyx(stdscr, oldRow, oldCol);
    mvprintw(40, 15, text.c_str());

    move(oldRow, oldCol);
}

class Button
{
public:
    Button(std::string labelText, uint16_t row, uint16_t column) : labelText(labelText),
                                                                   row(row),
                                                                   column(column){};
    std::string labelText;
    uint16_t row, column;

    void draw(bool isCursorOnMe = false)
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
};

std::vector<Button> buttons = {
    Button("option 1", 15, 4), Button("option 2", 16, 4), Button("option 3", 17, 4), Button("option 4", 18, 4)};

auto starCursor = buttons.begin();
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

void printTextInColor(std::string text, unsigned short x, unsigned short y)
{
    mvprintw(x, y, text.c_str());
    getyx(stdscr, cursor::row, cursor::col);
    mvchgat(cursor::row, 10, text.length(), A_BOLD, textColor::red_black, NULL);
}

void drawFrame()
{
    uint8_t frameHeigh = 20;
    mvprintw(0, 0, "##########################################\n");
    for (unsigned short i = 1; i < frameHeigh; ++i)
        mvprintw(i, 0, "#");
    mvprintw(frameHeigh, 0, "##########################################\n");
}

void drawButtons()
{
    for (auto &button : buttons)
        button.draw();
    starCursor->draw(true);
}

void drawStarCursor(uint8_t buttonFromTop)
{
    for (unsigned short i = 1; i <= buttons.size(); ++i)
        mvprintw(i + 15, 4, "[ ]");

    attron(A_BOLD | COLOR_PAIR(textColor::red_black));
    mvprintw(buttonFromTop + 15, 4, "[*]");
}

int main()
{
    int ch;

    initscr();
    // cbreak();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    start_color();
    init_pair(textColor::red_black, COLOR_RED, COLOR_BLACK);
    init_pair(textColor::white_black, COLOR_WHITE, COLOR_BLACK);
    drawFrame();
    drawButtons();
    attroff(A_BOLD | COLOR_PAIR(textColor::red_black));
    // drawStarCursor(1);
    curs_set(0);
    mvprintw(1, 10, "Type 'q' to quit\n");
    char quit_string[10];

    while (true)
    {
        getyx(stdscr, cursor::row, cursor::col);
        move(cursor::row, 4);
        // getstr(quit_string);
        ch = getch();

        switch (ch)
        {
        case 'q':
            move(10, 4);
            getyx(stdscr, cursor::row, cursor::col);
            printTextInColor("Made by PK", cursor::row + 1, 10);
            printTextInColor("bye...", cursor::row + 1, 10);
            refresh();
            napms(500);
            endwin();
            return 0;
        case KEY_UP:
            upperButton();
            drawButtons();
            break;
        case KEY_DOWN:
            lowerButton();
            drawButtons();
            break;
        case '\n':
            getyx(stdscr, cursor::row, cursor::col);
            mvprintw(cursor::row, cursor::col + 10, "ENTER was pressed! Try again.\n");
            break;
        default:
            move(10, 4);
            getyx(stdscr, cursor::row, cursor::col);
            mvprintw(cursor::row, cursor::col, "%c was pressed! Try again.\n", ch);
            break;
        }
    }
    endwin();
}