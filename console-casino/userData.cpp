// Library Inclusions
#include <iostream>
#include <string>

//Header Inclusion
#include "userData.h"

// Function Definitions
/**
 Gets the players bet for the current game
 @return - The player's bet.
 */
int getPlayerBet()
{
    std::cout << "Place your bet (Bet 0 to exit)";
    std::cin >> playerBet;
    return playerBet;
}
/**
 Generates a new card for the current game using the PRNG.
 @return - The value of the new card.
 */
int generateNewCard()
{
    int card = rand() % 10 + 1;
    return card;
}
