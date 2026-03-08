#ifndef FIVECARDPOKER_H
#define FIVECARDPOKER_H

// Library Inclusions
#include <iostream>
#include <string>

// Header Inclusions
#include "userData.h"

// Constant Declarations
const int FIVE_CARD_HAND_SIZE = 5;

// Variable Declarations

// Function Prototypes
int* newPokerHand(int handSize);
void outputPokerHand(int* handArray, int handSize);
void pokerExchange(int*& handArray);
int pokerWinCheck(int* handArray, int handSize);

#endif //FIVECARDPOKER_H
