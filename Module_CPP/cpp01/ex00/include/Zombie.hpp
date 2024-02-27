/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:54:43 by memahote          #+#    #+#             */
/*   Updated: 2024/02/26 19:54:43 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
	std::string 		name;

	public:
	Zombie(std::string name);
	~Zombie();
	void announce(void);
	std::string getName(void);

};

Zombie *newZombie(std::string name);
void randomChump( std::string name );

#endif