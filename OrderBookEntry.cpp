//#pragma once
// Created by leit on 06.04.24.
//
#include <iostream>
#include "OrderBookEntry.h"

using namespace std;


    OrderBookEntry::OrderBookEntry(double _price,
                                   double _amount,
                                   string _timestamp,
                                   string _product,
                                   OrderBookType _orderType)
   : price(_price),
     amount(_amount),
     timestamp(_timestamp),
     orderType(_orderType)
    {

    }
OrderBookType OrderBookEntry::stringToOrderBookType(std::string s){
    if (s == "bid") {
        return OrderBookType::bid;
    } else if (s == "ask") {
        return OrderBookType::ask;
    } else {
        return OrderBookType::unknown;
    }
    }
