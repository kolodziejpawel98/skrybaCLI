#include <ncurses.h>
#include <string>
#include <vector>

#pragma once

class Purchase
{
public:
    Purchase(std::string, int, std::string);

    std::string category;
    int cost;
    std::string shopName;
};