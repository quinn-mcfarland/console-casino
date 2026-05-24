#include <iostream>

#include "utilities.h"
#include "card.h"
#include "CardDeck.h"
#include "player.h"

void clearConsole() {
    std::cout << "\n\n\n\n\n\n\n\n\n\n" << std::endl;
}

void getBet(player* activePlayer) {
    int betAmount;

    // Prompt player for bet
    do {
        std::cout << "Place your bet please (enter 0 to exit): ";
        std::cin >> betAmount;
        if (betAmount < 0 || betAmount > (*activePlayer->getMoney())) {
            std::cout << "Invalid amount, please try again." << std::endl;
        }

    } while (betAmount < 0 || betAmount > (*activePlayer->getMoney()));

    if (betAmount > 0) {
        activePlayer->setMoney(activePlayer->getMoney() - betAmount);
        activePlayer->setBetAmount(&betAmount);
    }
}