/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:50:30 by rwegat            #+#    #+#             */
/*   Updated: 2025/03/25 15:07:39 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

// Constructor
PhoneBook::PhoneBook(void) : _index(0), _is_full(false)
{

}

// Destructor
PhoneBook::~PhoneBook(void)
{

}

// Add a new contact
void PhoneBook::add_contact(const std::string data[5])
{
    _contacts[_index].setFirstName(data[0]);
    _contacts[_index].setLastName(data[1]);
    _contacts[_index].setNickname(data[2]);
    _contacts[_index].setPhoneNumber(data[3]);
    _contacts[_index].setDarkestSecret(data[4]);

    _index = (_index + 1) % 8;
    if (_index == 0)
        _is_full = true;
}

// Display all contacts in a tabular format
void PhoneBook::display_phonebook(void) const
{
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    std::cout << std::string(44, '_') << std::endl;

    int i = 0;
    while (i < (_is_full ? 8 : _index))
    {
        std::string first_name = _contacts[i].getFirstName();
        if (first_name.length() > 10)
            first_name = first_name.substr(0, 9) + ".";
        std::string last_name = _contacts[i].getLastName();
        if (last_name.length() > 10)
            last_name = last_name.substr(0, 9) + ".";
        std::string nickname = _contacts[i].getNickname();
        if (nickname.length() > 10)
            nickname = nickname.substr(0, 9) + ".";
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << first_name << "|"
                  << std::setw(10) << last_name << "|"
                  << std::setw(10) << nickname << std::endl;
        i++;
    }
}

// Get the number of contacts currently stored
int PhoneBook::get_size(void) const
{
    return (_is_full ? 8 : _index);
}

// Display the details of a specific contact
void PhoneBook::display_contact(int _index) const
{
    if (_index < 0 || _index >= get_size())
    {
        std::cout << "Index is Invalid or Empty" << std::endl;
        return ;
    }
    std::cout << "First Name: " << _contacts[_index].getFirstName() << std::endl;
    std::cout << "Last Name: " << _contacts[_index].getLastName() << std::endl;
    std::cout << "Nickname: " << _contacts[_index].getNickname() << std::endl;
    std::cout << "Phone Number: " << _contacts[_index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << _contacts[_index].getDarkestSecret() << std::endl;
}
