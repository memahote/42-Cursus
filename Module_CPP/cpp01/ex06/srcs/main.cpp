/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 01:08:37 by memahote          #+#    #+#             */
/*   Updated: 2024/03/03 01:08:37 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

int main(int ac, char **av)
{
	Harl test;

	if (ac == 2)
		test.complain(av[1]);
	else
		test.complain("Level not found");
}