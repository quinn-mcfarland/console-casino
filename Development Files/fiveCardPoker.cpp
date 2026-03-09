// Library Inclusions
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include <array>

// Header Inclusions
#include "utilities.h"
#include "fiveCardPoker.h"

// Variable Definitions
std::array<int, 5> playerHand;

// Function Definitions
void newPokerHand(std::array<int, 5>& handArray)
{
	// Assign player a hand of 5 new cards
	for (int i = 0; i < 5; i++)
	{
		handArray[i] = generateNewCard();
	}

	// Output the player's current hand
	outputPokerHand(playerHand);
}

void outputPokerHand(const std::array<int, 5>& handArray)
{
	std::cout << "Current hand: ";
	for (int i = 0; i < 5; i++)
	{
		std::cout << handArray[i] << " ";
	}
	std::cout << std::endl;
}

void pokerExchange(std::array<int, 5>& handArray)
{
	// Declare the variables for the exchange system
	int pokerMenu;
	int exchangeAmount;
	int exchangeCard;

	// Prompt the player for their exchange
	std::cout << "1) Exchange" << std::endl
		<< "2) Don't Exchange" << std::endl
		<< "Please make a selection: ";
	std::cin >> pokerMenu;

	// Switch case for the exchange system
	switch (pokerMenu)
	{
		case 1:
			// Ask the player how many cards to exchange
			do
			{
				std::cout << "How many cards to exchange (1 - 3): ";
				std::cin >> exchangeAmount;
			} while (exchangeAmount < 1 || exchangeAmount > 3);

			// Output the hand in a way to make the exchange process easy
			outputPokerHand(handArray);
			std::cout << std::right << std::setw(24) << "^ ^ ^ ^ ^" << std::endl;
			std::cout << std::right << std::setw(24) << "1 2 3 4 5" << std::endl;

			// Generate a new card in the slot a card is exchanged with
			for (int i = 0; i < exchangeAmount; i++)
			{
				std::cout << "Enter the number of the card you'd like to exchange for card " << i + 1 << " :";
				std::cin >> exchangeCard;
				handArray[exchangeCard - 1] = generateNewCard();
			}
			break;
		case 2:
			break;
	}

	// Display the player's hand once more
	outputPokerHand(handArray);
}

void pokerWinCheck(const std::array<int, 5>& handArray)
{
	// Initialize Win check variables
	int fullHouseCheck = 0;
	int twoPairCheck = 0;
	int winID = 0;
	int count = 0;
	int highCount = 0;

	// Check the hand for win conditions
	for (int i = 0; i < 4; i++)
	{
		count = 1;
		for (int j = i; j < 5; j++)
		{
			if (handArray[j] == handArray[i])
			{
				count++;
			}
		}
		if (count > highCount)
		{
			highCount = count;
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