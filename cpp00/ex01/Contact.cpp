/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:49:45 by memahote          #+#    #+#             */
/*   Updated: 2023/11/22 19:49:45 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

//constructeur
Contact::Contact() {

}

//destructeur
Contact::~Contact(){

}

void	Contact::set_fname(std::string fname)
{
	this->first_name = fname;
}

void	Contact::set_lname(std::string lname)
{
	this->last_name = lname;
}

void	Contact::set_nname(std::string nname)
{
	this->nick_name = nname;
}

void	Contact::set_phone_nb(std::string phone_nb)
{
	this->phone_number = phone_nb
}

void	Contact::set_secret(std::string secret)
{
	this->darkest_secret = secret;
}

std::string	Contact::get_fname()
{
	return  (this->first_name);
}

std::string	Contact::get_lname()
{
	return   (this->last_name);
}

std::string	Contact::get_nname()
{
	return   (this->nick_name);
}

std::string	Contact::get_phone_nb()
{
	return (this->phone_number);
}

std::string	Contact::get_secret()
{
	return  (this->darkest_secret);
}