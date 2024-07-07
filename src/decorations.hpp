#include <ncurses.h>
#include <iostream>

#pragma once

void drawFrame();
void drawBanner();
void printTextInColor(std::string, unsigned short, unsigned short);
void debugPrint(std::string);