#ifndef CONSOLECASINO_CARD_H
#define CONSOLECASINO_CARD_H

// Library Includes
#include <string>

// Class Definition
class card {
private:
    std::string suit;
    std::string rank;
public:
    // Constructors and Destructor
    card();
    card(std::string s, std::string r);
    ~card();
    // Accessors
    std::string getSuit() { return suit; }
    std::string getRank() { return rank; }
    // Mutators
    void setSuit(std::string data) { suit = data; }
    void setRank(std::string data) { rank = data; }
    // Other Member Functions
    void displayCard();
};

#endif //CONSOLECASINO_CARD_H