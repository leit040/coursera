#include "CSVReader.h"
#include <iostream>
#include <exception>
#include <fstream>

CSVReader::CSVReader()
{
}
std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFile)
{
    std::vector<OrderBookEntry> entries;
    std::ifstream file{csvFile};
    std::string line;
    if (file.is_open()) {
        std::string line;

        while (std::getline(file, line)) {

           OrderBookEntry obj = stringsToOBE(tokenise(line,','));
           entries.push_back(obj);
        }
        std::cout <<"Read "<< entries.size() << "entries from file"<< std::endl;
        file.close();
    }

    return entries;
}


std::vector<std::string> CSVReader::tokenise(std::string csvLine, char separator)
{
    std::vector<std::string> tokens;
    int start, end;
    std::string token;
    start = csvLine.find_first_not_of(separator);
    do{
        end = csvLine.find_first_of(separator,start+1);
        if (start == csvLine.length() or start == end)      break;

        if (end >= 0)
        {token = csvLine.substr(start, end - start);}
        else
        {token = csvLine.substr(start, csvLine.length() - start);}
        tokens.push_back(token);
        start = csvLine.find_first_not_of(separator, end + 1);

    } while (end >0);

    return tokens;
}

OrderBookEntry CSVReader::stringsToOBE(std::vector<std::string> strings)
{
            if(strings.size()!=5){
            throw std::exception{};
            }
    double price;
    double amount;
            try {
                price = std::stod(strings[3]);
                amount = std::stod(strings[4]);

            }catch (std::exception& e){

                std::cout << "=================================="<<std::endl;
                throw;
            }
            return OrderBookEntry{price,amount,strings[0],strings[1],OrderBookEntry::stringToOrderBookType(strings[2])};

        };




