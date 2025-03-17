/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:50:26 by rwegat            #+#    #+#             */
/*   Updated: 2025/03/17 01:39:01 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

// Static field names
std::string Contact::_fields_name[5] = {
    "First Name", "Last Name", "Nickname", "Phone Number", "Darkest Secret"
};

// Constructor
Contact::Contact(void) {}

// Destructor
Contact::~Contact(void) {}

// Set contact information
bool Contact::set_entry() {
    for (int i = 0; i < 5; i++) {
        std::cout << "Enter " << _fields_name[i] << ": ";
        std::getline(std::cin, _informations[i]);
        if (_informations[i].empty()) {
            return false;
        }
    }
    return true;
}

// Display contact information
void Contact::get_entry(int i) const
{
    for (int j = 0; j < 3; j++) {
        if (_informations[j].length() > 10)
            std::cout << std::setw(10) << _informations[j].substr(0, 9) + "." << "|";
        else
            std::cout << std::setw(10) << _informations[j] << "|";
    }
    std::cout << std::endl;
}
