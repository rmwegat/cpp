/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:15:18 by ldick             #+#    #+#             */
/*   Updated: 2025/08/29 16:21:30 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <algorithm>
#include <stack>
#include <fstream>

class RPN
{
	public:
		RPN();
		RPN(RPN const &copy);
		RPN &operator=(RPN const &copy);
		~RPN();
		int calculate(std::string input);
	private:
		std::stack<int> stack;
};

#endif