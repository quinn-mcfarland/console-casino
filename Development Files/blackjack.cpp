// Library Inclusions
#include <cstdlib>
#include <iostream>
#include <string>

// Header Inclusion
#include "utilities.h"
#include "blackjack.h"

// Variable Definitions
int playerScore = 0;
int dealerScore = 0;
int playerSoft = 0;
int dealerSoft = 0;
bool playerStand = false;
bool dealerStand = false;
bool playerHasBlackjack = false;

// Function Definitions
/**
 Set the table for a new game of blackjack
 */
void blackjackNewGame()
{
    // Reinitialize variables
    playerScore = 0;
    dealerScore = 0;
    playerSoft = 0;
    dealerSoft = 0;
    playerStand = false;
    dealerStand = false;
    playerHasBlackjack = false;
    
    // Get Bet
    showChips();
    do {
        playerBet = getPlayerBet();
    } while (playerBet < 0 || playerBet > playerChips);
        
    // Set Table for new Game
    if (playerBet != 0)
    {
        playerChips -= playerBet; // Subtracts player's current bet from their bank.
        clearConsole();
            
        // Deal player 2 cards
        for (int i = 0; i < 2; i++)
        {
            currentCard = generateNewCard();
            playerScore += currentCard;
            
            // Checker for if player was dealt an ace, giving them a soft score if true
            if ((currentCard == 1 && !playerStand) || (playerSoft > 0 && playerSoft < 21))
            {
                playerSoft = playerScore + 10;
            }
        }
    }
            
    // Check for if player was dealt a blackjack
    if (playerScore == 21)
    {
        playerStand = true;
        playerHasBlackjack = true;
    }
            
    // Dealer gets first face-up card
    dealerScore = generateNewCard();
            
    // Check for if dealer was dealt an ace, giving the dealer a soft score if true.
    if(dealerScore == 1)
    {
        dealerSoft = dealerScore + 10;
    }
    
    // Display current scores before going to the player's turn
    
    // Display player's soft score, if they have one, else their hard score.
    if (playerSoft <= 21 && playerSoft > 0)
    {
        std::cout << "You have " << playerScore << "/" << playerSoft << std::endl;
    }
    else
    {
        std::cout << "You have " << playerScore << std::endl;
    }
    
    // Display dealer's soft score, if they have one, else their hard score.
    if (dealerScore == 1 || dealerSoft > 0)
    {
        std::cout << "Dealer has " << dealerScore << "/" << dealerSoft << std::endl;
    }
    else
    {
        std::cout << "Dealer has " << dealerScore << std::endl;
    }
    
}
