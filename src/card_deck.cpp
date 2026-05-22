// Header Includes
#include "../include/card_deck.h"
#include "../include/card.h"

// Library Includes
#include <array>
#include <random>
#include <string>

// Function Definitions
card_deck::card_deck() {
    int cardNumber = 0;

    for (int i = 0; i < suits.size(); i++) {
        for (int j = 0; j < ranks.size(); j++) {
            deck[cardNumber] = card(suits[i], ranks[j]);
            cardNumber++;
        }
    }

    deck[52] = card("joker", "joker");
}

void card_deck::shuffle() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(deck.begin(), deck.end(), gen);
}

void card_deck::displayDeck() {
    for (int i = 0; i < deck.size(); i++) {
        deck[i].displayCard();
    }
}