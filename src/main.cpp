/* Global Project Issue Tracker
 * Issue #19: Roulette Implementation
 * Issue #20: Craps Implementation
 * Issue #21: Slots Implementation
 * Issue #35: SDL Graphic Implementation
 * Issues #42, #43, #44: Deployability and Stability Tests */

//Library Inclusions
#include <iostream> // Library to manage I/O streams
#include <iomanip> // Library to manage visuals for I/O data
#include <string> // Library for strings, manages basically all stringed output

// Header Inclusions
#include "../include/utilities.h"
#include "../include/blackjack.h"
#include "../include/fiveCardPoker.h"

// Main Function
int main(int argc, char** argv)
{
    // Set up program variables
    std::string userInput;
    int menu = 0;// Main menu variable for switch case
    srand(static_cast<unsigned int>(time(nullptr))); // Seeds the RNG | Issue #30: Better Random Number Generator
    
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
                do {
                    // Start a new game
                    fiveCardPokerNewGame(playerHand);
                    fiveCardPokerExchange(playerHand);
                    fiveCardPokerScoring(playerHand);
                } while (playerBet> 0 && playerChips > 0);
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
