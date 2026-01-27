/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:15:10 by ldick             #+#    #+#             */
/*   Updated: 2025/08/29 16:12:16 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		RPN polish;
		std::cout << polish.calculate(argv[1]) << std::endl;
	}
	if (argc == 1)
	{
		RPN polish;
		std::stack<std::string> input;
		std::string temp;
		std::ifstream text("input.txt");
		if (!text.is_open())
			return (std::cout << "Text file could not be opened" << std::endl, 1);
		while(std::getline(text, temp))
			input.push(temp);
		while(!input.empty())
		{
			std::cout << polish.calculate(input.top()) << std::endl;
			input.pop();
		}
	}
	return (0);
}