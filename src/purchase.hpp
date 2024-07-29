#include <ncurses.h>
#include <string>
#include <vector>

#pragma once

class Purchase
{
public:
    Purchase(std::string, std::string, std::string);

    std::string category;
    std::string cost;
    std::string shopName;
};