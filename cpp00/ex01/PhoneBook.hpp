/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:45:47 by rwegat            #+#    #+#             */
/*   Updated: 2025/03/17 01:37:18 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook{
	private:
    int		_index;
    bool	_is_full;
    Contact	_contacts[8];

	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	set_entry(void);
		void	get_entry(void)const;
		void	show_instruction(void);
};

#endif