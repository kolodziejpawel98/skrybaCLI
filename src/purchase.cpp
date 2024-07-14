#include <ncurses.h>
#include <string>
#include <vector>

#include "definitions.hpp"
#include "purchase.hpp"

Purchase::Purchase(std::string category, int cost, std::string shopName) : category(category), cost(cost), shopName(shopName){};
