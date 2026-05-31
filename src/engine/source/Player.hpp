#ifndef CONSOLECASINO_PLAYER_H
#define CONSOLECASINO_PLAYER_H

#include <vector>
#include "../include/Card.hpp"

class Player {
public:
  int getBetAmount() const { return betAmount; }
  int getMoney() const { return money; }
  int getInsuranceBetAmount() const { return insuranceBetAmount; }
  void setMoney(int newMoney) { money = newMoney; }
  void setBetAmount(int newBetAmount) { betAmount = newBetAmount;}
  void getPlayerBet();
  void getInsuranceBet();
  std::vector<std::vector<Card>> allHands = {};
private:
  int money = 1000;
  int betAmount = 0;
  int insuranceBetAmount = 0;
};

#endif //CONSOLECASINO_PLAYER_H