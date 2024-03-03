/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:44:45 by memahote          #+#    #+#             */
/*   Updated: 2024/03/02 10:44:45 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "[DEBUG] : I love having extra bacon for my "
	<< "7XL-double-cheese-triple-pickle-specialketchup burger. I really do"  << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO] : cannot believe adding extra bacon costs more money." 
		<< "You didn’t put enough bacon in my burger ! "
		<< "If you did, I wouldn’t be asking for more !" << std::endl;
}

void	Harl::warning(void)
{
	std::cerr << "[WARNING] : think I deserve to have some extra bacon for free. "
		<< "I’ve been coming for years whereas you started working here since last month"
		<< std::endl;
}
	
void	Harl::error(void)
{
	std::cerr << "[ERROR] : This is unacceptable ! I want to speak to the manager now"
	<< std::endl;
}

void	Harl::complain(std::string level)
{
	std::string tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*func[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int i = 0;

	while (i < 4)
	{
		if (tab[i] == level)
			(this->*func[i])();
		i++;
	}

}