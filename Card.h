#ifndef CONSOLECASINO_CARD_H
#define CONSOLECASINO_CARD_H

#include <string>

class Card {
public:
  // Accessors
  [[nodiscard]] inline std::string getSuit() const { return suit; }
  [[nodiscard]] inline std::string getRank() const { return rank; }
  [[nodiscard]] inline int getValue() const { return value; }
  // Mutators
  inline void setSuit(std::string newSuit) { suit = std::move(newSuit); }
  inline void setRank(std::string newRank) { rank = std::move(newRank); }
  inline void setValue(int newValue) { value = newValue; }
  // Default Constructor
  inline Card() {suit = ""; rank = ""; value = 0; }
  inline Card(std::string s, std::string r, int v) {suit = std::move(s); rank = std::move(r); value = v; }
private:
  std::string suit, rank;
  int value = 0;

};

#endif //CONSOLECASINO_CARD_H