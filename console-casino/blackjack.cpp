// Library Inclusions
#include <iostream>
#include <string>

// Header Inclusions
#include "blackjack.h"

// Function definitions
/**
 Resets all variables to an initial value for a new game and deals two cards to each active player.
 */
void blackjackNewGame()
{
    playerScore = 0;
    dealerScore = 0;
    playerSoft = 0;
    dealerSoft = 0;
    playerStand = false;
    dealerStand = false;
    playerHasBlackjack = false;
}
