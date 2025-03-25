/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:50:26 by rwegat            #+#    #+#             */
/*   Updated: 2025/03/25 12:12:13 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

// Constructor and Destructor
Contact::Contact(void)
{

}

Contact::~Contact(void)
{

}

// Getters
std::string Contact::getFirstName(void) const
{
    return this->firstName;
}

std::string Contact::getLastName(void) const
{
    return this->lastName;
}

std::string Contact::getNickname(void) const
{
    return this->nickname;
}

std::string Contact::getPhoneNumber(void) const
{
    return this->phoneNumber;
}

std::string Contact::getDarkestSecret(void) const
{
    return this->darkestSecret;
}

// Setters
void Contact::setFirstName(const std::string &firstName)
{
    this->firstName = firstName;
}

void Contact::setLastName(const std::string &lastName)
{
    this->lastName = lastName;
}

void Contact::setNickname(const std::string &nickname)
{
    this->nickname = nickname;
}

void Contact::setPhoneNumber(const std::string &phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string &darkestSecret)
{
    this->darkestSecret = darkestSecret;
}