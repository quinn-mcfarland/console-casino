#ifndef UTILITIES_HPP
#define UTILITIES_HPP

// Standard Library Includes
#include <vector> // Handles vector containers
#include <array> // Handles array containers
#include <memory> // Handles smart pointers

// User-Defined Includes
#include "Card.hpp" // Card class

// Function Prototypes
void clearConsole();
void createCardDeck(std::array<std::unique_ptr<Card>, 52> deck, bool needsRanks, bool needsSuits, bool needsValues);
void shuffleDeck(std::array<std::unique_ptr<Card>, 52> deck);
void dealOneCard(std::vector<std::unique_ptr<Card>> hand, std::array<std::unique_ptr<Card>, 52> deck);
void displayHand(std::vector<std::unique_ptr<Card>> hand);

#endif
