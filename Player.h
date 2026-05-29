#ifndef CONSOLECASINO_PLAYER_H
#define CONSOLECASINO_PLAYER_H

#include <vector>
#include "Card.h"

class Player {
public:
  [[nodiscard]] inline int getBetAmount() const { return betAmount; }
  [[nodiscard]] inline int getMoney() const { return money; }
  [[nodiscard]] inline int getInsuranceBetAmount() const { return insuranceBetAmount; }
  inline void setMoney(int newMoney) { money = newMoney; }
  inline void setBetAmount(int newBetAmount) { betAmount = newBetAmount;}
  void getPlayerBet();
  void getInsuranceBet();
  std::vector<std::vector<Card>> allHands = {};
private:
  int money = 1000;
  int betAmount = 0;
  int insuranceBetAmount = 0;
};

#endif //CONSOLECASINO_PLAYER_H