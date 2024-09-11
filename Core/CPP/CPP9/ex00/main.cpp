#include "BitcoinExchange.hpp"

std::string parse(std::string in){
	if (in.find("|") == std::string::npos)
		return ("Error: bad input => " + in);
	int place = in.find("|");
	std::vector<std::string> tokens;
	std::string token;
	token = in.substr(0, in.find("|"));
	tokens.push_back(token);
	
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
	std::string line;
	while (std::getline(file, line)){
		std::cout << parse(line)  << std::endl;
	}
	file.close();
	return 0;
}