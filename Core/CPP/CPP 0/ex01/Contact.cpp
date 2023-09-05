#include "Contact.hpp"

Contact::Contact(void){
	
	//std::cout << "constructor called" << std::endl;
	return;
};

Contact::~Contact(void){

	//std::cout << "destructor called" << std::endl;
	return;
};

std::string	Contact::GetFirstName(void) const{
	return (this->_first_name);
}

std::string	Contact::GetLastName(void) const{
	return (this->_last_name);
}

std::string	Contact::GetNickName(void) const{
	return (this->_nickname);
}

std::string	Contact::GetNumber(void) const{
	return (this->_number);
}

std::string Contact::GetDarkestSecret(void) const{
	return (this->_darkest_secret);
}

void Contact::SetFirstName(std::string str){
	this->_first_name = str;
}

void Contact::SetLastName(std::string str){
	this->_last_name = str;
}

void Contact::SetNickName(std::string str){
	this->_nickname = str;
}

void Contact::SetNumber(std::string str){
	this->_number = str;
}

void Contact::SetDarkestSecret(std::string str){
	this->_darkest_secret = str;
}

std::string Contact::Truncate(std::string str)
{
	if (str.length() > 10) 
		return str.substr(0, 9) + ".";
	else
		return str;
};

void Contact::AddContact(void){

	Contact::_first_name = "";
	Contact::_last_name = "";
	Contact::_nickname = "";
	Contact::_number = "";
	Contact::_darkest_secret = "";

	std::cout << "please enter a first name: ";
	std::cin >> Contact::_first_name;
	std::cout << "first name entered: " << Contact::_first_name << std::endl;

	std::cout << "please enter a last name: ";
	std::cin >> Contact::_last_name;
	std::cout << "last name entered: " << Contact::_last_name << std::endl;

	std::cout << "please enter a nickname: ";
	std::cin >> Contact::_nickname;
	std::cout << "nickname entered: " << Contact::_nickname << std::endl;

	std::cout << "please enter a phone number: ";
	std::cin >> Contact::_number;
	std::cout << "phone number entered: " << Contact::_number << std::endl;

	std::cout << "please enter darkest secret: ";
	std::cin >> Contact::_darkest_secret;
	std::cout << "secret entered: " << Contact::_darkest_secret << std::endl;
};
