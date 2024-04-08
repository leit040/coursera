#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <exception>

std::vector<std::string> tokenise(std::string csvLine, char separator){
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

void testReadFile(){
    char separator = ',';
    std::ifstream csvFile{"20200317.csv"};
    if (csvFile.is_open()) {
        std::string line;
        int counter = 0;
        while (std::getline(csvFile, line)) {
            std::vector <std::string> tokens = tokenise(line, separator);
            if(tokens.size()!=5){
                continue;
            }
            std::cout << "counter: " << counter++ << std::endl;
            try {
                double price = std::stod(tokens[3]);
                double amount = std::stod(tokens[4]);
                std::cout << "price : " << price << std::endl;
                std::cout << "amount : " << amount << std::endl;
                std::cout << "=================================="<<std::endl;
            }catch (std::exception& e){
                std::cout << "error float" << counter++ << std::endl;
                std::cout << "=================================="<<std::endl;
                continue;
            }


            /*for (std::string &token: tokens) {
                std::cout << token << std::endl;
            }*/
        }
        csvFile.close();
    }

}


int main(){


    testReadFile();
    /*std::vector <std::string> tokens = tokenise(csvLine, separator);
    for (std::string &token : tokens) {
    std::cout << token <<std::endl;
    }*/
    return 0;
}