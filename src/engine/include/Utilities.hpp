#ifndef UTILITIES_HPP
#define UTILITIES_HPP

// Standard Library Includes
#include <vector> // Handles vector containers
#include <array> // Handles array containers
#include <memory> // Handles smart pointers

// User-Defined Includes
#include "Card.hpp" // Card class

// Function Prototypes
void clearConsole(); // Clears the console
void createCardDeck(std::array<std::unique_ptr<Card>, 52> deck, bool needsRanks, bool needsSuits, bool needsValues); // Populates a card deck
void shuffleDeck(std::array<std::unique_ptr<Card>, 52> deck); // Shuffles a populated card deck
void dealOneCard(std::vector<std::unique_ptr<Card>> hand, std::array<std::unique_ptr<Card>, 52> deck); // Deals a card from the deck to a hand

#endif
