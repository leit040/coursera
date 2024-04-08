
#include <iostream>
#include "vector"
#include "OrderBookEntry.h"
#include "MerkelMain.h"
#include "CSVReader.h"
using namespace std;

double computeAveragePrice(std::vector<OrderBookEntry>& entries)
{
double result;
    for(OrderBookEntry e : entries){
        result += e.price;
    }
    return result/entries.size();
}

double computeLowPrice(std::vector<OrderBookEntry>& entries)
{
    double minPrice = entries[0].price;
    for (OrderBookEntry e: entries) {
        if (e.price < minPrice) {
            minPrice = e.price;
        }
    }
    return minPrice;
}

double computeHighPrice(std::vector<OrderBookEntry>& entries)
{
    double maxPrice = entries[0].price;
    for (OrderBookEntry e: entries) {
        if (e.price > maxPrice) {
            maxPrice = e.price;
        }
    }
    return maxPrice;
}

double computePriceSpread(std::vector<OrderBookEntry>& entries){
    return computeHighPrice(entries) - computeLowPrice(entries);
}



int main()
{
    MerkelMain app{};
    app.printHelp();
    app.init();
  //  CSVReader::readCSV("20200317.csv");

}