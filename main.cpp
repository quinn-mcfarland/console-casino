/* Library Includes */
#include <iostream>
#include <string>

/* Local Includes */
#include "card.h"
#include "CardDeck.h"
#include "player.h"

/* Global Constants */

/* Global Variables */

/* Function Prototypes */

/* Driver Function */
int main (int argc, char *argv[]) {
    // Local Variables
    player* user = new player();
    CardDeck* cardDeck = new CardDeck();
    int mainMenu;

    do {
        // Main Menu
        std::cout << "1) Blackjack" << std::endl
            << "2) Five Card Poker" << std::endl
            << "3) Exit" << std::endl
            << "Please make a selection: ";
        std::cin >> mainMenu;
    } while (mainMenu != 3);

    return 0;
}

/* Function Definitions */