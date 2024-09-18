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
        bool matchDates(std::string refDate, std::string checkDate);

    private:
        std::map<std::string, float> _data;

};