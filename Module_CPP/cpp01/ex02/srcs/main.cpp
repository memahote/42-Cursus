/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:37:01 by memahote          #+#    #+#             */
/*   Updated: 2024/02/27 21:37:01 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string str;
	std::string *stringPTR;

	str = "HI THIS IS BRAIN";
	stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Adresse de str : " << &str << std::endl;
	std::cout << "Adresse de stringPTR : " << &stringPTR << std::endl;
	std::cout << "Adresse de stringREF : " << &stringREF << std::endl;

	std::cout << "Valeur de str : " << str << std::endl;
	std::cout << "Valeur de stringPTR : " << *stringPTR << std::endl;
	std::cout << "Valeur de stringREF : " << stringREF << std::endl;
}