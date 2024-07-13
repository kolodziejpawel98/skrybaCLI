#include <ncurses.h>
#include <iostream>

#pragma once

void drawFrame();
void drawBanner();
void printTextInColor(std::string, unsigned short, unsigned short, int);
void debugPrint(std::string, int = 30, int = 25);