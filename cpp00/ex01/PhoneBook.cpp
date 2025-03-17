/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:50:30 by rwegat            #+#    #+#             */
/*   Updated: 2025/03/17 01:30:40 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

// Constructor
PhoneBook::PhoneBook(void) : _index(0), _is_full(false) {}

// Destructor
PhoneBook::~PhoneBook(void) {}

// Add a new contact
void PhoneBook::set_entry(void) {
    if (_contacts[_index].set_entry()) {
        _index = (_index + 1) % 8;
        if (_index == 0)
            _is_full = true;
    } else {
        std::cout << "Error: All fields must be filled. Contact not saved." << std::endl;
    }
}

// Display all contacts and prompt for an index to display details
void PhoneBook::get_entry(void) const {
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;

    for (int i = 0; i < (_is_full ? 8 : _index); i++) {
        std::cout << std::setw(10) << i << "|";
        _contacts[i].get_entry(i);
    }

    std::cout << "Enter the index of the contact to display: ";
    std::string input;
    std::getline(std::cin, input);
    if (input.empty() || input.find_first_not_of("01234567") != std::string::npos) {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    int idx = std::stoi(input);
    if (idx < 0 || idx >= (_is_full ? 8 : _index)) {
        std::cout << "Invalid index." << std::endl;
    } else {
        _contacts[idx].get_entry(idx);
    }
}