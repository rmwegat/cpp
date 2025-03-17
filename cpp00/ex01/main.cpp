/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:50:33 by rwegat            #+#    #+#             */
/*   Updated: 2025/03/10 22:54:15 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Contact.hpp"
#include "./PhoneBook.hpp"

int main(void)
{

    PhoneBook   PhoneBook;
    bool        run = true;
    std::string cmd;

    while (run && std::getline(std::cin, cmd))
    {
        if (cmd.compare("ADD") == 0)
            PhoneBook.set_entry();
        else if (cmd.compare("SEARCH") == 0)
            PhoneBook.get_entry();
        else if (cmd.compare("EXIT") == 0)
            run = false;
        cmd.clear();
    }
    return (0);
}