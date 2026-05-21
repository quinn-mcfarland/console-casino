#ifndef CONSOLECASINO_CARD_DECK_H
#define CONSOLECASINO_CARD_DECK_H

// Library inclusions
#include <string>
#include <iostream>
#include <array>

// Individual card clas
class Card {
public:
    // Constructors
    Card(); // Default Constructor
    Card(std::string s, std::string r); // Parameterized Constructor
    // Accessors
    std::string getSuit() const { return suit;}
    std::string getRank() const { return rank;}
    // Mutators
    void setSuit(std::string data) { suit = data;}
    void setRank(std::string data) { rank = data;}
    // Other Member Functions
    void printCard() const { std::cout << rank << " of " << suit << std::endl; }
private:
    std::string suit;
    std::string rank;
};

// The actual deck of 52 cards.
class Deck {
public:
    // Constructor and Destructor
    Deck();
    ~Deck();
    // Accessors
    // Mutators
    // Other Member Functions
    void draw();
    void shuffle();
    void deal();
    void printDeck() const;
private:
    std::array<Card, 53> deck;
    Deck* deckPtr;
    std::array<std::string, 4> suits = {"hearts", "diamonds", "clubs", "spades"};
    std::array<std::string, 13> ranks = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
};

#endif //CONSOLECASINO_CARD_DECK_H
