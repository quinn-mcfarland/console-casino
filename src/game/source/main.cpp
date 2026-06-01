/* Includes */
// Standard Library Includes
#include <iostream>
#include <memory>
#include <array>

// User-Defined Includes
#include "../../engine/include/Card.hpp"
#include "../../engine/include/Player.hpp"
#include "../../engine/include/Utilities.hpp"

/* Global Constants */

/* Global Variables */

/* Function Prototypes */

/* Main Function */
int main() {
    // Object Creation
    std::unique_ptr<Player> player = std::make_unique<Player>(1000, 0);
    std::array<std::unique_ptr<Card>, 52> cardDeck;

    // Local Variables
    int mainMenu;

    do {
        // Main Menu Prompt
        std::cout << "1) Blackjack" << std::endl << "2) Five Card Poker" << std::endl << "3) Exit" << std::endl <<
            "Please make a selection: ";
        std::cin >> mainMenu;

        // Main Menu Switch case
        switch (mainMenu) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            default:
                std::cout << "Invalid Input. Please try again." << std::endl;
                break;
        }

    } while (mainMenu != 3);
    return 0;
}

/* Function Definitions */