# CONSOLE CASINO

## DESCRIPTION:
This application is a text-based game consistent of Blackjack and Five-Card Poker, meant to be an academic demonstration of a union between Procedural and Object-Oriented Programming.
### Procedural Programming Principles Used
- An understanding of prototyping and defining functions, differentiating between functions with no return value (void functions) and functions with return values (integers, floating points, booleans, etc.).
- Understanding, when contextually appropriate, how to declare global and local variables within a program.
- Understanding the foundations of DRY (Don't Repeat Yourself)
### Object Oriented Principles Used
- How to declare classes and understand data encapsulation, Rule of Zero, header-only libraries, and how to utilize header-implementation file pairings.
- How to declare and initialize new objects, modify object variables through accessor and mutator functions, and how to properly define, implement, and call Constructor functions
- How to define inline functions within a class declaration
- Understanding the difference between classes and structures
- Understanding the differences between vectors and arrays, and how to determine which container is needed.

## GAMEPLAY:
Player will start with $1000 for money. Player can make any bet of whole numbers $1 or higher with returns outlined in the game description. If the player runs out of money, the game will softlock and betting will not be possible.

### Blackjack:
Blackjack is a game between the player and the dealer where each party tries to get as close to 21 as possible without going over. The game starts with the player making an inital bet and each party being dealt 2 cards. 
The player will only see the dealer's first card. The player can "hit" adding a new card to their hand until they "stand" and are done playing. The dealer will then do the same. Aces in blackjack are different, they count as either 1 or 11 points. 
The 11 points is known as a soft score. If you stand with a soft score higher than your hard score, and it is not over 21, your soft score will become your hard score.
Table rules for blackjack are as follows:
- Blackjack pays 3:2
- Dealer must hit on Soft 17
- Insurance pays 2:1
- Doubles and Hand splitting is enabled

### 5-Card Poker:
In this version of 5-card poker, the user will make an initial bet from their bank, and will get the opportunity to switch out up to 3 cards in their hand. The cards are ordered, from left to right, 1 2 3 4 5. 
After this, the game will determine if a winning hand is held, and will return the user's bet on a linear scale.
Payouts for 5 card poker:
- Four of a Kind: 5:1
- Full House: 4:1
- Three of a Kind: 3:1
- Two Pair: 2:1
- Pair: 1:1

## Known/Possible Issues
- On all user inputs, there is no type-checking, only bounds checking. Inputting a data type other than expected can lead to undefined behavior
- Logic blocks on functions declared within main.cpp are large, and can/should be split into smaller, task-based functions.
- Games can easily be within their own header-implementation file pairs, as this was done on a previous, procedural programming only version of the application.
- Objects can probably be initialized better. This possibility remains unresearched.
