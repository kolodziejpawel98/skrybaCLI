#include <ncurses.h>
#include <iostream>

#pragma once

#include "screens/screen.hpp"
#include "../definitions.hpp"
#include "../decorations.hpp"
#include "../button.hpp"
#include "../purchase.hpp"

#include "../include/json.hpp"

// for convenience
using json = nlohmann::json;

class PurchasesListEdit : public Screen
{
public:
    void setup() override;
    void loop() override;
    void setCurrentScreen() override;
    int inputChar;
    std::vector<Purchase> purchases;
    bool closeWithoutSaving;

    void savePurchasesAsButtons();
    void drawLabelDescription();
    std::vector<Purchase> getUpdatedPurchasesList();
};