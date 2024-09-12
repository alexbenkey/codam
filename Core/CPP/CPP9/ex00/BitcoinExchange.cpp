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
    std::string date, line;
    float value;
    size_t delim;
    std::getline(dataBase, line);
    while (std::getline(dataBase, line)){
        //std::cout << line << std::endl;
        if ((delim = line.find(',')) != std::string::npos){
            std::string temp = line.substr(delim + 1);
            //std::cout << "temp: " << temp << std::endl;
            value = std::stof(temp); 
            this->_data[line.substr(0, delim)] = value;
        }
    }
    // for (auto iter = this->_data.rbegin(); iter != this->_data.rend();++iter){
	// 	std::cout << iter->first << std::endl;
	// }
    dataBase.close();
}

float BitcoinExchange::findValueFromDate(std::string date){
    for (auto iter = this->_data.rbegin(); iter != this->_data.rend();++iter){
        if (iter->first == date){
            std::cout << "date found: " << iter->first << std::endl;
            return iter->second; 
        }
	}
    // int second = date.find_last_of('-'); 
    // int year1 = std::stoi(date.substr(0, date.find("-")));
    // int month1 = std::stoi(date.substr(date.find('-')+1, second));
    // int day1 = std::stoi(date.substr(second + 1, date.size()));
    return (-100);
    }
BitcoinExchange::~BitcoinExchange(){};