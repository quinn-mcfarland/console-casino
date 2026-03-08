#ifndef BLACKJACK_H
#define BLACKJACK_H

// Library Inclusions
#include <iostream>
#include <string>

// Header Inclusions
#include "userData.h"

// Variable Declarations
int playerScore;
int dealerScore;
int playerSoft;
int dealerSoft;
bool playerStand;
bool dealerStand;
bool playerHasBlackjack;

// Function Prototypes
void blackjackNewGame();
void blackjackPlayersTurn();
void blackjackDealersTurn();
void blackjackScoring();

#endif //BLACKJACK_H

