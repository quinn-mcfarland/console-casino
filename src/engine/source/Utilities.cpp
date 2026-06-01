#include "../include/Utilities.hpp"

// Standard Library Includes
#include <iostream>
#include <random>
#include <array>
#include <string>
#include <algorithm>

// User-Defined Includes
#include "../include/Card.hpp"

// Constants
std::random_device rd;
std::mt19937 gen(rd());

// Function Definitions
void clearConsole() {
    for (int i = 0; i < 10; i++) {
        std::cout << std::endl;
    }
}

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

void shuffleDeck(std::array<std::unique_ptr<Card>, 52> deck) {
    std::shuffle(deck.begin(), deck.end(), gen);
}

void dealOneCard(std::vector<std::unique_ptr<Card>> hand, std::array<std::unique_ptr<Card>, 52> deck) {
    hand.emplace_back(std::move(deck[0]));
}

