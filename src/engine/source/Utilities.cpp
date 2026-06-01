#include "../include/Utilities.hpp" // Main header

#include <iostream> // Handles input and output stream
#include <random> // Handles random number generator
#include <array> // Handles array containers and members
#include <string> // Handles string containers and members
#include <algorithm> // Preconstructed free functions

#include "../include/Card.hpp" // Handles Card objects and members

std::random_device rd; // RNG seed
std::mt19937 gen(rd()); // RNG generator

/**
 * @brief "Clears" the console by inserting 10 newline characters
 */
void clearConsole() {
    for (int i = 0; i < 10; i++) {
        std::cout << std::endl;
    }
}

/**
 * @brief Populates the global card deck
 *
 * @param deck The deck to populate
 * @param needsRanks Does the deck need Ranks?
 * @param needsSuits Does the deck need Suits?
 * @param needsValues Does the deck need Values?
 */
void createCardDeck(std::array<std::unique_ptr<Card>, 52> deck, bool needsRanks, bool needsSuits, bool needsValues) {
    // Local Variables
    std::array<std::string, 13> ranks = {};
    std::array<std::string, 4> suits = {};
    std::array<int, 10> values = {};
    int valueIndex;
    int deckIndex = 0;

    // Populate arrays dependent on boolean Arguments
    if (needsRanks) {
        ranks = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };
    }

    if (needsSuits) {
        suits = { "Clubs", "Diamonds", "Hearts", "Spades" };
    }

    if (needsValues) {
        values = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    }

    // Populate the deck
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            if (j > 10) {
                valueIndex = 9;
            } else {
                valueIndex = j;
            }
            deck[deckIndex] = std::make_unique<Card>(ranks[j], suits[i], values[valueIndex]);
            deckIndex++;
        }
    }
}

/**
 * @brief Shuffles the global card deck
 *
 * @param deck The deck that needs shuffling
 */
void shuffleDeck(std::array<std::unique_ptr<Card>, 52> deck) {
    std::shuffle(deck.begin(), deck.end(), gen);
}

/**
 * @brief Moves a card object from the card deck to a player's hand
 *
 * @param hand The hand needing dealt to
 * @param deck The deck to deal from
 */
void dealOneCard(std::vector<std::unique_ptr<Card>> hand, std::array<std::unique_ptr<Card>, 52> deck) {
    hand.emplace_back(std::move(deck[0]));
}

