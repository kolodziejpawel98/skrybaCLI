// src/main.cpp
#include <ncurses.h>

int main() {
    // Inicjalizacja ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // Wyświetlenie tekstu na ekranie
    printw("Hello, world!");
    refresh();

    // Czekaj na naciśnięcie klawisza
    getch();

    // Zakończenie pracy z ncurses
    endwin();

    return 0;
}

