#include "../include/card.h"
#include <string>
#include <iostream>

// Function Definitions
card::card() {
    setSuit(" ");
    setRank(" ");
}

card::card(std::string s, std::string r) {
    setSuit(s);
    setRank(r);
}

void card::displayCard() {
    std::cout << getRank() << " of " << getSuit() << std::endl;
}