#include "RPN.hpp"

std::string chars = "+-/*";

RPN::RPN(){};

RPN::RPN(RPN & rhs){
	*this = rhs;
};

RPN & RPN::operator=(RPN & rhs){
	this->_result = rhs._result;
	this->_formula = rhs._formula;
	return *this;
};

RPN::~RPN(){};

void RPN::convertVals(std::string input) {
	for (auto i : input){
		if (i != ' ')
			_formula.push_back(i);
	}
}

void RPN::printResult(void){
	std::cout << _result << std::endl;
}

int RPN::add(int val1, int val2){return (val1 + val2);};
int RPN::sub(int val1, int val2){return (val1 - val2);};
int RPN::mult(int val1, int val2){return (val1 * val2);};
int RPN::div(int val1, int val2){return (val1 / val2);};

int RPN::calcInd(int val1, int val2, char val3){
	int val; 
	switch (val3) {
		case '+':
			val = add(val1, val2);
			break ;
		case '-':
			val = sub(val1, val2);
			break ;
		case '/':
			val = div(val1, val2);
			break ;
		case '*':
			val = mult(val1, val2);
			break ;
		}
	return val;
}

void RPN::Calc(void){
	while(_formula.size()){
		if (std::isdigit(_formula[0]) && std::isdigit(_formula[1]) && std::isdigit(_formula[3]) && chars.find(_formula[2]) != std::string::npos){
			_result = calcInd(_formula[0] - '0', _formula[1] - '0', _formula[2]);
		_formula.pop_front();
		_formula.pop_front();
		_formula.pop_front();
		}
		else if(std::isdigit(_formula[0]) && chars.find(_formula[1]) != std::string::npos){
			_result = calcInd(_result, _formula[0] - '0', _formula[1]);
			_formula.pop_front();
			_formula.pop_front();
		}
		else if(std::isdigit(_formula[0]) && std::isdigit(_formula[1]) && chars.find(_formula[2]) != std::string::npos && chars.find(_formula[3]) != std::string::npos){
			int temp;
			temp = calcInd(_formula[0] - '0', _formula[1] - '0', _formula[2]);
			_formula.pop_front();
			_formula.pop_front();
			_formula.pop_front();
			if (_formula[0]){
				_result = calcInd(_result, temp, _formula[0]);
			_formula.pop_front();
			}
		}
		else {
			std::cout << "Error" << std::endl;
			exit (0);
		}
		printResult();
	}
}
