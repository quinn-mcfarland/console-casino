/* Miscellaneous GitHub Issues
*  Issue #6: Implementing Save Files for users
*  Issue #19: Implementing a version of Roulette
*  Issue #20: Implementing a version of Craps
*  Issue #21: Implementing a version of Slots
*  Issue #29: Implementing card deck objects.
*/ 

//Library Inclusions
#include <cstdlib> // Core library.
#include <iostream> // Library to manage I/O streams
#include <iomanip> // Library to manage visuals for I/O data
#include <ctime> // Library to manage seeding of PRNG
#include <string> // Library for strings

// Header Inclusions
#include "utilities.h"
#include "blackjack.h"
#include "fiveCardPoker.h"

// Main Function
int main(int argc, char** argv)
{
    // Set up program variables
    std::string userInput;
    int menu = 0;// Main menu variable for switch case

    // Issue #30: This is not the most modern version of a PRNG and should be updated.
    srand((unsigned int)time(NULL)); // Seeds the PRNG
    
    // Main Menu
    do
    {
        // Prompt user for choices
        std::cout << "1. Blackjack" << std::endl;
        std::cout << "2. Five Card Poker" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Make a selection: ";
        std::cin >> menu;
        
        // Menu switch case
        switch(menu)
        {
            case 1:
            {
                clearConsole();
                do
                {
                    // Start a new game for blackjack
                    blackjackNewGame();
                    
                    if (playerBet > 0)
                    {
                        // Process the player's turn if they did not get dealt a blackjack or bust during a current turn.
                        while (!playerStand && playerScore < 21)
                        {
                            blackjackPlayersTurn();
                            clearConsole();
                        }

                        // Process the dealer's turn
                        while (playerStand && !dealerStand)
                        {
                            blackjackDealersTurn();
                            clearConsole();
                        }

                        // When all parties stand, score the round and pay out player for a win.
                        blackjackScoring();
                    }
                } while (playerBet > 0 && playerChips > 0);
                break;
            }
            case 2:
            {
                clearConsole();
                
                do
                {
                    // Get Player's bet
                    playerBet = getPlayerBet();

                    if (playerBet != 0)
                    {
                        // Deduct money from player's bank and deal them a fresh hand.
                        playerChips -= playerBet;
                        clearConsole();
                        newPokerHand(playerHand);

                        // Run the exchange function to decide if the player wants to exchange cards from their hand
                        pokerExchange(playerHand);

                        // Then run the win condition checker
                        pokerWinCheck(playerHand);
                    }
                } while (playerBet > 0 && playerChips > 0);

                break;
            }
            case 3:
            {
                break;
            }
            default:
            {
                std::cout << "Input not valid. Please try again." << std::endl;
            }
        }
    } while(menu != 3); // Program will continuously run until user wishes to exit
    
    return 0;
}
