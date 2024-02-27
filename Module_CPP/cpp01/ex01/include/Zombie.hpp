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

# include <iostream>
# include <stdlib.h> 

class Zombie
{
	private:
	std::string 		name;

	public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void announce(void);
	void set_Name(std::string name);

};

Zombie* zombieHorde( int N, std::string name );

#endif