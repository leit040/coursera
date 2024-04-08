//
// Created by leit on 06.04.24.
//
#pragma once
#include <string>

using namespace std;

enum class OrderBookType
{
    bid,
    ask,
    unknown
};

class OrderBookEntry
{
public:

    OrderBookEntry(double _price,
                   double _amount,
                   string _timestamp,
                   string _product,
                   OrderBookType _orderType);
    static OrderBookType stringToOrderBookType(std::string s);
    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderBookType orderType;

    };