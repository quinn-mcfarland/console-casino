/* Includes */
// Primary Header Include
#include "Player.hpp"

// Standard Library Includes
#include <memory>
#include <iostream>

// User-Defined Includes
Player::Player(int m, int b) {
    // acquire resources at initialization
    money = std::make_unique<int>(m);
    bet = std::make_unique<int>(b);
}

void Player::getBet() const {
    do {
        std::cout << "Place your bet (enter 0 to exit): ";
        std::cin >> *bet;
        if (*bet < 0 || *bet > *money) {
            std::cout << "Invalid input. Please try again" << std::endl;
        }
    } while (*bet < 0 || *bet > *money);

    *money -= *bet;
}

void Player::payout(int p) const {
    *money += p;
}