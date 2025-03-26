/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:50:33 by rwegat            #+#    #+#             */
/*   Updated: 2025/03/26 10:13:58 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Contact.hpp"
#include "./PhoneBook.hpp"
#include <cctype>
#include <iostream>
#include <string>
#include <limits>


bool is_valid_number(const std::string &number)
{
    for (std::string::const_iterator it = number.begin(); it != number.end(); ++it)
    {
        if (!std::isdigit(*it))
            return false;
    }
    return true;
}


void handle_add(PhoneBook &phonebook)
{
    std::string fields[] = {"First Name", "Last Name", "Nickname", "Phone Number", "Darkest Secret"};
    std::string data[5];

    int i = 0;
    while (i < 5)
    {
        std::cout << fields[i] << ": ";
        std::getline(std::cin, data[i]);
        if (data[i].empty() || (i == 3 && !is_valid_number(data[i])))
            std::cout << "Invalid input. Please try again." << std::endl;
        else
            i++;
    }
    phonebook.add_contact(data);
    std::cout << "Saved to Contacts✅" << std::endl;
}


void handle_search(PhoneBook &phonebook)
{
    int index;

    phonebook.display_phonebook();
    std::cout << "\nDisplay Index: ";
    std::cin >> index;
    if (std::cin.fail() || index < 0 || index >= phonebook.get_size())
    {
        std::cout << "Index not found\n" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    phonebook.display_contact(index);
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
    PhoneBook phonebook;
    std::string input;

    while (std::cin)
    {
        std::cout << "PhoneBook> ";
        std::getline(std::cin, input);
        if (input == "ADD")
            handle_add(phonebook);
        else if (input == "SEARCH")
            handle_search(phonebook);
        else if (input == "EXIT")
            break;
        else if (!std::cin.eof())
            std::cout << "Invalid command. Valid Commands are 'ADD' 'SEARCH' 'EXIT'\n" << std::endl;
    }
    return 0;
}
