/* Includes */
// Primary Includes
#include "../include/blackjack.hpp"

// Standard Library Includes
#include <iostream>

// User-Defined Includes
#include "../include/Player.hpp"

/* Function Definitions */
/**
 * @brief Gets an insurance bet from the player
 * @param user Object belonging to the human player
 * @param dealer Object belonging to the NPC player
 * @return If the user object made a valid insurance bet
 */
bool blackjackInsurance(Player user, Player dealer) {
    // Local Variables
    int insuranceCheck;

    // Insurance bet prompt
    do {
        if (dealer.getHands()[0][0]->getValue() == 1 || dealer.getHands()[0][0]->getValue() == 10) {
            std::cout << "Insurance? (1 for yes, 0 for no): ";
            std::cin >> insuranceCheck;
            if (insuranceCheck < 0 || insuranceCheck > 1) {
                std::cout << "Invalid input. Please try again." << std::endl;
            }
        }
    } while (insuranceCheck < 0 || insuranceCheck > 1);

    // Resolve if player has insurance
    if (insuranceCheck == 1) {
        user.getBet();
        return true;
    } else {
        return false;
    }
}