#ifndef FIVECARDPOKER_H
#define FIVECARDPOKER_H

// Function Prototypes
int* newPokerHand(int handsize);
void outputPokerHand(int* handArray, int handSize);
void pokerExchange(int*& handArray);
int pokerWinCheck(int* handArray, int handSize);

// Constant Declarations
extern const int FIVE_CARD_HAND_SIZE;

// Variable Declarations
extern int winID;
extern int* playerHand;

#endif // !FIVECARDPOKER_H