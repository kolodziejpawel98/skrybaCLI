#include <ncurses.h>
#include <iostream>

#pragma once

#include "screens/screen.hpp"
#include "../definitions.hpp"
#include "../decorations.hpp"
#include "../button.hpp"
#include "../purchase.hpp"

class PurchasesListEdit : public Screen
{
public:
    void setup() override;
    void loop() override;
    void setCurrentScreen() override;
    int inputChar;
    std::vector<Purchase> purchases;

    void savePurchasesAsButtons();
    void drawLabelDescription();
    std::vector<Purchase> getUpdatedPurchasesList();
};