/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:16:01 by rwegat            #+#    #+#             */
/*   Updated: 2025/03/26 14:50:00 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}


Fixed::Fixed(const float val)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = static_cast<int>(roundf(val * (1 << Fixed::_fractionalBits)));
}

Fixed::Fixed(const int val)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = val << Fixed::_fractionalBits;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

int 	Fixed::toInt() const
{
	return (this->_value >> Fixed::_fractionalBits);
}

float	Fixed::toFloat() const
{
	return ((float)this->_value/(float)(1 << Fixed::_fractionalBits));
}

void	Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}
Fixed& Fixed::operator=(const Fixed& source)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &source)
	{
		this->_value = source.getRawBits();
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
