/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:38:30 by ldick             #+#    #+#             */
/*   Updated: 2025/08/29 16:21:38 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	std::cout << "RPN: Default constructor called" << std::endl;
}

RPN::RPN(RPN const &copy)
{
	this->stack = copy.stack;
	std::cout << "RPN: copy constructor called" << std::endl;
}

RPN &RPN::operator=(RPN const &copy)
{
	this->stack = copy.stack;
	std::cout << "RPN: Assignment constructor called" << std::endl;
	return (*this);
}

RPN::~RPN()
{
	std::cout << "RPN: Default Deconstructor called";
}

static int input_check(std::string input)
{
	size_t pos = input.find_first_not_of("+-*/0123456789 ");
	if (pos == std::string::npos)
		return (0);
	else
		std::cerr << "Character '" << input[pos] << "' at position "<< pos << " is not an allowed input" << std::endl;
	return (-1);
}

int RPN::calculate(std::string input)
{
	int result = 0;
	int temp = 0;
	if (input_check(input) == -1)
		return (-1);
	for (int i = 0; input[i]; i++)
	{
		if (std::isdigit(input[i]))
			this->stack.push(input[i] - '0');
		if (input[i] == '+')
		{
			temp = this->stack.top();
			this->stack.pop();
			temp = this->stack.top() + temp;
			this->stack.pop();
			this->stack.push(temp);
		}
		if (input[i] == '-')
		{
			temp = this->stack.top();
			this->stack.pop();
			temp = this->stack.top() - temp;
			this->stack.pop();
			this->stack.push(temp);
		}
		if (input[i] == '*')
		{
			temp = this->stack.top();
			this->stack.pop();
			temp = this->stack.top() * temp;
			this->stack.pop();
			this->stack.push(temp);
		}
		if (input[i] == '/')
		{
			temp = this->stack.top();
			this->stack.pop();
			temp = this->stack.top() / temp;
			this->stack.pop();
			this->stack.push(temp);
		}
	}
	result = this->stack.top();
	while(!this->stack.empty())
		this->stack.pop();
	return (result);
}