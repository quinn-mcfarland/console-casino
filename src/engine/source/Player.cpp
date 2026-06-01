#include "Player.hpp"

#include <memory>
#include <iostream>

/**
 * @brief Constructs a new Player object with parameters for variable initialization
 *
 * @param m Starting money
 * @param b Starting bet (should be 0)
 */
Player::Player(int m, int b) {
    // acquire resources at initialization
    money = std::make_unique<int>(m);
    bet = std::make_unique<int>(b);
}

/**
 * @brief Collects a bet from the player
 */
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

/**
 * @brief Pays a player out on the bet
 *
 * @param p The amount to pay the player
 */
void Player::payout(int p) const {
    *money += p;
}