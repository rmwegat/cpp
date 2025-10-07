/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 20:44:18 by shovsepy          #+#    #+#             */
/*   Updated: 2025/03/26 14:21:22 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int 				value;
		static const int	fractBits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed& other);
		Fixed(const float val);
		Fixed(const int val);
		~Fixed(void);

		Fixed&			operator=(const Fixed& other);
		int 			getRawBits(void) const;
		void			setRawBits(const int raw);
		
		int 			toInt(void) const;
		float			toFloat(void) const;
};

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed);
