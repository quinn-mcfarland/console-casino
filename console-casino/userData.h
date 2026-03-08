#ifndef USERDATA_H
#define USERDATA_H

// Necessary Library Inclusions
#include <iostream>
#include <string>

// Variable Declarations
int playerChips = 100;
int playerBet = 0;
int currentCard;

// Function Prototypes
int showChips()
{return playerChips;}
void clearConsole()
{std::cout << "\n\n\n\n\n\n\n\n\n\n";}
int getPlayerBet();
int generateNewCard();

#endif //USERDATA_H
