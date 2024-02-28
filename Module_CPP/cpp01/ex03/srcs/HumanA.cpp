/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumainA.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:15:19 by memahote          #+#    #+#             */
/*   Updated: 2024/02/28 13:15:19 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name , Weapon& weapon) : weapon(weapon)
{
	std::cout << "HumanA constructor"<< name << this->weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA constructor"<< this->name << this->weapon.getType() << std::endl;
}

void 	HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}