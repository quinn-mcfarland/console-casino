#ifndef CONSOLECASINO_CARDDECK_H
#define CONSOLECASINO_CARDDECK_H

#include <array>
#include <string>
#include <random>
#include "card.h"

class CardDeck {
private:
    std::array<std::string*, 13> ranks;
    std::array<std::string*, 4> suits;
    std::array<card*, 53>* deck;
    int deckIndex;
public:
    // Constructor and Destructor
    CardDeck(); // Default Constructor
    ~CardDeck(); // Default Destructor
    // Accessors
    std::array<card*, 53>* getDeck() const { return deck; }
    int getDeckIndex() const { return deckIndex; }
    // Mutators
    void setDeck(std::array<card*, 53>* data) { deck = data; }
    void setDeckIndex(int data) { deckIndex = data; }
    // Other Member Functions
    void shuffle(); // Shuffles the current deck
};

#endif //CONSOLECASINO_CARDDECK_H