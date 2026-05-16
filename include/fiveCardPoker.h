#ifndef FIVECARDPOKER_H
#define FIVECARDPOKER_H

// Library Includes
#include<array>

// Variable Declarations
extern std::array<int, 5> playerHand;

// Function Prototypes
void fiveCardPokerNewGame(std::array<int, 5>& handArray);
void displayHand(const std::array<int, 5>& handArray);
void fiveCardPokerExchange(std::array<int,5>& handArray);
void fiveCardPokerScoring(const std::array<int, 5>& handArray);

#endif // !FIVECARDPOKER_H