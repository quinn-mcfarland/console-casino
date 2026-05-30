#ifndef CONSOLECASINO_CARD_H
#define CONSOLECASINO_CARD_H

#include <string>

class Card {
public:
  // Accessors
  std::string getSuit() const { return suit; }
  std::string getRank() const { return rank; }
  int getValue() const { return value; }
  // Mutators
  void setSuit(std::string newSuit) { suit = std::move(newSuit); }
  void setRank(std::string newRank) { rank = std::move(newRank); }
  void setValue(int newValue) { value = newValue; }
  // Default Constructor
  Card() {suit = ""; rank = ""; value = 0; }
  Card(std::string s, std::string r, int v) {suit = std::move(s); rank = std::move(r); value = v; }
private:
  std::string suit, rank;
  int value = 0;

};

#endif //CONSOLECASINO_CARD_H