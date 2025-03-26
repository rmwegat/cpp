/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:09:57 by rwegat            #+#    #+#             */
/*   Updated: 2025/03/26 14:51:45 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_fractionalBits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed& copy);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed(void);
	
		Fixed&	operator=( const Fixed& copy );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		int 	getRawBits( void ) const;
		void	setRawBits( const int raw );
};

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed);

#endif