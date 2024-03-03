/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:08:23 by memahote          #+#    #+#             */
/*   Updated: 2024/02/29 21:08:23 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <fstream>


class Replace
{
	public :

	Replace(std::string filename);
	~Replace();
	void	replace_s1bys2(std::string s1, std::string s2);

	private :

	std::string fin;
	std::string fout;
};

#endif