#ifndef FIVECARDPOKER_H
#define FIVECARDPOKER_H

// Function Prototypes
void newPokerHand(std::array<int, 5>& handArray);
void outputPokerHand(const std::array<int, 5>& handArray);
void pokerExchange(std::array<int, 5>& handArray);
void pokerWinCheck(const std::array<int, 5>& handArray);

// Variable Declarations
extern std::array<int, 5> playerHand;

#endif // !FIVECARDPOKER_H