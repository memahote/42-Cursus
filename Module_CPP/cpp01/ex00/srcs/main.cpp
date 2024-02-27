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

int	main(void)
{
	std::cout << "Creating a zombie from main... (on the stack)" << std::endl;
	// Stack Zombie
	Zombie z2("Test2");

	std::cout << "Creating a zombie from the newZombie function... (on the heap)" << std::endl;
	// Heap zombie
	Zombie*	z = newZombie("Test");
	
	z->announce();
	z2.announce();

	std::cout << "Creating a zombie and making it announce itself" << std::endl;
	randomChump("Random Guy");
	std::cout << "And... he's gone..." << std::endl;

	// deleting the zombie on the Heap
	std::cout << "Manually deleting heap zombie." << std::endl;
	delete(z);
	// same thing as free after using malloc in C
	return (0);
}