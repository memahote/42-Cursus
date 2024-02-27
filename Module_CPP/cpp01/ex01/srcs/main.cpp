/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:26:15 by memahote          #+#    #+#             */
/*   Updated: 2024/02/27 12:26:15 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		std::cout << "./ex01 <name> <quantity>" << std::endl;
		return (1);
	}

	std::string	name = av[1];
	int			n = std::atoi(av[2]);

	std::cout << "Testing with " << n << " zombies named " << name << std::endl;
	Zombie	*horde = zombieHorde(n, name);

	std::cout << "horde announce" << std::endl;
	for (int i = 0; i < n; i++)
		horde[i].announce();

	std::cout << "I'll now burry them again..." << std::endl;
	delete [] horde;
	return (0);
}