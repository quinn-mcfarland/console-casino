#ifndef FIVECARDPOKER_H
#define FIVECARDPOKER_H

// Variable Declarations
extern std::array<int, 5> playerHand;

// Function Prototypes
void fiveCardPokerNewGame(std::array<int, 5>& handArray);
void outputPokerHand(const std::array<int, 5>& handArray);
void pokerExchange(std::array<int,5>& handArray);
void pokerWinCheck(const std::array<int, 5>& handArray);

#endif // !FIVECARDPOKER_H