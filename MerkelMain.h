#pragma once
#include <vector>
#include "OrderBookEntry.h"
class MerkelMain
{
  public:
    MerkelMain();
    void init();
    void printHelp();
  private:
    void loadOrderBook();
    void printMenu();
    unsigned short getUserOption();
    void printMarketStats();
    void enterOffer();
    void enterBid();
    void printWallet();
    void gotoNextTimeframe();
    void processUserOption(int userOption);
    std::vector<OrderBookEntry> orders;
};
