/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:40:13 by memahote          #+#    #+#             */
/*   Updated: 2023/11/22 19:40:13 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

//constructeur
PhoneBook::PhoneBook(){
	this->index = 0;
	this->helpMenu();
}

//destructeur
PhoneBook::~PhoneBook(){

}

void	PhoneBook::helpMenu()
{
		std::cout<<"---     Welcome to the PhoneBool     ---"<<std::endl
				<<"---    Write ADD, to add a contact    ---"<<std::endl
				<<"--- Write SEARCH, to search a contact ---"<<std::endl
				<<"---   Write EXIT, to exit PhoneBook   ---"<<std::endl;
}

void	PhoneBook::addContact()
{
	Contact 	new_contact;
	std::string 	input;

	std::cout << "Enter  first name of your contact " << std::endl;
	getline(std::cin, input);
	new_contact.set_fname(input);
	std::cout << "Enter last name of your contact " << std::endl;
	getline(std::cin, input);
	new_contact.set_lname(input);
	std::cout << "Enter phone number of your contact " << std::endl;
	getline(std::cin, input);
	new_contact.set_phone_nb(input);
	std::cout  << "Enter the nickname of your contact" << std::endl;
	getline(std::cin, input);
	new_contact.set_nname(input);
	std::cout  << "Enter the secret of your contact" << std::endl;
	getline(std::cin, input);
	new_contact.set_secret(input);
	this->contact[this->index % 8] = new_contact;
	this->index++;
}

void	PhoneBook::searchContat()
{

}

void	PhoneBook::printContact()
{

}