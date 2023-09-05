/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/03 18:32:33 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/07/14 15:06:26 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook {

public:

	Phonebook (void);
	~Phonebook (void);
	
	void	PrintContact(int i);
	void	AddContact(void);
	void	PrintAllContacts(void);
	int		GetNextPos(void);
	void	ClearContact(void);
	void 	SetNextPos(void);
	void	GetFullContact(std::string);
	int		ContactIsEmpty(int i);
	int 	ProtectCin(void);

private:

	Contact Contacts[8];
	int 	NextPos;
};
#endif