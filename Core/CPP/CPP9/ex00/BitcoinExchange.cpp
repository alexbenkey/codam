#include "BitcoinExchange.hpp"
#define NODATE "no_date"

BitcoinExchange::BitcoinExchange(){};

BitcoinExchange::BitcoinExchange(BitcoinExchange & rhs){
    *this = rhs;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
};

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange & rhs){
    this->_data = rhs._data;
    return *this;
};

void BitcoinExchange::storeData(std::string data){
    std::ifstream dataBase(data);
    if (!dataBase.is_open()){
		std::cerr << "Error: could not open database file." << std::endl;
		exit(0);
	}
    std::string date, line;
    float value;
    size_t delim;
    std::getline(dataBase, line);
    while (std::getline(dataBase, line)){
        if ((delim = line.find(',')) != std::string::npos){
            std::string temp = line.substr(delim + 1);
            value = std::stof(temp); 
            this->_data[line.substr(0, delim)] = value;
        }
    }
    dataBase.close();
}

bool BitcoinExchange::matchDates(std::string refDate, std::string checkDate){
    int refYear = std::stoi(refDate.substr(0, 4));
    int refMonth = std::stoi(refDate.substr(5, 7));
    int refDay = std::stoi(refDate.substr(8, 10));
    int checkYear = std::stoi(checkDate.substr(0, 4));
    int checkMonth = std::stoi(checkDate.substr(5, 7));
    int checkDay = std::stoi(checkDate.substr(8, 10));
    if(refYear <= checkYear){
        if (refMonth <= checkMonth){
            if (refDay <= checkDay){
                return (1);
            }
        }
    }
    return (0);
}   

float BitcoinExchange::findValueFromDate(std::string date){
    for (auto iter = this->_data.rbegin(); iter != this->_data.rend();++iter){
        if (matchDates(iter->first, date)){
            return iter->second;
        }
	}
    return (-100);
    }
BitcoinExchange::~BitcoinExchange(){};