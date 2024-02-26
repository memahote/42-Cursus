/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:29:40 by memahote          #+#    #+#             */
/*   Updated: 2023/11/22 19:29:40 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "Contact.hpp"
#include <limits>

class PhoneBook
{
	private:
	Contact contact[8];
	int	index;

	public:
	PhoneBook();
	~PhoneBook();

	void helpMenu();
	void addContact();
	void searchContat();
	void printContact(Contact contact);
	void errorCommand();
	std::string trunc(std::string input);

};


#endif