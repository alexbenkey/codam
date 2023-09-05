/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/03 18:32:30 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/08/02 13:18:48 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"
# include <iostream>

Phonebook::Phonebook(void){

	//std::cout << "Phonebook has been constructed" << std::endl;
	Phonebook::NextPos = 0;
	return ;
};

Phonebook::~Phonebook(void){

	//std::cout << "Phonebook has been deconstructed" << std::endl;
	return ;
};

void Phonebook::PrintContact(int i){
	if (this->ContactIsEmpty(i))
		std::cout << "this contact field is empty\n\n";
	else{
	std::cout << "first name: " << this->Contacts[i].GetFirstName() << std::endl;
	std::cout << "last name : " << this->Contacts[i].GetLastName() << std::endl;
	std::cout << "nickname  : " << this->Contacts[i].GetNickName() << std::endl;
	std::cout << "number    : " << this->Contacts[i].GetNumber() << std::endl;
	std::cout << "secret    : " << this->Contacts[i].GetDarkestSecret() << std::endl;
	}
}

void Phonebook::PrintAllContacts(void){
	
	std::cout << "#################### CONTACTS ###################" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (!this->ContactIsEmpty(i))
		{
			std::cout << (i + 1) << " |"; 
			std::cout << std::right << std::setw(10) << this->Contacts[i].Truncate(this->Contacts[i].GetFirstName()) << "|";
			std::cout << std::right << std::setw(10) << this->Contacts[i].Truncate(this->Contacts[i].GetLastName()) <<  "|";
			std::cout << std::right << std::setw(10) << this->Contacts[i].Truncate(this->Contacts[i].GetNickName()) << "\n";
		}
	}
	std::cout << "\n\n";
};

int Phonebook::GetNextPos(void){
	return this->NextPos;
};

void Phonebook::SetNextPos(void){
	if (this->GetNextPos() == 7)
		this->NextPos = 0;
	else
		this->NextPos++;
}


void Phonebook::ClearContact(void){
	int i;
	
	i = this->GetNextPos();
	this->Contacts[i].SetFirstName("");
	this->Contacts[i].SetLastName("");
	this->Contacts[i].SetNickName("");
	this->Contacts[i].SetNumber("");
	this->Contacts[i].SetDarkestSecret("");
}

void	Phonebook::AddContact(){
	
	std::string str;
	int			index;

	index = Phonebook::GetNextPos();
	std::cout << "please enter a first name: ";
	//std::getline(std::cin, str);
	std::cin >> str;
	this->ProtectCin();
	if (str.length() == 0){
		this->ClearContact();
		std::cout << "a field cannot be empty, please try again\n\n";
		return ;
	}
	this->Contacts[index].SetFirstName(str);

	std::cout << "please enter a last name: ";
	std::cin >> str;
	this->ProtectCin();
	if (str.length() == 0){
		this->ClearContact();
		std::cout << "a field cannot be empty, please try again\n\n";
		return ;
	}
	this->Contacts[index].SetLastName(str);

	std::cout << "please enter a nickname: ";
	std::cin >> str;
	this->ProtectCin();
	if (str.length() == 0){
		this->ClearContact();
		std::cout << "a field cannot be empty, please try again\n\n";
		return ;
	}
	this->Contacts[index].SetNickName(str);

	std::cout << "please enter a phone number: ";
	std::cin >> str;
	this->ProtectCin();
	if (str.length() == 0){
		this->ClearContact();
		std::cout << "a field cannot be empty, please try again\n\n";
		return ;
	}
	this->Contacts[index].SetNumber(str);

	std::cout << "please enter a darkest secret: ";
	std::cin >> str;
	this->ProtectCin();
	if (str.length() == 0){
		this->ClearContact();
		std::cout << "a field cannot be empty, please try again\n\n";
		return ;
	}
	this->ProtectCin();
	this->Contacts[index].SetDarkestSecret(str);

	std::cout << "\n\n";
	this->SetNextPos();
};

void Phonebook::GetFullContact(std::string val){
	if (val == "1")
		this->PrintContact(0);
	else if (val == "2")
		this->PrintContact(1);
	else if (val == "3")
		this->PrintContact(2);
	else if (val == "4")
		this->PrintContact(3);
	else if (val == "5")
		this->PrintContact(4);
	else if (val == "6")
		this->PrintContact(5);
	else if (val == "7")
		this->PrintContact(6);
	else if (val == "8")
		this->PrintContact(7);
	else
		std::cout << "invalid input please try again" << std::endl;
}

int Phonebook::ContactIsEmpty(int i){
	if (this->Contacts[i].GetFirstName() == "")
		return (1);
	else
		return (0);
}

int Phonebook::ProtectCin(void){
	if (std::cin.eof())
	{
		std::cin.clear();
		std::clearerr(stdin);
		return (1);
	}
	return (0);
}

int main()
{
	Phonebook 	instance;
	std::string input_s;
	std::string buf;
	int			contact_val;
	
	while(input_s != "EXIT")
	{
		std::cout << "\nplease select an option by typing 'ADD', 'SEARCH' or 'EXIT'\n" << std::endl;
		std::cout << "input an option: ";
		std::cin >> input_s;
		instance.ProtectCin();
		if (input_s == "ADD")
		{
			instance.AddContact();
		}
		else if (input_s == "SEARCH")
		{
			instance.PrintAllContacts();
			std::cout << "\n\n";
			if (!instance.ContactIsEmpty(0))
			{
				std::cout << "\nplease input a number to print all contact info, or type 'EXIT': ";
				std::cin >> buf;
				instance.ProtectCin();
				if (buf != "EXIT")
					instance.GetFullContact(buf);
			}
		}
		else
			std::cout << "\ninvalid input, please use 'ADD', 'SEARCH' or 'EXIT'" << std::endl;
	}
	return (0);
}