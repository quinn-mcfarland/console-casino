#ifndef CONSOLECASINO_CARD_DECK_H
#define CONSOLECASINO_CARD_DECK_H

// Includes
#include "card.h"
#include <array>
#include <string>

// Class Definition
class card_deck {
private:
    std::array<std::string,4> suits = { "hearts", "spades", "clubs", "diamonds" };
    std::array<std::string, 13> ranks = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9",
        "10", "Jack", "Queen", "King" };
    std::array<card, 53> deck;
public:
    // Constructor and Destructor
    card_deck();
    ~card_deck();
    // Accessors
    // Mutators
    // Other Member Function
    void shuffle();
    void deal();
    void draw();
    void displayDeck();
};


#endif //CONSOLECASINO_CARD_DECK_H
