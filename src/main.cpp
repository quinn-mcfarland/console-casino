//Library Inclusions
#include <iostream> // Library to manage I/O streams
#include <iomanip> // Library to manage visuals for I/O data
#include <string> // Library for strings, manages basically all stringed output
#include <random> // Library that runs the PRNG
#include <fstream> // Library to save game data and player progress to external files

// Header Inclusions
#include "../include/utilities.h"
#include "../include/blackjack.h"
#include "../include/fiveCardPoker.h"
#include "../include/card.h"
#include "../include/card_deck.h"
#include "../include/player.h"
#include "../include/dealer.h"

// Main Function
int main(int argc, char** argv)
{
    // Program Variables
    int mainMenu;
    card_deck* debugDeck = nullptr;

    do {
        // Main Menu Prompt
        std::cout << "1: Blackjack" << std::endl
            << "2: Five Card Poker" << std::endl
            << "3: Exit" << std::endl
            << "Please make a selection: ";
        std::cin >> mainMenu;

        // Switch case for game functions
        switch (mainMenu) {
            case 1: // Blackjack
                break;
            case 2: // Five Card Poker
                break;
            case 3: // Run exit protocols
                break;
            default:
                std::cout << "Invalid selection. Please try again" << std::endl;
                break;
        }

    } while (mainMenu != 3);

    return 0;
}