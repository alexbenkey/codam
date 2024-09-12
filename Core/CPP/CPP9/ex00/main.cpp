#include "BitcoinExchange.hpp"

std::string parse(std::string in){
	if (in.find("|") == std::string::npos)
		return ("Error: bad input => " + in);
	int place = in.find('|');
	std::vector<std::string> tokens;
	std::string token;
	token = in.substr(0, place);
	tokens.push_back(token);
	token = in.substr(place + 1, in.size());
	tokens.push_back(token);
	//std::cout << "date: " << tokens[0] << std::endl;
	//std::cout << "val: " << tokens[1] << std::endl << std::endl;
	return (in);
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
		std::cout << parse(line)  << std::endl;
		std:: cout << "found value: " << btc.findValueFromDate(line.substr(0, line.find('|') - 1)) << std::endl;
	}
	file.close();
	return 0;
}