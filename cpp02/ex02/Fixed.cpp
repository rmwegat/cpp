/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:22:37 by rwegat            #+#    #+#             */
/*   Updated: 2025/03/26 15:41:06 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _value(0)
{

}

Fixed::Fixed(const int val) : _value(val << Fixed::_fractionalBits)
{

}

Fixed::Fixed(const float val) : _value(static_cast<int>(roundf(val * (1 << Fixed::_fractionalBits))))
{

}

Fixed::Fixed(const Fixed& copy) : _value(copy._value)
{
	
}

Fixed::~Fixed()
{

}

Fixed& Fixed::operator=(const Fixed& source)
{
    if (this != &source)
    {
        this->_value = source._value;
    }
    return *this;
}

bool Fixed::operator>(Fixed fixed) const
{
    return (this->_value > fixed._value);
}

bool Fixed::operator<(Fixed fixed) const
{
    return (this->_value < fixed._value);
}

bool Fixed::operator>=(Fixed fixed) const
{
    return (this->_value >= fixed._value);
}

bool Fixed::operator<=(Fixed fixed) const
{
    return (this->_value <= fixed._value);
}

bool Fixed::operator==(Fixed fixed) const
{
    return (this->_value == fixed._value);
}

bool Fixed::operator!=(Fixed fixed) const
{
    return (this->_value != fixed._value);
}

float Fixed::operator+(Fixed fixed) const
{
    return this->toFloat() + fixed.toFloat();
}

float Fixed::operator-(Fixed fixed) const
{
    return this->toFloat() - fixed.toFloat();
}

float Fixed::operator*(Fixed fixed) const
{
    return this->toFloat() * fixed.toFloat();
}

float Fixed::operator/(Fixed fixed) const
{
    return this->toFloat() / fixed.toFloat();
}

Fixed Fixed::operator++()
{
    this->_value++;
    return *this;
}

Fixed Fixed::operator--()
{
    this->_value--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->_value++;
    return temp;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->_value--;
    return temp;
}

float Fixed::toFloat() const
{
    return static_cast<float>(this->_value) / (1 << Fixed::_fractionalBits);
}

int Fixed::toInt() const
{
    return this->_value >> Fixed::_fractionalBits;
}

int Fixed::getRawBits() const
{
    return this->_value;
}

void Fixed::setRawBits(const int raw)
{
    this->_value = raw;
}

Fixed& Fixed::min(Fixed& first, Fixed& second)
{
    return (first < second) ? first : second;
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second)
{
    return (first < second) ? first : second;
}

Fixed& Fixed::max(Fixed& first, Fixed& second)
{
    return (first > second) ? first : second;
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second)
{
    return (first > second) ? first : second;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}