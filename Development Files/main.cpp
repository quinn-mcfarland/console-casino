//Library Inclusions
#include <cstdlib> // Core library.
#include <iostream> // Library to manage I/O streams
#include <iomanip> // Library to manage visuals for I/O data
#include <ctime> // Library to manage seeding of PRNG
#include <string> // Library for strings

// Header Inclusions
#include "utilities.h"
#include "blackjack.h"

// Main Function
int main(int argc, char** argv)
{
    // Set up program variables
    std::string userInput;
    int menu = 0;// Main menu variable for switch case
    srand((unsigned int)time(NULL)); // Seeds the RNG
    
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
                    blackjackNewGame();
                } while (playerBet > 0 && playerChips > 0);
                break;
            }
            case 2:
            {
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
