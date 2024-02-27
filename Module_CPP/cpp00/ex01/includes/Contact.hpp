/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:49:28 by memahote          #+#    #+#             */
/*   Updated: 2023/11/22 19:49:28 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP
#include <iostream>
#include <iomanip>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;

	public:
	void	set_fname(std::string fname);
	void	set_lname(std::string lname);
	void	set_nname(std::string nname);
	void	set_phone_nb(std::string phone_nb);
	void	set_secret(std::string secret);

	std::string get_fname();
	std::string get_lname();
	std::string get_nname();
	std::string get_phone_nb();
	std::string get_secret();

	Contact(void);
	~Contact(void);
};

#endif