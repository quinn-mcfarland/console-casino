#ifndef FIVECARDPOKER_H
#define FIVECARDPOKER_H

// Library Includes
#include<array>

// Variable Declarations
extern std::array<int, 5> playerHand;

// Function Prototypes
void fiveCardPokerNewGame();
void displayHand();
void fiveCardPokerExchange();
void fiveCardPokerScoring();

#endif // !FIVECARDPOKER_H