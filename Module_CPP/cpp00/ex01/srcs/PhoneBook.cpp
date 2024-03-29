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

std::string PhoneBook::trunc(std::string input)
{
	if (input.length() > 10)
    {
        input = input.substr(0,9);
        input += ".";
    }
    return input;
}

void	PhoneBook::helpMenu()
{
		std::cout<<"---     Welcome to the PhoneBool     ---"<<std::endl
				<<"---    Write ADD, to add a contact    ---"<<std::endl
				<<"--- Write SEARCH, to search a contact ---"<<std::endl
				<<"---   Write EXIT, to exit PhoneBook   ---"<<std::endl;
}

void PhoneBook::errorCommand()
{
	std::cout << "You can only use ADD, SEARCH or EXIT " << std::endl;
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
	int input;

	std::cout << "Enter the Index That you want to see!" << std::endl;
    std::cin >> input;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Only digit" << std::endl;
        return ;
    }
    if (this->index == 0)
        std::cout << "Table Is Empty" << std::endl;
    else if (input < (this->index < 8 ? this->index % 8 : 8) && input > -1)
    {
        std::cout << std::left << std::setw(10) << "First Name";
        std:: cout << " : ";
        std::cout << this->contact[(input)].get_fname() << std::endl;
        std::cout << std::setw(10) << "Last Name";
        std:: cout << " : ";
        std::cout << this->contact[(input)].get_lname() << std::endl;
        std::cout << std::setw(10) << "Nick Name";
        std:: cout << " : ";
        std::cout << this->contact[(input)].get_nname() << std::endl;
        std::cout << std::setw(10) << "Phone Number";
        std:: cout << " : ";
        std::cout << this->contact[(input)].get_phone_nb() << std::endl;
        std::cout << std::setw(10) << "Darkest Secret";
        std:: cout << " : ";
        std::cout << this->contact[(input)].get_secret() << std::endl;
    }
    else
    {
        std::cout << "Out of Index Range!" << std::endl;
    }
}
