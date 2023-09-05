#ifndef CONTACT_HPP
# define  CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact{

public:
	Contact(void);
	~Contact(void);

	void		AddContact(void);
	std::string Truncate(std::string s);
	
	//setters
	void SetFirstName(std::string str);
	void SetLastName(std::string str);
	void SetNickName(std::string str);
	void SetNumber(std::string str);
	void SetDarkestSecret(std::string str);

	//getters
	std::string GetFirstName(void) const;
	std::string GetLastName(void) const;
	std::string GetNickName(void) const;
	std::string GetNumber(void) const;
	std::string GetDarkestSecret(void) const;

private:

	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_number;
	std::string _darkest_secret;
}; 

#endif