/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 23:00:01 by memahote          #+#    #+#             */
/*   Updated: 2024/03/01 23:00:01 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
	private :
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

	public :
	Harl();
	~Harl();
	void	complain(std::string level);
};
#endif