/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:22:16 by memahote          #+#    #+#             */
/*   Updated: 2023/11/22 19:22:16 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	std::string input;
	PhoneBook iphone;

	while (1)
	{
		if (std::cin.eof()) 
		{
            return 1;
        }
		std::getline(std::cin, input);
		if (input == "EXIT")
			break;
		else if (input == "ADD")
			iphone.addContact();
		else if (input == "SEARCH")
			iphone.searchContat();
		else
			iphone.errorCommand();
	}
	return (0);
}