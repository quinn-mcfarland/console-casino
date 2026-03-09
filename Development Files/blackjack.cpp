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

/**
 Function to process the player's current turn for blackjack.
 */
void blackjackPlayersTurn()
{
    // Declare a menu variable for the player's turn.
    int blackjackMenu;
    
    // Prompt the player to hit or stand
    std::cout << "1) Hit" << std::endl;
    std::cout << "2) Stand" << std::endl;
    std::cout << "Make a selection: ";
    std::cin >> blackjackMenu;
    
    // Switch case for the player's turn
    switch (blackjackMenu)
    {
        case 1:
            currentCard = generateNewCard();
            playerScore += currentCard;
            break;
        case 2:
            playerStand = true;
            break;
        case 3:
            std::cout << "Invalid input." << std::endl;
            break;
    }
    
    // Process if the new card was a 1 and the player can be given a valid soft score
    if ((currentCard == 1 && !playerStand) || (playerSoft > 0 && playerSoft < 21))
    {
        playerSoft = playerScore + 10;
    }
}

/**
Processes the dealer's turn for blackjack.
*/
void blackjackDealersTurn()
{
    // First the dealer will check if the player has bust. If they have, the dealer will automatically stand.
    if (playerScore > 21)
    {
        dealerStand = true;
    }

    // Dealer will play only when the player has stood and while they aren't standing themself.
    while (playerStand && !dealerStand)
    {
        // Dealer will hit under 18 and when at or under a soft 17, else dealer will stand.
        if (dealerScore < 18 && dealerSoft <= 17)
        {
            currentCard = generateNewCard();
            dealerScore += currentCard;
            if ((currentCard == 1 && !dealerStand) || dealerSoft > 0 && dealerSoft < 21)
            {
                dealerSoft = dealerScore + 10;
            }
        }
        else
        {
            dealerStand = true;
        }
    }
}

void blackjackScoring()
{
    // Check if either party has a soft score better than their hard score. If so, assign it.
    if (dealerSoft > dealerScore)
    {
        dealerScore = dealerSoft;
    }
    if (playerSoft > playerScore)
    {
        playerScore = playerSoft;
    }

    // Score the round
}