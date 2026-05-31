#include "../include/Player.hpp"
#include <iostream>

void Player::getPlayerBet() {
  std::cout << "You have $" << money << std::endl;

  do {
    std::cout << "Place your bet (enter 0 to exit): ";
    std::cin >> betAmount;
    if (betAmount < 0 || betAmount > money) {
      std::cout << "Invalid bet amount. Please try again." << std::endl;
    }
  } while (betAmount < 0 || betAmount > money);

  if (betAmount > 0) {
    money -= betAmount;
  }
}

void Player::getInsuranceBet() {
  std::cout << "You have $" << money << std::endl;

  do {
    std::cout << "Place your bet (enter 0 to decline insurance): ";
    std::cin >> insuranceBetAmount;
    if (insuranceBetAmount < 0 || insuranceBetAmount> money) {
      std::cout << "Invalid bet amount. Please try again." << std::endl;
    }
  } while (insuranceBetAmount < 0 || insuranceBetAmount > money);

  if (insuranceBetAmount > 0) {
    money -= insuranceBetAmount;
  }
}