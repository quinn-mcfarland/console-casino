// Library Inclusions
#include <cstdlib>
#include <iostream>
#include <string>

// Header Inclusion
#include "utilities.h"

// Variable Definitions
int playerChips = 100;
int playerBet = 0;
int currentCard = 0;

// Function Definitions

/**
 Clears the console view while also allowing the player to scroll up if necessary
 */
void clearConsole()
{
    std::cout << "\n\n\n\n\n";
}

/**
 Displays in the console how much money the player currently has.
 */
void showChips()
{
    std::cout << "You have $" << playerChips << ". " << std::endl;
}

/**
 Gets the players current bet.
 @return - The player's current bet.
 */
int getPlayerBet()
{
    std::cout << "Place your bet (Bet 0 to exit): ";
    std::cin >> playerBet;
    return playerBet;
}

int generateNewCard()
{
    int card = rand() % 10 + 1;
    return card;
}
