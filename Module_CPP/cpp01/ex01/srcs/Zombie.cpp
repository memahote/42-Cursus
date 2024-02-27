/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:56:03 by memahote          #+#    #+#             */
/*   Updated: 2024/02/26 19:56:03 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Default Zombie Constructor called" << std::endl;
	return ;
}

Zombie::Zombie(std::string name) : name(name)
{
	std::cout << "Zombie \"" << this->name << "\" Constructor called" << std::endl;
	return ;
}

Zombie::~Zombie()
{
	std::cout << "Zombie \"" << this->name << "\" Destructor called" << std::endl;
}

void 	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_Name(std::string name)
{
	this->name = name;
}