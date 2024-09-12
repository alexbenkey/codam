#pragma once

#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange { 
    public:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange & rhs);
        BitcoinExchange & operator=(BitcoinExchange & rhs);
        ~BitcoinExchange();

        void findCurrentVal();
        void storeData(std::string data);
        float findValueFromDate(std::string date);
        std::map<std::string, float> _data;

    private:
        

        

};