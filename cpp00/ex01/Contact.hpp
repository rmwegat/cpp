/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:48:45 by rwegat            #+#    #+#             */
/*   Updated: 2025/03/17 01:31:16 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

class Contact
{
    private:
        static std::string	_fields_name[5];
        std::string			_informations[11];

        enum Field {
            FirstName = 0,
            LastName,
            NickName,
            PhoneNumber,
            DarkestSecret
        };
    public:
		Contact(void);
		~Contact(void);

		bool	set_entry();
		void	get_entry(int i);
};

#endif