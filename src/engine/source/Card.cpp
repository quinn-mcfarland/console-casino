#include "Card.hpp"

#include <string>
#include <memory>

/**
 * @brief Parameterized Constructor for the Card class
 *
 * @param r The card's rank
 * @param s The card's suit
 * @param v The card's blackjack value
 */
Card::Card(std::string r, std::string s, int v) {
    rank = std::make_unique<std::string>(r);
    suit = std::make_unique<std::string>(s);
    value = std::make_unique<int>(v);
}