/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:01:07 by memahote          #+#    #+#             */
/*   Updated: 2024/03/04 22:01:07 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int	nb;
		static const int bit = 8;

	public :
		Fixed();
		Fixed(const Fixed &fixed);
		~Fixed();
		Fixed& operator=(const Fixed&fixed);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif