#include "BitcoinExchange.hpp"

inline std::string& ltrim(std::string& s, const char* t = " \t\n\r\f\v")
{
    s.erase(0, s.find_first_not_of(t));
    return s;
}

bool parse_date(std::string date)
{
	if (date.size() != 10)
		return (0);
	if (date.find('-') != 4)
		return (0);
	if (date.find_last_of('-') != 7)
		return (0);
	if (date.substr(5, 7).empty())
		return (0);
	if (date.substr(8, 10).empty())
		return (0);
	for (int i = 0; i < 4; i++){
		if (!isdigit(date[i]))
			return (0);
	}
	for (int i = 5; i <= 6; i++){
		if (!isdigit(date[i]))
			return (0);
	}
	for (int i = 8; i <= 9; i++){
		if (!isdigit(date[i]))
			return (0);
	}
	return (1);
}

bool parse(std::string line){
	if (line.find(" | ") == std::string::npos || line.size() < 14){
		std::cerr << "Error: bad input => " << line << std::endl;
		return 0;
	}
	std::string date = line.substr(0, line.find(" | "));
	if (!parse_date(date)){
		std::cerr << "Error: date formatted incorrectly." << std::endl;
		return 0;
	}
	float val = std::stof(line.substr(line.find('|') + 1, line.size()));
	if (val < 0){
		std::cerr << "Error: not a positive number" << std::endl;
		return 0;
	}
	if (val > 1000) {
		std::cerr << "Error: too large a number." << std::endl;
		return 0;
	}
	return (1);
}

int main(int argc, char **argv){
	if (argc != 2){
		std::cerr << "Error: could not open file." << std::endl;
		exit(0);
	}
	std::ifstream file(argv[1]);
	if (!file.is_open()){
		std::cerr << "Error: could not open file." << std::endl;
		exit(0);
	}
	BitcoinExchange btc;
	btc.storeData("data.csv");
	std::string line;
	while (std::getline(file, line)){
		if (parse(ltrim(line))){
			std::string date = line.substr(0, line.find("|") - 1);
			float rate = btc.findValueFromDate(line.substr(0, line.find('|') - 1));
			if(rate != -100){
				float val = std::stof(line.substr(line.find('|') + 1, line.size()));
				std::cout << line.substr(0, line.find('|') - 1) << " => " << val << " = " << val * rate << std::endl;
			}
		}
	}
	file.close();
	return 0;
}