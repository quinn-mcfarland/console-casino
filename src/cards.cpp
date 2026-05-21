// Library Includes
#include <iostream>
#include <string>
#include <array>
#include <random>

// Header Includes
#include "../include/cards.h"

// Global Thingies that need used
std::random_device rd;
std::uniform_int_distribution<int> dist(0, 52);

// Card Class Function Definitions
Card::Card() {
    suit = "";
    rank = "";
}

Card::Card(std::string s, std::string r) {
    suit = s;
    rank = r;
}

// Deck Class Function Definitions
Deck::Deck() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            deck[i * 13 + j].setSuit(suits[i]);
            deck[i * 13 + j].setRank(ranks[j]);
        }
    }
    // Insert a "Joker of Joker" that serves as a shuffle trigger.
    deck[52].setSuit("joker");
    deck[52].setRank("joker");
}

Deck::~Deck() {
    deckPtr = nullptr;
}

void Deck::draw() {

}

void Deck::shuffle() {
    // Destroy the old deck and null its pointer
    delete deckPtr;
    deckPtr = nullptr;
    // Construct a new deck and assign it to the deck pointer
    deckPtr = new Deck();
    // Shuffle the deck by simply swapping each card into a random index
    for (int i = 0; i < 53; i++) {
        
    }
}

void Deck::deal() {

}

void Deck::printDeck() const {
    int suitChange = 0;
    for (int i = 0; i < 53; i++) {
        deck[i].printCard();
        suitChange++;
        if (suitChange < 13) {
            std::cout << " | ";
        } else {
            suitChange = 0;
            std::cout << std::endl;
        }
    }
}
