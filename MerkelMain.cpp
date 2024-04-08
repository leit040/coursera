#pragma once
#include <iostream>
#include <vector>
#include "MerkelMain.h"
#include "CSVReader.h"



MerkelMain::MerkelMain(){};
void MerkelMain::init()
{
    loadOrderBook();
    unsigned short input;
    while (true){
        input = getUserOption();
        processUserOption(input);
    }
}
void MerkelMain::printHelp()
{
    printMenu();
}
void MerkelMain::printMenu()
{
    std::cout << "1: Print help " << std::endl;
    std::cout << "2: Print market status " << std::endl;
    std::cout << "3: Make your ask " << std::endl;
    std::cout << "4: Make your bit " << std::endl;
    std::cout << "5: Your wallet " << std::endl;
    std::cout << "6: Go to next action " << std::endl;

}
unsigned short MerkelMain::getUserOption()
{
  unsigned short userOption;
    std::cout << "Please chose action: 1-6 " << std::endl;
    std::cin >> userOption;
    return userOption;
}

void MerkelMain::printMarketStats()
{
    unsigned int ask = 0;
    unsigned int  bid = 0;
    for (OrderBookEntry& e: orders) {
        if (e.orderType == OrderBookType::ask){
            ask++;
        } else{
            bid++;
        }
    }
    std::cout << "Order book contains: " << orders.size()<<", asks is: "<<ask<< ", bits: "<< bid<< std::endl;

}
void MerkelMain::enterOffer()
{
std::cout << "Make your ask" << std::endl;
}

void MerkelMain::enterBid()
{
    std::cout << "Make your bit" << std::endl;
}
void MerkelMain::printWallet()
{
std::cout << "Wallet is empty" << std::endl;
}
void MerkelMain::gotoNextTimeframe()
{
    std::cout << "Go to next timeFrame" << std::endl;
}
void MerkelMain::processUserOption(int userOption)
{
    switch (userOption) {
        case 1:
            MerkelMain::printHelp();
            break;
        case 2:
            MerkelMain::printMarketStats();
            break;
        case 3:
            MerkelMain::enterOffer();
            break;
        case 4:
            MerkelMain::enterBid();
            break;
        case 5:
            MerkelMain::printWallet();
            break;
        case 6:

            MerkelMain::gotoNextTimeframe();
        default:
            std::cout << "Invalid choice. Choose 1-6" << std::endl;
            break;

    }

}

void MerkelMain::loadOrderBook()
{
    orders = CSVReader::readCSV("20200317.csv");

}

