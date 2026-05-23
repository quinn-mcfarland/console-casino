#ifndef CONSOLECASINO_PLAYER_H
#define CONSOLECASINO_PLAYER_H

#include<vector>
#include<iostream>

#include "card.h"

class player {
private:
    int* money;
    int* betAmount;
    std::vector<card*>* hand;
public:
    // Constructors and Destructors
    player(); // Default Constructor
    ~player(); // Default Destructor
    // Operator Overloads
    friend std::ostream& operator<<(std::ostream& os, const player& p);
    friend std::istream& operator>>(std::istream& is, player& p);
    // Accessors
    int* getMoney() const { return money; }
    int* getBetAmount() const { return betAmount; }
    std::vector<card*>* getHand() const { return hand; }
    // Mutators
    void setMoney(int* data) { money = data; }
    void setBetAmount(int* data) { betAmount = data; }
    void setHand(std::vector<card*>* data) { hand = data; }
    // Other Member Methods
};


#endif //CONSOLECASINO_PLAYER_H
