/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:08:27 by memahote          #+#    #+#             */
/*   Updated: 2024/02/29 21:08:27 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

Replace::Replace(std::string filename) : fin(filename)
{
	std::cout << "Constructor  called for class Replace." << std::endl;

	std::ifstream infile(this->fin.c_str());
	if (infile.is_open())
	{
		this->fout = this->fin + ".replace";
	}
	else
	{
		std::cout << "ERROR: Can't open the file" << std::endl;
	}
	infile.close();
}

Replace::~Replace()
{
	std::cout << "Destructor called"  << std::endl;
}

void Replace::replace_s1bys2(std::string s1, std::string s2)
{
	std::ifstream infile(this->fin.c_str());
	if (infile.is_open())
	{
		std::string  line;
		std::ofstream outfile(this->fout.c_str());
		if(outfile.is_open())
		{
			while (std::getline(infile, line))
			{
				int i = 0;
				size_t found = line.find(s1);
				while (found != std::string::npos) 
				{
					outfile <<  line.substr(i, found - i);
					outfile << s2;
					i = found + s1.length();
					found = line.find(s1, i);
				}
				outfile << line.substr(i);
                outfile << std::endl;
            }
            infile.close();
            outfile.close();
			
		}
		else
			std::cout << "Error : Open outfile";
	}
	else
		std::cout << "Error : Open infile" ;
}
