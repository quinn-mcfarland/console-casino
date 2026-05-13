/* Five Card Poker Issue Tracker
 * Issue #34: Misaligned Display during exchange sequence */

// Library Inclusions
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

// Header Inclusions
#include "utilities.h"
#include "fiveCardPoker.h"

// Constant Definitions
const int FIVE_CARD_HAND_SIZE = 5;

// Variable Definitions
int winID = 0;
int* playerHand;

// Function Definitions