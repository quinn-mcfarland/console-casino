#ifndef PLAYER_H
#define PLAYER_H

// Standard Library Includes
#include <memory> // Handles smart pointers
#include <vector> // Handles vector containers

// User-defined Includes
#include "Card.hpp" // Card class

// Class Declaration
class Player {
public:
    // Constructor
    Player() = default; // Default Constructor
    Player(int m, int b); // Parameterized Constructor
    // Methods
    void getBet() const; // Collects a bet from the player
    void payout(int p) const; // Pays a player on their bet
private:
    std::unique_ptr<int> money; // The player's money
    std::unique_ptr<int> bet; // The player's current bet
    std::vector<std::vector<std::unique_ptr<Card>>> hands; // A collection of the player's currently played hands

};

#endif