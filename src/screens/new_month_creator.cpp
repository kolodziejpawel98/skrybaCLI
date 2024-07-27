#include "new_month_creator.hpp"

void NewMonthCreator::setup()
{
    clear();
    refresh();
    drawFrame();
    drawBanner();

    // interfaceElements.clear();
    // interfaceElements.push_back(Button("Cofnij", 20, LEFT_MARGIN, NEW_MONTH_INTRO));
    // interfaceElements.push_back(InputLabel("[]", 21, LEFT_MARGIN));
    // interfaceElements.push_back(InputLabel("[]", 22, LEFT_MARGIN));
    // if (!interfaceElements.empty())
    // {
    //     starCursorOnInterfaceElement = interfaceElements.begin();
    // }
    // for (auto &interfaceElement : interfaceElements)
    // {
    //     interfaceElement.temporaryDraw();
    // }

    // purchases.push_back(Purchase("[]", 0, "[]"));
    buttons.clear();
    // buttons.emplace_back(Button(purchases[0].category, 36, 4, EMPTY));
    // buttons.emplace_back(Button("[" + std::to_string(purchases[0].cost) + "]", 37, 4, EMPTY));
    // buttons.emplace_back(Button(purchases[0].shopName, 38, 4, EMPTY));
    // buttons.emplace_back(Button("xd", 37, 4, NEW_MONTH_INTRO));

    buttons.emplace_back(Button({Button("Button1", 38, 4, 1),
                                 Button("Button2", 38, 32, 1),
                                 Button("Button3", 38, 52, 1)}));
    buttons.emplace_back(Button("Cofnij", 39, 4, NEW_MONTH_INTRO));
    buttons.emplace_back(Button("Cofnij-2", 40, 4, NEW_MONTH_INTRO));
    if (!buttons.empty())
    {
        starCursor = buttons.begin();
    }
    starCursorStoredPlace = starCursor;
    drawButtons();
}

void NewMonthCreator::loop()
{

    while (currentScreen == NEW_MONTH_CREATOR)
    {
        printTextInColor("Month: " + monthName, 8, LEFT_MARGIN, textColor::white_black);
        // refresh();
        inputChar = getch();
        switch (inputChar)
        {
        case KEY_UP:
            goToUpperButton();
            drawButtons();
            break;
        case KEY_DOWN:
            goToLowerButton();
            drawButtons();
            break;
        case KEY_LEFT:
            goToUpperButton();
            drawButtons();
            break;
        case KEY_RIGHT:
            goToLowerButton();
            drawButtons();
            break;
        case '\n': // ENTER
            // inputWord.substr(1, inputWord.size() - 2)
            if (starCursor->getLabelText() == "Cofnij")
            {
                currentScreen = starCursor->getPointingToScreen();
            }
            //     else
            //     {
            //         std::string newPurchaseCellText = inputWord.substr(1, inputWord.size() - 2);
            //         starCursor->setLabelText(newPurchaseCellText);
            //         inputWord = "[]";
            //         clear();
            //         refresh();
            //         drawFrame();
            //         drawBanner();
            //         drawButtons();
            //         printTextInColor("[" + newPurchaseCellText + "]", starCursor->getRow(), LEFT_MARGIN, textColor::white_black);
            //     }
            break;
            // case KEY_BACKSPACE:
            //     if (inputWord.length() > 2)
            //     {
            //         inputWord.erase(inputWord.length() - 2, 1);
            //         clear();
            //         refresh();
            //         drawFrame();
            //         drawBanner();
            //         drawButtons();
            //         printTextInColor("Purchase: " + inputWord, 35, LEFT_MARGIN, textColor::white_black);
            //     }
            //     break;
            // default:
            //     inputWord.insert(inputWord.size() - 1, 1, inputChar);
            //     starCursor->setLabelText(inputWord);
            //     clear();
            //     refresh();
            //     drawFrame();
            //     drawBanner();
            //     drawButtons();
            //     printTextInColor(starCursor->getLabelText(), starCursor->getRow(), LEFT_MARGIN, textColor::white_black);
            //     break;
        }
    }
}

void NewMonthCreator::setCurrentScreen()
{
}
