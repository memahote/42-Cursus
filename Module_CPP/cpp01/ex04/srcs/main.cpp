/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:02:18 by memahote          #+#    #+#             */
/*   Updated: 2024/02/29 17:02:18 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int ac, char **av)
{
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	if (ac == 4)
	{
		if (filename.empty() ||  s1.empty() || s2.empty())
		{
			std::cout << "Error : empty arg" << std::endl;
			return (-1);
		}
		Replace replace(av[1]);
		replace.replace_s1bys2(av[2], av[3]);
	}
	else
		std::cout << "Please retry  with exactly 3 arguments." << 
		"./replace file string1 string2" << std::endl;
}