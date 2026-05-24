#include "card.h"
#include "CardDeck.h"

CardDeck::CardDeck() {
    // Initialize rank and suits arrays and populate them
    ranks = {
        new std::string("ace"), new std::string("2"), new std::string("3"), new std::string("4"),
        new std::string("5"), new std::string("6"), new std::string("7"), new std::string("8"),
        new std::string("9"), new std::string("10"), new std::string("jack"), new std::string("queen"),
        new std::string("king")
    };
    suits = {
        new std::string("hearts"), new std::string("diamonds"), new std::string("clubs"),
        new std::string("spades")
    };
    deck = new std::array<card*, 53>();
    int deckIndex = 0;

    // Populate the new deck with standard card objects
    for (int i = 0; i < suits.size(); i++) {
        for (int j = 0; j < ranks.size(); j++) {
            (*deck)[deckIndex] = new card(ranks[j], suits[i]);
            if (j >= 10) {
                (*deck)[deckIndex]->setValue(10);
            } else {
                (*deck)[deckIndex]->setValue(j + 1);
            }
            deckIndex++;
        }
    }

    // Add a joker to the end of the deck
    (*deck)[52] = new card(new std::string, new std::string, new int);
    (*deck)[52]->setRank("joker");
    (*deck)[52]->setSuit("joker");
    (*deck)[52]->setValue(-1);
}

CardDeck::~CardDeck() {
    // Deallocate memory for rank array
    for (int i = 0; i < ranks.size(); i++) {
        delete ranks[i];
        ranks[i] = nullptr;
    }

    // Deallocate memory for suit array
    for (int i = 0; i < suits.size(); i++) {
        delete suits[i];
        suits[i] = nullptr;
    }

    // Deallocate memory for deck array and object
    for (int i = 0; i < deck->size(); i++) {
        delete (*deck)[i];
        (*deck)[i] = nullptr;
    }
    delete deck;
    deck = nullptr;
}

void CardDeck::shuffle() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(deck->begin(), deck->end(), gen);
}
