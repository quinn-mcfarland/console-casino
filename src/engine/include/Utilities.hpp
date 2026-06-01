#ifndef UTILITIES_HPP
#define UTILITIES_HPP
/* Includes */
// Standard Library Includes
#include <vector>
#include <array>
#include <memory>

// User-Defined Includes
#include "Card.hpp"

// Function Prototypes
void clearConsole();
void createCardDeck(std::array<std::unique_ptr<Card>, 52> deck, bool needsRanks, bool needsSuits, bool needsValues);
void shuffleDeck(std::array<std::unique_ptr<Card>, 52> deck);
void dealOneCard(std::vector<std::unique_ptr<Card>> hand, std::array<std::unique_ptr<Card>, 52> deck);

#endif
