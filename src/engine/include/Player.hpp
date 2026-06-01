#ifndef PLAYER_H
#define PLAYER_H

// Standard Library Includes
#include <memory>
#include <vector>

// User-defined Includes
#include "Card.hpp"

// Class Declaration
class Player {
public:
    // Constructor
    Player() = default;
    Player(int m, int b);
    // Methods
    void getBet() const;
    void payout(int p) const;
private:
    std::unique_ptr<int> money;
    std::unique_ptr<int> bet;
    std::vector<std::vector<Card>> hands;

};

#endif