#ifndef CARD_H
#define CARD_H

// Standard Library Includes
#include <memory> // Handles smart pointers
#include <string> // Handles string containers

// Class Declaration
class Card {
public:
    Card() = default; // Default Constructor
    Card(std::string r = "", std::string s = "", int v = 0); // Parameterized constructor
    [[nodiscard]] inline int getValue() const { return *value; }
private:
    std::unique_ptr<std::string> rank; // Rank of the card
    std::unique_ptr<std::string> suit; // Suit of the card
    std::unique_ptr<int> value; // How many points the card is worth in blackjack
};

#endif