#ifndef BLACKJACK_H
#define BLACKJACK_H

// Function Prototypes
void blackjackNewGame();
void blackjackPlayersTurn();
void blackjackDealersTurn();
void blackjackScoring();

// Variable Declarations
extern int playerScore;
extern int dealerScore;
extern int playerSoft;
extern int dealerSoft;
extern bool playerStand;
extern bool dealerStand;
extern bool playerHasBlackjack;

#endif // !BLACKJACK_H
