/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:05:04 by memahote          #+#    #+#             */
/*   Updated: 2024/02/27 22:05:04 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{
	std::cout << "Weapon constructor" << this->type << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon destructor" << this->type << std::endl;
}


const std::string& Weapon::getType()
{
	return (this->type);
}


void	Weapon::setType(std::string type)
{
	this->type = type;
}