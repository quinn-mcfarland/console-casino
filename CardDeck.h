#ifndef CONSOLECASINO_CARDDECK_H
#define CONSOLECASINO_CARDDECK_H

#include <array>
#include <string>
#include <random>
#include "card.h"

class CardDeck {
private:
    std::array<std::string, 13> ranks;
    std::array<std::string, 4> suits;
    std::array<card, 53> deck;
public:
    // Constructor and Destructor
    CardDeck();
    ~CardDeck();
    // Other Member Functions
    void shuffle();
};

#endif //CONSOLECASINO_CARDDECK_H