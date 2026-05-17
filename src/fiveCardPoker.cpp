/* Five Card Poker Issue Tracker
 * Issue #47, Exchange value validation
 * Issue #48, Win Check Optimization
 */

// Library Inclusions
#include <iostream>
#include <string>
#include <iomanip>
#include <array>

// Header Inclusions
#include "../include/utilities.h"
#include "../include/fiveCardPoker.h"

// Variable Initializations
std::array<int, 5> playerHand;

// Function Definitions
void fiveCardPokerNewGame()
{
	// Get player bet as is normal for all new games.
	getPlayerBet();

	if (playerBet != 0) {
		// Assign player a hand of 5 new cards
		for (int i = 0; i < 5; i++)
		{
			playerHand[i] = generateNewCard();
		}

		// Output the player's current hand
		displayHand();
	}
}

void displayHand()
{
	std::cout << "Current Hand: " << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << std::left << std::setw(2) << playerHand[i] << " ";
	}
	std::cout << std::endl;
}

void fiveCardPokerExchange()
{
	// Declare the variables for the exchange system
	int pokerMenu;

	// Prompt the player for their exchange
	std::cout << "1) Exchange" << std::endl
		<< "2) Don't Exchange" << std::endl
		<< "Please make a selection: ";
	std::cin >> pokerMenu;

	// Switch case for the exchange system
	if (pokerMenu == 1) {

		int exchangeAmount;
		int exchangeCard;

			// Ask the player how many cards to exchange
			do
			{
				std::cout << "How many cards to exchange (1 - 3): ";
				std::cin >> exchangeAmount;
				if (exchangeAmount < 1 || exchangeAmount > 3) {
					std::cout << "Invalid amount, please try again." << std::endl;
				}
			} while (exchangeAmount < 1 || exchangeAmount > 3);

			// Output the hand in a way to make the exchange process readable
			displayHand();
			std::cout << std::left;
			for (int i = 0; i < 5; i++) {
				std::cout << std::setw(3) << "^ ";
			}
			std::cout << std::endl
				<< std::setw(3) << "1 "
				<< std::setw(3) << "2 "
				<< std::setw(3) << "3 "
				<< std::setw(3) << "4 "
				<< std::setw(3) << "5 " << std::endl;

			// Generate a new card in the slot a card is exchanged with
			for (int i = 0; i < exchangeAmount; i++) {
				do {
					std::cout << "Enter the number of the card you'd like to exchange for card " << i + 1 << " :";
					std::cin >> exchangeCard;
					if (exchangeCard < 1 || exchangeCard > 5) {
						std::cout << "Invalid card number, please try again." << std::endl;
					}
				} while (exchangeCard < 1 || exchangeCard > 5);
				playerHand[exchangeCard - 1] = generateNewCard();
			}
	}

	// Display the player's hand once more
	displayHand();
}

void fiveCardPokerScoring()
{
	// Initialize Win check variables
	int fullHouseCheck = 0;
	int twoPairCheck = 0;
	int winID = 0;
	int count = 0;

	// Check the hand for win conditions
	for (int i = 0; i < 5; i++) {
		count = 0;
		count++;
		for (int j = i; j < 5; j++) {
			if (playerHand[j] == playerHand[i] && j != i) {
				count++;
			}
		}
		// Finalize Win Conditions
		if (count == 4)
		{
			winID = 5;
		}
		if (count == 3)
		{
			fullHouseCheck++;
			winID = 3;
		}
		if (count == 2)
		{
			twoPairCheck++;
			fullHouseCheck++;
			winID = 1;
		}
		if (fullHouseCheck == 2)
		{
			winID = 4;
		}
		if (twoPairCheck == 2)
		{
			winID = 2;
		}
	}

	// Display a win or loss message
	if (winID == 5)
	{
		std::cout << "4-of-a-Kind!" << std::endl;
		playerChips += playerBet * 6;
	}
	else if (winID == 4)
	{
		std::cout << "Full House!" << std::endl;
		playerChips += playerBet * 5;
	}
	else if (winID == 3)
	{
		std::cout << "3-of-a-Kind!" << std::endl;
		playerChips += playerBet * 4;
	}
	else if (winID == 2)
	{
		std::cout << "Two Pair!" << std::endl;
		playerChips += playerBet * 3;
	}
	else if (winID == 1)
	{
		std::cout << "Pair!" << std::endl;
		playerChips += playerBet * 2;
	}
	else
	{
		std::cout << "You lose" << std::endl;
	}
}